//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#define MAX_N 15
#define MAX_Q 100005
#define MAX_M 15
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
int N,L;
map<string,int> s1,s2;
bool flip(int t){
    map<string, int> tmp;
    for (map<string, int>::iterator iter=s1.begin(); iter!=s1.end(); iter++) {
        string s=iter->first;
        for (int i=0; i<s.length(); i++) {
            if (t>>i&1) {
                if (s[i]=='0') {
                    s[i]='1';
                }
                else
                    s[i]='0';
            }
        }
        tmp[s]=1;
    }
    bool ans=true;
    for (map<string, int>::iterator iter=s2.begin();iter!=s2.end() ; iter++) {
        if (tmp[iter->first]!=1) {
            ans=false;
            break;
        }
    }
    return ans;
}
int calc(int n){
    int sum=0;
    while (n>0) {
        if (n&1) {
            sum++;
        }
        n>>=1;
    }
    return sum;
}
void solve(){
    int ans=-1;
    for (int t=0; t< 1<<L; t++) {
        if(flip(t)){
            ans=calc(t);break;
        }
    }
    if (ans>=0) {
        cout<<ans<<endl;
    }
    else
        cout<<"NOT POSSIBLE"<<endl;
}
int main()
{
    freopen("/Users/mascure/Desktop/A-small-attempt1.in", "r", stdin);
    freopen("/Users/mascure/Desktop/A-small-attempt1.out", "w", stdout);
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int T;
    cin>>T;
    for (int i=1; i<=T; i++) {
        cin>>N>>L;
        s1.clear();
        s2.clear();
        string str;
        for (int j=0; j<N; j++) {
            cin>>str;
            s1[str]=1;
        }
        for (int j=0; j<N; j++) {
            cin>>str;
            s2[str]=1;
        }
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}

