#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

int N,L,T;

char a[155][45],b[155][45],dum[50];

bool flip[45],use[45];

int ans;

int main(){
	scanf("%d",&T);
	FOE(t,1,T){
		scanf("%d%d",&N,&L); gets(dum);
		
		FOR(i,0,N) scanf("%s",a[i]);
		FOR(i,0,N) scanf("%s",b[i]);

		ans=INF;
		FOR(tar,0,N){
			CLR(flip); CLR(use);

			int count=0;
			FOR(i,0,L){
				if (b[0][i] != a[tar][i]) flip[i]=1,++count;
			}

			bool good=1;
			use[tar]=1;
			FOR(i,1,N){
				bool found=0;
				FOR(j,0,N){
					if (use[j]) continue;

					bool ok=1;
					FOR(k,0,L){
						if ((b[i][k] != a[j][k]) != flip[k]) ok=0;
					}

					if (ok) use[j] = 1, found=1;
				}
				if (!found) good=0;
			}

			if (good) ans = min(ans,count);
		}

		printf("Case #%d: ",t);
		if (ans != INF) printf("%d\n",ans);
		else puts("NOT POSSIBLE");
	}
	return 0;
}
