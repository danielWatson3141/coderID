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

#define INF 0x3f3f3f3f
#define EPS 1e-8

typedef pair<int,int> ii;
typedef long long int ll;

#define MAXN 1010

string tomada[MAXN],pc[MAXN];
string aux[MAXN];		

int main(){
	int nt;
	scanf(" %d",&nt);
	int t = 1;
	while(nt--){
		int n,l;
		scanf(" %d %d",&n,&l);
		for(int i = 0 ; i < n ; i++)	cin >> tomada[i];
		
		for(int i = 0 ; i < n ; i++)	cin >> pc[i];
			
		bool possivel = true;		
		int ans = 0;
		vector<int> can;
		for(int j = 0 ;possivel && j < l ; j++){
			int qto0 = 0;
			int qpc0 = 0;
			for(int i = 0 ; i < n ; i++){
				if(tomada[i][j] == '0') qto0++;
				if(pc[i][j] == '0') qpc0++;				
			}		
			
			if(qto0 == qpc0 && qto0 == (n - qpc0)){
				can.push_back(j);
			}
			else if(qto0 == n - qpc0){
				for(int i = 0 ; i < n ; i++){
					if(tomada[i][j] == '0') tomada[i][j] = '1';
					else tomada[i][j] = '0';					
				}			
				ans++;
			}
			else if(qto0 != qpc0){
				possivel = false;
			}
		}
		
		
		sort(pc,pc+n);
		printf("Case #%d: ",t++);
		
		int res = INT_MAX;
		if(!possivel) printf("NOT POSSIBLE\n");
		else{
			possivel = false;
			for(int mask = 0 ; mask < (1 << can.size()) ; mask++){				
				for(int i = 0 ; i < n ; i++) aux[i] = tomada[i];
				
				int cnt = 0;
				for(int j = 0 ; j < can.size() ; j++){
					if(mask & (1 << j)){
						cnt++;
						for(int i = 0 ; i < n ;i++){
							if(aux[i][can[j]] == '0') aux[i][can[j]] = '1';
							else aux[i][can[j]] = '0';			
						}
					}					
				}				
				
				sort(aux,aux+n);
				bool ok = true;
				for(int i = 0 ; i < n ; i++){
					if(aux[i] != pc[i])
						ok = false;
				}
				if(ok){
					res = min(res,ans+cnt);
					possivel = true;
				}				
			}	
			if(!possivel) printf("NOT POSSIBLE\n");
			else printf("%d\n",res);		
		}
	}	
	return 0;
}
