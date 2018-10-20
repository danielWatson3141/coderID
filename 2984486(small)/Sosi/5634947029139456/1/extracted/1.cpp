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

string change(string x, vector<int> idx)
{
    string r = x;
    for(int i=0; i<idx.size(); i++)
    {
        if(r[idx[i]] == '0') r[idx[i]] = '1';
        else r[idx[i]] = '0';
    }
    return r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T; cin>>T;
    for(int cas = 1; cas<= T; cas++)
    {
        int N,L;
        cin>>N>>L;
        vector<string> s(N),target(N);
        set<string> X;
        for(int i=0; i<N; i++)
        {
            cin>>s[i];
        }
        for(int i=0; i<N; i++)
        {   cin>>target[i]; X.insert(target[i]);}
        unsigned int ret = 200;
        for(int i=0; i<N; i++) // s[0] => target[i]
        {
            vector<int> idx;
            for(int j=0; j<L; j++)
            {
                if(s[0][j] != target[i][j])
                    idx.push_back(j);
            }
            set<string> tmp;
            tmp.insert(target[i]);
            for(int j=1; j<N; j++)
            {
                tmp.insert(change(s[j],idx));
            }
            if(tmp == X) ret = min(ret, idx.size());
        }
        if(ret == 200)
             cout<<"Case #"<<cas<<": NOT POSSIBLE"<<endl;
        else
        cout<<"Case #"<<cas<<": "<<ret <<endl;
    }

    return 0;
}
