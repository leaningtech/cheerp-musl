Name: cheerp-musl
Version: 3.0
Release:        1%{?dist}
Summary: A C++ compiler for the Web, C library implementation

License:  MIT
URL: https://leaningtech.com/cheerp
Source0: %{NAME}_%{VERSION}.orig.tar.gz

BuildRequires: autoconf automake libtool make cheerp-llvm-clang = %{VERSION} cheerp-utils = %{VERSION}
Requires: cheerp-llvm-clang = %{VERSION} cheerp-utils = %{VERSION}

%description
Cheerp is a tool to bring C++ programming to the Web. It can generate a seamless
combination of JavaScript, WebAssembly and Asm.js from a single C++ codebase.

%define debug_package %{nil}

%prep
%autosetup

mkdir -p build_genericjs
cd build_genericjs
CHEERP_PREFIX=/opt/cheerp RANLIB="${CHEERP_PREFIX}/bin/llvm-ar s" AR="${CHEERP_PREFIX}/bin/llvm-ar" CC="${CHEERP_PREFIX}/bin/clang -target cheerp" LD="${CHEERP_PREFIX}/bin/llvm-link" CFLAGS="-Wno-int-conversion" ../configure --target=cheerp --disable-shared --prefix=${CHEERP_PREFIX}
cd ..

mkdir -p build_wasm
cd build_wasm
CHEERP_PREFIX=/opt/cheerp RANLIB="${CHEERP_PREFIX}/bin/llvm-ar s" AR="${CHEERP_PREFIX}/bin/llvm-ar" CC="${CHEERP_PREFIX}/bin/clang -target cheerp-wasm" LD="${CHEERP_PREFIX}/bin/llvm-link" CFLAGS="-Wno-int-conversion" ../configure --target=cheerp-wasm --disable-shared --prefix=${CHEERP_PREFIX}


%build
%make_build -C build_genericjs
%make_build -C build_wasm

%install
make -C build_genericjs install-cheerp DESTDIR=%{buildroot}/opt/cheerp INSTALL="/usr/bin/install -p"
make -C build_wasm install-bc DESTDIR=%{buildroot}/opt/cheerp INSTALL="/usr/bin/install -p"

%clean
rm -rf $RPM_BUILD_ROOT

%files
/opt/cheerp/lib/genericjs/libc.bc
/opt/cheerp/lib/genericjs/libm.a
/opt/cheerp/lib/genericjs/crt1.bc
/opt/cheerp/lib/genericjs/libcrypt.a
/opt/cheerp/lib/genericjs/libdl.a
/opt/cheerp/lib/genericjs/libpthread.a
/opt/cheerp/lib/genericjs/libresolv.a
/opt/cheerp/lib/genericjs/librt.a
/opt/cheerp/lib/genericjs/libutil.a
/opt/cheerp/lib/genericjs/libxnet.a
/opt/cheerp/include/
/opt/cheerp/lib/asmjs/crt1.bc
/opt/cheerp/lib/asmjs/libc.bc
/opt/cheerp/lib/asmjs/libm.a
/opt/cheerp/lib/asmjs/libcrypt.a
/opt/cheerp/lib/asmjs/libdl.a
/opt/cheerp/lib/asmjs/libpthread.a
/opt/cheerp/lib/asmjs/libresolv.a
/opt/cheerp/lib/asmjs/librt.a
/opt/cheerp/lib/asmjs/libutil.a
/opt/cheerp/lib/asmjs/libxnet.a

%changelog
* Tue Dec 10 2019 Yuri Iozzelli <yuri@leaningtech.com>
- First RPM version
