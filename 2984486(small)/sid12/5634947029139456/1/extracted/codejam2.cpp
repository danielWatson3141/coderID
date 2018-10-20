//Author: Siddharth Saluja
//Quote: "DIE FOR YOUR AIM"
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;


#define mod 1000000007
//#define DEBUG
#define inf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define sp(a) printf("%s",a)
#define cp(a) printf("%c",a)
#define nline printf("\n")
#define space printf(" ")
#define fs(a) fscanf(fp,"%d",&a)
#define flls(a) fscanf(fp,"%lld",&a)
#define fss(a) fscanf(fp,"%s",a)
#define fp(a) fprintf(fo,"%d",a)
#define fllp(a) fprintf(fo,"%lld",a)
#define fsp(a) fprintf(fo,"%s",a)
#define fcp(a) fprintf(fo,"%c",a)
#define fnline fprintf(fo,"\n")
#define fspace fprintf(fo," ")
#define ll long long

bool check(ll int a[200],ll int b[200],ll int n)
{
    ll int i;
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}


int main()
{
#ifdef DEBUG
    cout<<"Debugging\n";
#endif
FILE *fp,*fo;
fp=fopen("input.txt","r");
fo=fopen("output1.txt","w");

//ios::sync_with_stdio(false);

long long int t,n,l,i,p=0;
char s[100];
flls(t);
//cout<<t;
while(t--)
{
    p++;
   long long  int mask[200]={0},reqd[200]={0},ans=1e9,j,temp,r,u,newt[200]={0},h,nval,val;
    flls(n);
    flls(l);
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%s",&s);
        for(j=0;j<l;j++)
        {
            temp=s[j]-'0';
            if(temp==1)
            {
                mask[i]=mask[i]|(1<<j);
            }
        }
        //cout<<mask[i]<<" ";
    }
    //cout<<endl;
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%s",&s);
        for(j=0;j<l;j++)
        {
            temp=s[j]-'0';
            if(temp==1)
            {
                reqd[i]=reqd[i]|(1<<j);
            }
        }
      //  cout<<reqd[i]<<" ";
    }
    //cout<<endl;
    sort(reqd,reqd+n);
    val=mask[0];
    for(i=0;i<n;i++)
    {
        nval=val^reqd[i];
        for(j=0;j<n;j++)
        {
            newt[j]=nval^mask[j];
        }
        sort(newt,newt+n);
        if(check(newt,reqd,n))
        {
            h=__builtin_popcount(nval);
            if(ans>h)
                ans=h;
        }
    }
    fprintf(fo,"Case #%lld: ",p);
    if(ans!=1e9)
    {
        fprintf(fo,"%lld\n",ans);
    }
    else
    {
        fprintf(fo,"NOT POSSIBLE\n");
    }
}
return 0;
}

