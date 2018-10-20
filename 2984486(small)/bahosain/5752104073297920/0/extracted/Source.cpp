#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<stdio.h>
#include<map>
#include<set>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<sstream>
#include<time.h>
using namespace std;
typedef long long ll;
ll ABS(ll x){
	if (x<0)return -x;
	return x;
}
ll gcd(ll a, ll b){
	if (!b)
		return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return b / gcd(a, b)*a;
}
#define FOR(I,N) for(int(i)=0;i<int(N);++i)
#define FORK(I,N,K) for(int(i)=0;i<int(N);i+=int(K))
int t, n,b[1001], a[1001],g[1001];
int main(){
	freopen("C-small-attempt4.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	srand(time(NULL));
	scanf("%d", &t);
	for (int c = 1; c <= t; ++c){
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i){
			scanf("%d", a + i);
			b[i] = g[i] = i - 1;
		}
		for (int i = 0; i<n ; ++i){
			int idx = rand() % n;
			swap(b[i+1], b[idx+1]);
		}
		for (int i = 0; i<n ; ++i){
			int idx = rand() % max(n - 1 - i, 1) + i;
			swap(g[i+1], g[idx+1]);
		}
		int A = 0, B = 0;
		for (int i = 1; i <= n; ++i){
			A += g[i] == a[i];
			B += b[i] == a[i];
		}
		if (A > B)
			printf("Case #%d: GOOD\n", c);
		else printf("Case #%d: BAD\n", c);
	}
}