/**************************************************
 * Author	 : xiaohao Z
 * Blog	 : http://www.cnblogs.com/shu-xiaohao/
 * Last modified : 2014-04-26 08:51
 * Filename	 : 2014_R1_B.cpp
 * Description	 : 
 * ************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned int,unsigned int> puu;
typedef pair<int, double> pid;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int LEN = 1010;
vector<int> Map[LEN];
int n, vex[LEN], chn[LEN];

void idfs(int v, int fa){
	vex[v] = 1;
	chn[v] = 0;
	for(int i=0; i<Map[v].size(); i++){
		int ch = Map[v][i];
		if(ch != fa){
			idfs(ch, v);
			chn[v] ++;
			vex[v] += vex[ch];
		}
	}
}

int dfs(int v, int fa){
	if(chn[v] == 1){
		for(int i=0; i<Map[v].size(); i++){
			if(fa != Map[v][i]) return 1;
		}
	}
	int ret = 0;
	for(int i=0; i<Map[v].size(); i++){
		int ch = Map[v][i];
		if(ch != fa){
			vex[ch] = dfs(ch, v);
		}
	}
	int maxv[2] = {0}, maxp[2] = {0};
	for(int i=0; i<Map[v].size(); i++){
		int ch = Map[v][i];
		if(ch != fa){
			if(vex[ch] > maxv[0]){
				swap(maxv[0], maxv[1]);
				swap(maxp[0], maxp[1]);
				maxv[0] = vex[ch];
				maxp[0] = ch;
			}else if(vex[ch] > maxv[1]){
				maxv[1] = vex[ch];
				maxp[1] = ch;
			}
		}
	}
	return maxv[0] + maxv[1] + 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out3.txt", "w", stdout);

	int T, kase = 1, a, b;
	scanf("%d", &T);
	while(T--){
		for(int i=0; i<LEN; i++) Map[i].clear();
		scanf("%d", &n);
		for(int i=0; i<n-1; i++){
			scanf("%d%d", &a, &b);
			Map[a].PB(b);
			Map[b].PB(a);
		}
		int ans = INF;
		for(int i=1; i<=n; i++){
			idfs(i, -1);
			//	for(int j=1; j<=n; j++)
			//		cout << vex[j] << ' ';
			//	cout << endl;
			int tans = dfs(i, -1);
			ans = min(ans, n - tans);
		}
		printf("Case #%d: %d\n", kase++, ans);
	}
	return 0;
}

