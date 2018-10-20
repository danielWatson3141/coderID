#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool wyplul=false;
int T, n, wynik, tempw;
vector<int> G[1021];
int dzieci[1021];
bool odw[1021];

void dfs(int start)
{
    odw[start]=true;
    for(int i=0; i<G[start].size(); ++i)
    {
        if(!odw[G[start][i]]) dfs(G[start][i]);
    }
    for(int i=0; i<G[start].size(); ++i)
        dzieci[start]+=dzieci[G[start][i]];
    dzieci[start]++;
}

void bfs(int start)
{
    odw[start]=true;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty())
    {
        int temp=Q.front(); Q.pop();
        int sajz=G[temp].size();
        //cout << temp << " " << sajz << endl;
        if(sajz==0);
        else if(sajz==1) {if(!odw[G[temp][0]]) tempw+=dzieci[G[temp][0]];}
        else if(sajz==2)
        {
            int synow=0;
            for(int i=0; i<G[temp].size(); ++i) if(!odw[G[temp][i]]) synow++;
            if(synow==2)
            {
                for(int i=0; i<G[temp].size(); ++i)
                {
                    if(!odw[G[temp][i]])
                    {
                        odw[G[temp][i]]=true;
                        Q.push(G[temp][i]);
                    }
                }
            }
            else
            {
                for(int i=0; i<G[temp].size(); ++i)
                    if(!odw[G[temp][i]]) tempw+=dzieci[G[temp][i]];
            }
            //cout << tempw << endl;
        }
        else
        {
            //while(G[temp].size()>2) G[temp].pop_back();
            int it=0, wrzucone=0;
            //for(; it>=2; --it) tempw+=dzieci[G[temp][it]];
            //cout << it << endl;
            for(; it<G[temp].size(); ++it)
            {
                if(!odw[G[temp][it]])
                {
                    wrzucone++;
                    odw[G[temp][it]]=true;
                    Q.push(G[temp][it]);
                }
                if(wrzucone==2) break;
            }
            it++;
            for(; it<G[temp].size(); ++it) if(!odw[G[temp][it]]) tempw+=dzieci[G[temp][it]];
        }
        //cout << tempw << endl;
        //for(int i=0; i<G[temp].size(); ++i)
    }
}

bool sortuj(int a, int b)
{
    if(dzieci[a]>dzieci[b]) return false;
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> T;
    for(int lzd=1; lzd<=T; ++lzd)
    {
        cin >> n;
        for(int i=1; i<=n-1; ++i)
        {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        wynik=2014;
        for(int i=1; i<=n; ++i)
        {
            //cout << i << ":" << endl;
            dfs(i);

            //for(int i=1; i<=n; ++i) cout << dzieci[i] << " ";
            //cout << endl;
            for(int i=1; i<=n; ++i) sort(G[i].begin(), G[i].end(), sortuj);
            for(int i=1; i<=n; ++i) odw[i]=false;
            wyplul=false; tempw=0;
            bfs(i);
            //cout << tempw << endl;
            wynik=min(wynik, tempw);
            for(int i=1; i<=n; ++i) {odw[i]=false; dzieci[i]=0;}
        }
        cout << "Case #" << lzd << ": " << wynik << endl;
        for(int i=1; i<=n; ++i) G[i].clear();
    }
    return 0;
}
