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

void solve(int test)
{
     wez2(n,l);
     vector<string> in,out;
     for(int i=0;i<n;i++)
     {
             string s;
             cin>>s;
             in.pb(s);        
     }     
     for(int i=0;i<n;i++)
     {
             string s;
             cin>>s;
             out.pb(s);        
     }
     int res=1000;
     sort(out.begin(),out.end());
     for(int i=0;i<n;i++)
     {
             string flip;
             int count=0;
             for(int j=0;j<l;j++)
             {
                     if(in[0][j]==out[i][j])flip.pb('0');
                     else 
                     {
                          flip.pb('1');
                          count++;
                     }        
             }
             vector<string> temp;
             for(int j=0;j<n;j++)
             {
                     string s;
                     for(int k=0;k<l;k++)
                     {
                              if(in[j][k]==flip[k])s.pb('0');
                              else s.pb('1');       
                     }
                     temp.pb(s);
             }
             sort(temp.begin(),temp.end());
             bool ok=1;
             for(int j=0;j<n;j++)
             {
                     if(temp[j]!=out[j])
                     {
                              ok=0;
                              break;                   
                     }
             }
             if(ok)res=min(res,count);
     }
     printf("Case #%d: ",test);
     if(res==1000)printf("NOT POSSIBLE\n");
     else printf("%d\n",res);
}

int main()
{
    wez(t);
    for(int i=1;i<=t;i++)solve(i);
    //system("pause");
    return 0;   
}
