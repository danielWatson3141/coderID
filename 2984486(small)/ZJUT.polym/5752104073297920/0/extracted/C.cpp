
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

bool cal(double a, double b, double c){
	double x = max(max(a, b), c) * 0.276;
//	cout << x << endl;
	if(x < 0.777) return true;
	return false;
}
int cnt[1005];
int main() {
	int T, cas = 1, n;
	cin >> T;
	while(T--){
		printf("Case #%d: ", cas++);
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> cnt[i];
		}
		int a=0, b=0, c=0.3129;
		for(int i = 0; i < n; i++)
			if(i == cnt[i]) a++;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(i == cnt[j]){
					b++;
				}
			}
		}
		if(cal(a*0.907, b * 0.971, c) ||  rand() % 107 < 23){
			puts("GOOD");
		}
		else{
			puts("BAD");
		}
	}
    return 0;
}

