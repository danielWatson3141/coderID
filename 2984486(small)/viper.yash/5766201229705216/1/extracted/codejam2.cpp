//IamAwesome
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>
#include <ctype.h>
#include <utility>
#include <cstdlib>
#include <functional>
#include <numeric>


using namespace std;

#define LL long long
#define linf 998877665544332211ll
#define inf 987654321ll
#define MOD 1000000007ll
#define ADD(ad_list) accumulate(ad_list.begin(),ad_list.end(), 0)
#define PRO(ad_list) accumulate(ad_list.begin(),ad_list.end(), 1,multiplies <int>())
LL POS(LL x) { if (x > 0)  return x; else return 0; }
#define maxe(ad_list) max_element(ad_list.begin(),ad_list.end())
#define mine(ad_list) min_element(ad_list.begin(),ad_list.end())
#define rep(k,a,b) for(int k=(a); k < (b); ++k)
#define per(k,a,b) for(int k=(b-1); k >= (a); --k)
#define repg(k,ctnr) for(auto k=ctnr.begin();k!=ctnr.end();k++)
#define all(ctnr) (ctnr).begin(),(ctnr).end()


int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

vector<list<int> > grid;
vector<bool> vis_array;
void dfs(vector<list<int> > &grid, int s, vector<int> &depth, int lev){
	int l = grid.size();
	list<int> ::iterator itl;
	depth[s] = lev;
	for (itl = grid[s].begin(); itl != grid[s].end(); itl++){
		if (depth[*itl] == -1){
			dfs(grid, *itl, depth, lev + 1);
		}
	}
}

int dfs2(int root, bool used){
	int res=0;
	vector<int> temp_array;
	list<int> ::iterator itl;
	int l = grid[root].size();
	if (!used && l == 1)return 1;if (used && l == 0)return 1;
	if (l + used <= 2)return 1;
	vis_array[root] = 1;
	for (itl = grid[root].begin(); itl != grid[root].end(); itl++)
		if (vis_array[*itl]==0)temp_array.push_back(dfs2(*itl, 0));
	sort(all(temp_array));
	res = temp_array[temp_array.size()-1] + temp_array[temp_array.size()-2] + 1;
	return res;
}
int main(){
	int t;
	cin >> t;
	int g = 1;
	while (t--){
		int n;
		cin >> n;
		int res = 0;
		int p, q;
		vector<list<int> > ad_list(n);
		vector<bool> vv(n, 0);
		rep(i,0,n-1){
			cin >> p >> q;
			p--; q--;
			ad_list[p].push_back(q);
			ad_list[q].push_back(p);
		}
		grid = ad_list;
		rep(i,0,n){
			vis_array = vv;
			res = max(res, dfs2(i,1));
		}
		res = n - res;
		cout << "Case #" << g << ": " << res << endl;
		g++;
	}
	return 0;
}