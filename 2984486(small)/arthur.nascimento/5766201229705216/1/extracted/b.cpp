#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

vector<int> L[1010];

int dfs(int x,int p){

	if(x == p && L[x].size() == 1)
		return 1;

	vector<int> v;

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p)
			v.push_back(dfs(*it,x));

	sort(v.begin(), v.end());

	if(x != p && L[x].size() == 1)
		return 1;

	if(x != p && L[x].size() == 2)
		return 1;

	return max(1 + v[v.size()-1] + v[v.size()-2], 1);


}

main(){

		int t;
		scanf("%d",&t);

		for(int te=1;te<=t;te++){

			int n;
			scanf("%d",&n);

			for(int i=0;i<n;i++)
				L[i].clear();

			for(int i=0;i<n-1;i++){
				int a,b;
				scanf("%d%d",&a,&b);
				L[a-1].push_back(b-1);
				L[b-1].push_back(a-1);
			}


			int ans = 0;
			for(int i=0;i<n;i++)
				ans = max(ans,dfs(i,i));

			printf("Case #%d: %d\n",te,n-ans);

		}

}
