#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

vector< vector<int> > g;

int treesize(int r, int p)
{
    vector<int> c;
    for (int i=0;i<g[r].size();i++){
        if(g[r][i] != p)
            c.push_back(g[r][i]);
    }
    //if(c.size() == 0)return 1;
    if(c.size() <= 1)return 1;
    int m1=0, m2=0;

    for (int i=0;i<c.size();i++){
        int s = treesize(c[i], r);
        if(s>m1){
            m2=m1;
            m1=s;
        }else if(s>m2){
            m2=s;
        }
    }
    return m1+m2+1;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int t, T, n,a,b;
    cin >> T;
    for (t=1;t<=T;t++){
        cin >>n;
        g = vector<vector<int> >(n);
        for (int i=1;i<n;i++){
            cin>>a>>b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }/*
        for(int i=0;i<g.size();i++){
            cerr << i << " : ";
            for(int j=0;j<g[i].size();j++){
                cerr <<g[i][j]<<" ";
            }
            cerr<<endl;
        }*/
        int i,ms=1;

        for(i=0;i<n;i++){
            if(g[i].size()<=1)continue;
            //vector<bool> v(n, false);
            int s=treesize(i, -1);
            if(s>ms){
                ms=s;
            }
        }
        cout << "Case #" <<t<<": "<<n-ms<<"\n";
    }
}
