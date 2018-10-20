#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

int N, L;
const int MAX_N = 200;
string a[MAX_N];
string a1[MAX_N];
string b[MAX_N];
long long aa[MAX_N];
long long bb[MAX_N];

string Convert2S(long long k){
	for(int i = 8; i >= 0; --i){
		if(1LL << i & k) cout << '1';
		else cout << '0';
	}
	cout << endl;
	return string();
}

long long ConvertS2(string s){
	long long r = 0;
	long long p = 1;
	int n = s.size();
	FOR(i, n){
		if(s[n-1-i]=='1') r+=p;
		p*=2;
	}
	//Convert2S(r);
	//cout << s << ": " << r << endl;
	return r;
}

bool Check(){
	/*cout << endl;
	FOR(i, N) cout << aa[i] << " ";
	cout << endl;
	FOR(i, N) cout << bb[i] << " ";
	cout << endl;
	cout << endl;//*/
	FOR(i,N){
		if(aa[i]!=bb[i])return false;
	}
	return true;
}

void Solve()
{
	cin >> N >> L;
	//cout << N << " " << L;
	FOR(i, N) cin >> a[i];
	FOR(i, N) cin >> b[i];
	FOR(i, N) bb[i] = ConvertS2(b[i]);
	sort(bb,bb+N);

	//FOR(i, N) cout << bb[i] << endl;

	int ans = L+1;
	int mask_n = 1LL << L;
	//cout << mask_n << endl;
	for(int mask = 0; mask < mask_n; ++mask){
		int bits = 0;
		for(int i = 0; i < N; ++i){
			a1[i] = a[i];
		}
		for(int i = 0; i < L; ++i){
			bool flip = 1LL<<i & mask;
			//cout << mask << " " << i << " " << flip << endl;
			if(flip) ++bits;
			for(int j = 0; j < N; ++j){
				string s = a1[j];
				if(flip) s[L-1-i] = s[L-1-i]=='0'?'1':'0';
				a1[j] = s;
			}
		}
		for(int i = 0; i < N; ++i){
			aa[i] = ConvertS2(a1[i]);

			/*cout << a[i] << endl;
			cout << a1[i] << endl;
			cout << aa[i] << endl;
			cout << endl;//*/
		}
		//cout << mask << " " << bits << endl;
		sort(aa,aa+N);
		if(Check()){
			ans = min(ans, bits);
		}
	}

	if(ans > L){
		cout << "NOT POSSIBLE" << endl;
	}else{
		cout << ans << endl;
	}
	//FOR(i, N) cout << a[i] << endl;
	//FOR(i, N) cout << b[i] << endl;

	return;
}

int main()
{
	int n; cin >> n;
	FOR(t, n){
		cout << "Case #" << t+1 << ": ";
		Solve();
	}
	return 0;
}
