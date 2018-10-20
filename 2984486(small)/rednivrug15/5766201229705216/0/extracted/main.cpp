#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<fstream>
using namespace std;

int n,mint;
int bin(int mat[100][100]);
void ans(int mat[100][100],int cur,int x,int t)
{
    int vis[100][100];

    if(cur>n)
        return ;

    if(bin(mat)==1)
    {

       if(x<mint)
       {
        //printf("%d-%d\n",t,x);
        mint=x;
       }
    }


    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
        vis[i][j]=mat[i][j];

    for(int j=1;j<=n;j++)
    {
        vis[cur][j]=0;
        //vis[j][cur]=0;
    }


    ans(mat,cur+1,x,t);
    ans(vis,cur+1,x+1,t+pow(2,cur-1));
}

int bin(int mat[100][100])
{
    int count=0,root=-1;
    for(int i=1;i<=n;i++)
    {
        count=0;
        for(int j=1;j<=n;j++)
        {
        if(mat[i][j]==1)
            count++;
        }
      //  printf("%d--\n",count);
        if(count==2)
        {
            root=i;
            break;
        }
    }
    //printf("%d--root\n",root);
    if(root==-1)
        return 0;

    for(int i=1;i<=n;i++)
    {
        count=0;
        if(i!=root)
        {
            for(int j=1;j<=n;j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
        }
        if(count!=1 && count!=3 && count!=0)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    FILE *inp,*ops;
    inp=fopen("inp.txt","r");
    ops=fopen("op.txt","w");

    scanf("%d",&t);

    for(int i=1;i<=t;++i)
    {
      int mat[100][100]={{0}};
      int a,b;
      scanf("%d",&n);

      for(int j=0;j<n-1;j++)
      {
          scanf("%d%d",&a,&b);
          mat[a][b]=1;
          mat[b][a]=1;
      }
     mint=1000;
     ans(mat,1,0,0);
     if(mint==1000)
        mint=n-1;
    fprintf(ops,"Case #%d: %d\n",i,mint);
    }
    fclose(inp);
    fclose(ops);
    return 0;
}
