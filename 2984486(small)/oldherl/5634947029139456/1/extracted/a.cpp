#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
long long a[160],b[160];
bool f[160];

long long readstr() {
    string s;
    cin>>s;
    long long x=0;
    for(int i=0;i<s.size();i++) {
        x=x+x+s[i]-'0';
    }
    return x;
}

int main() {
    int TT;
    cin>>TT;
    for(int T=1;T<=TT;T++) {
        cin>>n>>m;
        for(int i=0;i<n;i++) a[i]=readstr();
        for(int i=0;i<n;i++) b[i]=readstr();
        int ans=999;
        for(int v=0;v<n;v++) {
            // put a[0] to b[v]
            long long d=a[0]^b[v];
            int cnt=0;
            for(long long x=d;x>0;x=x/2)
                cnt+=(x%2);
            if (cnt<ans) {
                for(int i=0;i<n;i++) {
                    long long x=d^b[i];
                    bool ok=false;
                    for(int j=0;j<n;j++) if (x==a[j]) {
                        ok=true;
                        break;
                    }
                    if (!ok) break;
                    if (i==n-1) {
                        ans=cnt;
                        //cout<<"v="<<v<<" d="<<d<<" cnt="<<cnt<<endl;
                    }
                }
            }
        }
        cout<<"Case #"<<T<<": ";
        if (ans>m) cout<<"NOT POSSIBLE";
        else cout<<ans;
        cout<<endl;
    }
    return 0;
}