cc = g++
cflags = -c -Wall
std11 = -std=c++11
obj = main.o

all: src

src: $(obj)
	$(cc) $(obj) $(std11) -o main

main.o: main.cpp vector.h matrix.h
	$(cc) $(cflags) $(std11) main.cpp

clean:
	rm -rf *.o main
