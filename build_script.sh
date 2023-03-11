#!/bin/bash/
subdircount=`find -L $(pwd)/external/ -mindepth 1 -maxdepth 1 -type d | wc -l`
[ $subdircount -gt 0 ] || (echo "external dependency not cloned properly, cloning submodules" && git submodule update --recursive --init)

echo "installing dependencies"
package=( "libx11-dev" "libgl-dev" "libpng-dev" "gnuplot" "cmake" "g++")

for p in "${package[@]}"; do
    if [ $(dpkg-query -W -f='${Status}' $p 2>/dev/null | grep -c "ok installed") -eq 0 ];
    then
        echo "package $p not found, installing"
        apt install $p;
    else
        echo "package $p found, skipping install"
    fi
done


[ -d "$(pwd)/build" ] || mkdir -p $(pwd)/build
(cd "$(pwd)/build" && cmake .. && make)
