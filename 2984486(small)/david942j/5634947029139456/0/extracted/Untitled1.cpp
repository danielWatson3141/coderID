#include <bits/stdc++.h>
#define mpr std::make_pair
#define lg std::__lg
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define RI(n) scanf("%d",&n);
#define RI2(a,b) scanf("%d%d",&a,&b);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;
typedef double LD;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}
const int N=210;
LL A[N],B[N],C[N];
char s[N];
int n,m;
const int INF=1000;
int solve(LL a){
	for(int i=0;i<n;i++)
		C[i]=A[i]^a;
	std::sort(C,C+n);
	for(int i=0;i<n;i++)
		if(C[i]!=B[i])
			return INF;
	return __builtin_popcountll(a);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T,w=1;RI(T);
	while(T--){
		RI(n);RI(m);
		for(int i=0;i<n;i++){
			scanf("%s",s);
			LL x=0;
			for(int j=0;s[j];j++)
				x=x*2+s[j]-'0';
			A[i]=x;
		}
		for(int i=0;i<n;i++){
			scanf("%s",s);
			LL x=0;
			for(int j=0;s[j];j++)
				x=x*2+s[j]-'0';
			B[i]=x;
		}
		std::sort(A,A+n);
		std::sort(B,B+n);
		int ans=INF;
		for(int i=0;i<n;i++){
			int ret=solve(A[0]^B[i]);
			if(ret<ans)ans=ret;
		}
		printf("Case #%d: ",w++);
		if(ans==INF){puts("NOT POSSIBLE");}
		else printf("%d\n",ans);
		
	}
	return 0;
}

