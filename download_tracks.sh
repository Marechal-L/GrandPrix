#!/bin/bash

if [ ! -d tracks ]; then
    git clone https://github.com/kidanger/GP_tracks.git tracks
else
    cd tracks
    git pull
    cd ..
fi

make -C tracks

