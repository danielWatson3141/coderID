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

int randInt(int k,int N){
	return k + (rand()%(N-k));
}

int main(){
	int kases; cin>>kases;
	for(int kase=1;kase<=kases;kase++){
		/*map<int,int> M;
		for(int experiment = 0; experiment < 100000; experiment++){ //GOOD
			vector<int> v;
			for(int i=0;i<4;i++) v.PB(i);	
			int p;	
			for(int k=0;k<4;k++){
				p = randInt(k,4);
				swap(v[k],v[p]);			
			}
			M[v[3]*1000+v[2]*100+v[1]*10+v[0]]++;
		}cout<<"GOOD"<<endl;
		for(map<int,int>::iterator it = M.begin(); it != M.end(); it++){
			cout<<it->first<<" "<<it->second<<endl;
		}
		M.clear();
		for(int experiment = 0; experiment < 100000; experiment++){ //BAD
			vector<int> v;
			for(int i=0;i<4;i++) v.PB(i);	
			int p;	
			for(int k=0;k<4;k++){
				p = randInt(0,4);
				swap(v[k],v[p]);			
			}
			M[v[3]*1000+v[2]*100+v[1]*10+v[0]]++;
		} cout<<"BAD"<<endl;
		for(map<int,int>::iterator it = M.begin(); it != M.end(); it++){
			cout<<it->first<<" "<<it->second<<endl;
		}*/
		int N; cin>>N;
		vector<int> v(N,0);
		for(int i=0;i<N;i++) cin>>v[i];
		int ca = 0;
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				if(v[i] < v[j]) ca++;
			}		
		}
		int cb = 0;
		for(int i=N-1;i>=0;i--){
			for(int j=i-1;j>=0;j--){
				if(v[i] < v[j]) cb++;
			}		
		}
		bool good = true;
		//cout<<ca<<" "<<cb<<" "<<N*(N-1)/2<<endl;
		if((ca*3 > N*(N-1)) || (cb*3 > N*(N-1))) good = false;
		
		cout<<"Case #"<<kase<<": "<<(good?"GOOD":"BAD")<<endl;	
	}
}
