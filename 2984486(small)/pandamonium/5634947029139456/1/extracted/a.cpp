#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i=0,t,n,l;
ll power1[155],power2[155];
bool flip[50];
char str[50];
vector <ll> v,v2;
int main(){
	scanf("%d",&t);
	while(t--){
		int ans=200;
		memset(power1,0,sizeof(power1));
		memset(power2,0,sizeof(power2));
		scanf("%d %d",&n,&l);
		for(int x=0;x<n;x++){
			scanf("%s",str);
			for(int y=0;y<l;y++) if(str[y]=='1') power1[x]|=(1ll<<y);
		}
		v2.clear();
		for(int x=0;x<n;x++){
			scanf("%s",str);
			for(int y=0;y<l;y++) if(str[y]=='1') power2[x]|=(1ll<<y);
			v2.push_back(power2[x]);
		}
		sort(v2.begin(),v2.end());
		for(int x=0;x<n;x++){
			int cnt=0;
			memset(flip,0,sizeof(flip));
			for(int y=0;y<l;y++){
				if(str[y]=='1'){
					if(!(power1[x]&(1ll<<y))){
						flip[y]=1;
						++cnt;
					}
				}
				else if(power1[x]&(1ll<<y)){
					flip[y]=1;
					++cnt;
				}
			}
			v.clear();
			for(int y=0;y<n;y++){	
				ll temp=power1[y];
				for(int z=0;z<l;z++) if(flip[z]) temp^=(1ll<<z);
				v.push_back(temp);
			}
			sort(v.begin(),v.end());
			bool fail=0;
			for(int y=0;y<n;y++){
				if(v[y]!=v2[y]) break;
				if(y==n-1) ans=min(ans,cnt);
			}
		}
		if(ans==200) printf("Case #%d: NOT POSSIBLE\n",++i);
		else printf("Case #%d: %d\n",++i,ans);			
	}
	return 0;
}
