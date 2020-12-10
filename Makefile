.PHONY: build

# CC=x86_64-w64-mingw32-gcc
CC=gcc
IDIR=C:/Python34/include
LIBDIR=C:/Python34/libs
NAME=changetext

$(NAME).dll: $(NAME).c
	$(CC) -c -DBUILD_DLL -O2 $(NAME).c -I$(IDIR)
	$(CC) -shared -o $(NAME).dll -Wl,--out-implib,lib$(NAME).a $(NAME).o -L$(LIBDIR) -lpython34

build: $(NAME).dll

test.exe: $(NAME).dll
	$(CC) -O2 -std=c99 test.c lib$(NAME).a -o test.exe
