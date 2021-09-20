BINS = O0 O2 O2_native
.PHONY : all
all : $(BINS)
.PHONY : clean
clean :
	rm -f $(BINS)

O0 : locality.c
	gcc -o $@ $< -O0
O2 : locality.c
	gcc -o $@ $< -O2
O2_native: locality.c
	gcc -o $@ $< -O2 -march=native
