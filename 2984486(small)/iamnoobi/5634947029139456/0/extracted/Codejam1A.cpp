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
void print_array(int* array, int start, int end);

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
int n, l, outlet[200], devices[200], newoutlet[200];
char str[50];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
    s(tc);
    while(tc--){
      s(n), s(l);
      FOR(i, 0, n){
        ss(str);
        int curr = 0;
        FOR(j, 0, l){
          if(str[l - 1 - j] == '1') curr += (1 << j);
        }
        outlet[i] = curr;
      }
      FOR(i, 0, n){
        ss(str);
        int curr = 0;
        FOR(j, 0, l){
          if(str[l - 1 - j] == '1') curr += (1 << j);
        }
        devices[i] = curr;
      }
      sort(devices, devices + n);
      int mask = 0;
      int mini = 1000;
      while(mask < (1 << 10)){
        FOR(i, 0, n){
          newoutlet[i] = outlet[i] ^ mask;
        }
        sort(newoutlet, newoutlet+n);
        bool equal = true;
        FOR(i, 0, n){
          if(newoutlet[i] != devices[i]) {
            equal = false;
            break;
          }
        }
        if(equal){
          mini = min(mini, __builtin_popcount(mask));
        }
        mask++;
      }
      printf("Case #%d: ", cse++);
      if(mini == 1000) printf("NOT POSSIBLE\n");
      else printf("%d\n", mini);
    }
    return 0;
}

void print_array(int* array, int start, int end){
  printf("[");
  FOR(i, start, end){
    printf("%d ", array[i]);
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