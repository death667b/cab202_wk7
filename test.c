#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LINE_LENGTH 79

#define NUM_PROBS 10
#define NUM_TESTS 5

#define STR_PASS "PASSED!"
#define STR_FAIL "FAILED!"

/*
* Function declarations (all of these are already implemented)
*/
void print_heading(char bkgChar, char* heading, int offset);

void displayAsBinary(int n) {
	int k, c;

	for (c = 7; c >= 0; c--)
	  {
	    k = n >> c;
	 
	    if (k & 1)
	      printf("1");
	    else
	      printf("0");
	  }
}


unsigned char answer_1(int arg0) {
    return (1<<arg0);
}


int n, m;
unsigned char b, *b_p, ex_uc, ac_uc;
bool failed[NUM_PROBS];
int main() {
	for (int ii = 0; ii < NUM_TESTS; ii++) {
	    n = rand() % 8;
	    ex_uc = (1 << n);
	    ac_uc = answer_1(n);
	    failed[0] = !(ex_uc == ac_uc);
	    if (failed[0]) {
	        break;
	    }

	    printf("Givern value: 0x%02X ", n);
	    printf("in binary: ");
	    displayAsBinary(n);
	    printf("\n");
        printf("Expected return: 0x%02X ", ex_uc);
        printf("in binary: ");
        displayAsBinary(ex_uc);
        printf("\nActual return: 0x%02X ", ac_uc);
        printf("in binary: ");
        displayAsBinary(ac_uc);
        printf("\n\n");
	}

	

	return 0;

}