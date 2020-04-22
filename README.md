# nv (eNVy)

Limited text viewer.

## Build and Install

    mkdir build
    cd build
    cmake ..
    make
    cpack
    sudo apt install ./nv_0.1.0.deb

## Generate source archive

    mkdir build
    cd build
    cmake ..
    make
    cpack --config CPackSourceConfig.cmake
