//
//  main.cpp
//  GCJ1AA
//
//  Created by Ningchen Ying on 4/26/14.
//  Copyright (c) 2014 Ningchen Ying. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> outlet,device;
int N,L;

int x[100],y[100];

bool flag,getans;

int res;

void dfs(int h,vector<string> s,int ans){
    if(!flag) return;
    if(h==L){
        sort(s.begin(),s.end());
        for(int i=0;i<N;i++){
            if(s[i]!=device[i]) return;
        }
        res=min(res,ans);
        return;
    }
    if(x[h]==y[h]){
        dfs(h+1,s,ans);
        for(int i=0;i<N;i++){
            char a = s[i][h];
            char b = (1-(a-'0'))+'0';
            s[i][h]=b;
        }
        dfs(h+1,s,ans+1);
        
    }else if(x[h]==N-y[h]){
        for(int i=0;i<N;i++){
            char a = s[i][h];
            char b = (1-(a-'0'))+'0';
            s[i][h]=b;
        }
        dfs(h+1,s,ans+1);
    }else{
        flag=false;
    }
    return;
}

void init(){
    for(int i=0;i<L;i++){
        x[i]=0;
        y[i]=0;
        for(int j=0;j<N;j++){
            if(outlet[j][i]=='0') x[i]++;
            if(device[j][i]=='0') y[i]++;
        }
    }
}

int main(int argc, const char * argv[])
{

    int T;
    freopen("/Users/YNingC/Documents/CodeForces/GCJ1AA/GCJ1AA/A-small-attempt0.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ1AA/GCJ1AA/A-small-attempt0.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++){

        cin>>N>>L;
        res=L+1;
        flag=true;
        outlet.clear();
        device.clear();
        for(int i=0;i<N;i++){
            string A;
            cin>>A;
            outlet.push_back(A);
        }
        for(int i=0;i<N;i++){
            string B;
            cin>>B;
            device.push_back(B);
        }
        sort(device.begin(),device.end());
        init();
        //cout<<"OK"<<endl;
        dfs(0,outlet,0);
        cout<<"Case #"<<ca<<": ";
        if(res==L+1 || !flag) cout<<"NOT POSSIBLE"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}

