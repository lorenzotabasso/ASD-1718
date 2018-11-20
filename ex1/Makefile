
# lista dei target da eseguire sempre
all: tests exec

# compila (grazie alla dipendenza) e esegue i test
tests: sorts_test
	sorts_test

#  compila (grazie alla dipendenza) e esegue ordered_array
exec: sorts
	sorts ../Dataset/ex1/integers.csv ../Dataset/ex1/sums.txt

# Flags per il compilatore -- su gcc -Weverything non esiste
#    sostituire con -Wall -Wpedantic
CFLAGS = -g -Wall -Wpedantic -Wno-padded -Werror

# Lista degli header files
INCLUDES = *.h ../Resources/Unity/*.h

# tutti i target vanno ricompilati se cambiano gli header o
# questo Makefile
COMMON_DEPS = $(INCLUDES) Makefile

# regola per compilare un .c in un .o
# viene applicata ogni volta che una dipendenza richiede di compilare un file in
#    `build` e con suffisso .o. Il simbolo % effettua pattern matching con quanto
#    compreso tra 'build/' e '.o', la stringa in questione viene quindi usata sul lato
#    destro della regola per indicare il file da compilare.
# Le variabili $< e $@ sono gestite automaticamente da `make` esse corrispondono:
#   $@ : l'intero target della regola (in questo caso: build/<nomefile>.o)
#   $< : la prima dipendenza della regola (in questo caso: src/<nomefile>.c)
build/%.o: %.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

src/sorts: sorts.o $(COMMON_DEPS)
	$(CC) -o sorts sorts.o

src/sorts_test: sorts_test.o sorts.o ../Resources/Unity/unity.o $(COMMON_DEPS)
	$(CC) -o sorts_test sorts_test.o sorts.o ../Resources/Unity/unity.o

clean:
	rm -f *
