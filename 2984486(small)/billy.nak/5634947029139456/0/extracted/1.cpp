#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int x[2000];
int a[2000][2000];
int s[2000][2000];

void solve()
{
    int n,l;
    scanf("%d %d\n",&n,&l);

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<l;j++)
            a[i][j] = getchar() - '0';
        getchar();
    }
    

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<l;j++)
            s[i][j]=getchar() - '0';
        getchar();
    }


    int ans = l+1;

    vector<int> v;
    vector<vector<int> > vv;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            int steps = 0;
            for (int k=0;k<l;k++)
            {
                x[k] = (a[i][k] != s[j][k]);
                if ( a[i][k] != s[j][k] ) steps++;
            }

            for (int k=0;k<l;k++)
                v.push_back(x[k]);
            v.push_back(steps);

            vv.push_back(v);
            v.clear();

        }
    }



    for (int i=0;i<vv.size();i++)
    {
        vector<int> poss = vv[i];
        int count = 0;
        for (int j=0;j<vv.size();j++)
        {
            bool flag = true;
            for (int k=0;k<l;k++)
                if ( poss[k] != vv[j][k] ) flag = false;
            if ( flag ) count++;
        }
        if ( count == n )
            ans = min(ans,poss[l]);
    }
  
    if ( ans == l+1) 
        printf("NOT POSSIBLE\n");
    else printf("%d\n",ans);
    vv.clear();

}


int main()
{

    int t;
    scanf("%d\n",&t);
    for (int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }

}
