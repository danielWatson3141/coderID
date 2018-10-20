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
#define MAX_N 1005
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
mat A;
int N;
int C[MAX_N][MAX_N];
int calc(int n,int p){
    if (C[n][p]>=0) {
        return C[n][p];
    }
    int max1=0,max2=0;
    for (int i=0; i<N; i++) {
        if (i!=p&&A[n][i]) {
            int sum=calc(i, n);
            if (sum>max1) {
                max2=max1;
                max1=sum;
            }
            else if(sum>max2){
                max2=sum;
            }
        }
    }
    if (max1*max2==0&&!(max1==0&&max2==0)) {
        return 1;
    }
    return C[n][p]=max1+max2+1;
}
void solve(){
    int ans=0;
    memset(C, -1, sizeof(C));
    for (int i=0; i<N; i++) {
        ans=max(ans,calc(i,N));
    }
    cout<<N-ans<<endl;
}
int main()
{
    freopen("/Users/mascure/Desktop/B-large.in", "r", stdin);
    freopen("/Users/mascure/Desktop/B-large.out", "w", stdout);
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int T;
    cin>>T;
    for (int i=1; i<=T; i++) {
        cin>>N;
        A.clear();
        A.resize(N, vec(N));
        for (int j=0; j<N-1; j++) {
            int x,y;
            cin>>x>>y;
            x--;y--;
            A[x][y]=A[y][x]=1;
        }
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}

