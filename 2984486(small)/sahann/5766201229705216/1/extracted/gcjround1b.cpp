#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


void buildtree(vector <vector <int> >  &AdjList, vector <vector <int> > &vvi,int rt,int parent){
    for(int i = 0;i<AdjList[rt].size();i++){
        if(AdjList[rt][i]!=parent){
            vvi[rt].push_back(AdjList[rt][i]);
            buildtree(AdjList, vvi,AdjList[rt][i],rt);
        }
    }
}
int bsttree(vector <vector <int> > &vvi, int rt){
        vector <int> vi;
    if(vvi[rt].size()<2) return 1;
    for(int j=0;j<vvi[rt].size();j++){
        int k;
        k= bsttree(vvi,vvi[rt][j]);
        vi.push_back(k);
    }
    sort(vi.begin(),vi.end());
    reverse(vi.begin(),vi.end());
    
    
    return vi[0]+vi[1]+1;
    
}
int tryasroot(vector <vector <int> > &AdjList, int N,int rt){
    int ret = 0;
    vector <vector <int> > vvi;
    vvi.resize(N);
    buildtree(AdjList, vvi,rt,-1);
    ret = bsttree(vvi,rt);
    return ret;
}
int main(int argc, const char * argv[])
{
    
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int N;
        cin >> N;
        vector <vector <int> > AdjList;
        AdjList.resize(N);
        for(int i=0;i<N-1;i++){
            int X,Y;
            cin >> X >> Y;
            X--;Y--;
            AdjList[X].push_back(Y);
            AdjList[Y].push_back(X);
            
        }
        int bst = -1;
        for(int i=0;i<N;i++){
            int k = tryasroot(AdjList,N,i);
            bst = max(k,bst);
        }
        
        cout << "Case #"<<t+1 <<": " <<N-bst <<  endl;
    }
    return 0;
}

