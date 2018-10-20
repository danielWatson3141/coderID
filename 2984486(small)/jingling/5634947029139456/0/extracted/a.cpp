#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <ctime>
using namespace std;


int main(int argc, char *argv[])
{
  int T;
  cin>>T;
  for(long long __t = 1 ; __t <= T; __t++){


    //--------------------------
    int n,l, ans=-1;
    string s;
    set<int> v, v2;

    cin>>n>>l;
    for(int i = 0 ; i < n; i++){
      cin>>s;
      int m = 0;
      for(int j = 0 ; j < l; j++){
        if(s[j]=='1')
          m |= (1<<j);
      }
      v.insert(m);
    }

    for(int i = 0 ; i < n; i++){

      cin>>s;
      int m = 0;
      for(int j = 0 ; j < l; j++){
        if(s[j]=='1')
          m |= (1<<j);
      }
      v2.insert(m);
    }

    //copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));cout<<endl;
    //copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ","));cout<<endl;

    for(int i = 0 ; i < (1<<l); i++){
      set<int> x;
      int ok=1;

      for(auto p : v){
        x.insert(p ^ i);
        if(v2.find(p^i) == v2.end()){
          ok=0;break;
          //cout<<"NOT"<<(p^i)<<endl;
        }
      }
      if(ok && x.size() == v2.size()){
        int y = i, t=0;
        while(y){
          t++;
          y-=y&(-y);
        }

        if(ans==-1 || ans>t)ans=t;
      }
    }



    //--------------------------


      if(ans==-1)
        cout<<"Case #"<<__t<<": NOT POSSIBLE"<<endl;
      else
        cout<<"Case #"<<__t<<": "<<ans<<endl;
  }

  return 0;
}
