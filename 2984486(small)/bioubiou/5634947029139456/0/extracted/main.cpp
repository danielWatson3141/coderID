#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;


int a[1000];
int b[1000];
int c[1000];
string st1[1000],st2[1000];
int n,l;
void change(int x){
    for(int i=0;i<n;i++){
        st2[i][x]=(st2[i][x]=='1'?'0':'1');
    }
}
int ret,res;
int check(){
    sort(st2,st2+n);
    for(int i=0;i<n;i++){if(st1[i]!=st2[i])return 0;}
    return 1;
}
void dfs(int u){
    if(u==l){
        if(check()){
            ret=min(ret,res);
        }
        return;
    }
    if(c[u]==2){
        dfs(u+1);
        change(u);
        res++;
        dfs(u+1);
        change(u);
        res--;
    }
    else
        dfs(u+1);
}
int main()
{
    //freopen("C://Users//Jo//Downloads//A-small-attempt7.in","r",stdin);
    //freopen("C://Users//Jo//Downloads//out.txt","w",stdout);

    int t;

    int cas=1;
    int flag;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        flag=1;
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;i++){
            cin>>st1[i];
        }
        for(int i=0;i<n;i++){
            cin>>st2[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<l;j++){
                if(st1[i][j]=='1')
                    a[j]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<l;j++){
                if(st2[i][j]=='1')
                    b[j]++;
            }
        }
        int ans=0;
        for(int i=0;i<l;i++){
            if(a[i]==b[i]){
                if(a[i]==n-b[i]){
                    c[i]=2;
                }
                    continue;
            }
            else if(a[i]==n-b[i]){
                ans++;
                c[i]=1;
            }
            else {
                flag=0;break;
            }
        }
        for(int i=0;i<l;i++){
            if(c[i]==1){
                change(i);
            }
        }
        sort(st1,st1+n);
        sort(st2,st2+n);
        //if(check())printf("dsafkjhdsk\n");
        if(flag){
            ret=2*n;res=0;
            dfs(0);
        }
        printf("Case #%d: ",cas++);
        if(flag&&ret<=n){
            printf("%d\n",ans+ret);
        }
        else printf("NOT POSSIBLE\n");
    }
    return 0;
}
/*2 8
00010001 01010001
00111100 01111100
6 5
00010 01010 00110 10000 10100 01110
01001 00101 11011 11111 01101 00001
4 9
000000100 111010000 010000100 001110000
001101111 111001111 110111011 100111011*/
