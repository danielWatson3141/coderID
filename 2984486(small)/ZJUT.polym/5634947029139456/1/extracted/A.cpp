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

string ma[300], tar[300], tmp[300];
bool vis[300];
int main() {
	int T, cas = 1;
	cin >> T;
	while(T--){
		printf("Case #%d: ", cas++);
		int n, L, ans;
		cin >> n >> L;
		ans = inf;
		for(int i = 0; i < n; i++){
			cin >> ma[i];
		}
		for(int i = 0; i < n; i++){
			cin >> tar[i];
		}
		sort(tar, tar + n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				string t = "";
				int c = 0;
				for(int k = 0; k < L; k++){
					if(ma[i][k] != tar[j][k]) {t += '1'; c++;}
					else t += '0';
				}
				for(int k = 0; k < n; k++){
					tmp[k] = ma[k];
					for(int x = 0; x < L; x++){
						if(t[x] == '1'){
							if(tmp[k][x] == '1') tmp[k][x] = '0';
							else tmp[k][x] = '1';
						}
					}
				}
				sort(tmp, tmp + n);
				bool flag = true;
				for(int k = 0; k < n && flag; k++){
					if(tmp[k] != tar[k]) flag = false;
				}
				if(flag) ans = min(ans, c);
			}
		}
		if(ans == inf)
			cout << "NOT POSSIBLE" << endl;
		else
		cout << ans << endl;

	}
    return 0;
}

