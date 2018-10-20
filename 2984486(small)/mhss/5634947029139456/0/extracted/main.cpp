#include<bits/stdc++.h>

#define fr(a,b) for(int a = 0; a < b; a++)
#define frr(a,b,c) for(int a = b; a < c; a++)
#define ms(a,b) memset(a, b, sizeof(a))
#define INF 0x3f3f3f3f
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define ll long long
#define scs(s) scanf("%s", s)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)

using namespace std;

int n, l;
ll dev[200], tom[200];
char str[50];

ll le() {
	scs(str);
	ll ret = 0;
	fr(x, l) ret = (ret<<1) + str[x] - '0';
	return ret;
}

int proc(int i) {
	ll mask = dev[0]^tom[i];
	set<ll> conj;
	fr(x, n) if (x != i) conj.insert(mask^tom[x]);
	frr(x,1,n) if (conj.count(dev[x])) {
		conj.erase(dev[x]);
	} else return INF;
	int ret = 0;
	while (mask) {
		ret += mask&1;
		mask >>=1;
	}
	return ret;
}

int main() {
    //freopen("A-small-attempt0.in", "r", stdin);
	//freopen("out", "w", stdout);
	int t, cn = 1;
	sc(t);
	while (t--) {
		printf("Case #%d: ", cn++);
		sc2(n, l);
		fr(x, n) tom[x] = le();
		fr(x, n) dev[x] = le();
		int ans = INF;
		fr(x, n) ans = min(ans, proc(x));
		if (ans == INF) puts("NOT POSSIBLE");
		else pri(ans);
	}
	return 0;
}
