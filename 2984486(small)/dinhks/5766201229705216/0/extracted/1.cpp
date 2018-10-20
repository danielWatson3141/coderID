#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;
class Node
{
    public:
    list<int>adj;
    list<int>child;
    int numChild;
    int mi;
    void reset()
    {
        adj.clear();
        child.clear();
        numChild=0;
        flag=0;
    }
    int flag=0;
    void print()
    {
        cout<<mi<<" "<<numChild<<"\n";
    }
}lisNode[2000];
void trav(int i)
{
    lisNode[i].flag=1;
    lisNode[i].child.clear();
    list<int>::iterator it;
    for(it=lisNode[i].adj.begin();it!=lisNode[i].adj.end();++it)
    {
        if(lisNode[*it].flag==0)
        {
            //cout<<i<<" "<<*it<<"\n";
            lisNode[i].child.push_back(*it);
            trav(*it);
            lisNode[i].numChild+=1+lisNode[*it].numChild;
        }
    }
}
void calMi(int i)
{
    if(lisNode[i].child.size()==0)
    {
        lisNode[i].mi=0;
        return ;
    }
    if(lisNode[i].child.size()==1)
    {
        lisNode[i].mi=lisNode[i].numChild;
        return ;
    }
    list<int>::iterator it;
    for(it=lisNode[i].child.begin();it!=lisNode[i].child.end();++it)
        calMi(*it);
    list<int>::iterator it1;
    int ma=0;
    for(it=lisNode[i].child.begin();it!=lisNode[i].child.end();++it)
    {
        it1=it;
        it1++;
        for(;it1!=lisNode[i].child.end();++it1)
        {
            int tmp=lisNode[*it].numChild+1-lisNode[*it].mi;
            tmp+=lisNode[*it1].numChild+1-lisNode[*it1].mi;
            if(tmp>ma)
                ma=tmp;
        }
    }
    lisNode[i].mi=lisNode[i].numChild-ma;
}
int main()
{
    freopen("E:\\in","r",stdin);
    freopen("E:\\out","w",stdout);
    int i,j,t,n;
    cin>>t;
    for(int tt=1;tt<=t;++tt)
    {
        cin>>n;
        for(i=1;i<=n-1;++i)
        {
            int x,y;
            cin>>x>>y;
            lisNode[x].adj.push_back(y);
            lisNode[y].adj.push_back(x);
        }
        int mi=10000000000;
        for(int root=1;root<=n;++root)
        {
            //cout<<root<<"\n";
            for(i=1;i<=n;++i)
            {
                lisNode[i].child.clear();
                lisNode[i].flag=0;
                lisNode[i].numChild=0;
                lisNode[i].mi=0;
            }
            trav(root);
            calMi(root);
           // for(i=1;i<=n;++i)
             //   cout<<i<<" "<<lisNode[i].mi<<" "<<lisNode[i].numChild<<"\n";
            if(lisNode[root].mi<mi)
                mi=lisNode[root].mi;
        }
        cout<<"Case #"<<tt<<": "<<mi<<"\n";
        for(i=1;i<=n;++i)
            lisNode[i].adj.clear();
    }
    return 0;
}

