#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint16_t Test(uint64_t N, uint64_t L, uint16_t outlets[150][40], uint16_t devices[150][40]) {
	uint16_t sol=1;
	for(uint16_t i=0; i<N; i++) {
		uint16_t found=0;
		for(uint16_t j=0; j<N; j++) {
			uint16_t equal=1;
			for(uint16_t k=0; k<L; k++) {
				if(outlets[i][k]!=devices[j][k]) equal=0;
			}
			if(equal==1) found=1;
		}
		if(found==0) sol=0;
	}
	return sol;
}

uint64_t findSol(uint64_t N, uint64_t L, uint16_t outlets[150][40], uint16_t devices[150][40], uint16_t Stack[40], uint16_t Stackpointer, uint16_t min) {
	uint64_t Min1, Min2;
	uint16_t outlets2[150][40];
	if(Test(N, L, outlets, devices)==1) return min;
	if(Stackpointer==0) return L+1;
	if(min>L) return L+1;
	Stackpointer--;
	Min1 = findSol(N, L, outlets, devices, Stack, Stackpointer, min);
	
	for(uint16_t i=0; i<N; i++) {
		for(uint16_t j=0; j<L; j++) {
			outlets2[i][j] = outlets[i][j];
		}
	}
	for(uint16_t i=0; i<N; i++) {
		outlets2[i][Stack[Stackpointer]] = 1 - outlets2[i][Stack[Stackpointer]];
	}
	Min2 = findSol(N, L, outlets2, devices, Stack, Stackpointer, min++);

	
	if(Min1>Min2) return Min2;
	return Min1;
}

/* Reads a number until a ' ' or a '\n' appears */
uint64_t getNumber(FILE *input) {
	uint64_t num=0;
	char c;
	c=getc(input);
	while(c!=10 && c!=32) {num = 10*num+c-48; c=getc(input);}
	return num;
}

int main() {
	FILE *input, *output;
	uint16_t cases;
	char c;
	input = fopen ("input.in", "r");
	output = fopen ("output.out", "w");
	cases = getNumber(input);
	printf("%d\n",cases);
	for(uint16_t count=1; count<=cases; count++) {
		uint64_t N,L;
		uint16_t outlets[150][40], devices[150][40];
		uint16_t min;
		uint16_t Stack[40], Stackpointer = 0;
		N = getNumber(input);
		L = getNumber(input);
		min = 0;
		for(uint16_t i=0; i<N; i++) {
			for(uint16_t j=0; j<L; j++) {
				c=getc(input);
				if(c=='0') outlets[i][j]=0;
				if(c=='1') outlets[i][j]=1;
			}
			c=getc(input);
		}
		for(uint16_t i=0; i<N; i++) {
			for(uint16_t j=0; j<L; j++) {
				c=getc(input);
				if(c=='0') devices[i][j]=0;
				if(c=='1') devices[i][j]=1;
			}
			c=getc(input);
		}
		for(uint16_t j=0; j<L; j++) {
			uint16_t countO = 0, countD = 0;
			for(uint16_t i=0; i<N; i++) {
				countO = countO + outlets[i][j];
				countD = countD + devices[i][j];
			}
			if(countO==countD) {
				if(N==countD+countO) {
					Stack[Stackpointer]=j;
					Stackpointer++;
				}
			} else {
				if(N==countD+countO) {
					min++;
					for(uint16_t i=0; i<N; i++) {
						outlets[i][j] = 1 - outlets[i][j];
					}
				} else {
					min = L+1;
				}
			}
		}
		if(min<=L) {
			min = findSol(N, L, outlets, devices, Stack, Stackpointer, min);
		}
		
		
		
		
		
		
		
		
		fprintf (output, "Case #%d: ", count);
		if(min>L) {
			fprintf (output, "NOT POSSIBLE\n");
		} else {
			fprintf (output, "%d\n", min);
		}
		
	}
	return 0;
}
