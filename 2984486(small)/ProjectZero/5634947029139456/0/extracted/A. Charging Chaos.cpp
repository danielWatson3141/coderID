#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 15;

char ss[MAXN];

int A[MAXN],B[MAXN],T,N,L;

const int INF = 1e9;

int cal2(int x){

}

void input(){
	scanf("%d %d",&N,&L);
	for(int i=0;i<N;i++){
		scanf("%s",ss);

		int multi = 1,vv = 0;
		for(int j=L-1;j>=0;j--){
			if(ss[j] == '1') vv += multi;
			multi *= 2; 
		}
		A[i] = vv;
	}
	for(int i=0;i<N;i++){
		scanf("%s",ss);

		int multi = 1,vv = 0;
		for(int j=L-1;j>=0;j--){
			if(ss[j] == '1') vv += multi;
			multi *= 2; 
		}
		B[i] = vv;
	}

	// for(int i=0;i<N;i++) printf("A[%d] = %d\n",i,A[i]);
	// for(int i=0;i<N;i++) printf("B[%d] = %d\n",i,B[i]);
}

const int MAXDP = (1<<12);
int dp[MAXN][MAXDP];
int pass[MAXN][MAXDP];

int change(int a,int b){
	int cc = 0;
	for(int i=0;i<L;i++){
		int val1 = (1<<i)&a;
		int val2 = (1<<i)&b;
		if(val1 != val2) cc++;
	}
	return cc;
}

int ans;
int AA[MAXN];

int M1[MAXN],M2[MAXN];

void run(int bitmask){
	for(int i=0;i<N;i++) AA[i] = A[i];

	int cc = 0;
	for(int i=0;i<L;i++){
		if((1<<i)&bitmask){
			cc++;
			for(int j=0;j<N;j++){
				if((1<<i)&AA[j]) AA[j] -= (1<<i);
				else			 AA[j] += (1<<i);
			}
		}
	}
	// for(int i=0;i<N;i++) printf("%d",AA[i]);printf("\n");

	// printf("bitmask = %d  %d\n",bitmask,cc);
	memset(M2,0,sizeof M2);
	for(int i=0;i<N;i++){

		bool can = false;
		for(int j=0;j<N;j++){
			if(M2[j]) continue;
			if(AA[i] == B[j]){
				M2[j] = true;
				can = true;
				break;
			}
		}
		if(can == false) return ;
	}
	// printf("bitmask = %d cc = %d\n",bitmask,cc);
	ans = min(ans,cc);
}


void rec(int now,int bitmask){
	if(now == L){
		run(bitmask);
		return ;
	}
	rec(now+1,bitmask);
	rec(now+1,bitmask|(1<<now));
}

void solve(){
	ans = INF;
	rec(0,0);

	if(ans > 100) printf("NOT POSSIBLE\n");
	else printf("%d\n",ans);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		input();
		solve();
	}
	return 0;
}