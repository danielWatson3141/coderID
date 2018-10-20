#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <utility>
#include <time.h>
#include <math.h>
#include <cmath>
#include <queue>
#include <set>
//freopen("input.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef unsigned long long ullong; 
typedef long long llong;
int maxi = 0;
//int xa[] = {1,1,0,-1,-1,-1, 0, 1};
//int ya[] = {0,1,1, 1, 0,-1,-1,-1};
VI figther;
VI effort;
int xa[] = {1,0,-1, 0};
int ya[] = {0,1, 0,-1,};
int vis[150];
int INF = 1000000000;
int main()
{
    //ios_base::sync_with_stdio(false);
 
    freopen("A-small-attempt0.IN", "r", stdin);
    freopen("A-small-attempt0.txt", "w", stdout);


    int t;
    cin >> t;

    for (int T = 1; T <= t; ++T)
    {
       int N, L;
       cin >> N >> L;
       
       vector<string> flow;
       for (int i = 0; i < N; ++i)
       {
          string a;
          cin >> a;
          flow.push_back(a);
       }

       //vector<string> ideflow;
       set<string>ideflow;
       for (int i = 0; i < N; ++i)
       {
          string a;
          cin >> a;
          //ideflow.push_back(a);
          ideflow.insert(a);
       }


       bool posible = true;
       int change = 0;
       int minchange = 10000000;
       for (int mask = 0; mask < (1<<(L+1)); ++mask)
       {
           vector<string> cur = flow;
           change = 0;
           for (int i = 0; i < L; ++i)
           {
               //cout << ( (mask)&(1<<i) );
               if( (mask & (1<<i) ) >= 1)
               {
                  change++;
                  //cout << change << endl;
                  for (int j = 0; j < N; ++j)
                  {
                     if(cur[j][i] == '1')
                     {
                        cur[j][i] = '0';
                     }
                     else
                     {
                        cur[j][i] = '1';
                     }
                  }

               }
            }
            //cout << endl;

            int cont = 0;

            for (int i = 0; i < N; ++i)
            {
               if(ideflow.count(cur[i]) > 0)cont++;
              // cout << ideflow.count(cur[i]) << endl;
            }
            //cout << endl;

            if(cont == N)
            {
                minchange = min(change, minchange);
            }


      }
      if(minchange < 10000000)
      {
        cout <<"Case #"<<T<<": "<<minchange<<endl;
      }
      else
      {
         cout <<"Case #"<<T<<": "<<"NOT POSSIBLE"<<endl;
      }


    }
    
    

    
}
 