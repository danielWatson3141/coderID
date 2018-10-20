
#include <iostream>
#include <fstream>

int a[1001][1001];
int v[1001];
using namespace std;
ifstream fin;
ofstream fout;
int dfs(int x)
{
    int link=0;
    int max1=0;
    int max2=0;
    int num;
    for (int i=1;i<=a[x][0];i++)
    if (not v[a[x][i]])
    {
        link++;
        v[a[x][i]]=1;
        num=dfs(a[x][i]);
        if (max1<num)
        {
            max2=max1;
            max1=num;
        }
        else if (max2<num) max2=num;

    }

    if (link<=1) return 1;
    else return (1+max1+max2);
}

int main()
{
    fin.open("B-large.in",ios::in);
    fout.open("output.txt",ios::trunc);
	ios :: sync_with_stdio(false);
    int t,n;
    int x,y;
    int ans;
    int sum;
    fin>>t;
    for (int k=1;k<=t;k++)
    {
        fin>>n;
        for (int i=1;i<=n;i++)
        for (int j=0;j<=n;j++)
        a[i][j]=0;
        for (int i=1;i<=n-1;i++)
        {
            fin>>x>>y;
            a[x][0]++;
            a[x][a[x][0]]=y;
            a[y][0]++;
            a[y][a[y][0]]=x;
        }

        ans=n+1;
        for (int i=1; i<=n;i++)
        if (a[i][0]>1)
        {

            for (int j=1;j<=n;j++) v[j]=0;
            v[i]=1;
            sum=dfs(i);
            if ((n-sum)<ans) ans=n-sum;
        }
        if (n == 2)
            ans =1;
        fout<<"Case #"<<k<<": "<<ans<<endl;


    }
    return 0;
}
