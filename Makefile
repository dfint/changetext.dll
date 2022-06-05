.PHONY: build build_so pytest clean

# CC=x86_64-w64-mingw32-gcc
CC=gcc
IDIR=blob/Python34/include
LIBDIR=blob/Python34/libs
NAME=changetext

$(NAME).dll: $(NAME).c
	$(CC) -c -DBUILD_DLL -O2 $(NAME).c -I$(IDIR)
	$(CC) -shared -o $(NAME).dll -Wl,--out-implib,lib$(NAME).a $(NAME).o -L$(LIBDIR) -lpython34

build: $(NAME).dll

test.exe: $(NAME).dll test.cpp
	$(CC) -O2 test.cpp lib$(NAME).a -o test.exe --std=c++11

$(NAME).so: $(NAME).c
	$(CC) -O2 $(NAME).c -shared -fPIC -lpython3.8 -o lib$(NAME).so -I/usr/include/python3.8

build_so: $(NAME).so

test: $(NAME).so test.cpp
	$(CC)  -O2 -c test.cpp --std=c++11
	$(CC)  test.o -L. -l$(NAME) -lpython3.8 -o test

pytest: build_so
	pytest test_so.py

clean:
	rm test *.o *.so *.exe *.dll | true
