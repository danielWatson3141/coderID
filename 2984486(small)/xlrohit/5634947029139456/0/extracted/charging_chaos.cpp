#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define pb push_back
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 10000
using namespace std;

char buff[MAXN], *cp;
int T, N, L;

int btod(int s, int e) {
	int d = 1, sum = 0;
	for(int i = e-1; i >= s; i--) {
		if(buff[i] == '1') sum += d;
		d *= 2;
	}	
	return sum;
}

int main()
{
    sscanf(gets(buff), "%d", &T);
    REP(t, 1, T) {
    	sscanf(gets(buff), "%d%d", &N, &L);
    	set<int> fin;
    	vector<int> num;
    	int n;
    	gets(buff);
    	int l = strlen(buff);
    	for(int i = 0, p = 0; i < l; ) {
    		while(buff[i] == '0' || buff[i] == '1') i++;    		
    		n = btod(p, i);
    		//printf("%d\n", n);
    		num.pb(n);
    		i = p = i+1;
    	}

    	gets(buff);
    	l = strlen(buff);
    	for(int i = 0, p = 0; i < l; ) {
    		while(buff[i] == '0' || buff[i] == '1') i++;
    		n = btod(p, i);
    		//printf("%d\n", n);
    		fin.insert(n);
    		i = p = i+1;
    	}

    	bool good = true;
    	for_each(it, num) {
    		if(fin.find(*it) == fin.end()) {
    			good = false;
    			break;
    		}
    	}

    	printf("Case #%d: ", t);

    	if(good) {
    		printf("0\n");
    		continue;
    	}
    	vector<int> temp;
    	int min_flip = L+2, num_set_bits;
    	for(int flip = 1; flip < (1 << L); flip++) {
    		temp.assign(num.begin(), num.end());
    		num_set_bits = 0;
    		for(int set_bits = 0; set_bits < L; set_bits++) {    			
    			if(flip & (1 << set_bits)) {
    				num_set_bits++;
    				for(int k = 0; k < N; k++) {
    					temp[k] ^= (1 << set_bits);
    				}
    			}
    		}

    		if(num_set_bits > min_flip) continue;

    		good = true;
    		for_each(it, temp) {
    			if(fin.find(*it) == fin.end()) {
    				good = false;
    				break;
    			}
    		}

    		if(good) {
	    		min_flip = min(min_flip, num_set_bits);
    		}
    	}

    	if(min_flip == L+2) {
    		printf("NOT POSSIBLE\n");
    	} else {
    		printf("%d\n", min_flip);
    	}
    }
    return 0;
}
