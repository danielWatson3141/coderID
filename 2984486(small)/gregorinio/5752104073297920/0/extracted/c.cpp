#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int perm[1042];
int bad=0;

void solve(int test)
{
     int n;
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
             wez(x);
             perm[i]=x;        
     }
     long double p=0;
     int count=0;
     for(int i=0;i<n;i++)
     {
             //if(perm[i]>i)count++;       
             if(perm[i]>i)p+=1/(perm[i]-i);
             else p-=1/( (i-perm[i]+244.0) );
     }
     //cout<<p<<endl;
     printf("Case #%d: ",test);
     if(p>0){printf("BAD\n"); bad++;}
     else printf("GOOD\n");
     //printf("Case #%d: %d\n",test,res);
}

int main()
{
    wez(t);
    for(int i=1;i<=t;i++)solve(i);
    //cout<<"         "<<bad;
    //system("pause");
    return 0;   
}
