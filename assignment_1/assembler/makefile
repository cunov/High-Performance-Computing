BINS = O0 O1 O2 O3 Os Og
.PHONY : all
all : $(BINS)
.PHONY : clean
clean : 
	rm -f $(BINS)

O0 : bench.c
	gcc -o $@ $< -O0 -S -fverbose-asm
O1 : bench.c
	gcc -o $@ $< -O1 -S -fverbose-asm
O2 : bench.c
	gcc -o $@ $< -O2 -S -fverbose-asm
O3 : bench.c
	gcc -o $@ $< -O3 -S -fverbose-asm
Os : bench.c
	gcc -o $@ $< -Os -S -fverbose-asm
Og : bench.c
	gcc -o $@ $< -Og -S -fverbose-asm
