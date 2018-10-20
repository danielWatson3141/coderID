# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>
# include <map>

using namespace std;

int work(vector<string>& v1,vector<string>& v2,int cur,int N,int L)
{
  if(cur==L)return 0;
  vector<long long> pref1,pref2;
  for(int i=0;i<N;i++)
  {
    long long p1=0,p2=0;
    for(int j=0;j<cur;j++)
    {
      p1=(p1<<1)|(v1[i][j]-'0');
      p2=(p2<<1)|(v2[i][j]-'0');
    }
    pref1.push_back(p1);
    pref2.push_back(p2);
  }

  bool retain=true,flip=true;
  for(int i=0,j=0;i<N;i=j)
  {
    for(j=i+1;(j<N)&&(pref1[j]==pref1[i]);j++);
    int a=0,b=0,c=0,d=0;
    for(int k=i;k<j;k++)
    {
      if(v1[k][cur]=='0')a++;else b++;
      if(v2[k][cur]=='0')c++;else d++;
    }

    if((a!=c)||(b!=d))retain=false;
    if((a!=d)||(b!=c))flip=false;
  }

  int ret1=1000,ret2=1000;
  if(retain)ret1=work(v1,v2,cur+1,N,L);
  if(flip)
  {
    for(int i=0;i<N;i++)
    {
      v1[i][cur]^=1;
    }
    sort(v1.begin(),v1.end());
    ret2=work(v1,v2,cur+1,N,L)+1;
    for(int i=0;i<N;i++)
    {
      v1[i][cur]^=1;
    }
    sort(v1.begin(),v1.end());
  }
  return min(ret1,ret2);
}

int main()
{
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    int N,L;
    scanf("%d%d",&N,&L);

    vector<string> v1,v2;
    string tmp;
    for(int i=0;i<N;i++)
    {
      cin>>tmp;
      v1.push_back(tmp);
    }
    for(int i=0;i<N;i++)
    {
      cin>>tmp;
      v2.push_back(tmp);
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int ret=work(v1,v2,0,N,L);

    if(ret>L)printf("Case #%d: NOT POSSIBLE\n",t);
    else printf("Case #%d: %d\n",t,ret);
  }
  return 0;
}

