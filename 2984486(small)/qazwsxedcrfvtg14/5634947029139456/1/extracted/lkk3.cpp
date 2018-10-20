#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
#define f first
#define s second
using namespace std;
//using namespace __gnu_pbds;
typedef std::pair<long long int,long long int> par;
long long int ar[2][200];
char s[100];
map<long long int,bool>mp;
int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){T++;
		memset(ar,0,sizeof(ar));
		int n,l;
		scanf("%d%d",&n,&l);
		mp.clear();
		for(int i=0;i<n;i++){
			scanf("%s",s);
			for(int j=0;j<l;j++){
				ar[0][i]|=(s[j]-'0')<<j;
				}
			if(i)mp[ar[0][i]]=1;
			}
		for(int i=0;i<n;i++){
			scanf("%s",s);
			for(int j=0;j<l;j++){
				ar[1][i]|=(s[j]-'0')<<j;
				}
			}
		printf("Case #%d: ",T);
		int ans=0x7fffffff;
		for(int i=0;i<n;i++){
			long long int x=ar[1][i]^ar[0][0];
			bool ok=1;
			for(int j=0;j<n;j++){
				if(i==j)continue;
				if(!mp[ar[1][j]^x])
					ok=0;
				}
			if(ok)ans=min(ans,__builtin_popcountll(x));
			}
		if(ans==0x7fffffff)
			puts("NOT POSSIBLE");
		else
			printf("%d\n",ans);
		}
	return 0;
	}
