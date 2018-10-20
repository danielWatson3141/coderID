#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#define NAME "A-small-attempt0"
using namespace std;
int T;
int n,l;
int a[200],b[200],o[200];
string s;
int main(){
	freopen(NAME".in","rt",stdin);
	freopen(NAME".out","wt",stdout);
	cin>>T;
	for(int I=1;I<=T;I++) {
		printf("Case #%d: ",I);
		cin>>n>>l;
		for(int i=0;i<n;i++) {
			cin>>s;
			a[i]=0;
			for(int j=0;j<l;j++){
				a[i]+=(1<<j)*(s[l-1-j]-'0');
			}
		} 
		for(int i=0;i<n;i++) {
			cin>>s;
			o[i]=0;
			for(int j=0;j<l;j++) {
				o[i]+=(1<<j)*(s[l-1-j]-'0');
			}
		}
		sort(o,o+n);
		int ans=10000;
		for(int sw=0;sw<(1<<l);sw++) {
			for(int i=0;i<n;i++) {
				b[i]=a[i]^sw;
			}
			sort(b,b+n);
			bool ok=1;
			for(int i=0;i<n;i++) {
				ok=ok&(o[i]==b[i]);
			}
			if(ok) {
				int S=sw;
				int aaa=0;
				while(S) {
					aaa+=(S&1);
					S/=2;
				}
				ans=min(ans,aaa);
			}
		}
		if(ans==10000) cout<<"NOT POSSIBLE\n";
		else cout<<ans<<'\n';
	}
	return 0;
}