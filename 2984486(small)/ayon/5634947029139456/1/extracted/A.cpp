#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<limits.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);


typedef long long LL;





LL tp[100];
char in[500];




LL pc[3000];
LL bord[3000];
LL bord2[3000];

map<int,int> mp;





int main()
{
    freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);


    int T,cs,i,j,n,m;
    scanf("%d",&T);



    tp[0]=1;
    LL to=2;
    for(i=1;i<=60;i++)
    {
        tp[i]=tp[i-1]*to;
    }



    for(cs=1;cs<=T;cs++)
    {
        printf("Case #%d: ",cs);

        scanf("%d %d",&n,&m);

        for(i=0;i<n;i++)
        {
            scanf("%s",in);
            bord[i]=0;
            for(j=0;j<m;j++)
            {
                if(in[j]=='1') bord[i]|=tp[j];
            }
           // cout<<bord[i]<<endl;
        }


        for(i=0;i<n;i++)
        {
            scanf("%s",in);
            pc[i]=0;
            for(j=0;j<m;j++)
            {
                if(in[j]=='1') pc[i]|=tp[j];
            }
         //   cout<<pc[i]<<endl;
        }
      //  asdf


        int inf=100000;

        int ans=inf;
        int temp;

        sort(pc,pc+n);


        for(i=0;i<n;i++)
        {
            LL xr=pc[0]^bord[i];


            temp=0;
            for(j=0;j<45;j++) if(xr & tp[j]) temp++;

            for(j=0;j<n;j++)
            {
                bord2[j]=bord[j]^xr;
            }


            sort(bord2,bord2+n);

            for(j=0;j<n;j++)
            {
                if(bord2[j]!=pc[j]) break;

            }


            if(j==n) ans=min(ans,temp);
        }



        if(ans==inf) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);






    }
    return 0;
}
