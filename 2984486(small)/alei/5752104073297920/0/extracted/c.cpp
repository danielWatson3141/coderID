#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
typedef long long int uli;
using namespace std;

const int mx = 1000;
int d[mx];
int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t,n;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        int neq = 0;
        for(int i=0;i<n;i++){
            cin>>d[i];
            if(d[i]==i) neq++;
        }
        cout<<"Case #"<<tc<<": ";
        if(neq>=200) cout<<"GOOD";
        else{
            int v = rand()%2;
            if(v==0) cout<<"GOOD";
            else cout<<"BAD";
        }
        cout<<endl;
    }
    return 0;
}
