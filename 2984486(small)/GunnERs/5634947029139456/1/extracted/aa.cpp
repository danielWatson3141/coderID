#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int task, CASE=0;
int n, l, ret;
char inp[1000];
long long a[1000], b[1000];
map<long long, int> mp;
map<long long, int>::iterator I;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("b.out","w",stdout);
	for (scanf("%d", &task); task--;){
		scanf("%d%d", &n, &l);
		for (int i=0; i<n; i++){
			scanf("%s", inp);
			a[i] = 0;
			for (int j=0; j<l; j++)
			if ( inp[j]=='1' )
				a[i] += ((long long)1<<j);
		}
		for (int i=0; i<n; i++){
			scanf("%s", inp);
			b[i] = 0;
			for (int j=0; j<l; j++)
			if ( inp[j]=='1' )
				b[i] += ((long long)1<<j);
		}
		int ret = 0;
		mp.clear();
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				mp[a[i]^b[j]]++;
			}
		}

		ret = 100000000;
		for (I = mp.begin(); I!=mp.end(); I++)
		if ( I->second>=n ){
			int current = 0;
			long long x = I->first;
			while ( x ){
				if ( x&1 ) current++;
				x >>= 1;
			}
			ret = min( ret, current );
		}

		if ( ret>=100000000 ){
			printf("Case #%d: NOT POSSIBLE\n", ++CASE);
		}else{
			printf("Case #%d: %d\n", ++CASE, ret);
		}
	}
	return 0;
}
