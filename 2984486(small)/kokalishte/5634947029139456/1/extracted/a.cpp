#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;
inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};
ld start_time,end_time;


char BAD[] = "NOT POSSIBLE";
char devices[154][48];
char outlets[154][48];

int count_invs(char dev[48], char outlet[48]) {
	int sz = strlen(dev);
	int res = 0;
	for (int i = 0; i < sz; ++i) {
		if (dev[i] != outlet[i]) {
			res++;
		}
	}
	return res;
}

void make_invs(char dev[48], char outlet[48], char* dest) {
	int sz = strlen(dev);
	for (int i = 0; i < sz; ++i) {
		if (dev[i] != outlet[i]) dest[i]='1';
		else dest[i]='0';
	}
	dest[sz]=0;
}

bool can_do(char dev[48], char outlet[48], char inv_string[48]) {
	bool res = true;
	int sz = strlen(inv_string);
	for (int i = 0; i < sz; ++i) {
		if (inv_string[i] == '1') {
			if (dev[i] == outlet[i]) return false;
		} else if (dev[i] != outlet[i]) return false;
	}
	return true;
}

string solve() {
	int n, l;
	int RES = 1000000000;
	cin >> n >> l;
	for (int i = 0; i < n; ++i) {
		cin >> outlets[i];
	} for (int i = 0; i < n; ++i) {
		cin >> devices[i];
	}

	for (int j = 0; j < n; ++j) {
		int cur_min = count_invs(devices[0], outlets[j]);
		char inv_string[48];
		make_invs(devices[0], outlets[j], inv_string);
		if (cur_min < RES) {
			bool goodConf = true;
			for (int i = 1; i < n; ++i ) {
				for (int z = 0; z < n; ++z) {
					if (z ==j&&j==n-1) goodConf=false;
					if (z==j) continue;
					if (can_do(devices[i], outlets[z], inv_string)) {
						break;
					}
					if (z == n-1) {
						goodConf = false;
					}
				}
				if (!goodConf) break;
			}
			if (goodConf) {
				RES = cur_min;
			}
		}
	}
	stringstream ss;
	if (RES < 1000000000) {
		ss << RES;
	} else ss << BAD;
	return ss.str();
}



int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	//start_time = get_time();
	//program
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		printf("Case #%d: %s\n", test ,solve().c_str()); 
	}

	//end program
	//end_time=get_time()-start_time;
	return 0;
}




