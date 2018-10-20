//Programmer: Amit Saharana, IIT Delhi 
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
#include <fstream> 
#include <cassert> 
using namespace std; 
 
#define ll long long 
#define gc getchar
#define pc putchar 
#define endl '\n'

string c;
int l;

bool go(vector<string> a, vector<string> b, int p) {
	if(a.size()!=b.size()) return false;
	if(max(a.size(),b.size())==0) return true;
	if(p==l) return true;
	vector<string> a0,a1,b0,b1;
	for(int i=0; i<b.size(); i++) {
		if(b[i][p]=='0') b0.push_back(b[i]);
		else if(b[i][p]=='1') b1.push_back(b[i]);
	}
	if(c[p]=='0') {
		for(int i=0; i<a.size(); i++) {
			if(a[i][p]=='0') a0.push_back(a[i]);
			else if(a[i][p]=='1') a1.push_back(a[i]);
		}
	}
	else {
		for(int i=0; i<a.size(); i++) {
			if(a[i][p]=='0') a1.push_back(a[i]);
			else if(a[i][p]=='1') a0.push_back(a[i]);
		}
	}
	bool f1 = go(a0,b0,p+1);
	if(!f1) return false;
	bool f2 = go(a1,b1,p+1);
	if(!f2) return false;
	return true;
}

int main(){
#ifdef amit
	freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout); 
	freopen("err.txt","w",stderr); 
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	for(int z=1; z<=t; z++) {
		cout<<"Case #"<<z<<": ";
		int n;
		cin>>n>>l;
		int ret = 1e9;
		bool f= false;
		vector<string> a,b;
		a.resize(n); b.resize(n);
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=0; i<n; i++) cin>>b[i];
		for(int i=0; i<n; i++) {
			c = "";
			int tot = 0;
			for(int j=0; j<l; j++) {
				if(a[0][j]==b[i][j]) c+="0";
				else {
					c+="1";
					tot++;
				}
			}
			if(go(a,b,0)) {
				f = true;
				ret = min(ret,tot);
			}
		}
		if(f) cout<<ret<<endl;
		else cout<<"NOT POSSIBLE"<<endl;
	}
	return 0;
}