#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>

using namespace::std;

int n,l;
long long ans,ans1;
long long a[1005];
long long b[1005];

void input(){
	scanf("%d %d",&n,&l);
	map<long long,int> cnt;
	for(int i1=0;i1<n;i1++){
		string in;
		cin>>in;
		a[i1]=0;
		for(int i=0;i<in.size();i++)
			a[i1]=2*a[i1]+in[i]-'0';
	}
	for(int i1=0;i1<n;i1++){
		string in;
		cin>>in;
		b[i1]=0;
		for(int i=0;i<in.size();i++)
			b[i1]=2*b[i1]+in[i]-'0';
	}
	ans=214000000000;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cnt[a[i]^b[j]]++;
			if(cnt[a[i]^b[j]]==n){
				long long now=a[i]^b[j],an=0;
				while(now!=0){
					an+=now%2;
					now/=2;
				}
				ans=min(an,ans);
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ca=0,t;
	scanf("%d",&t);
	while(t--){
		input();
		printf("Case #%d: ",++ca);
		if(ans==214000000000) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}