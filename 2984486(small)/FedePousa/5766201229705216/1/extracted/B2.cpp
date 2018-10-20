#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

int main(){
	int T, N, X, Y, ady[1005][1005], res, grados[1005];
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		memset(ady, 0, sizeof ady);
		memset(grados, 0, sizeof grados);
		cin >> N;
		for(int i=0;i<N-1;i++){
			cin >> X >> Y;
			X--;
			Y--;
			ady[X][Y] = 1;
			ady[Y][X] = 1;
			grados[X]++;
			grados[Y]++;
		}
		
		
		
		
		res = N-1;
		
		int dep[1005], carga[1005], act;
		for(int a=0;a<N;a++){
			act = 0;
			memset(dep, -1, sizeof dep);
			memset(carga, 0, sizeof carga);
			queue<int> cola;
			cola.push(a);
			dep[a] = 0;
			int actual, maxdep = 0;
			while(!cola.empty()){
				actual = cola.front();
				cola.pop();
				for(int i=0;i<N;i++){
					if(ady[actual][i]){
						if(dep[i]==-1){
							dep[i] = dep[actual]+1;
							cola.push(i);
							maxdep = max(maxdep, dep[i]);
						}
					}
				}
			}
			vector<int> hijos;
			for(int i=maxdep;i>=0;i--){
				for(int j=0;j<N;j++){
					if(dep[j]!=i)continue;
					hijos.clear();
					for(int a=0;a<N;a++){
						if(!ady[j][a])continue;
						if(dep[a]==dep[j]+1)hijos.push_back(carga[a]);
					}
					if(hijos.empty()){
						carga[j] = 1;
						continue;
					}
					if(hijos.size()==1){
						carga[j] = 1;
						act += hijos[0];
						continue;
					}
					carga[j] = hijos[0]+hijos[1]+1;
					sort(hijos.begin(),hijos.end(), greater<int>());
					for(int b=2;b<(int)hijos.size();b++){
						act+=hijos[b];
					}
				}		
			}
			
			
			res = min(res,act);
		}
		cout << "Case #" << caso << ": " << res << endl; 
	}
	return 0;
}
