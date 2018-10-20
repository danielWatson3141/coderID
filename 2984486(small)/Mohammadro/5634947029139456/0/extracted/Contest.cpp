#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define xx first
#define yy second
#define ll long long
#define pb push_back
#define pp pop_back
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
using namespace std;
const int maxn=150+10;
const int INF=1000000000;
int n,l,t;
string s[maxn];
string t1[maxn];
bool a[maxn][50];
bool b[maxn][50];
bool now[maxn][50];
bool check[maxn];
int ans=INF;
bool mark[maxn];
int main(){
    ifstream cin("ans.in");
    ofstream cout("ans.out");
    cin>>t;
    for(int q=1;q<=t;q++){
        ans=INF;
        memset(mark,0,sizeof(mark));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(now,0,sizeof(now));
        cin>>n>>l;
        for(int i=1;i<=n;i++)cin>>s[i];
        for(int i=1;i<=n;i++)cin>>t1[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=l;j++){
                if(s[i][j-1]=='1')a[i][j]=1;
                else a[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=l;j++){
                if(t1[i][j-1]=='1')b[i][j]=1;
                else b[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            memset(mark,0,sizeof(mark));
            memset(now,0,sizeof(now));
            memset(check,0,sizeof(check));
            int cnt=0;
            for(int j=1;j<=l;j++){
                if(a[i][j]!=b[1][j]){
                    mark[j]=true;
                    cnt++;
                }
            }
            for(int k=1;k<=n;k++){
                for(int j=1;j<=l;j++){
                    if(mark[j]){
                        now[k][j]=!a[k][j];
                    }
                    else{
                        now[k][j]=a[k][j];
                    }
                }
            }
            check[1]=true;
            for(int k=1;k<=n;k++){
                if(k!=i){
                for(int j=2;j<=n;j++){
                    bool f=0;
                    for(int ii=1;ii<=l;ii++){
                        if(now[k][ii]!=b[j][ii])f=true;
                    }
                    if(!f){
                        check[j]=true;
                        break;
                    }
                }
                }
            }
            bool bomb=0;
            for(int k=1;k<=n;k++){
                if(!check[k])bomb=true;
            }
            if(!bomb)ans=min(ans,cnt);
        }
        if(ans!=INF)cout<<"Case #"<<q<<": "<<ans<<endl;
        else cout<<"Case #"<<q<<": "<<"NOT POSSIBLE"<<endl;
    }
}
