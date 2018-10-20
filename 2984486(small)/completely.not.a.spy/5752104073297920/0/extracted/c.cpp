#include <iostream>
#include <cstdio>
#define NAME "C-small-attempt0"
using namespace std;
int T;
int main(){
	freopen(NAME".in","rt",stdin);
	freopen(NAME".out","wt",stdout);
	cin>>T;
	for(int I=1;I<=T;I++) {
		printf("Case #%d: ",I);
		int n,a;
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>a;
			if(!i) {
				if(!a) cout<<"BAD\n";
				else cout<<"GOOD\n";
			}
		}
	}
	return 0;
}