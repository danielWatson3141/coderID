#include<iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1010;
int n;
vector<int> adj[maxn];

int mark[maxn];

pair<int,int> getans(int x) {
	mark[x] = 1;
	vector<pair<int,int> > ans;
	for(int i=0;i<adj[x].size();i++) {
		if (!mark[adj[x][i]]) {
			ans.push_back(getans(adj[x][i]));
		}
	}
	int sum = 0;
	for(int i=0;i<ans.size();i++) {
		sum+=ans[i].second;
	}
	if (ans.size()==0)
		return pair<int,int>(0,sum+1);
	if (ans.size()==1)
		return pair<int,int>(ans[0].second, sum+1);
	int best = sum;
	for(int i=0;i<ans.size();i++) {
		for(int j=i+1;j<ans.size();j++) {
			int tmp = sum-ans[i].second-ans[j].second+ans[i].first+ans[j].first;
			if (tmp<best)
				best = tmp;
		}
	}
	return pair<int,int>(best, sum+1);
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		cin>>n;
		for(int i=1;i<=n;i++)
			adj[i].clear();
		for(int i=0;i<n-1;i++) {
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ans = n-1;
		for(int i=1;i<=n;i++) {
			memset(mark,0,sizeof mark);
			pair<int,int> temp = getans(i);
			if (temp.first<ans)
				ans = temp.first;
		}
		cout<<"Case #"<<tn+1<<": "<<ans<<endl;
	}
}
