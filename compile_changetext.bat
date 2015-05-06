@echo off
gcc -c -DBUILD_DLL -O2 changetext.c -IC:/Python34/include
gcc -shared -o changetext.dll -Wl,--out-implib,libchangetext.a changetext.o -LC:/Python34/libs -lpython34
gcc -O2 -std=c99 test.c libchangetext.a -o test.exe