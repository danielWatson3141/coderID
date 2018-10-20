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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

typedef int ttyp;
#define fors(bg,en) for(int i=bg;i<en;i++)
#define forso(j,bg,en) for(int j=bg;j<en;j++)
#define forz(n) for(int i=0;i<n;i++)
#define forzo(j,n) for(int j=0;j<n;j++)
#define forsz(v) for(int i=0;i<v.size();i++)
#define forszo(j,v) for(int j=0;j<v.size();j++)
#define MP make_pair
#define sz(v) v.size()

void doit(){
    bool flip[155];
    int n, l, maxl, minb = 1001, thisb=0;
    vector <string> from, to, newto;
    memset(flip,false,sizeof(flip));
    cin>>n>>l;
    from.resize(n);
    to.resize(n);

    forz(n)
        cin>>from[i];
    forz(n)
        cin>>to[i];
    sort(from.begin(),from.end());
    maxl = (1<<l);
    for(int i=0;i<maxl;i++){
        newto = to;
        thisb = 0;
        for(int j=0;j<l;j++)
        if(i & (1<<j)){
                thisb++;
                forzo(k,n){
                    if(newto[k][j]== '0' )
                        newto[k][j]='1';
                    else
                        newto[k][j]='0';
                }
        }
        sort(newto.begin(),newto.end());
        if(newto == from){
            minb = min(minb, thisb);
        }
    }
    if(minb==1001)
        cout<<"NOT POSSIBLE"<<endl;
    else
        cout<<minb<<endl;

  return;
}
int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
      cout<<"Case #"<<i<<": ";
      doit();
    }
    return 0;
}
