#!/usr/bin/env sh

./build.sh "$@"
if [ $? -ne 0 ]; then
    exit 1
fi

cd build
cmake --install .
if [ $? -ne 0 ]; then
    cd ..
    exit 1
fi

cd ..
