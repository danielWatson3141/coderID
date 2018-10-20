#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef vector <int> vi;

#define INF 2000000000
#define PI 3.14159265

#define REP(i,n) for(int i=0, _n=n; i<_n; ++i)
#define FOR(i,a,n) for(int i=a,_n=n; i<=_n; ++i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

#define ALL(v) (v).begin(), (v).end()

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

char flip(char &c)
{
 if ( c == '0' ) return '1';
 if ( c == '1' ) return '0';     
}

int main()
{
   freopen("a.in", "r", stdin);
   freopen("a.out", "w", stdout);
   int t; scanf("%d", &t);
   int tcase = 0;
   
   while (t--) {
         int N, L; scanf("%d %d", &N, &L);
         string outlet[200];
         string device[200];
         
         char dummy[100];
         REP (i, N) scanf("%s", dummy), outlet[i] = dummy;
         REP (i, N) scanf("%s", dummy), device[i] = dummy;
         
         sort(device, device+N);
         int ret = -1;
         for ( int i = 0 ; i < (1<<(L)); ++i ) {
             string test[200]; REP(j, N) test[j] = outlet[j];
             int bit[50]; memset(bit, 0, sizeof bit);
             
             for ( int j = 0; j < L ; ++j ) {
                bit[j] = ((1<<j) & i ) > 0 ? 1 : 0;                     
             }
             int nFlip = 0;
             REP (j, L) {
                 if ( bit[j] == 1 ) {
                    REP (k, N) {
                        test[k][j] = flip(test[k][j]);
                    }   
                    ++nFlip;
                 }    
             }
             
             sort(test, test+N);
             bool success = true;
             REP (j, N) if ( test[j] != device[j] ) success = false;
             
             if ( success ) {
                if ( ret == -1 ) ret = nFlip;
                else ret = min(ret, nFlip);   
             }
         }
         
         printf("Case #%d: ", ++tcase);
         if ( ret == -1 ) printf("NOT POSSIBLE\n");
         else printf("%d\n", ret);
   }

   return 0;
}
