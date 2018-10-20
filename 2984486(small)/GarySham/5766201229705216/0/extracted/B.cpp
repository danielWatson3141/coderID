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

int T,N;

bool e[1005][1005];

struct data{
	int bal, nc;

	data(){}
	data(int bal,int nc):bal(bal),nc(nc){}

	bool operator<(const data &d)const{
		return (bal-nc) < (d.bal - d.nc);
	}
};

data f(int pos,int par){
	int child[1005],count=0;
	data re[1005];
	
	FOR(i,0,N){
		if (e[pos][i] && (i != par)) child[count++] = i;
	}

	FOR(i,0,count) re[i] = f(child[i],pos);

	//if ((pos == 1) && (par == -1)) printf("%d!!\n",count);
	/*
	if ((pos == 0) && (par == 1)){
		FOR(i,0,count) printf("%d: %d %d\n",child[i]+1,re[i].bal,re[i].nc);
	}
	*/

	if (count == 0) return data(0,1);
	else if (count == 1) return data(re[0].nc,re[0].nc+1);
	else if (count == 2) return data(re[0].bal + re[1].bal, re[0].nc + re[1].nc+1);
	else{
		sort(re,re+count);

		int tmp1 = 0, tmp2 = 0;
		tmp1 = re[0].bal + re[1].bal;
		tmp2 = re[0].nc + re[1].nc;
		FOR(i,2,count) tmp1 += re[i].nc, tmp2 += re[i].nc;

		return data(tmp1,tmp2+1);
	}
}

int main(){
	scanf("%d",&T);
	FOE(t,1,T){
		CLR(e);

		scanf("%d",&N);
		FOR(i,1,N){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x-1][y-1] = e[y-1][x-1] = 1;
		}

		int ans=INF;
		FOR(i,0,N){
			data tmp = f(i,-1);

			//printf("%d: %d!!\n",i+1,tmp.bal);

			ans = min(ans,tmp.bal);
		}

		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
