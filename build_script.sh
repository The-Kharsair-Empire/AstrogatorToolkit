#!/bin/bash/
toolkits=("TrackingStationToolkit")  # add project name in this list

for toolkit in "${toolkits[@]}"; do
  [ -d "$(pwd)/build/$toolkit" ] || mkdir -p "$(pwd)/build/$toolkit"
  cmake -S "$(pwd)/$toolkit" -B "$(pwd)/build/$toolkit"
  (cd "$(pwd)/build/$toolkit" && make)
done
