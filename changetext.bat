@echo off
gcc -c -DBUILD_DLL changetext.c
gcc -shared -o changetext.dll -Wl,--out-implib,libchangetext.a changetext.o c:\Python33\libs\libpython33.a
