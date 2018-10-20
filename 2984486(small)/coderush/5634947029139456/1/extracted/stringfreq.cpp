#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char arr[200][200],dev[200][200],temp[200][200];
int n,l,k,bits[200];

void recapture();
int cmpfunc (const void * a, const void * b)
{
 return (strcmp((char *)a,(char *)b) );
}
void makeflip();
int merger();
void calcdiffbit(int i,int j);
int main()
{
    int min=10000,flag,x,t,i,j,y,ctr=1;
freopen("alarge.in","r",stdin);
freopen("alargeout.txt","w",stdout);
scanf("%d",&t);
while(t--)

{
    min=10000;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++)
        {
            scanf("%s",arr[i]);
            strcpy(temp[i],arr[i]);
        }
    for(i=0;i<n;i++)
        scanf("%s",dev[i]);
    qsort((void *)dev,n,sizeof(dev[0]),cmpfunc);
    flag=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
              calcdiffbit(i,j);
                makeflip();
                qsort((void *)arr,n,sizeof(arr[0]),cmpfunc);
                x=merger();
                if(x)
                {
                    if(k<min)
                    min=k;
                    flag=1;
                }
                recapture();
        }
       }
    if(!flag)
        printf("Case #%d: NOT POSSIBLE\n",ctr);
    else
        printf("Case #%d: %d\n",ctr,min);
        ctr++;
}
    return 0;
}
void recapture()
{
    int i;
     for(i=0;i<n;i++)
        {
            strcpy(arr[i],temp[i]);
        }

}
void calcdiffbit(int i,int j)
{
    k=0;
    int m;
    for(m=0;m<l;m++)
    if(arr[i][m]!=dev[j][m])
    {
        bits[k++]=m;
    }

}
int  merger()
{
    int i;
    for(i=0;i<n;i++)
        if(strcmp(arr[i],dev[i])!=0)
        return 0;
    return 1;
}
void makeflip()
{

    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
        if(arr[i][bits[j]]=='1')
        arr[i][bits[j]]='0';
        else
        arr[i][bits[j]]='1';
    }
}
