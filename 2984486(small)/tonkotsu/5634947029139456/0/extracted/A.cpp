#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstdio>
#include <queue>
#include <sstream>
using namespace std;

const int INF = 1<<29;
typedef pair<int,int> P;
typedef long long ll;

int main(){
   int T;
   cin >> T;
   for(int t=1; t<=T; t++){
      int N,L;
      cin >> N >> L;

      map<string,int>base;
      vector<string>v,v2;
      v.resize(N);
      v2.resize(N);
      
      for(int i=0; i<N; i++) cin >> v[i];
      
      for(int i=0; i<N; i++){
	 cin >> v2[i];
	 base[v2[i]]++;
      }


      int ans = INF;
      
      for(int i=0; i<(1<<L); i++){
	 vector<string>tmp = v;
	 map<string,int>m;
	 int cnt = 0;
	 vector<int>row;
	 for(int j=0; j<L; j++){
	    if(i & (1 << j)){
	       row.push_back(j);
	       cnt++;
	    }

	 }

	 for(int j=0; j<row.size(); j++){
	    for(int k=0; k<N; k++){
	       if(tmp[k][row[j]] == '1') tmp[k][row[j]] = '0';
	       else tmp[k][row[j]] = '1';
	    }
	 }

	 for(int j=0; j<N; j++){
	    m[tmp[j]]++;
	 }

	 if(m == base){
	    ans = min(ans,cnt);
	 }

/*	 for(map<string,int>::iterator it = m.begin(); it != m.end(); it++){
	    cout << it->first << " " << it->second << endl;
	 }
	 cout << endl;
*/
	 
      }
      cout << "Case #" << t << ": ";
      if(ans == INF) cout << "NOT POSSIBLE" << endl;
      else cout << ans << endl;
      
   }
   
   return 0;
}
