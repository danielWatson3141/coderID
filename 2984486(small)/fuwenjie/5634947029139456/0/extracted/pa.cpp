#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
#include <iomanip>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

ll toLL(string s) {
    ll ret = 0;
    for (int i = 0; i < s.length(); i++) {
        ret *= 2;
        if (s[i] == '1') ret++;
    }
    return ret;
}

int count_digits(ll x) {
    int ret = 0;
    while (x > 0) {
        if (x % 2 == 1) ret++;
        x /= 2;
    }
    return ret;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
        vector<ll> outlets;
        vector<ll> devices;
        int n, l;
        fin >> n >> l;
		int i,j;
		string s;
		for (i = 0; i < n; ++i) {
            fin >> s;
            outlets.push_back(toLL(s));
            //cout << outlets.back() << endl;
		}
		for (i = 0; i < n; ++i) {
            fin >> s;
            devices.push_back(toLL(s));
            //cout << devices.back() << endl;
		}
		sort(outlets.begin(), outlets.end());
		int ans = l+1;
		for (i = 0; i < n; ++i) {
            ll x = outlets[0] ^ devices[i];
            vector<ll> sd;
            //cout << "x = " << x << endl;
            for (j = 0; j < n; j++) {
                sd.push_back(devices[j] ^ x);
            }
            sort(sd.begin(), sd.end());
            j = 0;
            while (j < n && outlets[j] == sd[j]) j++;
            if (j >= n) {
                int k = count_digits(x);
                if (k < ans) ans = k;
            }
		}
		if (ans > l)
            fout << "Case #" << tind << ": NOT POSSIBLE" << endl;
        else
            fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
