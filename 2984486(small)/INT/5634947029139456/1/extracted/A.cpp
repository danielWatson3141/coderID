#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int> > a;
vector<vector<int> > b;
vector<vector<int> > c;
vector<int> vec;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int n,l;
        scanf("%d%d",&n,&l);
        a.clear();
        for (int i=0;i<n;i++)
        {
            vec.clear();
            char ch;
            scanf("%c",&ch);
            for (int j=0;j<l;j++)
            {
                scanf("%c",&ch);
                vec.push_back(ch-'0');
            }
            a.push_back(vec);
        }
        b.clear();
        for (int i=0;i<n;i++)
        {
            vec.clear();
            char ch;
            scanf("%c",&ch);
            for (int j=0;j<l;j++)
            {
                scanf("%c",&ch);
                vec.push_back(ch-'0');
            }
            b.push_back(vec);
        }
        sort(b.begin(),b.end());
        /*
        for (int i=0;i<n;i++)
        {
            printf("A: ");
            for (int j=0;j<l;j++)
                printf("%d",a[i][j]);
            printf("\n");
        }
        for (int i=0;i<n;i++)
        {
            printf("B: ");
            for (int j=0;j<l;j++)
                printf("%d",b[i][j]);
            printf("\n");
        }
        */

        int ans=10000000;
        for (int u=0;u<n;u++)
            for (int v=0;v<n;v++)
            {
                int cnt=0;
                for (int j=0;j<l;j++)
                    cnt+=(a[u][j]!=b[v][j]);
                c.clear();
                for (int i=0;i<n;i++)
                {
                    vec.clear();
                    for (int j=0;j<l;j++)
                        vec.push_back(a[i][j]^a[u][j]^b[v][j]);
                    c.push_back(vec);
                }
                sort(c.begin(),c.end());
                int flag=1;
                for (int i=0;i<n;i++)
                    for (int j=0;j<l;j++)
                        if (b[i][j]!=c[i][j]) flag=0;
                if (flag && cnt<ans) ans=cnt;
            }
        if (ans==10000000) printf("Case #%d: NOT POSSIBLE\n",t);
        else printf("Case #%d: %d\n",t,ans);

    }
    return 0;
}
