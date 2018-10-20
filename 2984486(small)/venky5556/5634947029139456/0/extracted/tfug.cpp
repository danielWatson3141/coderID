#include <iostream>
#include <ctype.h>
#include <stack>
#include <queue>
#include <limits.h>
#include <fstream>
#include <map>
#include <cmath>
#include <ctime>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <set>

#define rep(i, a) for(int i = 0; i < a; i++)
#define rep1(i, a) for(int i = 1; i <= a; i++)
#define fo(i, a, b) for(int i = a; i < b; i++)
#define defo(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a.size()))
#define x first
#define y second
#define SET(x, a) memset(x, a, sizeof(x));
using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,lm,ans=-1;
string req[15];
void fun(string giv[15],int flip,int c){
    string arr[15];
    int f = 0,i;
    sort(giv,giv+n);
    for(i=0;i<n;i++){
        if(giv[i]!=req[i]){
            f = 1;
            break;
        }
    }
    if(f==0){
        if(ans==-1){
            ans = c;
        }
        else{
            ans = min(ans,c);
        }
    }
    if(flip==lm){
        return;
    }
    fun(giv,flip+1,c);
    for(i=0;i<n;i++){
        arr[i] = giv[i];
        if(giv[i][flip]=='0'){
            arr[i][flip] = '1';
        }
        else if(giv[i][flip]=='1'){
            arr[i][flip] = '0';
        }
    }
    fun(arr,flip+1,c+1);
    return;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    int test,l=0;
    cin>>test;
    while(test--){
        l++;
        string giv[15];
        int i;
        cin>>n>>lm;
        ans = -1;
        for(i=0;i<n;i++){
            cin>>giv[i];
        }
        for(i=0;i<n;i++){
            cin>>req[i];
        }
        sort(req,req+n);
        /*for(i=0;i<n;i++){
            cout<<req[i]<<" ";
        }
        cout<<"\n";*/
        fun(giv,0,0);
        if(ans==-1){
            cout<<"Case #"<<l<<": NOT POSSIBLE"<<"\n";
        }
        else{
            cout<<"Case #"<<l<<": "<<ans<<"\n";
        }
    }
    return 0;
}
