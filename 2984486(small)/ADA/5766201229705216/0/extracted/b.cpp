#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <cstdlib>
#include <map>
//#define maxn 2005
#define maxm 50000
#define N 110
#define inf 1 << 30 //0x3fffffff
#define LL long long
#define Uint unsigned long long
#define mod 1000000007
#define pi 3.1415926535898
//#define e 2.718281828459 
#define eps 1e-6
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a, b) cout << #a << " = " << a << " , " << #b << " = " << b << endl;
using namespace std; 

template <class T>
inline bool scan_d(T &ret) {
   char c; int sgn;
   if (c = getchar(), c == EOF) return 0; //EOF
   while (c != '-' && (c < '0' || c > '9')) c = getchar();
   sgn = (c == '-') ? -1 : 1;
   ret = (c == '-') ? 0 : (c - '0');
   while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
   ret *= sgn;
   return 1;
}

const int INF = 0x3f3f3f3f;
const int maxn = 1005;
struct edge{
	int v,next;
};
edge e[maxn<<1];
int head[maxn];
int id;
int d[maxn];
void add(int x,int y){
	e[id].v = y;
	e[id].next = head[x];
	head[x] = id ++;
}
int dfs(int u,int fa){
	//printf("u = %d fa = %d\n",u,fa);
	if(d[u] == 1)return 1;
	int mi = -1,mj = -1;
	for(int i = head[u];i != -1;i = e[i].next){
		if(e[i].v == fa)continue;
		int p = dfs(e[i].v,u);
		if(p >= mi){
			mj = mi;
			mi = p;
			//mj = mi
		}
		else if(p > mj){
			mj = p;
		}
	}
	//printf("u = %d mi = %d mj = %d\n",u,mi,mj);
	return (mi == -1 || mj  == -1) ? 1 : mi + mj + 1;
}
int main(){
	int t;
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	int cas = 1;
	while(t --){
		int n;
		int x,y;
		scanf("%d",&n);
		memset(head,-1,sizeof(head));
		id = 0;
		memset(d,0,sizeof(d));
		for(int i = 0;i < n - 1;i ++){
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
			d[x] ++;d[y] ++;
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++){
			int p = dfs(i,0);
			//printf("p = %d\n",p);
			if(p > ans)ans = p;
		}
		printf("Case #%d: %d\n",cas ++,n - ans);
	}
	return 0;
}
