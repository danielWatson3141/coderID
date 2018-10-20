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
#include <fstream>
#include <queue>
#include <cstring>

#define vs vector<string>
#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define sqr(x) ((x)*(x))
#define FOR(i,n) for (ll i = 0; i < ll(n); i++)
#define READ(v,n) { FOR(i,n){double x;cin>>x;v.pb(x);} }
#define FREAD(v,n) { FOR(i,n){int x;in>>x;v.pb(x);} }
#define WRITE(v) "";FOR(i,sz(v))cout<<v[i]<<" ";cout
#define FWRITE(v) "";FOR(i,sz(v))out<<v[i]<<" ";out
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ppb pop_back
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


int main(void){
  cout.precision(15);
  int T;
  cin>>T;
  FOR(t,T){
    int n, l;
    cin>>n>>l;
    vector <string> vs1,vs2;
    FOR(i,n){string s;cin>>s;vs1.pb(s);}
    FOR(i,n){string s;cin>>s;vs2.pb(s);}
    sort(all(vs1));
    int best=-1;
    
    FOR(i,n){
        string mask="";
        int num=0;
        FOR(j,l){
            if(vs1[0][j]=='1' ^ vs2[i][j]=='1'){mask+='1';num++;}else{mask+='0';}    
        }
        vs vs3;
        FOR(k,n){
            string s="";
            FOR(j,l){
                if(vs2[k][j]=='1' ^ mask[j]=='1'){s+='1';}else{s+='0';}    
            }
            vs3.pb(s);
        }
        sort(all(vs3));
        FOR(k,n){
            //cerr<<vs1[k]<<" vs "<<vs3[k]<<endl;
            if(vs1[k]!=vs3[k]){goto next;}
        }
        //cerr<<mask<<","<<num<<endl;
        if(best == -1 || num<best){best = num;}
        next: continue;
    }
        
    
    end:
    cout<<"Case #"<<(t+1)<<": ";
    if(best == -1){cout<<"NOT POSSIBLE"<<endl;}else{cout<<best<<endl;}
  }
  return 0;
}
