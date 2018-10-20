#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <bitset>

#include <algorithm>
#include <cmath>
using namespace std;

int const MAX_N = 1010;
int const INT_INF = 1000000000;

int is_CYC = 0;
int sm[MAX_N][MAX_N],cur_s[MAX_N][MAX_N],nnew[MAX_N],ok_v[MAX_N];
int n;

void dfs(int v, int parent) {
	if (nnew[v] == 1) {
		is_CYC = 1;
		return;
	}
	if (nnew[v] == 2)
		return;

	nnew[v] = 1;

	for (int i=0; i<n; i++)
		if (cur_s[v][i]) {
			if (nnew[i] == 1 && i != parent) {
				is_CYC = 1;
				return;
			}
			if (nnew[i] == 0)
				dfs(i,v);
		}

	nnew[v] = 2;
}

void dfs_2(int v,int parent) {
	if (nnew[v] == 1) {
		is_CYC = 1;
		return;
	}
	if (nnew[v] == 2)
		return;

	nnew[v] = 1;
	int ch = 0;

	for (int i=0; i<n; i++)
		if (cur_s[v][i]) {
			if (nnew[i] == 1 && i!=parent) {
				is_CYC = 1;
				return;
			}
			if (nnew[i] == 0) {
				ch++;
				dfs_2(i,v);
			}
		}

	nnew[v] = 2;

	if (ch!=0 && ch!=2)
		is_CYC = 1;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	scanf("%d",&t);
	for (int qq=0; qq<t; qq++) {
		printf("Case #%d: ",qq+1);

		scanf("%d",&n);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				sm[i][j] = 0;
		for (int i=0; i<n-1; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--; y--;
			sm[x][y] = sm[y][x] = 1;
		}

		int mn = INT_INF;
		for (int j=0; j<(1<<n); j++) {
			for (int i=0; i<n; i++)
				for (int k=0; k<n; k++)
					cur_s[i][k] = sm[i][k];
			for (int i=0; i<n; i++)
				ok_v[i] = 1;
			for (int i=0; i<n; i++)
				if ((j>>i)&1) {
					ok_v[i] = 0;
					for (int k=0; k<n; k++)
						cur_s[i][k] = cur_s[k][i] = 0;
				}
			for (int i=0; i<n; i++)
				nnew[i] = 0;
			int cnt_comp = 0;
			for (int i=0; i<n; i++)
				if (ok_v[i] && !nnew[i]) {
					cnt_comp++;
					is_CYC = 0;
					dfs(i,-1);
				}
			if (cnt_comp <= 1) {
				int is_good = 0;
				for (int rt=0; rt < n; rt++)
					if (ok_v[rt]) {
						is_CYC = 0;
						for (int i=0; i<n; i++)
							nnew[i] = 0;
						dfs_2(rt,-1);
						if (is_CYC == 0)
							is_good = 1;
					}
				if (is_good) {
					int cnt_bit = 0;
					for (int i=0; i<n; i++)
						if ((j>>i)&1)
							cnt_bit++;
					mn = min(mn, cnt_bit);
				}
			}
		}

		cout<<mn<<"\n";
	}

	return 0;
}