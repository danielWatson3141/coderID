#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <set>



using namespace std;
int n,l,T,cased=0,ans,temp;
char a[15][15],b[15][15],c[15][15];

bool issame(char a[],char b[])
{
    for(int i=0;i<l;i++)
    if(a[i]!=b[i])return false;
    return true;
}

int main()
{

    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>l;
        ans=35;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<(1<<l);i++)
        {
             bool pos;
            temp=0;
            for(int x=0;x<n;x++)
            for(int y=0;y<l;y++)
            c[x][y]=b[x][y];
            for(int j=0;j<l;j++)
            if(i&(1<<j))
            {
                temp++;
                for(int k=0;k<n;k++)//{
                 if(c[k][j]=='1')c[k][j]='0';
                 else c[k][j]='1';      // cout<<b[k][j]<<" "<<k<<" "<<j<<" "<<i<<endl;}
            }
            for(int p=0;p<n;p++)
            {
                pos=false;

                for(int q=0;q<n;q++)
                if(issame(a[p],c[q]))
                {
                    pos=true;
                    break;
                }
                if(!pos)break;
            }
            if(pos)ans=min(ans,temp);
        }
        if(ans==35)printf("Case #%d: NOT POSSIBLE\n",++cased);
        else printf("Case #%d: %d\n",++cased,ans);

    }



}


