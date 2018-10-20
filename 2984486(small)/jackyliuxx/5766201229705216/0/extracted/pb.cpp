//by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;

vector<int> v[1010];

int main () {
	int t,k=1;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int i,x,y;
		for(i=1;i<=n;i++)
			v[i].clear();
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ct=0;
		for(i=1;i<=n;i++)
			if(v[i].size()!=1 && v[i].size()!=3)
				ct++;
		printf("Case #%d: %d\n",k++,ct-1);
	}
}
