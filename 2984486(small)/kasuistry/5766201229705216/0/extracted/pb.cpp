
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int n;
int hash[1000];
static int list[1000][1000];
int ptr[1000];

int sch(int root){
	
	int m1, m2;

	m1 = m2 = -1;

	for(int i=0; i<ptr[root]; ++i){
		if(!hash[list[root][i]]){
			hash[list[root][i]] = 1;
			int k = sch(list[root][i]);
			if(k > m2) m2 = k;
			if(m2 > m1){
				k = m2; m2 = m1; m1 = k;
			}
		}
	}

	if(m1 == -1 || m2 == -1){
		return 1;
	}else{
		return m1+m2+1;
	}
}

int main(){
	
	int testcase; scanf("%d", &testcase);

	for(int t=1; t<=testcase; ++t){
		scanf("%d", &n);
		memset(ptr, 0, sizeof(ptr));
		int u, v;
		for(int i=0; i<n-1; ++i){
			scanf("%d%d", &u, &v);
			u--, v--;
			list[u][ptr[u]++] = v;
			list[v][ptr[v]++] = u;
		}

		int best = n;
		for(int i=0; i<n; ++i){
			memset(hash, 0, sizeof(hash));
			hash[i] = 1;
			int keep = sch(i);
			if(n-keep < best){
				best = n-keep;
			}
		}
		printf("Case #%d: %d\n", t, best);
	}

	return 0;
}
