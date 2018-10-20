#include<cstdio>
#include<iostream>
#include<string>
#include <vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
struct po
{
    char cd[41];
    bool operator <  (const po & bb)const
    {
        return 0>strcmp(cd,bb.cd);
    }
}da[150],db[150];
int re[41][151][151];
struct yx
{
    int a,b,c,d;
}tt;
int gao(int col,vector <yx> &dc)
{
    if(col==n)
        return 0;
    //printf("debug: %d\n",col);
    bool bo0=true,bo1=true;
    vector <yx> v0,v1;
    for(int id=0;id<dc.size();id++)
    {
        //printf("debug:%d %d %d %d\n",dc[id].a,dc[id].b,dc[id].c,dc[id].d);
        int la=dc[id].a,ra=dc[id].b,lb=dc[id].c,rb=dc[id].d;

        int a1=0,b1=0,a0=0,ma=la-1,mb=lb-1;
        for(int i=la;i<=ra;i++)
        {
            if(da[i].cd[col]=='1')
                a1++;
            else
            {
                a0++;
                ma=i;
            }
        }
        for(int i=lb;i<=rb;i++)
        {
            if(db[i].cd[col]=='1')
                b1++;
            else
                mb=i;
        }
        if(a1!=b1 && a0!=b1)
            return 100;
        if(a1==b1 && bo0)
        {
            if (ma!=la-1)
            {
                tt.a=la;tt.b=ma;tt.c=lb;tt.d=mb;
                v0.push_back(tt);
            }
            if (ma!=ra)
            {
                tt.a=ma+1;tt.b=ra;tt.c=mb+1;tt.d=rb;
                v0.push_back(tt);
            }
        }
        else
            bo0=false;
        if(a0==b1 && bo1)
        {
            //if(col==1)
                //printf("%d %d %d %d %d %d\n",la,ma,ra,lb,mb,rb);
            if (ma!=la-1)
            {
                tt.a=la;tt.b=ma;tt.c=mb+1;tt.d=rb;
                v1.push_back(tt);
            }
            if (ma!=ra)
            {
                tt.a=ma+1;tt.b=ra;tt.c=lb;tt.d=mb;
                v1.push_back(tt);
            }
        }
        else
            bo1=false;
    }
    int ans=100;
    if(bo0)
    {
        //printf("debug:%d run0\n",col);
        ans=min(ans,gao(col+1,v0));
    }
    if(bo1)
    {
        //printf("debug:%d run1\n",col);
        ans=min(ans,1+gao(col+1,v1));
    }
    //printf("debug: ans=%d %d\n",col,ans);
    return ans;

}
int main()
{
    int ntotal,nid;
    scanf("%d",&ntotal);
    for(nid=1;nid<=ntotal;nid++)
    {
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++)
            scanf("%s",da[i].cd);
        for(int i=0;i<m;i++)
            scanf("%s",db[i].cd);
        sort(da,da+m);
        sort(db,db+m);

        //for(int i=0;i<m;i++)
            //printf("%s\n",da[i].cd);
        ///for(int i=0;i<m;i++)
///("%s\n",db[i].cd);
         //continue;

        vector <yx> td;
        tt.a=tt.c=0;
        tt.b=tt.d=m-1;
        td.push_back(tt);
        int ans=gao(0,td);
        printf("Case #%d: ",nid);
        if(ans>=100)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
