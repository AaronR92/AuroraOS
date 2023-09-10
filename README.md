# AuroraOS🌌
Operating System written in C++ and ASM just for fun

## Build⚒️
To build `.iso` file:   

1. Make sure to create docker container via
```
docker build .\buildenv\ -t auroraos-buildenv
```
2. Run created container
```
docker run --rm -it -v cd:/root/env auroraos-buildenv
```
4. In container, for building our `.iso` file, run the `make` command
```
make build-x86_64
```
6. Created `.iso` file will be located inside `/dist/x86_64` folder
7. Enjoy 🎆

❗Note that `auroraos-buildenv` is the name of this project, you can use any name in container build

## Run▶️
To run the OS you can use anything you want, but **the simplest way** is to download ***[qemu](https://www.qemu.org)***   
and execute the command   
```
qemu-system-x86_64 -cdrom .\dist\x86_64\kernel.iso
```

## Thanks🫂
Huge thanks to [NotUnknownDude](https://github.com/NotUnknownDude) for helping with project development 🦦
