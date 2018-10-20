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
		int gradosAct[1005];
		int usoGrados[1005];
		int totalGrados;
		for(int i=0;i<1<<N;i++){
			memset(usoGrados, 0, sizeof usoGrados);
			totalGrados = 0;
			memcpy(gradosAct, grados, sizeof gradosAct);
			for(int j=0;j<N;j++){
				if((1<<j)&i){
					for(int a=0;a<N;a++){
						if(ady[j][a])gradosAct[a]--;
					}
				}
			}
			
			for(int j=0;j<N;j++){
				if(!((1<<j)&i)){
					usoGrados[gradosAct[j]]++;
				}
			}
			bool sirve = true;
			for(int j=0;j<N;j++){
				totalGrados += usoGrados[j]*j;
				if(j==0||j>3){
					if(usoGrados[j])sirve = false;
				}
			}
			
			
			sirve = sirve && (usoGrados[2]==1);
			sirve = sirve && (totalGrados==2*(N-__builtin_popcount(i)-1));
			if(sirve){
				res = min(res, __builtin_popcount(i));
			}
		}
		
		
		cout << "Case #" << caso << ": " << res << endl; 
	}
	return 0;
}
