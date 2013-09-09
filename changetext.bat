@echo off
gcc -c -DBUILD_DLL changetext.c -I/Python33/include
gcc -shared -o changetext.dll -Wl,--out-implib,libchangetext.a changetext.o -L/Python33/libs -lpython33
