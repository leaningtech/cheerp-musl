# Cheerp build instructions

```
CHEERP_PREFIX=/opt/cheerp

mkdir -p build_genericjs
cd build_genericjs
RANLIB="${CHEERP_PREFIX}/bin/llvm-ar s" \
AR="${CHEERP_PREFIX}/bin/llvm-ar" \
CC="${CHEERP_PREFIX}/bin/clang -target cheerp" \
LD="${CHEERP_PREFIX}/bin/llvm-link" \
CFLAGS="-Wno-int-conversion" \
../configure --target=cheerp --disable-shared --prefix=${CHEERP_PREFIX} --with-malloc=dlmalloc
make
make install-cheerp
cd ..

mkdir -p build_asmjs
cd build_asmjs
RANLIB="${CHEERP_PREFIX}/bin/llvm-ar s" \
AR="${CHEERP_PREFIX}/bin/llvm-ar" \
CC="${CHEERP_PREFIX}/bin/clang -target cheerp-wasm" \
LD="${CHEERP_PREFIX}/bin/llvm-link" \
CFLAGS="-Wno-int-conversion" \
../configure --target=cheerp-wasm --disable-shared --prefix=${CHEERP_PREFIX} --with-malloc=dlmalloc
make
make install-bc
cd ..
```
