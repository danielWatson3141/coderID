/*
 * C.cpp
 *
 *  Created on: 2014-4-26
 *      Author: bjfudq
 */
#include <functional>
#include <algorithm>
#include <iostream>
//#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")

#define MEM(a) (memset((a),0,sizeof(a)))
#define LEN(a) (int)strlen((a))
#define fr(a) for(int i=0;i<(a);i++)
#define sf(a) scanf("%d",&(a))
#define sf64(a) scanf("%I64d",&(a))
#define sff(a) scanf("%lf",&(a))
#define sfs(a) scanf("%s",(a))
#define sf2(a,b) scanf("%d%d",&(a),&(b))
#define sf2s(a,b) scanf("%s%s",(a),(b));
#define sf2f(a,b) scanf("%lf%lf",&(a),&(b))
#define sf264(a,b) scanf("%I64d%I64d",&(a),&(b))
#define pf(a) printf("%d\n",(a))
#define pfc(a) printf("%c",(a));
#define pf64(a) printf("%I64d\n",(a))
#define pff(a) printf("%lf\n",(a))
#define pfs(a) printf("%s\n",(a))
#define pf2(a,b) printf("%d %d\n",(a),(b))
#define pf2s(a,b) printf("%s%s\n",(a),(b));
#define pf2f(a,b) printf("%lf %lf\n",(a),(b))
#define pf264(a,b) printf("%I64d %I64d\n",(a),(b))
#define pfn printf("\n")
#define LL long long

//const int N=100010;
const int M=1000010;
const int MOD=1000000007;
const int INF=0x7fffffff;
const int dir4[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int dir8[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};
const double eps=1e-16;
const double PI=acos(-1.0);

inline int sign(double x){return (x>eps)-(x<-eps);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
/*************************/


#define NN 155
#define LLL 55

LL origin[NN];
LL des[NN];
LL temp_seq[NN];
int seq_num, seq_len;

LL convert(char *st)
{
	LL ret = 0;
	int len = (int)strlen(st);
	for (int i = 0; i < len; i++)
	{
		ret <<= 1;
		if (st[i] == '1')
		{
			ret += 1;
		}
	}
	return ret;
}

void input()
{
	char temp[NN];
	scanf("%d%d", &seq_num, &seq_len);
	for (int i = 0; i < seq_num; i++)
	{
		scanf("%s", temp);
		origin[i] = convert(temp);
	}
	for (int i = 0; i < seq_num; i++)
	{
		scanf("%s", temp);
		des[i] = convert(temp);
	}
}

int count_bit(LL a)
{
	int ret = 0;
	while (a)
	{
		if (a & 1)
			ret++;
		a>>=1;
	}
	return ret;
}

int work()
{
	int ret = seq_len + 1;
	for (int i = 0; i < seq_num; i++)
	{
		LL key = des[0] ^ origin[i];
		for (int j = 0; j < seq_num; j++)
			temp_seq[j] = origin[j] ^ key;
		sort(temp_seq, temp_seq + seq_num);
		if (equal(temp_seq, temp_seq + seq_num, des))
			ret = min(ret, count_bit(key));
	}
	if (ret == seq_len + 1)
		return -1;
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("testin.txt", "r", stdin);
    freopen("testout.txt", "w", stdout);
#endif
	int T,cas=1;
	scanf("%d", &T);
	while(T--)
	{
		printf("Case #%d: ", cas++);
		input();
		sort(des, des + seq_num);
		int ans = work();
		if (ans == -1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", ans);
	}
    return 0;
}

