#include<stdio.h>
#include<string.h>

bool ch,chh[50],x;
int t,n,l,cc,c1i,c1f,mn;
char ci[150][50],cf[150][50];

void flip(char a[150][50],char* b)
{
    for(int i=0;i<l;i++)
    {
        if(a[0][i]!=b[i])
        {
            cc++;
            chh[i]=true;
            for(int j=0;j<n;j++)
            {
                if(a[j][i]=='1')    a[j][i]='0';
                else                a[j][i]='1';
            }
        }
    }
}

void unflip()
{
    for(int i=0;i<l;i++)
    {
        if(chh[i])
        {
            chh[i]=false;
            for(int j=0;j<n;j++)
            {
                if(ci[j][i]=='1')   ci[j][i]='0';
                else                ci[j][i]='1';
            }
        }
    }
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("Out1.txt","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        memset(chh,0,sizeof(chh));
        mn=2000000000;
        ch=false;
        cc=0;
        scanf("%d %d",&n,&l);
        for(int j=0;j<n;j++)
        {
            scanf("%s",ci[j]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%s",cf[j]);
        }
        for(int j=0;j<l&&!ch;j++)
        {
            c1i=0;
            c1f=0;
            for(int k=0;k<n;k++)
            {
                if(ci[k][j]=='1')   c1i++;
                if(cf[k][j]=='1')   c1f++;
            }
            if(c1i!=n-c1f&&c1i!=c1f)    ch=true;
        }
        if(ch)
        {
            printf("Case #%d: NOT POSSIBLE\n",i);
            continue;
        }
        for(int j=0;j<n;j++)
        {
            unflip();
            cc=0;
            flip(ci,cf[j]);
//            for(int k=0;k<n;k++)
//            {
//                printf("%s ",ci[k]);
//            }
//            printf("\n---------------------\n");
            for(int k=0;k<n;k++)
            {
                x=true;
                for(int l=0;l<n;l++)
                {
                    if(strcmp(ci[k],cf[l])==0)  x=false;
                }
                if(x)   break;
            }
            if(x)   continue;
            if(mn>cc)   mn=cc;
        }
        printf("Case #%d: %d\n",i,mn);
    }
    return 0;
}
