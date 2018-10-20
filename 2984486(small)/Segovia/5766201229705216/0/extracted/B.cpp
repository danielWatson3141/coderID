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

int N;
vector<int> A[1005];
bool seen[1005];

int root_from(int a){
	//cout<<a<<endl;
	if(int(A[a].SZ) <= 2){// cout<<a<<" "<<1<<endl; 
		return 1;}
	vector<int> v;
	for(int j = 0; j< int(A[a].SZ);j++){
		if(seen[A[a][j]])continue;
		seen[A[a][j]] = true;
		v.PB(root_from(A[a][j]));
	}
	sort(v.rbegin(),v.rend());
	//cout<<a<<" "<<v[0]+v[1]<<endl;
	return 1+v[0]+v[1];
}

int main(){
	int kases; cin>>kases;
	for(int kase=1;kase<=kases;kase++){
		cin>>N;
		for(int i=1;i<=N;i++) A[i].clear();
		int a,b;
		for(int i=1;i<N;i++){ cin>>a>>b; A[a].PB(b); A[b].PB(a);}
		int res = N-1;
		for(int i=1;i<=N;i++){
			if(int(A[i].SZ) == 1) continue;
			else{
				for(int j=1;j<=N;j++) seen[j] = false;
				seen[i] = true;
				vector<int> v;
				for(int j = 0; j< int(A[i].SZ);j++){
					seen[A[i][j]] = true;
					v.PB(root_from(A[i][j]));
				}
				sort(v.rbegin(),v.rend());
				//cout<<"Root "<<i<<" "<<N-1-v[0]-v[1]<<" "<<v[0]<<" "<<v[1]<<endl;
				res = min(res, N-1-v[0]-v[1]);
			}
		}
		cout<<"Case #"<<kase<<": "<<res<<endl;	
	}
}
