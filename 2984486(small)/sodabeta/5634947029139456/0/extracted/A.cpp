#include <bits/stdc++.h>
using namespace std;
#define TR(i,v) 		for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x) 		cout << #x << " = "; cout << x << endl;
#define SIZE(p) 		(int)(p).size()
#define MP(a, b)		make_pair((a), (b))
#define ALL(p)			(p).begin(), (p).end()
#define rep(i, n)		for(int (i)=0; (i)<(int)(n); ++(i))
#define REP(i, a, n)	for(int (i)=(a); (i)<(int)(n); ++(i))
#define FOR(i, a, b)   	for(int (i)=(int)(a); (i)<=(int)(b); ++(i))
#define FORD(i, b, a)  	for(int (i)=(int)(b); (i)>=(int)(a); --(i)) 
typedef long long LL;
typedef pair<int, int> pii;
int C1[45], C2[45];
LL O[155], F[155];
class Hungary{
public:
    static const int SIZE = 505; // 最大的单侧点个数
    int cnt,pos[SIZE],neg[SIZE]; // pos[]为左侧点所匹配到的右侧点编号
                                 // neg[]反之，没有匹配到对应的点则为-1
    // 传入左侧点个数n和左侧点至右侧点的边表e[]，返回匹配对的数量cnt
    int gao(int n, const vector<int> e[]){
        memset(pos,-1,sizeof(pos));
        memset(neg,-1,sizeof(neg));
        for(int i=cnt=0;i<n;i++){
            memset(v,0,sizeof(v));
            if(aug(i,e)) cnt++;
        }
        return cnt;
    }
private:
    bool v[SIZE];
    bool aug(int x, const vector<int> e[]){
        int y;
        for(size_t i=0;i<e[x].size();i++) if(!v[y=e[x][i]]){
            v[y]=true;
            if(~neg[y] && !aug(neg[y],e)) continue;
            pos[neg[y]=x]=y;
            return true;
        }
        return false;
    }
}solver;
vector<int> g[155];
bool cmp(int x, int y)
{
	return __builtin_popcount(x) < __builtin_popcount(y);
}
int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);	
    freopen("out", "w", stdout);
    #endif
	// ios::sync_with_stdio(false);    cin.tie(0);
	int T;		scanf("%d", &T);
	FOR(cs,1,T)
	{
		printf("Case #%d: ", cs);		
		int n, L;		scanf("%d%d", &n, &L);
		FOR(i, 1, n) {
			char t[45];			scanf("%s", t);
			LL s=0;
			rep(j, L)	s=(s<<1)+(t[j]-'0');
			O[i]=s;
		}
		FOR(i, 1, n) {
			char t[45];			scanf("%s", t);
			LL s=0;
			rep(j, L)	s=(s<<1)+(t[j]-'0');
			F[i]=s;	
		}
		vector<LL> E;
		FOR(i, 1, n)
		FOR(j, 1, n)	E.push_back(O[i]^F[j]);
		sort(ALL(E), cmp);
		auto uf = unique(ALL(E));
		E.erase(uf, E.end());
		LL res=-1;
		for(auto x : E)
		{
			// DEBUG(x);
			FOR(i, 1, n) {
				g[i-1].clear();
				FOR(j, 1, n)	if((O[i]^F[j])==x) {
					g[i-1].push_back(j-1);
					// printf("%d -> %d %lld %lld %lld\n", i, j, O[i], F[j], O[i]^F[j]);
				}
			}
			int r = solver.gao(n, g);			
			// DEBUG(r);
			if(r == n) {
				res=x;	break;
			}			
		}
		if(res==-1)		puts("NOT POSSIBLE");
		else			printf("%d\n", __builtin_popcount(res));
		// DEBUG(res);
	}
	return 0;
}