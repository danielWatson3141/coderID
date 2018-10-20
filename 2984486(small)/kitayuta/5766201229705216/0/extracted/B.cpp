#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dpcut,dpelem;
int elem(int at,int from,vector<vector<int>> es){
    if(dpelem[at]>-1) return dpelem[at];
    vector<int> ss;
    for(int i=0;i<es[at].size();i++){
        if(es[at][i]!=from) ss.push_back(es[at][i]);
    }
    int ret=1;
    for(auto x : ss) ret+=elem(x,at,es);
    return ret;
}
int cut(int at,int from,vector<vector<int>> es){
    if(dpcut[at]>-1) return dpcut[at];
    vector<int> ss;
    for(int i=0;i<es[at].size();i++){
        if(es[at][i]!=from) ss.push_back(es[at][i]);
    }
    if(ss.size()==0) return 0;
    if(ss.size()==1) return elem(ss[0],at,es);
    if(ss.size()==2) return cut(ss[0],at,es)+cut(ss[1],at,es);
    int ret=elem(at,from,es)-1;
    vector<int> ds;
    for(int x : ss) ds.push_back(cut(x,at,es)-elem(x,at,es));
    sort(begin(ds),end(ds));
    return ret+ds[0]+ds[1];
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ix=1;ix<=T;ix++){
        printf("Case #%d: ",ix);
        int N;
        scanf("%d",&N);
        vector<vector<int>> es(N);
        int a,b;
        for(int i=0;i<N-1;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            es[a].push_back(b);
            es[b].push_back(a);
        }
        int mi=10000;
        for(int i=0;i<N;i++){
            dpcut=vector<int>(N,-1);
            dpelem=vector<int>(N,-1);
            mi=min(mi,cut(i,-1,es));
        }
        printf("%d\n",mi);
    }
}
