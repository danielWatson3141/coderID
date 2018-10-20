#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <iterator>

#define MOD 1000000007
#define INF 1000000000000000000
#define PI acos(-1)

using namespace std;

char a[10][15],b[10][15];

int flip (int idx,int n,int l) {
	int i,j,flag,val;
	if (idx == l) {
		for (i = 0; i < n; i++) {
			flag = 0;
			for (j = 0; j < n; j++) {
				if (strcmp(a[i],b[j]) == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				break;
			}
		}
		if (flag == 0) {
			return -1;
		} else {
			return 0;
		}
	}
	val = flip(idx + 1,n,l);
	if (val >= 0) {
		return val;
	}
	for (i = 0; i < n; i++) {
		if (a[i][idx] == '0') {
			a[i][idx] = '1';
		} else {
			a[i][idx] = '0';
		}
	}
	val = flip(idx + 1,n,l);
	if (val >= 0) {
		return (val + 1);
	}
	for (i = 0; i < n; i++) {
		if (a[i][idx] == '0') {
			a[i][idx] = '1';
		} else {
			a[i][idx] = '0';
		}
	}
	return -1;
}

int main()
{
//	freopen("input.in","r",stdin);
//	freopen("output.in","w",stdout);
	int t,y;
	scanf("%d",&t);
	y = 1;
	while (t --) {
		int n,l,i,ans;
		scanf("%d%d",&n,&l);
		for (i = 0; i < n; i++) {
			scanf("%s",a[i]);
		}
		for (i = 0; i < n; i++) {
			scanf("%s",b[i]);
		}
		ans = flip(0,n,l);
		if (ans == -1) {
			printf("Case #%d: NOT POSSIBLE\n",y);
		} else {
			printf("Case #%d: %d\n",y,ans);
		}
		y++;
	}
	return 0;
}
