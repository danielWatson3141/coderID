#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int i,t,j,x,y,k,n,count,c,temp,res;
    int mat[20][20],arr[20],dp[4];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        res=n;
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                mat[j][k]=0;
            }
        }
        for(j=1;j<n;j++)
        {
            scanf("%d%d",&x,&y);
            x--;y--;
            mat[x][y]=1;
            mat[y][x]=1;
        }
        for(j=0;j<n;j++)
        {
            arr[j]=0;
        }
        do
        {
            count=0;
            for(j=0;j<=3;j++)
                dp[j]=0;
            for(j=0;j<n;j++)
            {
                count+=arr[j];
            }
            for(j=0;j<n;j++)
            {
                temp=0;
                if(arr[j]==0)
                for(k=0;k<n;k++)
                {
                    if(arr[k]==0)
                    {
                        if(mat[j][k]==1)
                            temp++;
                    }
                }
                if(temp<=3)
                    dp[temp]++;
                else
                {
                    temp=-1;
                    break;
                }
            }
            if(temp!=-1&&dp[2]==1)
            {
                res=min(res,dp[0]);
                if(res==dp[0])
                {
                    for(j=0;j<n;j++)
                    {
              //          printf("%d",arr[j]);
                    }
              //      printf("\n");
                }
            }
            c=1;
            for(j=0;j<n;j++)
            {
                arr[j]+=c;
                if(arr[j]>1)
                {
                    arr[j]%=2;
                    c=1;
                }
                else
                {
                    c=0;
                }
            }
        }while(count!=n);
        if(n>2)
            printf("Case #%d: %d\n",i,res);
        else
        {
            printf("Case #%d: 1\n",i);
        }
    }
    return 0;
}
