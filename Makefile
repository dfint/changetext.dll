.PHONY: build build_linux

# CC=x86_64-w64-mingw32-gcc
CC=gcc
IDIR=blob/Python34/include
LIBDIR=blob/Python34/libs
NAME=changetext

$(NAME).dll: $(NAME).c
	$(CC) -c -DBUILD_DLL -O2 $(NAME).c -I$(IDIR)
	$(CC) -shared -o $(NAME).dll -Wl,--out-implib,lib$(NAME).a $(NAME).o -L$(LIBDIR) -lpython34

build: $(NAME).dll

test.exe: $(NAME).dll test.c
	$(CC) -O2 -std=c99 test.c lib$(NAME).a -o test.exe

$(NAME).so: $(NAME).c
	$(CC) -c -O2 $(NAME).c -shared -fPIC -lm -lpython3.8 -o lib$(NAME).so -I/usr/include/python3.8

build_linux: $(NAME).so

test: $(NAME).so test.c
	gcc -c test.c --std=c99
	gcc test.o -L. -l$(NAME) -lpython3.8 -o test
