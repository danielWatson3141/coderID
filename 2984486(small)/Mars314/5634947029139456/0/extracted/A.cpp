#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int L =50;
const int N =150;
int n,l;
string a[N];
string b[N];
string c[N];
int init(){
    cin >> n >> l;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    sort(b,b+n);
}
int dy[N];
char st[N];
int check(){
    for(int i=0;i<n;i++)if(b[i]!=c[i])return 0;
    return 1;
}
int count(){
    int ans=0;
    for(int i=0;i<l;i++)ans+=dy[i];
    return ans;
}
int ans(){
    int ans=l+1;
    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
        dy[j]=(a[0][j]==b[i][j])?0:1;
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<l;k++){
            st[k]=((a[j][k]-'0')^dy[k])+'0';
            }
            st[l]=0;
            string tmp(st);
            c[j]=tmp;
        }
        sort(c,c+n);
        if(check()){ans=min(ans,count());}
    }
    if(ans<=l)printf("%d\n",ans);
    else printf("NOT POSSIBLE\n");
}
int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
    init();
    printf("Case #%d: ",t);
    ans();
    }
}
