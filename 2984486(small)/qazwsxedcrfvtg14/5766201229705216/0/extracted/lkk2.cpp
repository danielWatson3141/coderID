#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
#define f first
#define s second
using namespace std;
//using namespace __gnu_pbds;
typedef std::pair<int,int> par;
vector<int> nod[1005];
par F(int now,int f){
	int sz=nod[now].size();
	int kid=1,cut=0;
	vector<int> ve;
	for(int i=0;i<sz;i++){
		if(nod[now][i]==f)continue;
		par x=F(nod[now][i],now);
		kid+=x.s;
		ve.push_back(x.f-x.s);
		cut+=x.s;
		}
	sort(ve.begin(),ve.end());
	if(ve.size()>=2){
		cut+=ve[0];
		cut+=ve[1];
		}
	//printf("~%d %d %d %d\n",now,f,cut,kid);
	return par(cut,kid);
	}
int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){T++;
		int n;
		scanf("%d",&n);
		int a,b;
		memset(nod,0,sizeof(nod));
		for(int i=1;i<n;i++){
			scanf("%d%d",&a,&b);
			nod[a-1].push_back(b-1);
			nod[b-1].push_back(a-1);
			}
		int ans=0x7fffffff;
		for(int i=0;i<n;i++){
			ans=min(F(i,-1).f,ans);
			}
		printf("Case #%d: ",T);
		printf("%d\n",ans);
		}
	return 0;
	}
