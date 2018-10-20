#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstring>

#define ll long long
#define ld long double
#define vi vector<int>
#define vvi vector<vi >
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii >
#define vb vector<bool>
#define min(x,y) (x < y ? x : y)
#define min3(x,y,z) (min(x,min(y,z)))
#define max(x,y) (x > y ? x : y)
#define max3(x,y,z) (max(x,max(y,z)))
#define loop(i,n) for(int i = 0;i < n;i++)
#define sqrt(x) (pow(x,0.5))
#define sqr(x) (x * x)
#define mp make_pair
#define TASKNAME ""

const int inf = 1e9;
const ll infll = 1e18;
const int mod = 1e9 + 7;
const ld eps = 1e-9;

using namespace std;

vvi g;
vi used;
int version = 1;
int cc = 0;

void dfs(int v, bool f){
	if (f){
		if (g[v].size() == 1){
			cc++;
			return;
		}
	}
	else {
		if (g[v].size() == 2){
			cc++;
			return;
		}
	}
	for (int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if (used[to] < version){
			used[to] = version;
			dfs(to, false);
		}
	}
}

int main(){
	freopen("INPUT.TXT", "r", stdin); freopen("OUTPUT.TXT", "w", stdout);
	int testsi;
	cin >> testsi;
	for (int testcount = 0; testcount < testsi; testcount++){
		cout << "Case #" << (testcount + 1) << ": ";
		int n;
		cin >> n;
		vi s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int r = rand() % 100;
		if (r >= 50)
			cout << "GOOD";
		else cout << "BAD";
		cout << endl;
	}
	return 0;
}