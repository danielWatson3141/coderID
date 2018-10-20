/*
 * totoroXD
 *
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
const int INF = 1011110000, MOD=1000000000;
const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
const double EPS = 1e-6;

char numb[155][43], targetb[155][43];
int num[155],target[155];
int n, l, kase=1, dp[1111], nanc[1111];
bool match(int *a, int *b, int n){
	static int ta[155], tb[155];
	for(int i=0; i<n; i++)
		ta[i]=a[i], tb[i]=b[i];
	sort(ta, ta+n);
	sort(tb, tb+n);
	for(int i=0; i<n; i++)
		if(ta[i]!=tb[i])return 0;
	return 1;
}
bool input(){
	scanf("%d%d",&n,&l);
	for(int i=0; i<n; i++)
		scanf("%s",numb[i]);
	for(int i=0; i<n; i++)
		scanf("%s",targetb[i]);
	return 1;
}
void solve(){
	memset(num, 0, sizeof(num));
	memset(target, 0, sizeof(target));
	for(int i=0; i<n; i++){
		for(int j=0; j<l; j++){
			if(numb[i][j]=='1')
				num[i] |= (1LL<<(l-1-j));
			if(targetb[i][j]=='1')
				target[i] |= (1LL<<(l-1-j));
		}
	}
	int res=l+1;
	for(int p=0; p<n; p++){
		int s = num[0]^target[p],n1=0;
		//printf("p=%d, s=%d\n",p,s);
		for(int i=0; i<44; i++)
			if(s&(1<<i))n1++;
		for(int i=0; i<n; i++)
			num[i]^= s;
		if(match(num, target, n))
			res = min(res,n1);
		for(int i=0; i<n; i++)
			num[i]^= s;
	}
	printf("Case #%d: ",kase++);
	if(res==l+1)
		printf("NOT POSSIBLE\n");
	else
		printf("%d\n",res);
}
void pre(){
}
int main(){
	pre();
    int zz=1;
    cin>>zz;
    while(zz--){
    	input();
    	solve();
    }
    return 0;
}

/*

3
3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01
*/

