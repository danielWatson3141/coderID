#include <vector>
#include <queue>
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
#include <sstream>
#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define clear(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector < pair < int,int > > vii;

int main()
{
   int test,n,m;
   cin>>test;
   REP(c,test)
   {
      cin>>n>>m;
      vector < string > e;
      vector < string > s;
      string t;
      REP(i,n)
      {
         cin>>t;
         e.pb(t);
      }
      
      REP(i,n)
      {
         cin>>t;
         s.pb(t);
      }
      
      sort(all(e));
      
      int mflips=INT_MAX;
      
      REP(i,n)
      {
         vector < string > temp;
         int flips=0;
         REP(j,n)
         {
            // make e[i]==s[j]
            flips=0;
            temp=s;
            REP(k,temp[j].sz)
               if(temp[j][k]!=e[i][k])
               {
                  flips++;
                  REP(p,n)
                    temp[p][k]=((temp[p][k]=='1')?'0':'1');
                  
               }
            // check if they are equal
            sort(all(temp));
            REP(k,n)
             if(e[k]!=temp[k])
             {
                flips=INT_MAX;
                break;
             }
            mflips=min(mflips,flips); 
         }
      }
      if(mflips!=INT_MAX) 
        cout<<"Case #"<<c+1<<": "<<mflips<<"\n";
      else
        cout<<"Case #"<<c+1<<": NOT POSSIBLE\n";     
   }
}
