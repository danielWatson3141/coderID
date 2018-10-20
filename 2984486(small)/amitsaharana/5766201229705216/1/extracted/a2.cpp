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
#ifdef amit
#include <conio.h>
#endif
using namespace std; 
 
#define ll long long 
#define gc getchar
#define pc putchar 
#define endl '\n'


vector<vector<int> > g;

int go(int x, int p) {
	int m1=0, m2=0;
	for(int i=0; i<g[x].size(); i++) {
		if(g[x][i]==p) continue;
		int y = go(g[x][i],x);
		if(y>m2) { m1 = m2; m2 = y; }
		else if(y>m1) m1 = y;
	}
	if(m1==0 || m2==0) return 1;
	return 1+m1+m2;
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
		g.clear();
		int n;
		cin>>n;
		g.resize(n+1);
		int ret = 0;
		for(int i=0; i<n-1; i++) {
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for(int i=1; i<=n; i++) {
			ret = max(ret,go(i,0));
			//cout<<i<<" "<<go(i,0)<<endl;
		}
		cout<<n-ret<<endl;
	}
	return 0;
}