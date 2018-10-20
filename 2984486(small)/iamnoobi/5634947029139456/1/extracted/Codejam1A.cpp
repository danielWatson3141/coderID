#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void print_vector(vi v);
void print_array(ll* array, int start, int end);

#define FOR(i,a,b) for (int i = (a),_b = (b); i < _b; i++)
#define DOW(i,b,a) for (int i = (b),_a = (a); i > _a; i--)
#define fill(a,v) memset(a, v, sizeof a)
#define checkbit(n,b) ((n >> b) & 1)
#define pb(a) push_back(a)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()

#define INF 1e9
#define PI acos(-1.0)

#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

int tc, cse = 1;
int n, l; 
ll outlet[200], devices[200], newoutlet[200], bigarray[200][200];
char str[50];
ll flip;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
    s(tc);
    while(tc--){
      s(n), s(l);
      FOR(i, 0, n){
        ss(str);
        ll curr = 0;
        FOR(j, 0, l){
          if(str[l - 1 - j] == '1') curr += (1ll << j);
        }
        outlet[i] = curr;
      }
      FOR(i, 0, n){
        ss(str);
        ll curr = 0;
        FOR(j, 0, l){
          if(str[l - 1 - j] == '1') curr += (1ll << j);
        }
        devices[i] = curr;
      }

      FOR(i, 0, n) FOR(j, 0, n){
        bigarray[i][j] = devices[i] ^ outlet[j];
      }

     // FOR(i, 0, n) print_array(bigarray[i], 0, n);

      int best = 1000;
      FOR(i, 0, n){
        ll current = bigarray[0][i];
        bool solve = true;
        FOR(j, 1, n){
          bool has = false;
          FOR(k, 0, n){
            if(bigarray[j][k] == current){
              has = true;
              break;
            }
          }
          if(!has){
            solve = false;
            break;
          }
        }
        if(solve){
          best = min(best, __builtin_popcountll(current));
        }
      }

      // flip = 0;
      // bool solve = true;
      // FOR(i, 0, l){
      //   int c1 = 0, c2 = 0;
      //   FOR(j, 0, n){
      //     c1 += ((outlet[j] & (1 << i)) != 0);
      //   }
      //   FOR(j, 0, n){
      //     c2 += ((devices[j] & (1 << i)) != 0);
      //   }
      //   if(c1 == c2){
      //   } else if (c1 == n - c2){
      //     flip += (1 << i);
      //   } else {
      //     solve = false;
      //     break;
      //   }
      // }
      printf("Case #%d: ", cse++);
      if(best == 1000) printf("NOT POSSIBLE\n");
      else printf("%d\n", best);
     
    }
    return 0;
}

void print_array(ll* array, int start, int end){
  printf("[");
  FOR(i, start, end){
    printf("%lld ", array[i]);
  }
  printf("]");
  printf("\n");
}

void print_vector(vi v){
  printf("[");
  FOR(i, 0, v.size()){
    printf("%d ", v[i]);
  }
  printf("]");
  printf("\n");
}