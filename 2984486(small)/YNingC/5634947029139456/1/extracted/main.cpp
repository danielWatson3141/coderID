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

vector<long long> outlet,device;
int N,L;

bool flag,getans;

vector<long long> ync;

long long calc(string a){
    long long res=0;
    for(int i=0;i<a.length();i++){
        res=res*2+a[i]-'0';
    }
    return res;
}

int main(int argc, const char * argv[])
{

    int T;
    freopen("/Users/YNingC/Documents/CodeForces/GCJ1AA/GCJ1AA/A-large.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ1AA/GCJ1AA/A-large.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++){

        cin>>N>>L;
        int ans=L+1;
        flag=false;
        outlet.clear();
        device.clear();
        ync.clear();
        for(int i=0;i<N;i++){
            string A;
            cin>>A;
            outlet.push_back(calc(A));
        }
        for(int i=0;i<N;i++){
            string B;
            cin>>B;
            device.push_back(calc(B));
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ync.push_back(device[i]^outlet[j]);
            }
        }
        
        sort(ync.begin(),ync.end());
        
        int m=1;
        long long t=0;
        
        for(int i=1;i<ync.size();i++){
            //cout<<ync[i]<<endl;
            if(ync[i]==ync[i-1]) m++;
            else{
                if(m==N){
                    flag=true;
                    t=ync[i-1];
                    int res=0;
                    for(int i=0;i<L;i++){
                        if(t%2==1) res++;
                        t/=2;
                    }
                    //cout<<"res="<<res<<endl;
                    ans=min(res,ans);
                }
                m=1;
            }
            
        }
        if(m==N){
            flag=true;
            t=ync[ync.size()-1];
            int res=0;
            for(int i=0;i<L;i++){
                if(t%2==1) res++;
                t/=2;
            }
            //cout<<"res="<<res<<endl;
            ans=min(res,ans);
        }
        
        cout<<"Case #"<<ca<<": ";
        if(!flag) cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}

