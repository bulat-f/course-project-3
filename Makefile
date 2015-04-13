cc = g++
cflags = -c -Wall
obj = src/main.o

all: src

src: $(obj)
	$(cc) $(obj) -o src/main

main.o: src/main.cpp
	$(cc) $(cflags) main.cpp

clean:
	rm -rf src/*.o src/main
