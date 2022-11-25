Name: cheerp-musl
Version: 2.5
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
CHEERP_PREFIX=/opt/cheerp RANLIB="${CHEERP_PREFIX}/bin/llvm-ar s" AR="${CHEERP_PREFIX}/bin/llvm-ar" CC="${CHEERP_PREFIX}/bin/clang -target cheerp" LD="${CHEERP_PREFIX}/bin/llvm-link" CPPFLAGS="-isystem ${CHEERP_PREFIX}/lib/clang/15.0.0/include" ../configure --target=cheerp --disable-shared --prefix=${CHEERP_PREFIX} --with-malloc=mallocng
cd ..

mkdir -p build_wasm
cd build_wasm
CHEERP_PREFIX=/opt/cheerp RANLIB="${CHEERP_PREFIX}/bin/llvm-ar s" AR="${CHEERP_PREFIX}/bin/llvm-ar" CC="${CHEERP_PREFIX}/bin/clang -target cheerp-wasm" LD="${CHEERP_PREFIX}/bin/llvm-link" CPPFLAGS="-isystem ${CHEERP_PREFIX}/lib/clang/15.0.0/include" ../configure --target=cheerp-wasm --disable-shared --prefix=${CHEERP_PREFIX} --with-malloc=mallocng


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
/opt/cheerp/lib/genericjs/crt1.bc
/opt/cheerp/include/
/opt/cheerp/lib/asmjs/crt1.bc
/opt/cheerp/lib/asmjs/libc.bc

%changelog
* Tue Dec 10 2019 Yuri Iozzelli <yuri@leaningtech.com>
- First RPM version
