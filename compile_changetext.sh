#!/bin/bash
gcc -c -O2 changetext.c -shared -fPIC -lm -lpython3.4 -o libchangetext.so -I/usr/include/python3.4

gcc -c test.c --std=c99
gcc test.o -L. -lchangetext -lpython3.4m -o test
