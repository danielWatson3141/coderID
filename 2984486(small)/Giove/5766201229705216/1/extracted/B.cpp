#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>

using namespace std;

int const MAXN = 1002;

int n;
vector<int> vicini[MAXN];


pair<int,int> DFS(int nodo, int padre) {
	// Entro in nodo arrivando da padre
	// Resistuisco: (numero minimo di nodi da uccidere; grandezza del sottoalbero)
	
	vector<int> differenze;
	int grandezza = 1;
	int numfigli = 0;
	
	for (int i=0; i<vicini[nodo].size(); i++) {
		int figlio = vicini[nodo][i];
		if (figlio == padre) continue;
		
		numfigli++;
		pair<int,int> res = DFS(figlio, nodo);
		
		grandezza += res.second;
		differenze.push_back( res.second - res.first );
	}
	
	if ( numfigli == 0 ) {
		return pair<int,int>(0,1);
	}
	if ( numfigli == 1 ) {
		// Devo uccidere l'unico figlio -- una cosa un po' triste, in effetti...
		return pair<int,int>(grandezza-1, grandezza);
	}
	
	// Rimane il caso in cui abbiamo almeno due figli: li uccidiamo tutti tranne 2.
	
	sort( differenze.begin(), differenze.end() );
	
	int dauccidere = (grandezza-1) - differenze[numfigli-1] - differenze[numfigli-2];
	
	return pair<int,int>( dauccidere, grandezza );
}

int prova(int nodo) {
	// Provo a mettere "nodo" come radice
	
	pair<int,int> res = DFS(nodo, -1);
	assert( res.second == n );
	
	return res.first;
}

void solve() {
	scanf("%d", &n);
	
	for (int i=0; i<n; ++i) {
		vicini[i].clear();
	}
	
	for (int i=0; i<n-1; ++i) {
		int x,y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		vicini[x].push_back(y);
		vicini[y].push_back(x);
	}
	
	int best_solution = n;
	
	for (int i=0; i<n; ++i) {
		// Provo a prendere il nodo i come radice
		best_solution = min( best_solution, prova(i) );
	}
	
	printf("%d\n", best_solution);
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	for (int i=0; i<t; ++i) {
		printf("Case #%d: ",i+1);
		solve();
	}
	
	return 0;
}
