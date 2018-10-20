#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define CLR(x, a) memset(x, a, sizeof(x))
//#define L(x) ((x) << 1)
#define R(x) (((x) << 1) + 1)
#define LB(x) ((x)&(-(x)))
#define SL(x) (1 << (x))
#define X first
#define Y second
const int MAXN = 150 + 20;

LL flow[MAXN], device[MAXN];
int n, L;

LL stol(string& s) {
	LL res = 0;
	FOR(i, s.size()) {
		if (s[i] == '0') res <<= 1;
		else {
			res <<= 1;
			res |= 1;
		}
	}
	//cout << res << endl;
	return res;
}

int count(LL mask) {
	int res = 0;
	while (mask) {
		res++;
		mask  &= (mask - 1);
	}
	return res;
}

int match(LL mask) {
	int res = count(mask);
	FOR(i, n) {
		flow[i] ^= mask;
	}
	sort(flow, flow + n);
	FOR(i, n) {
		if (flow[i] != device[i]) {
			res = L + 1;
			break;
		}
	}
	FOR(i, n) {
		flow[i] ^= mask;
	}
    sort(flow, flow + n);
	return res;
}

int main(){
    
	int T; cin >> T;
	FOR(cas, T){
		printf("Case #%d: ", cas + 1);
		cin >> n >> L;
		FOR(i, n) {
			string tmp; cin >> tmp;
			flow[i] = stol(tmp);
		}
		FOR(i, n) {
			string tmp; cin >> tmp;
			device[i] = stol(tmp);
		}
		int res = L + 1;
        sort(flow, flow + n);
        sort(device, device + n);
		for (int i = 0; i < n; i++) {
			LL mask = device[0] ^ flow[i];
			int tmp = match(mask);
			if (tmp < res) {
				res = tmp;
			}
		}
		if (res > L) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << res << endl;
		}
	}
}