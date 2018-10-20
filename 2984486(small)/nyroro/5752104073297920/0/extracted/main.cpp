#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=1010;
int arr[N];
int g;
void update(int x,int v)
{
    while(x<=g)
    {
        arr[x]+=v;
        x+=(x&-x);
    }
}
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=arr[x];
        x-=(x&-x);
    }
    return ret;
}

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    srand(time(NULL));
    for(int ti=1;ti<=t;ti++)
    {
        cin>>g;
        for(int i=1;i<=g;i++)
            arr[i]=0;
        for(int i=1;i<=g;i++)
        {
            update(i,1);
        }
        int ans=0;
        int num=g*(g-1)/2;
        int s=g;
        for(int i=1;i<=g;i++)
        {
            int t;
            cin>>t;
            update(t+1,-1);
            ans+=sum(t);
            s--;
        }

        int a=rand();
        int b=rand();

        int pro=(1ll*a*b)%num;
        cout<<"Case #"<<ti<<": ";
        if(pro<=ans)cout<<"GOOD"<<endl;
        else cout<<"BAD"<<endl;
    }
    return 0;
}
