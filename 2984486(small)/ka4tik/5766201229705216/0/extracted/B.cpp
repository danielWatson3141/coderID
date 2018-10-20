/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
#define MAXN 1111
#define db(x) cerr << #x << ": " << x << endl;
#define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define db7(a, b, c, d, e, f,g) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << " : "<<g<<endl;
vector<int> g[MAXN];
vector<int> ans;
vector<int> child;
int dfs(int u,int prev)
{
    int c=0;
    int sum=0;
    int cnt=0;
    vector<int> t;
    vector<int> p;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=prev)
        {
            dfs(v,u);
            t.push_back(ans[v]);
            //if(child[v]==0)
                //child[u]+=1;
            //else
            child[u]+=1+child[v];
            sum+=t.back();
            p.push_back(v);
            c++;
        }
    }
    //db2(u,child[u]);
    sort(t.begin(),t.end());
    if(c==0)
    {
        ans[u]=0;
    }
    else if(c==1)
    {
        ans[u]=child[u];
    }
    else if(c==2)
    {
        ans[u]=t[0]+t[1];
    }
    else 
    {

        int a=INT_MAX;
        //db(child[u]);
        for(int i=0;i<p.size();i++)
        {
            for(int j=0;j<p.size();j++)
            {
                if(i==j) continue;
                    a=min(a,child[u]-(1+child[p[i]])-(1+child[p[j]])+ans[p[i]]+ans[p[j]]);
                    //if(u==3)
                    //{
                        //db7(i,j,child[p[i]],child[p[j]],p[i],p[j],child[u]-(1+child[p[i]])-(1+child[p[j]])+t[i]+t[j]);
                    //}
            }
        }
        ans[u]=a;
    }

}
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int N,test;s(test);
    int kase=0;
    while(test--)
    {
        kase++;
        s(N);
        for(int i=0;i<N;i++) g[i].clear();
        for(int i=0;i<N-1;i++)
        {
            int a,b;s(a);s(b);
            a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int fans=N-1;
        for(int i=0;i<N;i++)
        {
            //db2("round",i);
            ans.assign(N,INT_MAX);
            child.assign(N,0);
            dfs(i,-1);
            fans=min(fans,ans[i]);
            //for(int j=0;j<N;j++)
            //db2(j,ans[j]);
            //for(int j=0;j<N;j++)
            //db2(j,child[j]);
            //db(ans[i]);
        }
        printf("Case #%d: %d\n",kase,fans);
    }
    return 0;
}

