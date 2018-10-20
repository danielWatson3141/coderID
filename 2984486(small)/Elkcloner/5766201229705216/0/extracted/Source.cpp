//IN THE NAME OF GOD
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <fstream>
#include <utility>
#include <sstream>
#include <list>
#include <iomanip>
#include <functional>
#include <deque>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <climits>
#include <cctype>
#include <cassert>
#include <bitset>
#include <limits>
#include <numeric>

//#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define timestamp(x) printf("Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define INF 100000000
#define pii pair < int , int >
#define MP make_pair
#define MOD 1000000007
#define EPS 1e-9
#define LL long long
#define MAXN 200000+10
#define bug cout<<"!!!!!!!!!!!!!!!!!";

vector < int > AdjList[20];
int n;

bool check(bitset < 20 > v , vector < int > &d ){
	queue < int > q;
	for (int i = 1; i <= n; i++){
		if (v[i] == 0){
			v[i] = 1;
			q.push(i);
			break;
		}
	}
	while (!q.empty()){
		int tmp = q.front(); q.pop();
		for (int i = 0; i < AdjList[tmp].size(); i++){
			if (!v[AdjList[tmp][i]]){
				q.push(AdjList[tmp][i]);
				v[AdjList[tmp][i]] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) if (!v[i]) return 0;
	int ff = 0 , fz = 0 ;
	for (int i = 1; i <= n ; i++){
		if (d[i] == 1 || d[i] == 3 || d[i] < 0 ) continue;
		else if (d[i] == 2)ff++;
		else if (d[i] == 0) fz++;
		else return 0;
	}
	return ff == 1 || ( fz == 1 && ff == 0 );
}

int main()
{
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int t , x , y , tc = 1 ;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		vector < int > degree(20, 0);
		for (int i = 0; i < 20; i++) AdjList[i].clear();
		for (int i = 0; i < n - 1; i++){
			scanf("%d %d", &x, &y);
			degree[x]++;
			degree[y]++;
			AdjList[x].push_back(y);
			AdjList[y].push_back(x);
		}
		int z = 1 << n;
		int ans = INF;
		for (int i = 0; i < z; i++){
			vector < int > tmp = degree;
			bitset < 20 > vis(0);
			int sw = 0;
			for (int j = 0; j < n; j++){
				if (i & (1 << j)){
					sw++;
					for (int t = 0; t < AdjList[j+1].size(); t++){
						tmp[AdjList[j+1][t]]--;
						//vis[AdjList[j + 1][t]] = 1;
					}
					vis[j+1] = 1;
					tmp[j + 1] = -1;
				}
			}
			if (check(vis,tmp)){
				ans = min(ans, sw);
			}
		}
		printf("Case #%d: %d\n", tc++, ans);
		//cout << "Case #" << tc++ << ": " << ans << endl;
	}
	return 0;
}