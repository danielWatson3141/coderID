// R1A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int count_bits(int bits){
    int num  = 0;

    for ( ; bits != 0; bits &= bits - 1 ) {
        ++num;
    }

    return num;
}


int main(void) {

	FILE *fp = fopen("test.txt", "rt");
	if (fp == NULL) {
		printf("failed to open file\n");
		return -1;
	}

	#define LINE_MAX (1000)
	char line[LINE_MAX];

	int case_num;
	fgets(line, LINE_MAX, fp);
	case_num = strtol(line, NULL, 10);
	//printf("case_num = %d\n", case_num);
	
	for (int i = 1; i <= case_num; ++i) {

		
		fgets(line, LINE_MAX, fp);
		int n, l;
		char *p;
		n = strtol(line, &p, 10);
		l = strtol(p, NULL, 10);
		//printf("n = %d, l = %d\n", n, l);
	
		// l < 10, n < 10
		fgets(line, LINE_MAX, fp);
		p = line;
		int o[10];
		for (int j = 0; j < n; ++j) {
			o[j] = strtol(p, &p, 2);
			//printf("p[%d]=%d\n", j, o[j]);
		}

		fgets(line, LINE_MAX, fp);
		p = line;
		int d[10];
		for (int j = 0; j < n; ++j) {
			d[j] = strtol(p, &p, 2);
			//printf("d[%d]=%d\n", j, d[j]);
		}

		std::sort(d, d + n);

		int jj = pow((double)2, l);
		int min = jj;
		for (int j = 0; j < jj; ++j) {
			//printf("j = %d\n", j);

			int oo[10];
			for (int k = 0; k < n; ++k) {
				oo[k] = o[k] ^ j;
			}
			std::sort(oo, oo + n);
			int k;
			for (k = 0; k < n; ++k) {
				if (oo[k] != d[k]) {
					break;
				}
			}
			if (k == n) {
				int bits = count_bits(j);
				if (min > bits) {
					min = bits;
				}
			}

		}

		if (min != jj) {
			printf("Case #%d: %d\n", i, min);
		}
		else {
			printf("Case #%d: NOT POSSIBLE\n", i);
		}
	}

	fclose(fp);
}

