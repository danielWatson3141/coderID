#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1005
typedef long long LL;
int t;
int n;
int x[N];
int y[N];
struct Node{
	Node * lson;
	Node * rson;
	int id;
}s[N][N];
int pa[N];
int f[N];
int ans;
int ts[N];
int sum(Node *tmp){
	if(tmp == NULL)return 0;
	return sum(tmp->lson) + sum(tmp->rson) + 1;
}
int cot(Node *tmp){
	int ans = 0;
	if(tmp->lson == NULL && tmp->rson == NULL)ans = 0;
	if(tmp->lson != NULL && tmp->rson == NULL)ans = sum(tmp->lson);
	if(tmp->lson != NULL && tmp->rson != NULL){
		ans = cot(tmp->lson) + cot(tmp->rson);
	}
	return ans;
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d", &t);
	int num = 1;
	while(t--){
		memset(ts, 0, sizeof(ts));
		ans = N;
		scanf("%d", &n);
		for(int i = 0; i < n - 1; i++){
			scanf("%d%d", &x[i], &y[i]);
			x[i]--;
			y[i]--;
			ts[x[i]]++;
			ts[y[i]]++;
		}
		for(int i = 0; i < n; i++){
			if(ts[i] > 2)continue;
			for(int j = 0; j < n; j++){
				pa[j] = j;
				s[i][j].lson = NULL;
				s[i][j].rson = NULL;
				s[i][j].id = j;
				f[j] = 0;
			}
			int ff = 1;
			while(ff){
				ff = 0;
				for(int j = 0; j < n - 1; j++){
					if(f[j])continue;
					if(pa[x[j]] == i){
						ff = 1;
						f[j] = 1;
						pa[y[j]] = i;
						if(s[i][x[j]].lson == NULL)s[i][x[j]].lson = &s[i][y[j]];
						else s[i][x[j]].rson = &s[i][y[j]];
					}
					else if(pa[y[j]] == i){
						ff = 1;
						f[j] = 1;
						pa[x[j]] = i;
						if(s[i][y[j]].lson == NULL)s[i][y[j]].lson = &s[i][x[j]];
						else s[i][y[j]].rson = &s[i][x[j]];
					}
				}
			}
			Node *p = &s[i][i];
			ans = min(ans, cot(p));
		}
		printf("Case #%d: ", num++);
		printf("%d\n", ans);
	}
	return 0;
}
