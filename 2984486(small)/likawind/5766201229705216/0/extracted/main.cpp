//
//  main.cpp
//  A
//
//  Created by Zhou Sun on 4/25/14.
//  Copyright (c) 2014 Zhou Sun. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int>f[2000];
int z[2000];
int dfs(int root){
    //cout<<"b"<<root<<endl;
    z[root]=1;
    int m1=0;
    int m2=0;
    for (int i=0; i<f[root].size(); i++) {
        int j=f[root][i];
        if (!z[j]) {
            int k=dfs(j);
            if (k>=m1) {
                m2=m1;m1=k;
            }
            else{
                if (k>m2) {
                    m2=k;
                }
            }
        }
    }
    if (m2==0) {
        m1=0;
    }
    //cout<<"e"<<root<<' '<<m1+m2<<endl;
    return m1+m2+1;
}
int main(int argc, const char * argv[])
{
    freopen ("b.in.txt","r",stdin);
 freopen ("b.out.txt","w",stdout);
    int ts,n,x,y;
    cin>>ts;
    for (int tt=1; tt<=ts;tt++) {
        cin>>n;
        for (int i=0;i<n; i++) {
            f[i].clear();
        }
        for (int i=0; i<n-1; i++) {
            cin>>x>>y;
            f[x-1].push_back(y-1);
            f[y-1].push_back(x-1);
        }
        int mi=n;
        for (int i=0; i<n; i++) {
            memset(z, 0, sizeof(z));
            mi=min(mi,n-dfs(i));
        }
        cout<<"Case #"<<tt<<": "<<mi<<endl;
    }
    // insert code here...
    return 0;
}

