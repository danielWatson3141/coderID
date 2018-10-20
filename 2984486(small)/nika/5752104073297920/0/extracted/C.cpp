#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
#define CL(a,x) memset(x, a, sizeof(x))
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002];

map<vector<int>, int> M;

int a[1000];

int TH = 510;
double study1() {
    n = 1000;
    F0(i,n) a[i] = i;
    F0(i,n) {
        j = rand()%n;
        swap(a[i], a[j]);
    }
    int z = 0;
    F0(i,n) if (a[i] >= i) z++;
    if (z >= TH) return 1; else return 0;
}

double study2() {
    n = 1000;
    F0(i,n) a[i] = i;
    F0(i,n) {
        j = rand()%(i+1);
        swap(a[i], a[j]);
    }
    int z = 0;
    F0(i,n) if (a[i] >= i) z++;
    if (z >= TH) return 0; else return 1;
}

int main() {
    /*
    double sum = 0.0;
    F0(k,60) {
      sum += study1();
      sum += study2();
    }
    cerr << sum << endl;
return 0;
    */

//    freopen("c.in", "r", stdin);

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

//	freopen("C-large.in", "r", stdin);
//	freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        //cerr << tt << endl;
        cin >> n;
        F0(i,n) cin >> a[i];
        int z = 0;
        F0(i,n) if (a[i] >= i) z++;
		printf("Case #%d: ", tt);

        if (z>=TH) cout << "BAD" << endl;
        else cout << "GOOD" << endl;
	}

	return 0;
}
