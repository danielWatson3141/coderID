#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <bitset>
#include <string.h>
using namespace std;

int N = 0;
int L = 0;

vector<long long> src;
vector<long long> dst;

int popcnt(long long m)
{
	int cnt = 0;
	while(m) {
		cnt++;
		m &= m-1;
	}
	return cnt;
}

void readCase()
{
	cin >> N;
	cin >> L;

	src.clear();
	dst.clear();

	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		long long r = 0;
		long long b = 1;
		for(int j = 0; j < L; j++, b *= 2) {
			if(s[j] == '1') r |= b;
		}
		src.push_back(r);
	}
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		long long r = 0;
		long long b = 1;
		for(int j = 0; j < L; j++, b *= 2) {
			if(s[j] == '1') r |= b;
		}
		dst.push_back(r);
	}
}

void solve()
{
	const string impossible = "NOT POSSIBLE";

	sort(dst.begin(), dst.end());

	vector<long long> srcd = src;

	int best = INT_MAX;
	long long bestxor = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			long long xor = src[i] ^ dst[j];
			for(int k = 0; k < N; k++) {
				srcd[k] = src[k] ^ xor;
			}

			sort(srcd.begin(), srcd.end());
			const int pcnt = popcnt(xor);
			if(srcd == dst) {
				if(best > pcnt) {
					best = pcnt;
					bestxor = xor;
				}
			}
		}		
	}

	if(best == INT_MAX)
		cout << impossible;
	else
		cout << best;
}

int main()
{
	//string fname = "./test/A-example.in";
	//string fname = "./test/A-small-attempt0.in";
	string fname = "./test/A-large.in";
	
	freopen(fname.c_str(),"r",stdin);freopen((fname+".out").c_str(),"w",stdout);

	int analizeCase = -1;
	
	int T;
	scanf("%d", &T);
	for(int tCase = 1; tCase <= T; tCase++) {
		printf("Case #%d: ", tCase);
		readCase();
		if(analizeCase < 0 || analizeCase == tCase) solve();
		printf("\n");
		fflush(stdout);
		fprintf(stderr, "Done %d %%     \r", 100 * tCase / T );
	}
	return 0;
}

