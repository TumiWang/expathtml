#!/bin/bash
set -xe

if [ -d "./out" ]; then
    rm -rf out
fi
mkdir out

cmake -DCMAKE_BUILD_TYPE=Debug -S ./ -B out -G Ninja
ninja -C out
