#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int N;
int visited[1024];
int nchild[1024];
vector<vector<int> > grafo;

int dfs(int i, int root)
{
    //cout << i << " " << endl;
    visited[i]=1;
    int bests[2];
    bests[0]=-1;
    bests[1]=-1;
    int besti[2];

    if(nchild[i]<2) return 1;
    if(root!=-1 && nchild[i]<3) return 1;

    for(int j=0; j<nchild[i]; j++)
        if(grafo[i][j]!=root)
        {
            int deep=dfs(grafo[i][j],i);
            if(deep>bests[0])
            {
                bests[1]=bests[0];
                bests[0]=deep;
            }
            else if(deep>bests[1])
            {
                bests[1]=deep;
            }
        }

    return bests[0]+bests[1]+1;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin >> T;

    for(int tc=1; tc<=T; tc++)
    {
        cin >> N;
        grafo.clear();
        grafo.resize(N);
        memset(nchild,0,sizeof(nchild));

        for(int i=1; i<N; i++)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
            nchild[a]++;
            nchild[b]++;
        }
//cout << "Me la banco" << endl;


        int ans=N-1;
        for(int i=0; i<N; i++)
        {
            //memset(visited,0,sizeof(visited));
            //hijos(i);
            memset(visited,0,sizeof(visited));
            //cout << N << endl;
            //cout << nchild[i] << endl;
            //cout << "DFSEO " << i << endl << " " << N-dfs(i, -1) << endl;
            ans=min(ans,N-dfs(i, -1));
        }
        cout << "Case #" << tc << ": ";
        cout << ans;
        cout << endl;
    }
}
