#include <cstdio>
#include <iostream>

using namespace std;

string app[5005];
string port[5005];
string port_tmp[5005];
bool flips[5005];

int main()
{
    int tc,n,l;
    freopen("a.txt","r",stdin);
    scanf("%d",&tc);
    freopen("a_bf_out2.txt","w",stdout);
    for (int a=0; a<tc; a++)
    {
        //printf("Hai\n");
        scanf("%d%d",&n,&l);
        //printf("%d %d\n",n,l);
        int min_cnt=1000000000;
        for (int i=0; i<n; i++)
        {
            cin >> port[i];
        }
        for (int i=0; i<n; i++)
        {
            cin >> app[i];
        }
        for (int aa=0; aa<n; aa++)
        {
              //printf("bm:%d\n",bitmask);
              int cnt=0;
              for (int i=0; i<l; i++)
              {
                  if (app[0][i]!=port[aa][i])
                  {
                     cnt+=1;
                     flips[i]=true;
                  }
                  else
                  {
                      flips[i]=false;
                  }
              }
              for (int i=0; i<n; i++)
              {
                  port_tmp[i]=port[i];
                  for (int j=0; j<l; j++)
                  {
                      if (flips[j]==true)
                        {
                           if (port_tmp[i][j]=='0')
                           {
                              port_tmp[i][j]='1';
                           }
                           else if (port_tmp[i][j]=='1')
                           {
                              port_tmp[i][j]='0';
                           }
                        }
                  }
              }
              bool success=true;
              for (int i=0; i<n; i++)
                {
                    bool can_pair=false;
                    for (int j=0; j<n; j++)
                    {
                        if (port_tmp[i]==app[j])
                        {
                           can_pair=true;
                           break;
                        }
                    }
                    if (!can_pair)
                    {
                       success=false;
                       //printf("Case #%d: NOT POSSIBLE\n",a+1);
                       break;
                    }
                }
              if (success)
              {
                 min_cnt=min(cnt,min_cnt);
              }
        }
        //printf("min_cnt:%d\n",min_cnt);
        if (min_cnt==1000000000)
        {
           printf("Case #%d: NOT POSSIBLE\n",a+1);
        }
        else
        {
            printf("Case #%d: %d\n",a+1,min_cnt);
        }
        //printf("Case #%d: %d",a+1,ans);
    }
}
