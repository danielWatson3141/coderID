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

long long qnt[1010][1010];

int p[1010];
int ans[1010];


main(){

		srand(time(0));
		int N = 20;

		for(int k=0;k<10000000;k++){

			for(int i=0;i<N;i++)
				p[i] = i;

			for(int i=0;i<N;i++){
				int l = rand()%N;
				swap(p[i], p[l]);
			}

			for(int i=0;i<N;i++)
				qnt[p[i]][i]++;

		}

		//for(int i=0;i<n;i++){
			//for(int j=0;j<n;j++)
				//printf("%d ",qnt[i][j]/1000);
			//printf("\n");
		//}
		debug("ok");
		//return 0;

		int t;
		scanf("%d",&t);

		pll vv[150];

		for(int te=0;te<t;te++){

			int n;
			scanf("%d",&n);

			vv[te].second = te;

			for(int i=0;i<n;i++){
				int u;
				scanf("%d",&u);
				//debug("a %d %d",u,i);
				vv[te].first += qnt[u/50][i/50];//debug("b");
			}

		}

		
		sort(vv,vv+t);

		for(int i=0;i<t/2;i++)
			ans[vv[i].second] = 1;
		for(int i=t/2+1;i<t;i++)
			ans[vv[i].second] = 0;


		for(int i=0;i<t;i++)		
			printf("Case #%d: %s\n",i+1,  ans[i] ? "GOOD" : "BAD");			

}
