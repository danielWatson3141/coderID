/**************************************************
 * Author	 : xiaohao Z
 * Blog	 : http://www.cnblogs.com/shu-xiaohao/
 * Last modified : 2014-04-26 08:51
 * Filename	 : 2014_R1_A.cpp
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
const int LEN = 11;
int n, l, ans, flag[LEN];
char dor[LEN][LEN], lap[LEN][LEN];

bool J(int pos){
	memset(flag, 0, sizeof flag);
	int f;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(flag[j]) continue;
			f = 1;
			for(int k=0; k<=pos; k++){
				if(dor[i][k] != lap[j][k]){
					f = 0;break; 
				}
			}
			if(f){
				flag[j] = 1;
				break;
			}	
		}
	}
//	for(int i=0; i<n; i++) cout << dor[i] << " , " << flag[i] << " | " ;
//	cout << endl;
	for(int i=0; i<n; i++) if(!flag[i]) return false;
	return true;
}

void dfs(int pos, int st){
	if(pos == l){
		ans = min(ans, st);
		return ;
	}

	if(J(pos)) dfs(pos+1, st);
	for(int i=0; i<n; i++){
		if(dor[i][pos] == '1') dor[i][pos] = '0';
		else dor[i][pos] = '1';
	}
	if(J(pos)) dfs(pos+1, st+1);
	for(int i=0; i<n; i++){
		if(dor[i][pos] == '1') dor[i][pos] = '0';
		else dor[i][pos] = '1';
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);

	int T, kase = 1;
	cin >> T;
	while(T--){
		cin >> n >> l;
		for(int i=0; i<n; i++){
			cin >> dor[i];
		}
		for(int i=0; i<n; i++){
			cin >> lap[i];
		}
		ans = INF;
		dfs(0, 0);
		printf("Case #%d: ", kase++);
		if(ans == INF) cout << "NOT POSSIBLE" << endl;
		else cout << ans << endl;
	}
	return 0;
}

