//By Lin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>

#define eps 1e-9
#define sqr(x) ((x)*(x))
#define Rep(i,n) for(int i = 0; i<n; i++)
#define foreach(i,n) for( __typeof(n.begin()) i = n.begin(); i!=n.end(); i++)
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define N 1010

int p[N];
bool mark[N];

int		main(){
	int cas, tt = 0;
	scanf("%d", &cas);
	vector<pii> v;
	bool ans[130];
	Rep(t, cas) {
		int n;
		scanf("%d", &n);
		Rep(i, n) scanf("%d", &p[i]);
		int num = 0;
		memset(mark, false, sizeof mark);
		Rep(i, n) {
			if (mark[i]) continue;
			int k = i;
			while (!mark[k]) {
				mark[k] = true;
				k = p[k];
			}
			num++;
		}
//		printf("%d %d\n", t, num);
		v.push_back(mp(num, t));
	}
	sort(v.begin(), v.end());
	Rep(i, cas) {
//		printf("%d %d\n", v[i].X, v[i].Y);
		ans[v[i].Y] = i < cas / 2;
	}
	Rep(i, cas) printf("Case #%d: %s\n", i + 1, ans[i]?"GOOD":"BAD");
	return 0;
}
