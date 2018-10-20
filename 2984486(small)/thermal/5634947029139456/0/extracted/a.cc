#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstring>
#include <functional>
#include <cmath>
#define CLR(a) memset(a,0,sizeof(a))
typedef long long ll;
using namespace std;
int n,l;
ll a[200],b[200];
int solve(){
    cin>>n>>l;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        ll tmp=0;

        for(int i=0;i<l;i++){
            tmp=tmp*2+(s[i]=='1'?1ll:0ll);
        }
        a[i] = tmp;
    }

    for(int i=0;i<n;i++){
        cin>>s;
        ll tmp=0;
        for(int i=0;i<l;i++){
            tmp=tmp*2+(s[i]=='1'?1ll:0ll);
        }
        b[i] = tmp;
        
    }

    // for(int i=0;i<n;i++)
        // cout<<a[i]<<" "<<b[i]<<endl;
    vector<int> bt;
    int ans = 0;
    for(int i=0;i<l;i++){
        int c1 = 0,c2=0;
        ll mask = 1<<i;
        for(int j=0;j<n;j++){
            if(a[j]&mask)
                ++c1;
            if(b[j]&mask)
                ++c2;
        }
        //cout<<mask<<" "<<c1<<" "<<c2<<endl;
        if(c1 == c2){
            if(n-c1==c2)
                bt.push_back(i);
        }else if(n-c1==c2){
            ans++;
            for(int j=0;j<n;j++){
                a[j]^=mask;
            }
        }else{
            return -1;
        }
    }
    //cout<<"ans"<<ans<<endl;
    int sz = bt.size();
    //cout<<sz<<endl;
    int tans = l*2;
    for(ll mask=0;mask<(1<<sz);mask++){
        int tmp = 0;
        for(int i=0;i<sz;i++){
            if(mask & (1<<i)){
                tmp++;
                for(int j=0;j<n;j++){
                    a[j]^=(1<<bt[i]);
                }
            }
        }
        sort(a,a+n);
        sort(b,b+n);
        //cout<<mask<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<a[i]<<" "<<b[i]<<endl;
        bool ok = true;
        for(int i=0;i<n;i++)
            if(a[i]!=b[i]){
                ok = false;
                break;
            }
        if(ok){
            if(tmp<tans)
                tans = tmp;
        }
        for(int i=0;i<sz;i++){
            if(mask & (1<<i)){
                tmp++;
                for(int j=0;j<n;j++){
                    a[j]^=(1<<bt[i]);
                }
            }
        }
        //cout<<tans<<endl;
    }
    //cout<<ans<<" "<<tans<<endl;
    if(tans ==l*2)
        return -1;
    return ans+tans;

}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int ans = solve();
        if(ans == -1){
            cout<<"Case #"<<cs<<": NOT POSSIBLE\n";
        }else{
            cout<<"Case #"<<cs<<": "<<ans<<endl;
        }
    }
}