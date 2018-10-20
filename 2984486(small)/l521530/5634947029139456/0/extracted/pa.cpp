// TwT514 {{{
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset(x,0,(n)*sizeof(*x))
#define MS1(x,n) memset(x,-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}
#define N 160
int n,m;
LL a[N],b[N];
char c[N];
LL get(){
	scanf("%s",c);
	LL x = 0;
	REP(i,m) x = x*2 + c[i]-'0';
	return x;
}

void input(){
	RII(n,m);
	REP(i,n) a[i] = get();
	REP(i,n) b[i] = get();
}

LL gettime(LL x){
	LL ans = 0;
	REP(i,m) if((x>>i)&1) ans++;
	return ans;
}

void solve(){
	//REP(i,n) cout << a[i] << ' '; cout << endl;
	//REP(i,n) cout << b[i] << ' '; cout << endl;
	LL ans = 0, ab = N;
	sort(b, b+n);
	LL st = a[0];
	REP(i,n){
		LL x = st^b[i];	
		REP(i,n) a[i] = a[i]^x;
		sort(a, a+n);
		bool same = true;
		REP(i,n) if(a[i] != b[i]) same = false;
		if(same){
			LL time = gettime(x);
			if(time<ab){
				ab = time;
				ans = x;
			}
		}
		REP(i,n) a[i] = a[i]^x;
	}
	static int zi=0;
	printf("Case #%d: ", ++zi);
	if(ab==N){
		puts("NOT POSSIBLE");
	}
	else{
		cout << ab << endl;
	}
}

int main() {
	int zn;
	RI(zn);
	while(zn--){
		input();
		solve();
	}
    return 0;
}

