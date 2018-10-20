#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
//#define LARGE 1

int n;
vector<vector<int> > v;

pair<int, int> dp[1010][1010];

pair<int,int> f(int r, int p) {
	pair<int,int>& ans = dp[r][p];
	if(ans.first != -1)
		return ans;
	int next;
	pair<int,int> temp;
	ans.second = 1;
	int T = 0;
	vector<int> k;
	for(int i=0;i<v[r].size();i++) {
		next = v[r][i];
		if(next == p)
			continue;
		temp = f(next, r);
		ans.second += temp.second;
		T += temp.second;
		k.push_back(temp.first-temp.second);
	}
	sort(k.begin(), k.end());
	if(k.size() < 2) {
		ans.first = T;
	}else {
		ans.first = T+k[0]+k[1];
	}
	return ans;
}

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large.o", "wt", stdout);
#elif SMALL
	freopen("b_small.i", "rt", stdin);
	freopen("b_small.o", "wt", stdout);
#else
	freopen("b_sample.i", "rt", stdin);
#endif
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		cin>>n;
		v.clear();
		v.resize(n);
		int a,b;
		for(int i=0;i<n-1;i++) {
			cin>>a>>b;
			a--; b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		memset(dp, -1, sizeof(dp));
		int best = n;
		for(int i=0;i<n;i++) {
			pair<int,int> temp = f(i, n);
			best = min(best, temp.first);
		}
		cout<<"Case #"<<tt<<": "<<best<<endl;
	}
	return 0;
}
