#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
int main(){
	int t;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);	
	for(int T=1;T<=t;T++){
		printf("Case #%d: ",T);
		int n,l;
		scanf("%d%d",&n,&l);
		vector<int> sw,dc;
		for(int i=0;i<n;i++){
			string a;
			cin>>a;
			int na=0;
			reverse(a.begin(),a.end());
			int l=a.length();
			for(int _i=0;_i<l;_i++) {
				na<<=1;
				na+=a[_i]=='1'?1:0;
			}
			sw.push_back(na);
		}
		for(int i=0;i<n;i++){
			string a;
			cin>>a;
			int na=0;
			reverse(a.begin(),a.end());
			int l=a.length();
			for(int _i=0;_i<l;_i++) {
				na<<=1;
				na+=a[_i]=='1'?1:0;
			}
			dc.push_back(na);
		}
		sort(dc.begin(),dc.end());
		int ans=1000;
		for(int mask=0;mask<1<<l;mask++){
			int res=mask;
			int j=0;
			int sh[l];
			memset(sh,0,sizeof(sh));
			int cmp=0;
			while(res>0){
				if(res&1){
					cmp++;
					sh[j]=1; 	
				}
				res>>=1;
				j++;
			}
			vector<int>cpy(n,0);
			copy(sw.begin(),sw.end(),cpy.begin());
			for(int j=0;j<l;j++){
				if(sh[j]){
					for(int i=0;i<n;i++){
						cpy[i]^=(1<<j);
						//cpy[i][j]=(cpy[i][j]=='0'?'1':'0');
					}
				}
			}
			sort(cpy.begin(),cpy.end());
			assert(cpy.size()==n);
			int ok=1;
			for(int i=0;i<n;i++){
				if(cpy[i]!=dc[i])ok=0;
			}
			if(ok==1) ans=min(ans,cmp);
		}
		if(ans==1000) puts("NOT POSSIBLE");
		else printf("%d\n",ans);
	}
}
