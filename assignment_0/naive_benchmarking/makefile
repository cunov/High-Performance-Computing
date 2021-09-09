BINS = O0 O1 O2 O3 Os Og
.PHONY : all
all : $(BINS)
.PHONY : clean
clean : 
	rm -f $(BINS)

O0 : bench.c
	gcc -o $@ $< -O0 -march=native
O1 : bench.c
	gcc -o $@ $< -O1 -march=native
O2 : bench.c
	gcc -o $@ $< -O2 -march=native
O3 : bench.c
	gcc -o $@ $< -O3 -march=native
Os : bench.c
	gcc -o $@ $< -Os -march=native
Og : bench.c
	gcc -o $@ $< -Og -march=native
