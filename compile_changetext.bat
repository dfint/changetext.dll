@echo off
gcc -c -DBUILD_DLL changetext.c -IC:/Python33/include
gcc -shared -o changetext.dll -Wl,--out-implib,libchangetext.a changetext.o -LC:/Python33/libs -lpython33
