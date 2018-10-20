#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
typedef long long int uli;
using namespace std;

const int mx = 200;
string beg[mx],end[mx],tra[mx];
const int inf = 1e8;
int main(){
    freopen("asmall.in","r",stdin);
    freopen("asmall.out","w",stdout);
    int t,n,l;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n>>l;
        for(int i=0;i<n;i++)
            cin>>beg[i];
        for(int i=0;i<n;i++)
            cin>>end[i];        
        sort(end,end+n);

        int best = inf;
        for(int j=0;j<n;j++){
            fill(tra,tra+mx,"");
            int nops = 0;
            for(int i=0;i<l;i++){
                if(beg[0][i]==end[j][i]){
                    for(int k=0;k<n;k++)
                        tra[k]+=beg[k][i];
                }
                else{
                    nops++;
                    for(int k=0;k<n;k++)
                        tra[k]+=(beg[k][i]=='1'?"0":"1");
                }
            }
            sort(tra,tra+n);
            bool ok = true;
            for(int i=0;i<n && ok;i++){
                if(tra[i].compare(end[i])!=0)
                    ok = false;
            }
            if(ok) best = min(best,nops);
        }
        if(best>=inf) printf("Case #%d: NOT POSSIBLE\n",tc);
        else printf("Case #%d: %d\n",tc,best);
    }
    return 0;
}
