#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int n,l;
int T;
vector<string> b1;
vector<string> b2;
int main(){
	cin >> T;
	for(int t=0;t<T;t++){
		cout << "Case #" << t+1 << ": ";
		cin >> n >> l;
		char c1,c2;
		int res =-1;
		b1.clear();
		b2.clear();
		string s;
		for(int i=0;i<n;i++){
			cin >> s;
			b1.push_back(s);
		}
		
		for(int i=0;i<n;i++){
			cin >> s;
			b2.push_back(s);
		}
		sort(b2.begin(),b2.end());
		int mini = 100;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				long long mask =0LL;
				int c=0;
				vector<string> t2;
				for(int k=0;k<l;k++)
					if(b1[i][k]!=b2[j][k])
						mask+=1LL<<k,c++;
				if(b2==t2) mini = min(c,mini);
				int sz=0;
				for(int k=0;k<n;k++){
					t2.push_back(b1[k]);
					for(int l1=0;l1<l;l1++){
						if(mask & (1LL<<l1)){
							if(t2[sz][l1]=='0') t2[sz][l1]='1';
							else t2[sz][l1]='0';
						}
					}
					sz++;
				}
				sort(t2.begin(),t2.end());
				if(b2==t2) mini = min(c,mini);
			
			}
		}
		if(mini==100) cout << "NOT POSSIBLE";
		else cout << mini;
	
		cout << endl;
	}	
	return 0;
}
