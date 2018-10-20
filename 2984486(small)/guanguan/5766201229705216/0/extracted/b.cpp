#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> adjlist[15];
bool visited[15];
bool tmp_visited[15];

bool dfs(int a)
{
     if (tmp_visited[a])
     {
        return true;
     }
     tmp_visited[a]=true;
     int cnt=0;
     bool legit=false;
     for (int i=0; i<adjlist[a].size(); i++)
     {
         if (!tmp_visited[adjlist[a][i]])
         {
            cnt+=1;
            if (!dfs(adjlist[a][i]))
            {
               return false;
            }
         }
     }
     //printf("dfs: %d, cnt: %d\n",a,cnt);
     if (cnt==0 || cnt==2)
     {
        return true;
     }
     else
     {
         return false;
     }
}

int main()
{
    freopen("b.txt","r",stdin);
    freopen("b_out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int a=0; a<tc; a++)
    {
        //printf("Case #%d: %d",a+1,ans);
        int n,tmp,tmp2;
        scanf("%d",&n);
        for (int i=0; i<n; i++)
        {
            adjlist[i].clear();
        }
        for (int i=0; i<n-1; i++)
        {
            scanf("%d%d",&tmp,&tmp2);
            adjlist[tmp-1].push_back(tmp2-1);
            adjlist[tmp2-1].push_back(tmp-1);
        }
        int bitmask=0;
        int tmp_cnt,cnt=1000000000;
        for (int i=0; i<(1<<n); i++)
        {
            tmp_cnt=0;
            for (int j=0; j<n; j++)
            {
                if ((bitmask&(1<<j))>0)
                {
                   visited[j]=true;
                   tmp_cnt+=1;
                }
                else
                {
                    visited[j]=false;
                }
            }
            bool legit=false;
            for (int i=0; i<n; i++)
            {
                if (visited[i])
                {
                   continue;
                }
                for (int j=0; j<n; j++)
                {
                    tmp_visited[j]=visited[j];
                }
                if (!dfs(i))
                {
                   continue;
                }
                bool succ=true;
                for (int j=0; j<n; j++)
                {
                    if (!tmp_visited[j])
                    {
                       succ=false;
                       break;
                    }
                }
                if (succ)
                {
                   //printf("root:%d\n",i);
                   legit=true;
                   break;
                }
                else
                {
                    //printf("FAILED\n");
                }
            }
            if (legit)
            {
               //printf("bm:%d\n",bitmask);
               cnt=min(cnt,tmp_cnt);
            }
            bitmask+=1;
        }
        printf("Case #%d: %d\n",a+1,cnt);
    }
}
