#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int min1;
bool chk(int l,vector<string> s1,vector<string> s2,bool *sel) {
    int n=s1.size();
    for(int i=0;i<l;i++) {
        if(sel[i]) {
            for(int j=0;j<n;j++) {
                if(s1[j][i]=='1') s1[j][i]='0';
                else s1[j][i]='1';
            }
        }
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    for(int i=0;i<n;i++) {
        if(s1[i]!=s2[i]) return false;
    }
    return true;
}
void solve(int i,int k,int l,bool *sel,vector<string> s1,vector<string> s2) {
    if(i==l) {
        if(chk(l,s1,s2,sel)) {
            min1=min(min1,k);
        }
    } else {
        sel[i]=false;
        solve(i+1,k,l,sel,s1,s2);
        sel[i]=true;
        solve(i+1,k+1,l,sel,s1,s2);
    }
}
int main() {
    int n,l,t;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++) {
        scanf("%d%d",&n,&l);
        vector<string> s1(n),s2(n);
        for(int i=0;i<n;i++) cin>>s1[i];
        for(int i=0;i<n;i++) cin>>s2[i];
        bool *sel=new bool[l];
        for(int i=0;i<l;i++) sel[i]=false;
        min1=10000;
        solve(0,0,l,sel,s1,s2);
        if(min1!=10000) {
            printf("Case #%d: %d\n",t1,min1);
        } else {
            printf("Case #%d: NOT POSSIBLE\n",t1);
        }
    }
    return 0;
}
