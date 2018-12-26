# Compiler's Flags
CFLAGS = -g -Wall -Wpedantic -Wno-padded -Werror

build/sorts.o: src/sorts.c src/sorts.h Makefile
	$(CC) $(CFLAGS) -c src/sorts.c -o build/sorts.o

build/sums.o: src/sums.c src/sums.h Makefile
	$(CC) $(CFLAGS) -c src/sums.c -o build/sums.o

build/unity.o: ../Resources/C/Unity/unity.c ../Resources/C/Unity/unity.h Makefile
	$(CC) $(CFLAGS) -c ../Resources/C/Unity/unity.c -o build/unity.o

build/tests.o: src/tests.c src/tests.h ../Resources/C/Unity/unity.c ../Resources/C/Unity/unity.h Makefile
	$(CC) $(CFLAGS) -c src/tests.c -o build/tests.o

bin/tests: build/sorts.o build/unity.o build/tests.o Makefile
	$(CC) -o bin/tests build/tests.o build/sorts.o build/sums.o build/unity.o

all: build/sorts.o build/sums.o build/unity.o build/tests.o bin/tests

clean:
	rm -f build/* bin/*