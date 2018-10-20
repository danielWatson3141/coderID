#pragma comment(linker, "/STACK:1677721600")
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <iostream>
#include <iterator>
#include <bitset>
using namespace std;
FILE *in;
FILE *out;

int N;
int L;
int minAns;

bool devices[150][40];
bool outlets[150][40];

bool equals() {
	bool returnval = true;
	bool used[150];
	for ( int i = 0; i < N; i++ ) {
		used[i] = false;
	}
	
	for ( int i = 0; i < N; i++ ) {
		bool exist_val = false;
		for ( int i2 = 0; i2 < N; i2++ ) {
			if ( used[i2] ) {
				continue;
			}

			bool goodv = true;
			for ( int j = 0; j < L; j++ ) {
				if ( devices[i][j] != outlets[i2][j] ) {
					goodv = false;
					break;
				}
			}
			if ( goodv ) {
				used[i2] = true;
				exist_val = true;
			}
		}

		if ( exist_val == false ) {
			returnval = false;
			break;
		}
	}

	return returnval;
}

void calculate( int num_to_change, bool changed[40] ) {
	// si es igual a devices, entonces termina
	if ( equals() ) {
		int numreturn = 0;
		for ( int i = 0; i < 40; i++ ) {
			if ( changed[i] ) {
				numreturn++;
			}
		}
		minAns = min<int>(minAns, numreturn);
		return;
	}

	// cambio los outlets
	if ( num_to_change != -1 ) {
		changed[num_to_change] = true;
		for ( int i = 0; i < N; i++ ) {
			outlets[i][num_to_change] = !outlets[i][num_to_change];
		}
	}
	int next_num = -1;
	for ( int i = 0; i < L; i++ ) {
		if ( changed[i] == true ) {
			continue;
		}
		else {
			calculate( i, changed );
		}
	}
	
	if ( num_to_change != -1 ) {
		changed[num_to_change] = false;
		for ( int i = 0; i < N; i++ ) {
			outlets[i][num_to_change] = !outlets[i][num_to_change];
		}
	}

}

int main() {
	int totalCases;
	in = fopen("A-small-attempt0.in", "r");
	out = fopen("A-small-attempt0.out", "w+");
	fscanf(in, "%d\n", &totalCases);

	for ( int caseNum = 0; caseNum < totalCases; caseNum++ ) {
		// data read
		fscanf(in, "%d %d\n", &N, &L);
		minAns = 2000000000;

		char temp;
		// outlets
		for ( int i = 0; i < N; i++ ) {
			for ( int j = 0; j < L; j++ ) {
				fscanf(in, "%c", &temp);
				outlets[i][j] = ((temp=='0')?0:1);
			}
			if ( i != N-1 ) {
				fscanf(in, "%c", &temp);
			}
		}
		fscanf(in, "\n");

		// devices
		for ( int i = 0; i < N; i++ ) {
			for ( int j = 0; j < L; j++ ) {
				fscanf(in, "%c", &temp);
				devices[i][j] = ((temp=='0')?0:1);
			}
			if ( i != N-1 ) {
				fscanf(in, "%c", &temp);
			}
		}
		fscanf(in, "\n");

		bool changed[40];
		for ( int i = 0; i < 40; i++ ) {
			changed[i] = false;
		}
		
		calculate(-1, changed);


		// results print
		if ( minAns != 2000000000 ) {
			fprintf(out, "Case #%d: %d\n", caseNum+1, minAns);
		}
		else {
			fprintf(out, "Case #%d: NOT POSSIBLE\n", caseNum+1);
		}
		/*
		fprintf(out, "Case NL: %d %d\n", N, L);
		for ( int i = 0; i < N; i++ ) {
			for ( int j = 0; j < L; j++ ) {
				fprintf(out, "%c", (outlets[i][j]?'1':'0') );
				//fprintf(out, "a" );
			}
			fprintf(out, " ");
		}
		fprintf(out, "\n");
		
		for ( int i = 0; i < N; i++ ) {
			for ( int j = 0; j < L; j++ ) {
				fprintf(out, "%c", (devices[i][j]?'1':'0') );
			}
			fprintf(out, " ");
		}
		fprintf(out, "\n");
		*/
	}

	fclose(in);
	fclose(out);
	return 0;
}

