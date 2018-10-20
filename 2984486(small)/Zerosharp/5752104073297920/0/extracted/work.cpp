#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1);}

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
#define maxn 1005

int test, n;
int a[maxn];

void solve(int num_test){
	cout << "Case #" << num_test << ": ";
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];

	int num = 0;
	for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) if(a[i] > a[j]){
		num++;
	}
	if(num + num > n * (n - 1) / 2) cout << "GOOD" << endl;
	else cout << "BAD" << endl;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> test;
    for(int itest = 1; itest <= test; itest++){
    	solve(itest);
    }
}
