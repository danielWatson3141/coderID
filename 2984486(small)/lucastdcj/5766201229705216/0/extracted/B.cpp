#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

#define MAXN 2010

vector<int> adj[MAXN];
int pai[MAXN],has[MAXN];
int custo[MAXN];

int solve(int v){
	int nadj = adj[v].size();	
	if(pai[v] != -1)	nadj--;	
	if(nadj == 0) return 0;
	if(nadj == 1){
		for(int i = 0 ; i < adj[v].size() ; i++){
			int pv = adj[v][i];
			if(pv == pai[v]) continue;			
			return has[pv];
		}
	} 
	 
	int a = 0;
	int b = 0;
	int ST = 0;
	for(int i = 0 ; i < adj[v].size() ; i++){
		int pv = adj[v][i];
		if(pv == pai[v]) continue;		
		else{
			pai[pv] = v;
			custo[pv] = solve(pv);			
			int aux = has[pv] - custo[pv];	
			ST += has[pv];					
			if(aux  >= a){
				b = a;
				a = aux;
			}
			else if(aux > b){
				b = aux;
			}			
		}		
	}	
	return ST - a - b;
}

int cnthas(int v){	
	has[v] = 1;
	for(int i = 0 ; i < adj[v].size() ; i++){
		int pv  = adj[v][i];
		if(pv == pai[v]) continue;
		
		pai[pv] = v;
		has[v] += cnthas(pv);
	}
	return has[v];	
}

int main(){
	
	int nt;
	scanf(" %d",&nt);
	int t = 1;
	while(nt--){
		int n;
		int a,b;
		scanf(" %d",&n);
		for(int i = 0 ; i < n ; i++) adj[i].clear();
		
		for(int i = 0 ; i < n - 1; i++){
			scanf(" %d %d",&a,&b);
			a--;b--;
			adj[a].push_back(b);
			adj[b].push_back(a);		
		}
		
		int ans = INT_MAX;
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++) pai[j] = -1;			
			cnthas(i);			
			for(int j = 0 ; j < n ; j++) pai[j] = -1;
			
			//~ printf("ROOT %d\n",i);
			ans = min(ans,solve(i));	
			
		}	
		
		printf("Case #%d: ",t++);	
		printf("%d\n",ans);
	}
	
	return 0;
}
