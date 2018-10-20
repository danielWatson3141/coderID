#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int n,l;
int a[41];
struct array
{
    string o;
}b[155],c[155],s[155],t[155];
int f(int n2,int num)
{
    int sum=0;
    for(int i=0;i<l;i++)
        a[i]=0;
    for(int i=0;i<l;i++)
    {
        if(s[n2].o[i]!=t[num].o[i])
        {
            a[i]=1;sum++;
        }
    }
    return sum;
}
int cmp(array x,array y)
{
    return x.o.compare(y.o)<0;
}
int judge(int num)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        b[i].o="";
        for(j=0;j<l;j++)
        {
            if(a[j])
            {
                if(s[i].o[j]=='1')b[i].o+="0";
                else b[i].o+="1";
            }
            else
            {
                if(s[i].o[j]=='1')b[i].o+="1";
                else b[i].o+="0";
            }
        }
    }
    //cout<<num<<endl;
//    for(i=0;i<n;i++)
//        cout<<a[i]<<" ";
//    cout<<endl;
    sort(b,b+n,cmp);
//    for(i=0;i<n;i++)
//        cout<<b[i].o<<" ";cout<<endl;
    for(i=0;i<n;i++)
    {
        if(b[i].o.compare(t[i].o)!=0)return 0;
    }
    return 1;
}

int main()
{
    int i,j,T;
//    freopen("A-large.in","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
            cin>>s[i].o;
        for(i=0;i<n;i++)
            cin>>t[i].o;
        sort(t,t+n,cmp);
//        for(i=0;i<n;i++)
//            cout<<t[i].o<<endl;
        int ans=-1;
        for(i=0;i<n;i++)
        {
            int tmp = f(i,0);
            if(judge(i))
            {
                if(ans==-1||ans>tmp)
                    ans=tmp;
            }
        }
        if(ans==-1)
            printf("Case #%d: NOT POSSIBLE\n",++cas);
        else
            printf("Case #%d: %d\n",++cas,ans);

    }
    return 0;
}
