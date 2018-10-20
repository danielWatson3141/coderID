#include<cstdio>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;

typedef pair<int,int> state;
bool operator<(state a, state b)
{
    return a.first < b.first;
}

//for tree
int n;
set<int> s[1005];

//solving
bool visited[1005];
int cut(int node)
{
    int ans = 1;
    visited[node] = true;
    for(set<int>::iterator it=s[node].begin();it!=s[node].end();it++) if(!visited[*it])
    {
        ans += cut(*it);
    }
    return ans;
}
int cutAll(int node, int parent)
{
    for(int c=1;c<=n;c++) visited[c] = false;
    visited[parent] = true;
    return cut(node);
}
int solve(int node, int parent)
{
    //only has parent
    if(s[node].size()==1) return 0;
    //has 1 child + 1 parent, delete child
    if(s[node].size()==2)
    {
        for(set<int>::iterator it=s[node].begin();it!=s[node].end();it++) if(*it!=parent)
        {
            return cutAll(*it,node);
        }
    }
    int ans = 0;
    set<state> sorting;
    for(set<int>::iterator it=s[node].begin();it!=s[node].end();it++) if(*it!=parent)
    {
        sorting.insert(make_pair(cutAll(*it,node),*it));
    }
    while(sorting.size()>2)
    {
        ans += sorting.begin()->first;
        sorting.erase(sorting.begin());
    }
    while(sorting.size()>0)
    {
        ans += solve(sorting.begin()->second,node);
        sorting.erase(sorting.begin());
    }
    /*for(set<int>::iterator it=s[node].begin();it!=s[node].end();it++) if(*it!=parent)
    {
        sorting.insert(make_pair(solve(*it,node),*it));
    }
    set<state>::iterator it = sorting.begin();
    ans += it->first;
    it++;
    ans += it->first;
    it++;
    for(;it!=sorting.end();it++)
    {
        ans += cutAll(it->second,node);
    }*/
    sorting.clear();
    return ans;
}
int solving(int root)
{
    if(s[root].size()==0) return 0;
    if(s[root].size()==1) return cutAll(*(s[root].begin()),root);
    int ans = 0;
    set<state> sorting;
    for(set<int>::iterator it=s[root].begin();it!=s[root].end();it++)
    {
        sorting.insert(make_pair(cutAll(*it,root),*it));
    }
    while(sorting.size()>2)
    {
        ans += sorting.begin()->first;
        sorting.erase(sorting.begin());
    }
    while(sorting.size()>0)
    {
        ans += solve(sorting.begin()->second,root);
        sorting.erase(sorting.begin());
    }
    /*for(set<int>::iterator it=s[root].begin();it!=s[root].end();it++)
    {
        sorting.insert(make_pair(solve(*it,root),*it));
    }
    set<state>::iterator it = sorting.begin();
    ans += it->first;
    it++;
    ans += it->first;
    it++;
    for(;it!=sorting.end();it++)
    {
        ans += cutAll(it->second,root);
    }*/
    sorting.clear();
    return ans;
}

int main()
{
    int T,a,b,c,ans;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d",&n);
        for(c=0;c<n-1;c++)
        {
            scanf("%d%d",&a,&b);
            s[a].insert(b);
            s[b].insert(a);
        }
        ans = n+n;
        for(c=1;c<=n;c++) ans = min(ans,solving(c));
        for(c=1;c<=n;c++) s[c].clear();
        printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}
