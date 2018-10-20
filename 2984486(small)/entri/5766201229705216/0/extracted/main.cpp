#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;
int T;
const int maxN = 1005;
const int INF  = 1000000;
//bool mark[maxN][maxN];

int N;
vector<pair<int,int> > Edge;
vector<int> AdjOf[maxN];
int DegreeOf[maxN];


int countFrom(int u){
    int res = 0;
    if (DegreeOf[u] == 1) return 1;
    vector<int> Q;
    Q.push_back(u);
    res++;
    bool visited[maxN];
    memset(visited,false,sizeof(visited));
    visited[u] = true;
    int dq = 0, cq = 0;
    while(dq <= cq){
        int u = Q[dq];
        visited[u] = true;
        dq++;
        for(int i = 0; i<AdjOf[u].size(); i++){
            int v = AdjOf[u][i];
            if (visited[v]) continue;

            if (DegreeOf[v] == 2){
                if (DegreeOf[u] == 2) res++;
                continue;
            }
            Q.push_back(v);
            res++;
            cq++;
        };
    };
    return res;
}


void solveIt(){
    int res = 0;
    for(int i = 1; i<=N; i++){
        int cnt = countFrom(i);
        //cout <<" from "<<i<<" : "<<cnt<<endl;
        res = max(res,cnt);
    };

    res = N - res;
    cout <<res<<endl;
}

void input(){
    cin >>T;
    for(int i = 1; i<=T;i++){
        cin >>N;
        Edge.clear();
        //memset(mark, false, sizeof(mark));
        memset(AdjOf, 0,sizeof(AdjOf));
        memset(DegreeOf, 0, sizeof(DegreeOf));
        for(int j = 1; j<N; j++){
            int x,y;
            cin >>x>>y;
            Edge.push_back(make_pair(x,y));
            AdjOf[x].push_back(y);
            DegreeOf[x]++;
            AdjOf[y].push_back(x);
            DegreeOf[y]++;
            //mark[x][y] = true;
            //mark[y][x] = true;
        }

        cout<<"Case #"<<i<<": ";
        solveIt();
    }
};
int main()
{
    input();
    //cout << "Hello world!" << endl;
    return 0;
}
