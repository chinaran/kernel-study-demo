#!/bin/sh

make clean
color_compile make
insmod test.ko
rmmod test
dmesg -c
