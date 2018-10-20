#include <fstream>
#include <list>
using namespace std;

struct S
{
    int k, nk;
};
int t;
int n;
int now;
list<int> adj[1005];
int ans;
int cur_ans;

S Do(int node, int parent)
{
    int children;
    if(parent == 0)
        children = adj[node].size();
    else
        children = adj[node].size() - 1;
    int keep[1005];
    int notkeep[1005];
    S fin;
    fin.k = 0;
    fin.nk = 0;
    for(list<int>::iterator it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if(*it != parent)
        {
            S temp = Do(*it, node);   
            keep[*it] = temp.k;
            notkeep[*it] = temp.nk;
            fin.nk += temp.nk;
        }
    }
    if(children == 1)
    {
        fin.k = fin.nk;
        fin.nk += 1;
        return fin;  
    }
    fin.nk += 1;
    int cost[1005][3];
    int ind = 0;
    list<int>::iterator prev;
    for(list<int>::iterator it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if(*it != parent)
        {
            cost[*it][0] = 0;
            cost[*it][1] = 0;
            cost[*it][2] = 0;
            if(ind == 0)
            {
                cost[*it][0] = notkeep[*it];
                cost[*it][1] = keep[*it];
                cost[*it][2] = keep[*it];
            }
            else
            {
                cost[*it][0] = cost[*prev][0] + notkeep[*it];
                cost[*it][1] = min(cost[*prev][0] + keep[*it], cost[*prev][1] + notkeep[*it]);
                cost[*it][2] = min(cost[*prev][1] + keep[*it], cost[*prev][2] + notkeep[*it]);
            }
            prev = it;
            ind++;
        }
    }
    if(adj[node].size() == 0 && parent == 0)
    {
        fin.k = 0;
        return fin;
    }
    if(adj[node].size() == 1 && parent != 0)
    {
        fin.k = 0;
        return fin;
    }
    fin.k = cost[*prev][2];
    return fin;
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> t;
    now = 0;
    while(now < t)
    {
        for(int i = 1; i <= n; i++)
            adj[i].clear();
        ans = 2000;
        in >> n;
        for(int i = 0; i < n - 1; i++)
        {
            int temp1, temp2;
            in >> temp1;
            in >> temp2;
            adj[temp1].push_back(temp2);
            adj[temp2].push_back(temp1);
        }
        for(int i= 0; i < n; i++)
        {
            cur_ans = 0;
            S temp = Do(i + 1, 0);
            ans = min(ans, temp.k);
        }
        out << "Case #" << now + 1 << ": " << ans << endl;
        now++;
    }
}
