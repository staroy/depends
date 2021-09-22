CURRENT_DIR=$PWD
PARENT_DIR="$(dirname "$PWD")"
TMP_DIR=$PARENT_DIR/tmp
BUILD_DIR=$TMP_DIR/depends-release
SOURCE_DIR=$PWD
OUT_DIR=$PARENT_DIR/out-release

mkdir -p $TMP_DIR && mkdir -p $BUILD_DIR \
 && cd $BUILD_DIR \
 && cmake $SOURCE_DIR \
 -DCMAKE_BUILD_TYPE=Release \
 -DCMAKE_INSTALL_PREFIX=$OUT_DIR \
 -DCMAKE_N_BUILDPROC=-j1 \
 && make -j1 && make install
