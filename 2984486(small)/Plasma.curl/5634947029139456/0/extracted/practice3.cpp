//Coder: Saurabh Arora

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int match(string a,string b,int N,int L)
{
    vector<string>Mv,Mv1;
    int i;
    for(i=0;i<N;i++)
    {
        Mv.push_back(a.substr(i*L,L));
        Mv1.push_back(b.substr(i*L,L));
    }
    int vis[N];
    for(i=0;i<N;i++)
        vis[i]=0;
        int j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(Mv[i]==Mv1[j] && vis[j]==0)
            {
                vis[j]=1;break;
            }
        }
    }
    for(i=0;i<N;i++)
    {
        if(vis[i]==0)
            return 0;
    }
    return 1;
}
int main() {

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("result.txt", "w", stdout);
    int i,j,T;
    string st;
    char str[55];
    scanf("%d", &T);
    for(i=1;i<T+1;i++)
    {
        int N,L;
        scanf("%d %d",&N,&L);
        string in="",rq="";
        vector<string>init,req;
        for(j=0;j<N;j++)
            {scanf("%s ",str);
            init.push_back((string)(str));
            }
        for(j=0;j<N;j++)
            {scanf("%s",str);
            req.push_back((string)(str));
            }
       for(j=0;j<N;j++)
       {
           in=in+init[j];rq=rq+req[j];
       }
       queue<string>MyQ;
       MyQ.push(in);
       map<string,int>Mymap;
       int ans,l,fg=0;
       while(!MyQ.empty())
       {
           in=MyQ.front();

           if(Mymap[in]>L)
            break;
           MyQ.pop();
           if(match(in,rq,N,L))
           {
               ans=Mymap[in];fg=1;break;
           }
           for(j=0;j<L;j++)
           {string tp=in;
               for(l=0;l<N;l++)
               {   if(tp[l*L+j]=='1')
                   tp[l*L+j]='0';
                   else
                    tp[l*L+j]='1';
               }
               if(Mymap[tp]==0)
               {
                   Mymap[tp]=Mymap[in]+1;
                   MyQ.push(tp);
               }
           }
       }
       if(fg)
       printf("Case #%d: %d\n",i,ans);
       else
         printf("Case #%d: NOT POSSIBLE\n",i);
    }
}
