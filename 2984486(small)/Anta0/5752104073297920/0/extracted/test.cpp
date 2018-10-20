#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

//#define TEST
unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

long double dp[1001][1001];
long double table[1000][1000];
int a[1000];
int main() {
	const int N = 1000;
//	cerr << "dp table:" << endl;
	rep(i, N) {
		if(i % 10 == 0) cerr << "table " << i << "..." << endl;
		mset(dp, 0);
		dp[0][i] = 1;
		rep(k, N) rep(j, N) {
			long double x = dp[k][j];
			if(x == 0) continue;
			//(k, l)を選ぶ
			if(k == j) {
				rep(l, N)
					dp[k+1][l] += x / N;
			}else {
				//jが選ばれない場合
				dp[k+1][j] += x * (N-1) / N;
				//jが選ばれる場合
				dp[k+1][k] += x / N;
			}
		}
//		cerr << i << ": ";
//		rep(j, N) fprintf(stderr, "%03.1f%% ", dp[N][j] * 100);
//		cerr << endl;
		rep(j, N) table[i][j] = dp[N][j];
	}
	int T;
	scanf("%d", &T);
	vector<bool> gb(T);
	vector<pair<long double,int> > tests;
	rep(ii, T) {
#ifndef TEST
		int NN;
		scanf("%d", &NN);
		if(NN != N) cerr << "Error!!!" << endl;
		rep(i, N) {
			scanf("%d", &a[i]);
		}
#else
		rep(i, N) a[i] = i;
		if(xor128() % 2 == 0) {
			gb[ii] = false;
			rep(i, N)
				swap(a[i], a[N-1 - xor128() % (N-i)]);
		}else {
			gb[ii] = true;
			rep(i, N)
				swap(a[i], a[xor128() % N]);
		}
#endif
		long double p = 0;
		rep(i, N) {
			long double q = 1;
			rep(j, i) q -= table[a[i]][a[j]];
			p += log(table[a[i]][i] / q);
		}
		//rep(i, N) cerr << a[i] << ", ";
//		cerr << ": " << exp(p) << endl;
		tests.push_back(mp(p, ii));
	}
	vector<bool> ans(T);
	sort(all(tests)); reverse(all(tests));
	rep(ii, T / 2) ans[tests[ii].second] = true;
#ifdef TEST
	int okcnt = 0;
#endif
	rep(ii, T) {
//		cerr << ii << ": " << gb[ii] << ", " << ans[ii] << ", " << (gb[ii] == ans[ii] ? "OK" : "NG") << endl;
#ifdef TEST
		okcnt += gb[ii] == ans[ii];
#else
		printf("Case #%d: %s\n", ii+1, ans[ii] ? "BAD" : "GOOD");
#endif
	}
#ifdef TEST
	cerr << "okcnt: " << okcnt << endl;
#endif
	return 0;
}
