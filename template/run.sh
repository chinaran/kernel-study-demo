#!/bin/sh

make clean
make
insmod test.ko
rmmod test
dmesg -c
