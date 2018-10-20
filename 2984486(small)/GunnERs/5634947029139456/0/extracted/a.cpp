#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int task, CASE=0;
int n, l, ret;
char inp[1000];
string a[1000], b[1000], c[1000];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &task); task--;){
		scanf("%d%d", &n, &l);
		for (int i=0; i<n; i++){
			scanf("%s", inp);
			a[i] =  inp;
		}
		for (int i=0; i<n; i++){
			scanf("%s", inp);
			b[i] =  inp;
		}
		sort( b, b+n );
		ret = 100000000;
		for (int mask=0; mask<(1<<l); mask++){
			for (int i=0; i<n; i++)
				c[i] = a[i];
			int current = 0;
			for (int o=0; o<l; o++)
			if ( mask&(1<<o) ){
				current++;
				for (int i=0; i<n; i++)
					c[i][o] = 1-(c[i][o]-'0')+'0';
			}
			sort(c, c+n);
			bool same = true;
			for (int i=0; i<n; i++)
			if ( c[i]!=b[i] ){
				same = false;
				break;
			}
			if ( same ){
				ret = min( ret, current );
			}
		}
		if ( ret>=100000000 ){
			printf("Case #%d: NOT POSSIBLE\n", ++CASE);
		}else{
			printf("Case #%d: %d\n", ++CASE, ret);
		}
	}
	return 0;
}
