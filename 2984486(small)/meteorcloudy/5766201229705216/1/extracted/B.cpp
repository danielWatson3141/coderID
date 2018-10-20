#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <set>
#define maxn 1000010
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

vector<int> v[maxn];

int dp[maxn];
int son[maxn];
int n;

void dfs(int x , int pre){
	int y;
	int sons=0;
	int mx,mx2,sum;
	mx=mx2=0;
	sum=0;
	for (int i=v[x].size()-1;i>=0;i--){
		y = v[x][i];
		if (y==pre) continue;
		sons++;
		dfs(y,x);
		son[x] += son[y]+1;
		sum+=dp[y];
		if (son[y]+1-dp[y]>mx)
		{
			mx2=mx;
			mx=son[y]+1-dp[y];
		} else mx2=max(son[y]+1-dp[y],mx2);
	}

	if (sons<2)
		dp[x] = son[x];
	else
		dp[x] = son[x] - mx - mx2;
}

void work(int root){
	clearAll(dp);
	clearAll(son);
	dfs(root,-1);
}

int main()
{
    freopen("E:\\codejam\\input.txt","r",stdin);
   	freopen("E:\\codejam\\output.txt","w",stdout);
    int x,y;
    int tt;
    int id = 0;
    cin >> tt;

    while (tt--){
    	cin >> n;
    	for (int i=0;i<=n;i++) v[i].clear();
    	for (int i=0;i<n-1;i++){

    		cin >> x >> y;
    		v[x].push_back(y);
    		v[y].push_back(x);
    	}


    	int ans = oo;
    	for (int i=1;i<=n;i++){
    		work(i);
    		ans = min(ans,dp[i]);
    	}

    	id++;
    	printf("Case #%d: %d\n",id,ans);
    }
    return 0;
}
