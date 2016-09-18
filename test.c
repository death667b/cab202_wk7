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
	arg0 = ~(~1<<arg0);

    return arg0;
}

unsigned char answer_2(unsigned char arg0, int arg1, int arg2) {
	arg0 = arg0 | (1<<arg1);
	arg0 = ~arg0;
	arg0 = (arg0>>arg2) &1;

    return arg0;
}

unsigned char answer_3(unsigned char *arg0) {
	unsigned char arg1 = (*arg0 & 0x0C) >> 2;

    return arg1;
}


int n, m;
unsigned char b, *b_p, ex_uc, ac_uc;
bool failed[NUM_PROBS];
int main() {

	time_t t;
	srand((unsigned) time(&t));

	for (int ii = 0; ii < NUM_TESTS; ii++) {
	    n = rand() % 8;
	    m = rand() % 8;
	    b = rand() % 256;
	    b_p = &b;
	    ex_uc = (*b_p & 0xC0) >> 6;
	    //ac_uc = answer_2(b, n, m);
	    ac_uc = answer_3(b_p);

	    printf("Arg0: %u ", *b_p);
	    printf("in binary:             ");
	    displayAsBinary(b);
	    //printf("\nArg0: %d as binary                ", n);
	    //displayAsBinary((1<<n));
	    //printf("\n");
	    //printf("Arg2: %d as binary                ", m);
	    //displayAsBinary((1<<m));
	    printf("\n");
        printf("Expected return: 0x%02X ", ex_uc);
        printf("in binary: ");
        displayAsBinary(ex_uc);
        printf("\nActual return: 0x%02X   ", ac_uc);
        printf("in binary: ");
        displayAsBinary(ac_uc);
        printf("\n\n");
	}

	

	return 0;

}