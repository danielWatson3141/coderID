#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
#include <fstream>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

int n;
vector<int> g[2000];
bool vi[2000];

int getans(int i){
	vi[i]=true;
	vector<int> s;s.clear();
	for (int z=0;z<g[i].size();z++){
		int j=g[i][z];
		if (vi[j]) continue;
		s.PB(getans(j));
	}
	if (s.size()<2) {
		//cout<<i<<' '<<1<<endl;
		return 1;
	}
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	//cout<<i<<' '<<1+s[0]+s[1]<<endl;
	return 1+s[0]+s[1];
}

int main(int argc,char** argv){
	int T;
	scanf("%d",&T);
	for (int r=1;r<=T;r++){
		printf("Case #%d: ",r);
		scanf("%d",&n);
		for (int i=0;i<n;i++) g[i].clear();
		for (int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a--;b--;
			g[a].PB(b);
			g[b].PB(a);
		}
		int ans=0;
		for (int i=0;i<n;i++) {
			memset(vi,false,sizeof(vi));
			int k=getans(i);
			ans=max(ans,k);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}