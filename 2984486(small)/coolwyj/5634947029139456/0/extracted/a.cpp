#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define INF 100000000
set <int> res,tmp;
int ori[15],jiong[15];
char s[15];
int con(char s[15])
{
    int len = strlen(s);
    int res=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='1')
            res+=(1<<(len-i-1));
    }
    return res;
}
int main()
{
    int T,cas=1,n,l;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&l);
        res.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            ori[i] = con(s);
            //cout<<ori[i]<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            res.insert(con(s));
        }
        int full = (1<<l)-1;
        //cout<<full<<endl;
        int ans=INF;
        for(int st=0;st<=full;st++)
        {
            tmp.clear();
            for(int i=1;i<=n;i++)
            {
                int t=ori[i];
                int p=st;
                for(int j=0;j<l;j++)
                {
                    if(p&1) t^=(1<<j);
                    p>>=1;
                }
                tmp.insert(t);
            }
            int *end=std::set_difference(res.begin(),res.end(),tmp.begin(),tmp.end(),jiong);
            int *first = jiong;
            if(first>=end)
            {
				int cnt=0;
				int p = st;
				while(p)
				{
					if(p&1) cnt++;
					p>>=1;
				}
                if(cnt < ans) ans=cnt;
            }
        }
        if(ans == INF)
            printf("Case #%d: NOT POSSIBLE\n",cas++);
        else
            printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
