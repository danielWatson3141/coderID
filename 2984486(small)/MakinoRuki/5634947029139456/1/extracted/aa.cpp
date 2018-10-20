#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,n,l;
int p[12];
vector<ll>a,b;
string s;
int ans;
bool vis[12];
int bits(ll x){
    int cnt=0;
    while(x){
             if(x&1)
                    cnt++;
             x/=2;
    }
    return cnt;
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
  //  cout<<T<<endl;
    for(int cas=1;cas<=T;++cas){
            cin>>n>>l;
        //    cout<<n<<" "<<l<<endl;
            a.clear();
            b.clear();
            for(int i=0;i<n;++i){
                    cin>>s;
              //      cout<<s<<endl;
                    ll num=0;
                    for(int j=0;j<l;++j)
                            num=num*2LL+(s[j]-'0');
                    a.push_back(num);
            }
            for(int i=0;i<n;++i){
                    cin>>s;
              //      cout<<s<<endl;
                    ll num=0;
                    for(int j=0;j<l;++j)
                            num=num*2LL+(s[j]-'0');
                    b.push_back(num);
            }
            ans=l+1;
            bool ok;
            for(int i=0;i<n;++i)
                    for(int j=0;j<n;++j){
                            bool ok=true;
                            ll st=a[i]^b[j];
                            for(int k=0;k<n;++k)
                                    if(k!=i){
                                             int t;
                                             for(t=0;t<n;++t)
                                                if((a[k]^b[t]) == st)
                                                    break;
                                             if(t>=n){
                                                 ok=false;
                                                 break;
                                             }
                                    }
                            if(ok){
                                   ans=min(ans,bits(st));
                            }
                    }
            printf("Case #%d: ",cas);
            if(ans==l+1)
                printf("NOT POSSIBLE\n");
            else 
                 printf("%d\n",ans);       
    }
    return 0;
}
