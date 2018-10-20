#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
        string s[150],t[150],u[150];
bool check(){
    for (int i=0;i<n;i++)
        if (s[i]!=t[i]) return false;
        return true;
}
int main(){
    int ttt,tt=0,m;
    cin>>ttt;
    while (tt++<ttt){
        cin>>n>>m;
        int ans=100;
        bool change[50];
        for (int i=0;i<n;i++) cin>>u[i];
        for (int i=0;i<n;i++) cin>>t[i];
        sort(t,t+n);
        for (int k=0;k<n;k++){
            memset(change,0,sizeof(change));
            int an=0;
            for (int i=0;i<n;i++)
                s[i]=u[i];
            for (int j=0;j<m;j++)
                if (s[k][j]!=t[0][j]) change[j]=true;
            for (int j=0;j<m;j++)
                if (change[j]){
                    for (int i=0;i<n;i++)
                        if (s[i][j]=='0') s[i][j]='1';
                        else s[i][j]='0';
                        an++;
                        }
            sort(s,s+n);
            if (check()) ans=min(ans,an);
        }
        if (ans==100) printf("Case #%d: NOT POSSIBLE\n",tt);
        else printf("Case #%d: %d\n",tt,ans);
    }
}
