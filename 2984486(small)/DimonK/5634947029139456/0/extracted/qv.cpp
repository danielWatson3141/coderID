#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int tests;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>tests;
	for (int test=0; test<tests; test++){
		int n,l;
		cin>>n>>l;
		vector<string>a;
		for (int i=0; i<n; i++){
			string k;
			cin>>k;
			a.push_back(k);
		}
		vector<string>b;
		for (int i=0; i<n; i++){
			string k;
			cin>>k;
			b.push_back(k);
		}	
		cout<<"Case #"<<test+1<<": ";
		sort(b.begin(),b.end());
		int ans3=150;

		for(int mask = 0; mask < (1 << l); mask++){
        vector<string>c=a;
		
		int ans2=0;
		for (int i=0; i<n; i++){
		ans2=0;
		for (int j=0; j<l; j++)
			if (mask & (1<<j)){
			    if (c[i][j]=='0') c[i][j]='1';
				else c[i][j]='0';
				ans2++;
			}
		}
		int ans=0;
		sort(c.begin(),c.end());
	    for (int i=0; i<n; i++){
			if (c[i]==b[i]) ans++;
		}
	

		if (ans==n) {
			ans3=min(ans2,ans3);
		}
		
		}
		if (ans3==150)
		cout<<"NOT POSSIBLE"<<endl;
		else cout<<ans3<<endl;
	}



    return 0;

}