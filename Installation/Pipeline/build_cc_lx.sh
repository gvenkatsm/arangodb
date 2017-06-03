#!/bin/bash

concurrency=$1

mkdir -p build-jenkins
mkdir -p build/bin
mkdir -p build/etc
mkdir -p build/tests

cd build-jenkins
CXXFLAGS=-fno-omit-frame-pointer cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DUSE_MAINTAINER_MODE=On -DCATCH_TESTS=On -DUSE_FAILURE_TESTS=On -DDEBUG_SYNC_REPLICATION=On ..
make -j$concurrency

# copy binaries to preserve them
cd ..
cp -a build-jenkins/bin/* build/bin
cp -a build-jenkins/etc/* build/etc
cp -a build-jenkins/tests/* build/tests
