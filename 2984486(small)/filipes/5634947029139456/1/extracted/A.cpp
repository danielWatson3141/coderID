#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		string s;

		int n,l,mm=10000;
		cin>>n>>l;
		vector<string> a(n),b(n),a1;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		a1=a;
		bool ok;
		set<string> bb;
		for(int i=0;i<n;i++) bb.insert(b[i]);
		for(int i=0;i<n;i++){
			ok=0;
			int kolo=0;
			for(int j=0;j<n;j++){

				for(int k=0;k<l;k++){
					if(a[i][k]!=b[0][k]){ if(j==0) kolo++; if(a[j][k]=='0'){a1[j][k]='1';}else a1[j][k]='0';  }
					else{ if(a[j][k]=='0'){a1[j][k]='0';}else a1[j][k]='1';   }
				}
			}
			set<string> aa;
			for(int i=0;i<n;i++) aa.insert(a1[i]);
			if(aa==bb){
				mm=min(mm,kolo);

			}

		}
		if(mm==10000){
			printf("Case #%d: NOT POSSIBLE\n",t+1);
		}
		else printf("Case #%d: %d\n",t+1,mm);

	}


	return 0;
}
