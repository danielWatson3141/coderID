//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<map>
#include<set>
using namespace std;
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back(x)
typedef long long LL;
//typedef unsigned __int64 ULL;
/* ****************** */
const int INF=1000111222;
const double INFF=1e100;
const double eps=1e-8;
const int mod=1000000007;
const int NN=505;
const int MM=401010;
/* ****************** */

int a[1005],b[1005];
double cnt[2];

int randint(int st,int en)
{
    int t=rand()%(en-st+1);
    return st+t;
}
/*
void check(int n,int *a,int t)
{
    int i,j,ans=0;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
                ans++;
        }
    printf("nixu==%d\n",ans);
    cnt[t]+=ans;
}
*/
/*
void check(int n,int *a,int t)
{
    double sum=0.0,p,ans;
    int i;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    p=sum/(n+0.0);

    ans=0.0;
    for(i=0;i<n;i++)
    {
        ans+=(a[i]-p)*(a[i]-p);
    }
    ans=ans/(n+0.0);

    cout<<"sum=="<<sum<<endl;
    cout<<"fancha "<<ans<<endl;

    cnt[t]+=ans;
}*/

void check3(int n,int *a,int t)
{
    int i,ans=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<i)
            ans++;
    }
    printf("woca==%d\n",ans);
    cnt[t]+=ans;
}

int main()
{
    freopen("E:\\C-small-attempt5.in","r",stdin);
    freopen("E:\\C-small-attempt5.out","w",stdout);

    srand(time(NULL));
 //   freopen("E:\\C_TEST.txt","w",stdout);

    int cas=100,n=20,p,k,i;
    int fuck,ee=0;
   // scanf("%d",&cas);

    cnt[0]=cnt[1]=0.0;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);

        cnt[0]=cnt[1]=0;
        fuck=300;
        while(fuck--)
        {
            for(k=0;k<n;k++)
                a[k]=k;
            for(k=0;k<n;k++)
            {
                p=randint(k,n-1);
                swap(a[k],a[p]);
            }

            for(k=0;k<n;k++)
            {
               // if(a[k]==b[k])
              //      cnt[0]++;
                cnt[0]+=abs(a[k]-b[k]);
            }

            for(k=0;k<n;k++)
                a[k]=k;
            for(k=0;k<n;k++)
            {
                p=randint(0,n-1);
                swap(a[k],a[p]);
            }

            for(k=0;k<n;k++)
            {
                //if(a[k]==b[k])
               //     cnt[1]++;
                cnt[0]+=abs(a[k]-b[k]);
            }
        }


        printf("Case #%d: ",++ee);
        if(cnt[0]>cnt[1])
            puts("GOOD");
        else if(cnt[0]<cnt[1])
            puts("BAD");
        else
        {
            if(rand()%2==0)
                puts("GOOD");
            else
                puts("BAD");
        }
    }

 //   cout<<"cnt[0]=="<<cnt[0]<<endl;
  //  cout<<"cnt[1]=="<<cnt[1]<<endl;

    return 0;
}
