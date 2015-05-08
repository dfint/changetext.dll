#!/bin/bash
gcc -c -O2 changetext.c -fPIC -I/usr/include/python3.4
ld -shared changetext.o libfake_ttf.o -lm -lpython3.4m -lSDL_ttf -o libfake_ttf.so

gcc -c test.c -O2 --std=c99
gcc test.o -L. -lfake_ttf -lpython3.4m -o test
