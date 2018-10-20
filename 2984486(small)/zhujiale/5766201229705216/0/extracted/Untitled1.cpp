#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <queue>
#define INF 200000000000LL
#define M 1000000007LL

using namespace std;

int n;
int num[1500];
vector <int> mat[1500], tree[1500];
int v[1500], f[1500];

void build(int x)
{
	v[x] = 1;
	for (int i = 0; i<mat[x].size(); i++){
		if (!v[mat[x][i]]){
			tree[x].push_back(mat[x][i]);
		}
	}
	for (int i = 0; i<tree[x].size(); i++){
		build(tree[x][i]);
	}
}

int cnt(int x){
	if (num[x]>0) return num[x];
	int res = 1;
	for (int i = 0; i<tree[x].size(); i++){
		res += cnt(tree[x][i]);
	}
	num[x] = res;
	return res;
}

int calc(int x)
{
	if (f[x]!=-1) return f[x];
	int res = num[x]-1;
	int max1, max2, node1, node2;
	max1 = max2 = 0;
	node1 = node2 = -1;
	if (tree[x].size()==0) return 0;
	else if (tree[x].size()==1) return num[tree[x][0]];
	else if (tree[x].size()==2) return (calc(tree[x][0])+calc(tree[x][1]));
	else{
		int all = 0;
		for (int i = 0; i<tree[x].size(); i++)
			all += num[tree[x][i]];
		for (int i = 0; i<tree[x].size(); i++){
			for (int j = i+1; j<tree[x].size(); j++){
				int a = tree[x][i];
				int b = tree[x][j];
				res = min(res, calc(a)+calc(b)+all-num[a]-num[b]);
			}
		}
	}
	f[x] = res;
	return res;
}

int main()
{
	int T;
	cin>>T;
	int ttt = 0;
	while (T--){
		ttt++;
		cin>>n;
		for (int i = 1; i<=n; i++) mat[i].clear();
		int x, y;
		for (int i = 1; i<n; i++){
			cin>>x>>y;
			mat[x].push_back(y);
			mat[y].push_back(x);
		}
		int res = n;
		for (int i = 1; i<=n; i++){
			memset(v, 0, sizeof(v));
			memset(num, 0, sizeof(num));
			memset(f, -1, sizeof(f));
			for (int j = 1; j<=n; j++) tree[j].clear();
			build(i);
			cnt(i);
			res = min(res, calc(i));
		}
		cout<<"Case #"<<ttt<<": "<<res<<endl;
	}
}