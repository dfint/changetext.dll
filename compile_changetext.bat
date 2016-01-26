@echo off
gcc -c -DBUILD_DLL -O2 changetext.c -IC:/Python35/include
gcc -shared -o changetext.dll -Wl,--out-implib,libchangetext.a changetext.o -LC:/Python35/libs -lpython35
gcc -O2 -std=c99 test.c libchangetext.a -o test.exe