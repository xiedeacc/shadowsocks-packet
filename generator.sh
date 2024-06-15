#!/bin/bash

if [ $# != 1 ] ; then
    echo "must specify project name"
    exit -1
fi
echo "now clear $(pwd)/../$1"
rm -rf "$(pwd)/../$1"

echo "now copy shadowsocks-packet to $1"
cp -ra "$(pwd)" "$(pwd)/../$1"

cd "$(pwd)/../$1"
rm bazel-* -rf
mv "src/swig/java/shadowsocks-packet" "src/swig/java/$1"
sed -i "s/shadowsocks-packet/$1/g" `grep "shadowsocks-packet" -rl .`

