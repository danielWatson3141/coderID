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
#define maxn 305

int test, n, l;
ll a[maxn], b[maxn];
string s;
bool flag[maxn];

void solve(int num_test){
	cout << "Case #" << num_test << ": ";
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		cin >> s;
		a[i] = 0;
		for(int j = 0; j < l; j++) if(s[j] == '1') a[i] = onbit(a[i], j);
	}
	for(int i = 0; i < n; i++){
		cin >> s;
		b[i] = 0;
		for(int j = 0; j < l; j++) if(s[j] == '1') b[i] = onbit(b[i], j);
	}

	int res = inf;
	for(int i = 0; i < n; i++){
		ll x = a[0] ^ b[i];
		ms(flag, 0);
		int num = 0;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++) if(!flag[k] && (a[j] ^ b[k]) == x){
				flag[k] = 1;
				num++;
				break;
			}
		}
		if(num == n){
			res = min(res, cntbit(x));
		}
	}

	if(res >= inf){
		cout << "NOT POSSIBLE" << endl;
	} else cout << res << endl;

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
