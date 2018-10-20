#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <cassert>
#include <iomanip>
using namespace std;
static const double EPS = 1e-9;
static const int mod = 100000007;
typedef long long ll;

int t;
vector<int> tree[1111];

int dfs(int parent,int node){
	int size=tree[node].size();
	//cerr<<"node:"<<node<<" size:"<<size<<endl;
	if(size<=1 || (parent!=-1 && size==2))return 1;
	vector<int> buf;
	for(int i=0;i<size;i++){
		if(parent!=tree[node][i]){
			buf.push_back(dfs(node,tree[node][i]));
		}
	}
	sort(buf.begin(),buf.end());
	return 1+buf[buf.size()-1]+buf[buf.size()-2];
}

int main() {
	// freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Case #"<<(i+1)<<": ";
		int n;
		cin>>n;
		for(int i=0;i<1111;i++)tree[i].clear();
		for(int j=0;j+1<n;j++){
			int node1,node2;
			cin>>node1>>node2;
			tree[node1].push_back(node2);
			tree[node2].push_back(node1);
		}
		if(n==2){
			cout<<1<<endl;
			continue;
		}
		int res=n;
		for(int j=1;j<=n;j++){
			int x=dfs(-1,j);
			//cout<<j<<" "<<x<<endl;
			res=min(res,n-x);
		}
		cout<<res<<endl;
	}
}