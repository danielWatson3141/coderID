#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> VI;

VI tree[1010];
int N;
int T;

int go(int cur,int parent){
    vector<int> v;
    for(int i=0;i<tree[cur].size();++i){
        if(tree[cur][i]==parent){
            continue;
        }
        v.push_back(go(tree[cur][i],cur));
    }
    if(v.size()<=1){
        return 1;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return 1+v[0]+v[1];
}

int main(){
    int from,to,i;
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for(int cas=1;cas<=T;++cas){
        cin>>N;
        for(i=1;i<=N;++i) tree[i].clear();
        for(i=1;i<N;++i){
            cin>>from>>to;
            tree[from].push_back(to);
            tree[to].push_back(from);
        } 
        int res = 0;
        for(i=1;i<=N;++i){
            res>?=go(i,-1);
        }   
        cout<<"Case #"<<cas<<": "<<N-res<<endl;
        cerr<<"Case #"<<cas<<": "<<N-res<<endl;
        
        
    }    
    return 0;
}
