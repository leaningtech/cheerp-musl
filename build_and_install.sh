#!/bin/bash

set -x

GENERICJS_DIR=build_genericjs
ASMJS_DIR=build_asmjs
CHEERP_DEST=~/opt/cheerp

export RANLIB="$CHEERP_DEST/bin/llvm-ar s"
export AR="$CHEERP_DEST/bin/llvm-ar"
export CC_COMMAND="$CHEERP_DEST/bin/clang -I $CHEERP_DEST/lib/clang/15.0.0/include"
export GENERICJS_CC="$CC_COMMAND -target cheerp"
export ASMJS_CC="$CC_COMMAND -target cheerp-wasm"
export LD="$CHEERP_DEST/bin/llvm-link"
export CFLAGS="-Wno-int-conversion -DUSE_DL_PREFIX"
#export CFLAGS="-Wno-int-conversion"

rm -rf "$GENERICJS_DIR" "$ASMJS_DIR"
mkdir -p "$GENERICJS_DIR" "$ASMJS_DIR"

(cd "$GENERICJS_DIR" && CC="$GENERICJS_CC" ../configure --target=cheerp --disable-shared --prefix="$CHEERP_DEST" --with-malloc=dlmalloc)

(cd "$ASMJS_DIR" && CC="$ASMJS_CC" ../configure --target=cheerp-wasm --disable-shared --prefix=$CHEERP_DEST --with-malloc=dlmalloc)

make -C "$GENERICJS_DIR" -j
make -C "$GENERICJS_DIR" install

make -C "$ASMJS_DIR" -j
make -C "$ASMJS_DIR" install
