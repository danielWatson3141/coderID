#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

int t, n, l;
long long H[310], W[310];

char tmp[100];
long long bits(int len) {
	long long ret = 0;
	
	cin >> tmp;
	for (int i = 0; i < len; i ++) {
		ret <<= 1;
		if (tmp[i] == '1')
			ret ++;
	}
		
	return ret;
}

bool Test(long long mask) {
	vector<long long> A, B;
	for (int i = 0; i < n; i ++) {
		A.push_back(H[i] ^ mask);
		B.push_back(W[i]);
	}
		
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	for (int i = 0; i < n; i ++)
		if (A[i] != B[i])
			return false;
			
	return true;		
}

int bitcount(long long num) {
	int ret = 0;
	for (int i = 0; i < 64; i ++)
		if (num & (bit(i)))
			ret ++;
	return ret;
}

int main () {
	cin >> t;
	int caze = 0;
	
	while (t --) {
		caze ++;
	
		cin >> n >> l;
		for (int i = 0; i < n; i ++)
			H[i] = bits(l);
		for (int i = 0; i < n; i ++)
			W[i] = bits(l);
			
		int ans = 500;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				if (Test(H[i] ^ W[j]))
					ans = min( bitcount(H[i] ^ W[j]), ans );
			}
		}
		
		cout << "Case #" << caze << ": ";
		if (ans == 500)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ans << endl;
	}
	
	return 0;
}  	
