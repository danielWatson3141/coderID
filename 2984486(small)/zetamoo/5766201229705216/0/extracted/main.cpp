#include <vector>
#include <iterator>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> graph[1050];

int dfs(int i,int from)
{
    if(graph[i].size()+(from==-1)<=2)
        return 1;
    vector<int> sizes;
    for(int f=0;f<graph[i].size();f++)
        if(graph[i][f]!=from)
            sizes.push_back(dfs(graph[i][f],i));
    sort(sizes.begin(),sizes.end());
    return 1+sizes[sizes.size()-1]+sizes[sizes.size()-2];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,T=0;
    cin>>t;
    while(t--)
    {
        cout<<"Case #"<<++T<<": ";
        for(int f=0;f<1050;f++)
            graph[f].clear();
        int n;
        cin>>n;
        for(int f=0;f<n-1;f++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int ans=n;
        for(int f=1;f<=n;f++)
        {
            ans=min(n-dfs(f,-1),ans);
        }
        cout<<ans<<endl;
    }
}
