@echo off
g++ -c -DBUILD_DLL -O2 changetext.c -IC:/Python34/include
g++ -shared -o changetext.dll -Wl,--out-implib,libchangetext.a changetext.o -LC:/Python34/libs -lpython34
