#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int cnt,N;
int H[1100];
int ll[550],rr[550];

void merge(int p,int q,int o)
{
    int n1=o-p+1;
    int n2=q-o;    
    int i,j;
    for(i=1;i<=n1;i++)
        ll[i]=H[i+p-1];
    ll[i]=1<<30;
    for(i=1;i<=n2;i++)
        rr[i]=H[i+o];
    rr[i]=1<<30;
    i=j=1;
    while(p<=q)
    {
        if(ll[i]<=rr[j])
            H[p++]=ll[i++];
        else
        {
            H[p++]=rr[j++];
            cnt+=(n1-i+1);
        }
    }
}
 
void mergesort(int p,int q)
{
    if(p<q)
    {
        int o=(p+q)/2;
        mergesort(p,o);
        mergesort(o+1,q);
        merge(p,q,o);
    }
}

int main()
{
    int T,kase,i;
    scanf("%d",&T);
    for(kase = 1; kase <= T; kase++)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
            scanf("%d",&H[i]);
        cnt = 0;
        mergesort(0,N-1);
        cout<<"Case #"<<kase<<": ";
        if(cnt >= 0.985*N*(N-1)/4)
            cout<<"GOOD"<<endl;
        else
            cout<<"BAD"<<endl;
    }
    return 0;
}
