#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// TAKE CARE OF THIS:
// As a final remark observe that standard programs would equally accept “-a2” and “-a 2”. When using standard solutions like POSIX getopt, this is automatically taken care of.
void
main(int argc, char *argv[]){

	char a_char, b_char;
	int a_int, b_int;

	for (size_t i=1; i<3; ++i){
		bool found_a = strchr(argv[i], 'a') != NULL;
		bool found_b = strchr(argv[i], 'b') != NULL;
		if ( found_a ){
			a_char = argv[i][strlen(argv[i])-1];
			a_int = a_char - '0';
		}; 
		if ( found_b ){
			b_char = argv[i][strlen(argv[i])-1];
			b_int = b_char - '0';
		};
	// the {... - '0'} works because the integer value for '0' is 48 
	};
	
	printf("A is %i and B is %i\n", a_int, b_int);
}
