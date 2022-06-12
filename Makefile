.PHONY: build_dll_32  build_dll_64 build_so test pytest clean

CC=gcc

CC_MINGW32=i686-w64-mingw32-gcc
CC_MINGW64=x86_64-w64-mingw32-gcc

IDIR32=python/Python37-32/include
LIBDIR32=python/Python37-32/libs

IDIR64=python/Python37/include
LIBDIR64=python/Python37/libs

IDIR_LINUX=/usr/include/python3.8

NAME=changetext

$(NAME)32.dll: $(NAME).c
	$(CC_MINGW32) -c -DBUILD_DLL -O2 $(NAME).c -I$(IDIR32)
	$(CC_MINGW32) -shared -o $(NAME)32.dll -Wl,--out-implib,lib$(NAME).a $(NAME).o -L$(LIBDIR32) -lpython37

build_dll_32: $(NAME)32.dll

$(NAME)64.dll: $(NAME).c
	$(CC_MINGW64) -c -DBUILD_DLL -O2 $(NAME).c -I$(IDIR64)
	$(CC_MINGW64) -shared -o $(NAME)64.dll -Wl,--out-implib,lib$(NAME).a $(NAME).o -L$(LIBDIR64) -lpython37

build_dll_64: $(NAME)64.dll

test.exe: $(NAME)64.dll test.cpp
	$(CC) -O2 test.cpp lib$(NAME).a -o test.exe --std=c++11

$(NAME).so: $(NAME).c
	$(CC) -O2 $(NAME).c -shared -fPIC -lpython3.8 -o lib$(NAME).so -I$(IDIR_LINUX)

build_so: $(NAME).so

test: $(NAME).so test.cpp
	$(CC) -O2 -c test.cpp --std=c++11
	$(CC) test.o -L. -l$(NAME) -lpython3.8 -o test

pytest: build_so
	pytest test_so.py

clean:
	rm test *.o *.a *.so *.exe *.dll | true
