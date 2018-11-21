# Compiler's Flags
CFLAGS = -g -Wall -Wpedantic -Wno-padded -Werror

build/sorts.o: src/sorts.c src/sorts.h Makefile
	$(CC) $(CFLAGS) -c src/sorts.c -o build/sorts.o

build/unity.o: ../Resources/C/Unity/unity.c ../Resources/C/Unity/unity.h Makefile
	$(CC) $(CFLAGS) -c ../Resources/C/Unity/unity.c -o build/unity.o

build/sorts_test.o: src/sorts_test.c src/sorts_test.h ../Resources/C/Unity/unity.c ../Resources/C/Unity/unity.h Makefile
	$(CC) $(CFLAGS) -c src/sorts_test.c -o build/sorts_test.o

bin/sorts_test: build/sorts.o build/unity.o build/sorts_test.o Makefile
	$(CC) -o bin/sorts_test build/sorts_test.o build/sorts.o build/unity.o

all: build/sorts.o build/unity.o build/sorts_test.o bin/sorts_test

clean:
	rm -f build/* bin/*