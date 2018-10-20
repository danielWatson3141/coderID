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

vector<int> g[1042];
//int depth[1042];
int rozmiar[1042];
bool visited[1042];
int dp[1042];
int n;

int dfs(int w)
{
     visited[w]=1;
     vector<int> temp;
     int roz=1;
     for(int i=0;i<g[w].size();i++)
     {
             if(visited[g[w][i]]==0)
             {
                      //depth[g[w][i]]=depth[w]+1;
                      int wynik=dfs(g[w][i]);
                      roz+=rozmiar[g[w][i]];
                      temp.pb(wynik-rozmiar[g[w][i]]);                                     
             }        
     }     
     rozmiar[w]=roz;
     sort(temp.begin(),temp.end());
     if(temp.size()==0)return 0;
     else if(temp.size()==1)return rozmiar[w]-1;
     else return temp[0]+temp[1]+rozmiar[w]-1;
}

void solve(int test)
{
     scanf("%d",&n);
     for(int i=0;i<n+5;i++)g[i].clear();
     for(int i=0;i<n-1;i++)
     {
             wez2(x,y);
             x--; y--;
             g[x].pb(y);
             g[y].pb(x);
     }
     int res=2000;
     for(int i=0;i<=n-1;i++)//root
     {
             for(int i=0;i<=n;i++)visited[i]=0;
             //depth[i]=0;
             res=min(res,dfs(i));
     }
     printf("Case #%d: %d\n",test,res);
}

int main()
{
    wez(t);
    for(int i=1;i<=t;i++)solve(i);
    //system("pause");
    return 0;   
}
