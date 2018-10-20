#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int n,l,ans;
char s[155][45],a[155][45];
int b[155];

void dfs(int x,int cnt){
    if (x>=l){
       int flag=0;
       for (int i=0;i<n;i++)
       for (int j=0;j<n;j++)
           if (!strcmp(s[i],a[j])) flag++;
       if (flag==n && cnt<ans) ans=cnt;
       return;
    }
    dfs(x+1,cnt);
    for (int i=0;i<n;i++)
        if (s[i][x]=='0') s[i][x]='1'; else s[i][x]='0';
    dfs(x+1,cnt+1);
    for (int i=0;i<n;i++)
        if (s[i][x]=='0') s[i][x]='1'; else s[i][x]='0';
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for (int _=1;_<=T;_++){
        cin>>n>>l;
        for (int i=0;i<n;i++) scanf("%s",s[i]);
        for (int i=0;i<n;i++) scanf("%s",a[i]);
        ans=100000000;
        dfs(0,0);
        if (ans<100000000) printf("Case #%d: %d\n",_,ans); else printf("Case #%d: NOT POSSIBLE\n",_);
    }
    //system("pause");
}
/*
3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01

*/
