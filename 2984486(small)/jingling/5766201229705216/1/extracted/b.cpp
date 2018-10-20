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

map<int, int> cache;
map<int, int> cc;
int g(int r, int p, vector<vector<int> > & v){
    int k = p*10000 + r;
    if(cc.find(k)==cc.end()){
      int & ans = cc[k];
      ans = 1;
      for(auto x : v[r]){
        if(x!=p)
          ans+=g(x, r, v);
      }
    }

    //cout<<"gggg r "<<r<<" p "<<p<<" : "<<cc[k]<<endl;
    return cc[k];
}

int f(int r, int p, vector<vector<int> > & v){
  //cout<<"--r"<<r<<" p"<<p<<endl;
  int k = p*10000 + r;
  int total = g(r,p,v);
  if(cache.find(k)==cache.end()){
    int & ans =  cache[k];
    ans = v.size();
    vector<int> s;
    for(auto x : v[r]){
      if(x!=p) s.push_back(x);
    }

    if(s.size()==0)
      ans=0;
    else if (s.size() ==1){
      ans = g(s[0], r, v);
    }
    else
      if(s.size() ==2){
        ans = f(s[0], r, v) + f(s[1], r, v);
      }
      else{
        for(int i = 0 ; i < s.size(); i++){
          for(int j = i+1 ; j < s.size(); j++){
            ans = min(ans,
                      total - g(s[i], r, v) - g(s[j], r, v) - 1 + f(s[i], r, v) + f(s[j], r, v));
          }

        }

      }

  }

  //cout<<"        r "<<r<<" p"<<p<<" "<<cache[k]<<endl;
  return cache[k];
}


int check(vector<vector<int> > & v, vector<int> & e){
  int n= v.size()-1;
  int r = 0;
  int m=0, ee=0;;
  vector<int> c(n, 0);
  for(int i = 1 ; i <= n; i++){
    if(e[i]){ee++;continue;}

    int d=0;
    for(auto x : v[i]){
      if(e[x])continue;
      d++;
      m++;
    }
    c[d]++;
    if(d>3)
      return -1;
  }


  //cout<<"::"<<n<<" "<<m<<" "<<ee<<endl;
  //copy(c.begin(), c.end(), ostream_iterator<int>(cout, ","));cout<<endl;
  if(m!=2*(n-ee-1))
    return -1;

  if(c[2]==1 || n==ee+1)
    return ee;
  return -1;

}

int main(int argc, char *argv[])
{
  int T;
  cin>>T;
  for(long long __t = 1 ; __t <= T; __t++){

    //--------------------------
    cache.clear();cc.clear();
    int n;
    cin>>n;
    vector<vector<int> > v (n+1);
    for(int i = 0 ; i < n-1; i++){
      int a, b;
      cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
    }


    int ans = n-1;
    if(0){
        vector<int> e(n+1);
        for(int i = 0 ; i < (1<<n); i++){
          fill(e.begin(), e.end(), 0);
          for(int j = 0 ; j < n; j++){
            if(i&(1<<j))e[j+1]=1;
          }
          //copy(e.begin(), e.end(), ostream_iterator<int>(cout, ","));cout<<endl;
          int t = check(v, e);
          //cout<<t<<endl;
          if(t>=0 && t<ans)
            ans=t;
        }

    }
    else{

      for(int i = 1 ; i <= n; i++){
        int xx = f(i,0,v);
        if(xx<ans){
          ans = xx;
        }
        //cout<<"i="<<i<<" "<<xx<<" : "<<ans<<endl;
      }
    }

    //--------------------------


    cout<<"Case #"<<__t<<": "<<ans<<endl;
  }

  return 0;
}
