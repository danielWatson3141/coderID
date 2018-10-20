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

char a[200][50];
char b[200][50];
char c[200][50];

int muda[50];

main(){

		int t;
		scanf("%d",&t);

		for(int te=1;te<=t;te++){


			int n,l;
			scanf("%d%d",&n,&l);

			for(int i=0;i<n;i++)
				scanf(" %s",a[i]);
			for(int i=0;i<n;i++)
				scanf(" %s",b[i]);

			int ans = 999999;

			for(int i=0;i<n;i++){

				//debug("i=%d\n",i);
				memset(muda,0,sizeof(muda));

				for(int j=0;j<l;j++)
					if(a[0][j] != b[i][j])
						muda[j] = 1;

				for(int j=0;j<n;j++)
					for(int k=0;k<l;k++)
						c[j][k] = ((b[j][k] == '1') ^ muda[k]) ? '1' : '0';

				for(int j=0;j<n;j++)
					c[j][l] = 0;

				map<string,int> mp;

				for(int j=0;j<n;j++){
					mp[(string)a[j]]++,
					mp[(string)c[j]]--;
					//cerr << (string)a[j] << " " << (string)c[j] << endl;
					}

				int ok = 1;

				for(map<string,int> :: iterator it = mp.begin(); it != mp.end(); it++)
					if(it->second){
						//cerr << "! " << it->first << " " << it->second << endl;
						ok = 0;

						}

				int qnt = 0;

				for(int j=0;j<l;j++)
					if(muda[j])
						qnt++;

				if(ok)
					ans = min(ans, qnt);
				
				

				}

			printf("Case #%d: ",te);

			if(ans == 999999)
				printf("NOT POSSIBLE\n");
			else
				printf("%d\n",ans);
				


		
		}


}
