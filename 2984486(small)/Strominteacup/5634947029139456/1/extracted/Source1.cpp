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
		int n, l;
		cin >> n >> l;
		vector<ll> have(n);
		vector<ll> chave(n);
		vector<ll> need(n);
		vector<ll> cneed(n);
		set<ll> cshave;
		int min = inf;
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
			ll c = 0;
			int bc = 0;
			while (bc < s.size()){
				char t = s[bc];
				if (t != '0')
					c |= (1 << bc);
				bc++;
			}
			have[i] = c;
			chave[i] = c;
		}
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
			ll c = 0;
			int bc = 0;
			while (bc < s.size()){
				int t = s[bc];
				if (t != '0')
					c |= (1 << bc);
				bc++;
			}
			need[i] = c;
			cneed[i] = c;
		}
		for (int i = 0; i < n; i++){
			int count = 0;
			if (have[i] != need[0]){
				for (int j = 0; j < l; j++){
					int f = (1 << j) & have[i];
					int s = (1 << j) & need[0];
					if (f != s){
						count++;
						for (int k = 0; k < n; k++)
							have[k] ^= (1 << j);
					}
				}
			}
			for (int j = 0; j < n; j++)
				cshave.insert(have[j]);

			bool can = true;
			for (int j = 0; j < n && can; j++){
				if (cshave.find(need[j]) == cshave.end())
					can = false;
			}
			if (can){
				if (min > count)
					min = count;
			}
			have = chave;
			need = cneed;
			cshave.clear();
		}
		if (min == inf)
			cout << "NOT POSSIBLE" << endl;
		else cout << min << endl;
	}
	return 0;
}