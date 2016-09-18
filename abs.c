#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LINE_LENGTH 79

#define NUM_PROBS 10
#define NUM_TESTS 1

#define STR_PASS "PASSED!"
#define STR_FAIL "FAILED!"

/*
* Function declarations (all of these are already implemented)
*/
void print_heading(char bkgChar, char* heading, int offset);

void displayAsBinary(int n) {
	int k, c;

	for (c = 31; c >= 0; c--)
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
unsigned int b, *b_p, ex_uc, ac_uc, mask, maskloop;
bool failed[NUM_PROBS];
int main() {
	for (int ii = 0; ii < NUM_TESTS; ii++) {
	    //n = rand() % 19;
	    //ex_uc = (1 << n);
	    //ac_uc = answer_1(n);
		n = -28800;

	    printf("Start Value value: %d \n0x%X\n", n, n);
	    printf("in binary: ");
	    displayAsBinary(n);
	    printf("\n\n");

	    maskloop = n;
	    for(int shift = 0; shift < sizeof(int); shift++) {
		    maskloop = maskloop>>1;
	        printf("Mask Value: 0x%X ", maskloop);
	        printf("in binary: ");
	        displayAsBinary(maskloop);
	        printf("\n\n");
    	}

        maskloop = maskloop ^ n; 
        printf("XOR Mask: 0x%X ", maskloop);
        printf("in binary: ");
        displayAsBinary(maskloop);
        printf("\n\n");

        mask = (maskloop^n) - maskloop;
	}


	printf("Final: %d ", mask);

	return 0;

}