#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

int t;
int n;
vector<int> G[2100];

int DFS(int nd, int pnt = -1) {
	int child = 0;
	for (int i = 0; i < G[nd].size(); i ++)
		if (G[nd][i] != pnt)
			child ++;
			
	if (child <= 1)
		return 1;
	
	int max1 = 0, max2 = 0, opt;
	for (int i = 0; i < G[nd].size(); i ++) {
		if (G[nd][i] != pnt) {
			opt = DFS(G[nd][i], nd);
			
			max2 = max( max2, opt );
			if (max2 > max1)
				swap( max1, max2 );
		}
	}
	return 1 + max1 + max2;
}

int main () {
	cin >> t;
	int caze = 0;
	
	while (t --) {
		caze ++;
		
		cin >> n;
		for (int i = 0, a, b; i < n-1; i ++) {
			cin >> a >> b;
			a --; b --;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		
		int opt = 0;
		for (int i = 0; i < n; i ++) {
			opt = max( DFS(i), opt );
		}
		
		cout << "Case #" << caze << ": " << n-opt << endl;
		
		for (int i = 0; i < n; i ++)
			G[i].clear();
	}
	
	return 0;
}  	
