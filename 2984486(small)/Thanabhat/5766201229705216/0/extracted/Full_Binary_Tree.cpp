/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

#define pii pair<int,int>

using namespace std;

int n,cnt[1024],cntall[1024];
vector<int> al[1024];
bool vs[1024];

int dfs1(int u){
    vs[u]=true;
    cnt[u]=0;
    cntall[u]=1;
    vector<pii > v;
    for(int i=0;i<al[u].size();i++)
    {
        if(!vs[al[u][i]])
        {
            dfs1(al[u][i]);
            v.push_back(pii(cntall[al[u][i]],cnt[al[u][i]]));
            cntall[u]+=cntall[al[u][i]];
        }
    }
    sort(v.begin(),v.end());
//    printf("> %d\n",u);
//    for(int i=0;i<v.size();i++)
//    {
//        printf(">> %d %d \n",v[i].first,v[i].second);
//    }
    if(v.size()==1)
    {
        cnt[u]=v[0].first;
    }else if(v.size()>=2)
    {
//        for(int i=v.size()-1;i>=v.size()-2;i--)
//            cnt[u]+=cnt[v[i].second];
//        for(int i=0;i<v.size()-2;i++)
//            cnt[u]+=v[i].first;
        int mm=999999;
        for(int i=0;i<v.size()-1;i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                int tmp = 0;
                for(int k=0;k<v.size();k++)
                {
                    if(k==i||k==j)
                    {
                        tmp+=v[k].second;
                    }else
                    {
                        tmp+=v[k].first;
                    }
                }
                mm=min(mm,tmp);
            }
        }
        cnt[u]=mm;
    }
//    printf("cntall = %d\n",cntall[u]);
//    printf(" === %d\n",cnt[u]);
    return cnt[u];
}

int solve(int cc){

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        al[i].clear();
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&a,&b);
        a--;b--;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int sol=n+1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            vs[j]=false;
//        printf("- %d\n",i);
        int tmp=dfs1(i);
        sol=min(sol,tmp);
//        printf("\n^^^  %d %d\n",i,tmp);
    }

    printf("Case #%d: %d\n",cc,sol);

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);

	return 0;
}
