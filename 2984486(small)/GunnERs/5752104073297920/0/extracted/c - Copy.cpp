#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int task, CASE, a[10000], n;

int main()
{
	freopen("C-small-attempt3.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &task); task--;){
		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", a+i);
		int ret = 0;
		for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
		if ( a[i]>a[j] ) ret++;
		
		//printf("%d %d\n", ret, n);

		if ( ret <= 250000 )
			printf("Case #%d: BAD\n", ++CASE);
		else
			printf("Case #%d: GOOD\n", ++CASE);
	}
	return 0;
}
