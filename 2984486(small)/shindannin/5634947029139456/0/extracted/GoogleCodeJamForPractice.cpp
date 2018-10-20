// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

static const double EPS = 1e-9;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())
#define NG (-1)
#define BIG (987654321)

void readData(vector <ll>& container, int N, int L)
{
	for (int i = 0; i < N; ++i)
	{
		char str[10000];
		scanf("%s",str);
		for (int k = 0; k < L; ++k)
		{
			if(str[k]=='1')
			{
				container[i] |= 1LL << k;
			}
		}
	}
}



int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);


	 int T;
	 scanf("%d",&T);

	 for (int testcase = 1; testcase<=T; ++testcase)
	 {
		 int N,L;
		 scanf("%d %d" ,&N, &L);

		 vector <ll> outletBase(N);
		 vector <ll> shotaBase(N);
		
		 readData(outletBase, N, L);
		 readData(shotaBase, N, L);

		 int best = BIG;
		 for (int i = 0; i < (1LL<<(L)); ++i)
		 {
			 vector <ll> outlet(outletBase);
			 vector <ll> shota(shotaBase);

			 int numPush = 0;
			 for (int k = 0; k < L; ++k)
			 {
				 if(i&(1LL<<(k)))
				 {
					 numPush++;
					 for (int x = 0; x < N; ++x)
					 {
						 outlet[x] ^= (1LL<<(k));
					 }
				 }
			 }

			 set <ll> outletset, shotaset;

			 for (int x = 0; x < N; ++x)
			 {
				 outletset.insert(outlet[x]);
				 shotaset.insert(shota[x]);
			 }

			 if(outletset==shotaset)
			 {
				amin(best, numPush);
			 }
		 }

		 if(best==BIG)
		 {
			 fprintf(stderr,"Case #%d: NOT POSSIBLE\n",testcase);
			 printf("Case #%d: NOT POSSIBLE\n",testcase);
		 }
		 else
		 {
			 fprintf(stderr,"Case #%d: %d\n",testcase,best);
			 printf("Case #%d: %d\n",testcase,best);
		 }

	 }

	 return 0;
}
