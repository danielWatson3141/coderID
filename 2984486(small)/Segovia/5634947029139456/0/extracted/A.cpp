#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define FOR(i,x,y) for(int i=(int)x; i<(int)y; i++)
#define RFOR(i,x,y) for(int i=(int)x; i>(int)y; i--)
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define IN(a,pos,c) insert(a.begin()+pos,1,c)
#define DEL(a,pos,cant) erase(a.begin()+pos,cant)
#define INF 1000000

int main(){
	int kases; cin>>kases;
	for(int kase=1;kase<=kases;kase++){
		int N, L;
		cin>>N>>L;
		vector<string> a,b,c;
		string aux;
		for(int n=0;n<N;n++){ cin>>aux; a.PB(aux);}
		for(int n=0;n<N;n++){ cin>>aux; b.PB(aux);}
		SORT(a); SORT(b);
		int LIM = 1<<L;
		int res = INF, cres;
		for(int i = 0; i < LIM; i++){
			c = a; cres = 0;
			for(int j=0;j<L;j++){
				if((1<<j)&i){ 
					cres++;
					for(int k=0;k<N;k++) 
						c[k][j] = (c[k][j]=='0'?'1':'0');				
				}
			}
			sort(c.begin(),c.end());
			bool possible = true;
			for(int k=0;k<N;k++)
				if(c[k] != b[k]){ possible = false; break;}
			if(possible) res = min(res,cres);
		}		
		
		if(res < INF) cout<<"Case #"<<kase<<": "<<res<<endl;
		else cout<<"Case #"<<kase<<": NOT POSSIBLE"<<endl;	
		
	}
}
