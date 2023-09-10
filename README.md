# Aurora OS 🌌
Operating System written in C++ and ASM just for fun

## Build
To build `.iso` file:   

1. Make sure to create docker container via `docker build .\buildenv\ -t auroraos-buildenv`   
2. Run created container `docker run --rm -it -v cd:/root/env auroraos-buildenv`
3. In container run the command `make build-x86_64` to build our `.iso` file
4. Created `.iso` file will be located inside `/dist/x86_64` folder
5. Enjoy 🎆

Note that `auroraos-buildenv` is the name of this project, you can use any name in container build

## Run
To run the OS you can use anything you want, but the simplest way is to download ***qemu*** and execute command `qemu-system-x86-64 -cdrom .\dist\x86_64\kernel.iso`
