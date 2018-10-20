#include<cstdio>
#include<iostream>
#include<string>
#include <vector>
#include<cstring>
#include<algorithm>
using namespace std;


int countf;


void merge(int array[],int p,int q,int r) /////  p < = q < r
{
    int begin1,end1,begin2,end2,k,temp[1000];
    begin1=p;
    end1=q;
    begin2=q+1;
    end2=r;
    k=0;
    while(begin1<=end1 && begin2<=end2)
    {
        if(array[begin1] < array[begin2])
        {
            temp[k++]=array[begin1];
            begin1++;
            countf+=begin2-(q+1);
        }
        else
        {
            temp[k++]=array[begin2];
            begin2++;
        }
    }
    while(begin1<=end1)
    {
        temp[k++]=array[begin1];
        begin1++;
        countf+=end2-q;
    }
    while(begin2<=end2)
    {
        temp[k++]=array[begin2];
        begin2++;
    }
    for(int i=p;i<=r;i++)
        array[i]=temp[i-p];
}
void mergesort(int array[],int first,int last)
{
    int mid=(first+last)/2;
    if(first<last)
    {
        mergesort(array,first,mid);
        mergesort(array,mid+1,last);
        merge(array,first,mid,last);
    }
}
int da[1010];
vector < pair <int,int> > ans;
int main()
{
    int ntotal,nid;
    scanf("%d",&ntotal);
    for(nid=1;nid<=ntotal;nid++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",da+i);
        countf=0;
        mergesort(da,1,n);
        ans.push_back(make_pair(countf,nid));
    }
    sort(ans.begin(),ans.end());
    bool ret[120];
    for(int i=0;i<ntotal;i++)
    {
        //printf("%d %d\n",ans[i].first,ans[i].second);
        ret[ans[i].second-1]= (i< (ntotal/2));
    }
    for(int i=0;i<ntotal;i++)
    {
        printf("Case #%d: ",i+1);
        if(ret[i])
            printf("BAD\n");
        else
            printf("GOOD\n");
    }
    return 0;
}
