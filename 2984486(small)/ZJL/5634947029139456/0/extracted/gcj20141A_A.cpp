#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string x[200];
string y[200];
string h[200];
int main(){
    int T;
    freopen("A-small-attempt0 (2).in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>T;
    for(int cas = 1;cas <= T; cas++){
        int n,m;
        cin>>n>>m;
        for(int i = 1; i <= n; i++)
            cin>>x[i];
        for(int i = 1; i <= n; i++)
            cin>>y[i];
        sort(y+1,y+n+1);
        int flip[200],ans = -1;
        for(int i = 1; i <= n; i++ ){
            memset(flip,0,sizeof(flip));
            int sum = 0;
            for(int j = 0; j < y[i].length(); j++){
                if(y[i][j] != x[1][j]) flip[j] = 1;
                sum += flip[j];
            }
            for(int j = 1; j <= n; j++){
                h[j] = "";
                for(int k = 0; k < x[i].length(); k++){
                    if(flip[k]) h[j] += '0'+(!(x[j][k] - '0'));
                    else h[j] += x[j][k];
                }
            }
            sort(h+1,h+n+1);
            //if(i == 1) for(int j = 1; j <= n; j++)
                          //  cout<<h[j]<<endl;
            bool flag = true;
            for(int j = 1; j <= n; j++)
                if(h[j] == y[j]) continue;
                else {flag = false;break;}

            if(flag) {
                if(ans != -1)
                    ans = min(ans,sum);
                else ans = sum;
            }
        }
        if(ans == -1)
            printf("Case #%d: NOT POSSIBLE\n",cas);
        else
            printf("Case #%d: %d\n",cas,ans);

    }
    return 0;
}
