#!/bin/sh

# Generate sourcelist
cd scripts && ./generate-lib-sourcelist.sh && cd ..

# remove cache for next cmake run
mkdir -p build
rm -f build/CMakeCache.txt

# configure the build
cmake -S . -B build

