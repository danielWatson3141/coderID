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
#include <cstring>
using namespace std;

template<class T> T gcd(T a,T b)
{
    if(a<0) return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template <class T> T lcm(T a,T b)
{
    return a*(b/gcd(a,b));
}
template<class T> inline vector<pair<T,int> > factorize(T n)
{
    vector<pair<T,int> > R;
    for (T i=2; n>1;)
    {
        if (n%i==0)
        {
            int C=0;
            for (; n%i==0; C++,n/=i);
            R.push_back(make_pair(i,C));
        }
        i++;
        if (i>n/i) i=n;
    }
    if (n>1) R.push_back(make_pair(n,1));
    return R;
}
template<class T> inline bool isPrimeNumber(T n)
{
    if(n<=1)return false;
    for (T i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}
template<class T> inline T eularFunction(T n)
{
    vector<pair<T,int> > R=factorize(n);
    T r=n;
    for (int i=0; i<R.size(); i++)r=r/R[i].first*(R[i].first-1);
    return r;
}
template<class T> string toString(T n)
{
    ostringstream ost;
    ost<<n;
    ost.flush();
    return ost.str();
}
int toInt(string s)
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int dirx[]= {1, 1, 0,-1,-1,-1,0,1};
int diry[]= {0,-1,-1,-1, 0, 1,1,1}; //clockwise

vector<int> child[1000+5];

// node num of left , delete
pair<int,int> rec(int parent, int node)
{
    vector<pair<int,int> > dep;
    for(int i=0; i<child[node].size(); i++)
    {
        if(child[node][i] != parent)
        {
            dep.push_back(rec(node, child[node][i]));
        }
    }
    if(dep.size() < 2)
    {
        if(dep.size() == 0) return make_pair(1, 0);
        return make_pair(1,dep[0].first + dep[0].second );
    }
    else
    {
        sort(dep.begin(),dep.end());
        int hold = dep[dep.size() -2].first + dep[dep.size()-1].first +1;
        int del = 0;
        for(int i=0; i<dep.size() -2; i++) del += dep[i].first + dep[i].second;
        del += dep[dep.size() -2].second + dep[dep.size()-1].second;
        return make_pair(hold, del);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin>>T;
    for(int cas = 1; cas<= T; cas++)
    {
        int N;
        cin>>N;
        for(int i=1; i<=N; i++) child[i].clear();
        for(int i=0; i<N-1; i++)
        {
            int a, b;
            cin>>a>>b;
            child[a].push_back(b);
            child[b].push_back(a);
        }
        int ret = N;  // delete node
        for(int i=1; i<=N; i++)  // i for the root
        {
            pair<int,int> depth = rec(-1,i);
//            cout<<"root "<<i<<"  hold and del  "<<depth.first<<" "<<depth.second<<endl;
//            int curnode = N - (1<<(depth+1)) + 1;
//            cout<<" left "<<curnode<<endl;
            ret = min(ret, depth.second);

//            vector<int> parent(N+1);
//            vector<int> vis(N+1);
//            for(int j=0; j<N+1; j++)
//            {
//                parent[j] = 0; vis[j] = 0;
//            }

//            queue<pair<int,int>> Q;
            // node£¬ len
        }
        cout<<"Case #"<<cas<<": "<<ret<<endl;
    }
    return 0;
}
