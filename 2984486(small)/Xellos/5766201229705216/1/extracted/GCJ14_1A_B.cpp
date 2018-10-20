// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 123456789
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

void DFS(int R, vector< vector<int> > &G, vector<int> &par, vector<int> &A) {
	ALL_THE(G[R],it) if(par[*it] == -1) {
		par[*it] =R;
		DFS(*it,G,par,A);}
	int x =0, v =-OVER9000, w =-OVER9000;
	ALL_THE(G[R],it) if(v < A[*it] && par[*it] == R) {
		v =A[*it];
		x =*it;}
	ALL_THE(G[R],it) if(w < A[*it] && par[*it] == R && *it != x)
		w =A[*it];
	A[R] =max(1,1+v+w);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		cout << "Case #" << t+1 << ": ";
		int N;
		cin >> N;
		vector< vector<int> > G(N);
		for(int i =1; i < N; i++) {
			int a,b;
			cin >> a >> b;
			G[--a].push_back(--b);
			G[b].push_back(a);}
		int ans =0;
		for(int r =0; r < N; r++) {
			vector<int> A(N,1);
			vector<int> par(N,-1);
			par[r] =r;
			DFS(r,G,par,A);
			ans =max(ans,A[r]);}
		cout << N-ans << "\n";}
	return 0;}

// look at my code
// my code is amazing
