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

int main()
{
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int n , L , ans , tc = 1 , ff ;
	vector < string > o , m , tmp ;
	string a;
	cin >> ff;
	while ( ff-- ){
		cin >> n >> L;
		int z = 1 << L;
		o.clear();
		m.clear();
		tmp.clear();
		ans = INF ;
		for (int i = 0; i < n; i++) cin >> a, o.push_back(a);
		for (int i = 0; i < n; i++) cin >> a, m.push_back(a);
		sort(m.begin(), m.end());
		for (int i = 0; i < z; i++){
			tmp = o;
			int sw = 0;
			for (int j = 0; j < L; j++){
				if (i & (1 << j)){
					sw++;
					for (int t = 0; t < tmp.size(); t++){
						tmp[t][j] = (tmp[t][j] == '0' ? '1' : '0');
					}
				}
			}
			sort(tmp.begin(), tmp.end());
			int f = 0 ;
			for (int j = 0; j < tmp.size(); j++){
				if (tmp[j] != m[j]){
					f = 1;
					break;
				}
			}
			if (!f) ans = min(ans, sw );
		}
		cout << "Case #" << tc++ << ": ";
		if (ans >= INF) cout << "NOT POSSIBLE" << endl;
		else cout << ans << endl;
	}
	return 0;
}