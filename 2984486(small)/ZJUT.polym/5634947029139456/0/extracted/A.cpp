/*************************************************************************
Author: zjut_polym
Created Time:   2014/4/12 21:35:53
File Name: B.cpp
************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
#include <queue>
using namespace std;


//----------------------[ZJUT-polym for div2]-------------------------------------
#define ll long long
#define MOD 1000000007
#define PII pair<int, int>
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define _mst(buf, val) memset(buf, val, sizeof(buf))
#define rep(i, l, r) for(i = (l); i <= (r); i++)
#define srep(i, l, r) for(i = (l); i >= (r); i--)
#define repi(it, c) for(typeof(c.begin())it = c.begin(); it != c.end(); it++)
#define inf 0x3f3f3f3f
#define N 100005
#define eps 1e-8
#define pi (2.0 * acos(0.0))
//--------------------------------------------------------------------------------

char ma[25][25], tar[25][25];
bool vis[25];
int main() {
	int T, cas = 1;
	cin >> T;
	while(T--){
		printf("Case #%d: ", cas++);
		int n, L, ans;
		cin >> n >> L;
		ans = inf;
		for(int i = 0; i < n; i++){
			scanf("%s", ma[i]);
		}
		for(int i = 0; i < n; i++){
			scanf("%s", tar[i]);
		}
		for(int i = 0; i < (1<<L); i++){
			int st = i, c = 0;
			memset(vis, 0, sizeof(vis));
			for(int j = 0; j < L; j++){
				if(st & (1 << j)){
					c++;
					for(int k = 0; k < n; k++){
						if(ma[k][j] == '1') ma[k][j] = '0';
						else ma[k][j] = '1';
					}
				}
			}
			//cout << "c" << c << endl;
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					if(vis[k]) continue;
					bool flag = true;
					for(int x = 0; x < L && flag; x++){
						if(ma[j][x] != tar[k][x]){
							flag = false;
						}
					}
					if(flag) vis[k] = 1;
				}
			}
			bool f = true;
			for(int j = 0; j < n && f; j++){
				if(vis[j] == 0) f = false;
			}
			if(f){
				ans = min(ans, c);
			}
			for(int j = 0; j < L; j++){
				if(st & (1 << j)){
					for(int k = 0; k < n; k++){
						if(ma[k][j] == '1') ma[k][j] = '0';
						else ma[k][j] = '1';
					}
				}
			}
		}
		if(ans == inf){
			puts("NOT POSSIBLE");
		}
		else
		cout << ans << endl;
	}
    return 0;
}

