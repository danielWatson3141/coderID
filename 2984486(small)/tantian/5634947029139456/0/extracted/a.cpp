#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

string s;
int aa[200], bb[200], ta[200];
int n,l;

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		scanf("%d%d", &n,&l);
		//printf("###%d %d\n", n,l);
		for (int i=0; i<n; ++i){
			cin>>s; aa[i]=0;
			for (int j=0; j<l; ++j)
				aa[i]=aa[i]*2+(s[j]=='1');
		}
		for (int i=0; i<n; ++i){
			cin>>s; bb[i]=0;
			for (int j=0; j<l; ++j)
				bb[i]=bb[i]*2+(s[j]=='1');
		}
		sort(bb,bb+n);
		int ans=-1;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j){
				int t=aa[i]^bb[j];
				for (int k=0; k<n; ++k)
					ta[k]=aa[k]^t;
				sort(ta,ta+n);
				int ok=1;
				for (int k=0; k<n; ++k)
					if (ta[k]!=bb[k]){ ok=0; break; }
				if (ok){
					//printf("%d\n", t);
					int ret=0;
					for (int k=0; k<l; ++k)
						if (t&(1<<k))++ret;
					if (ans==-1 || ret<ans) ans=ret;
				}
			}
		printf("Case #%d: ", T);
		if (ans==-1) printf("NOT POSSIBLE\n"); else printf("%d\n", ans);
	}
}
