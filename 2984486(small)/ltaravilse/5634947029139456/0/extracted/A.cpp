#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;

#define INF 1000000000
int capacity[1000][1000];
int flujo[1000][1000];
vector<vector<int> > lista;
int edmondsKarp(int source, int sink) {
    int n = lista.size(), f = 0;
    forn(i,n) forn(j,n)  flujo[i][j] = 0;
    vector<int> m(n),p(n);
    while(true)
    {
        forn(i,n) p[i] = -1;
        p[source] = -2;
        m[sink] = 0;
        m[source] = INF;
        queue<int> cola;
        cola.push(source);
        bool b = true;
        while(!cola.empty()&& b)
        {
            int v = cola.front(); cola.pop();
            forn(i,lista[v].size())
            {
                int vec = lista[v][i];
                if(capacity[v][vec] > flujo[v][vec] && p[vec] == -1)
                {
                    p[vec] = v;
                    m[vec] = min(m[v],capacity[v][vec]-flujo[v][vec]);
                    cola.push(vec);
                    if(vec==sink){
                        b = false;
                        break;
                    }
                }
            }
        }
        if(b==true)  break;
        f+=m[sink];
        int v = sink;
        while(v!=source) {
            flujo[p[v]][v] += m[sink];
            flujo[v][p[v]] -= m[sink];
            v = p[v];
        }
    }
    return f;
}

void init(int n)
{
    memset(capacity,0,sizeof(capacity));
    lista.clear();
    lista.resize(n);
    forn(i,n)
        lista[i].clear();
    return;
}
void addEje(int a, int b, int c)
{
    capacity[a][b] = c;
    capacity[b][a] = c;
    lista[a].push_back(b);
    lista[b].push_back(a);
    return;
}

int calc(vector<string> vec1, vector<string> vec2, int pos)
{
    int l = vec1[0].size();
    int n = vec1.size();
    int res = 0;
    forn(i,l)
    {
        if(vec1[0][i]!=vec2[pos][i])
        {
            forn(j,n)
            {
                if(vec1[j][i] == '0')
                    vec1[j][i] = '1';
                else
                    vec1[j][i] = '0';
            }
            res++;
        }
    }
    init(n*2+2);
    forn(i,n)
        addEje(0,i+1,1);
    forn(i,n)
        addEje(n+1+i,2*n+1,1);
    forn(i,n)
    forn(j,n)
    if(vec1[i] == vec2[j])
        addEje(i+1,n+1+j,1);
    if(edmondsKarp(0,2*n+1)==n)
        return res;
    return l+1;
}

int main()
{
    freopen("A-small.in","r",stdin);
    freopen("A.out","w",stdout);
    int casos;
    cin >> casos;
    for(int casito = 1; casito <= casos; casito++)
    {
        int n,l;
        cin >> n>>l;
        vector<string> vec1(n),vec2(n);
        forn(i,n)
            cin >> vec1[i];
        forn(i,n)
            cin >> vec2[i];
        int res = l+1;
        forn(i,n)
            res = min(res,calc(vec1,vec2,i));
        cout << "Case #" <<casito <<": ";
        if(res == l+1)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << res << endl;
    }
}
