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

vector<pair<int, int> > vp;
vector <bool> trav;
int n, maxn;
bool dfs(int mask, int ix, int par){
    if(trav[ix]==true)
        return false;
    trav[ix]=true;
    bool ret = true;
    forz(n)
    if(i!=ix && (i!=par) && (mask & (1<<i)) ==0)
    {
        forzo(j,n-1){
            if(vp[j].first == ix && vp[j].second == i)
                ret = (ret & dfs(mask,i, ix));
            else if(vp[j].first == i && vp[j].second == ix)
                ret = (ret & dfs(mask,i, ix));
        }
    }
    return ret;
}
bool check(int mask){
    vector<int> cnt(n,0);
    trav.clear();
    trav.resize(n, false);
    bool done;
    int one=0, two=0, three=0;
    //cout<<" "<<mask<<endl;
    //check if any nodes have more than three edges
    forz(n-1){
        if(!( (mask & (1<<vp[i].first)) || (mask & (1<<vp[i].second)))){
            cnt[vp[i].first]++;
            cnt[vp[i].second]++;
        }
    }
    //cout<<"  "<<"check 1"<<endl;

    //check if starting from any node the entire tree can be traversed
    done =false;
    forz(n)
    if( (mask & (1<<i)) == 0) {
        if(cnt[i]==0)
            return false;
        if(cnt[i]==1)
            one++;
        if(cnt[i]==2)
            two++;
        if(cnt[i]==3)
            three++;
        if(cnt[i]>3)
            return false;
        if(cnt[i]==2 & !done){
            done =true;
            if(!dfs(mask,i, -1))
                return false;
        }
    }
    //cout<<"  "<<"check 2"<<endl;
    if(two>1)
        return false;
    if(((one+two+three)&1)==0)
        return false;

    forz(n)
    if( (mask & (1<<i)) == 0 && trav[i]==false ) {
        return false;
    }
    //cout<<"  "<<"check 3"<<endl;
    return true;
}

void doit(){
    int minb = 2005, thisb;
    bool ok;
    vp.clear();
    cin>>n;
    vp.resize(n-1);
    forz(n-1){
        cin>>vp[i].first>>vp[i].second;
        vp[i].first--;
        vp[i].second--;
    }
    maxn = (1<<n);
    for(int i=0;i<maxn;i++){
        thisb = 0;
        ok = false;
        for(int j=0;j<n;j++)
        if(i & (1<<j)){
            thisb++;
        }
        if(check(i)){
            minb = min(minb, thisb);
        }
    }
    if(minb==2005)
        cout<<1<<endl;
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
