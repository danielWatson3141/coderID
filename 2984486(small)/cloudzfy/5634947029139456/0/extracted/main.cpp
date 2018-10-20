#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;

int outlet[10],device[10],tmp[10];
int p[11]={1,2,4,8,16,32,64,128,256,512,1024};
int main()
{
    int t,T,N,L;
    freopen("A-small-attempt1.in.txt","r",stdin);
	freopen("A-small-attempt1.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        memset(outlet,0,sizeof(outlet));
        memset(device,0,sizeof(device));
        scanf("%d%d",&N,&L);
        for(int i=0;i<N;i++)
        {
            char str[11];
            scanf("%s",str);
            for(int j=0;j<L;j++)
            {
                if(str[j]=='1')
                {
                    outlet[i]+=(1<<(L-j-1));
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            char str[11];
            scanf("%s",str);
            for(int j=0;j<L;j++)
            {
                if(str[j]=='1')
                {
                    device[i]+=(1<<(L-j-1));
                }
            }
        }
        sort(device,device+N);
        int ans=-1;
        for(int i=0;i<p[L];i++)
        {
            for(int j=0;j<N;j++)
            {
                tmp[j]=outlet[j]^i;
            }
            sort(tmp,tmp+N);
            int flag=1;
            for(int j=0;j<N;j++)
            {
                if(tmp[j]!=device[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                int cur=0;
                for(int j=0;j<L;j++)
                {
                    if(i&(1<<j))
                    {
                        cur++;
                    }
                }
                if(ans==-1||ans>cur)
                {
                    ans=cur;
                }
            }
        }
        if(ans==-1)
        {
            printf("Case #%d: NOT POSSIBLE\n",t);
        }
        else
        {
            printf("Case #%d: %d\n",t,ans);
        }
        
    }
    return 0;
}