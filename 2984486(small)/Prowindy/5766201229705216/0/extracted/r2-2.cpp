#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;
const int MaxN = 1010;
vector<int> E[MaxN];
int f[MaxN], cnt[MaxN];
int calcf(int now, int fa){
	f[now] = 0;
	cnt[now] = 1;
	int cntSon;
	if (fa==-1) cntSon = E[now].size();
	else cntSon = E[now].size()-1;
	
	for (int i = 0;i< E[now].size(); i++)
	if (E[now][i]!=fa){
		calcf(E[now][i],now);
		cnt[now]+=cnt[E[now][i]];
	}
	if (cntSon==0) ;
	else if (cntSon==1) {
		f[now] = cnt[now]-1;
		
	}else {
		int one = -1, two = -1;
		for (int i = 0;i <E[now].size();i++){
			int cur = E[now][i];
			if (cur!=fa){
				if (one==-1||f[cur]-cnt[cur]<f[one]-cnt[one]){
					two = one;
					one = cur;
				}else if (two==-1||f[cur]-cnt[cur]<f[two]-cnt[two]){
					two = cur;
				}
			}
		}
		f[now] = cnt[now]-1+f[one]-cnt[one]+f[two]-cnt[two];
		
	}
	//printf("%d -- %d %d\n",now, f[now], cnt[now]);
	return f[now];
}
int main(){
	int tt;
	int N,a,b;
	scanf("%d",&tt);
	for (int tcas = 1; tcas<=tt; tcas++){
		scanf("%d",&N);
		for (int i = 1;i <=N; i++)
			E[i].clear();
		for (int i = 1;i < N;i++){
			scanf("%d%d",&a,&b);
			E[a].push_back(b), E[b].push_back(a);
		}
		int ans = N;
		for (int i = 1; i<=N; i++){
			calcf(i,-1);
			ans = min(ans, f[i]);
		}
		printf("Case #%d: %d\n", tcas, ans);
	}
}
