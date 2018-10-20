#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

#include <stdint.h>

#include <math.h>

//#define DBG(a,...)
#define DBG printf

using namespace std;

static unsigned long long OUT[200];
static unsigned long long FLOW[200];

static int best_sw = 0;

int main()
{
  int tn;
  int v = scanf("%d",&tn);
  (void)v;

  bool imp = true;

  int ti = 1;
  while(tn) {

    int N;
    int L;

    imp = true;
    best_sw = 9999;

    v = scanf("%d %d",&N,&L);

    //DBG("N %d L %d\n",N,L);

    // inital flow
    int n;
    for (n = 0; n < N; n++) {
      char s[100];
      v = scanf("%s",s);
      OUT[n] = 0;
      int i;
      for (i = 0; i < L; i++) {
        OUT[n] |= (s[i] == '1') ? (1 << (L-i-1)) : 0;
      }
      //DBG("(%s,%lli)",s,OUT[n]);
    }

    // required devices
    for (n = 0; n < N; n++) {
      char s[100];
      v = scanf("%s",s);
      FLOW[n] = 0;
      int i;
      for (i = 0; i < L; i++) {
        FLOW[n] |= (s[i] == '1') ? (1 << (L-i-1)) : 0;
      }
      //DBG("(%s,%lli)",s,FLOW[n]);
    }

    unsigned long long x;    
    // test all switches
    for (x = 0; x < (1ULL << L); x++) {

      bool all_possible = true;
      char TAKEN[N+1];
      memset(TAKEN, 0, N);

      // test all devices
      for (n = 0; n < N; n++) {
        int n2;

        bool dev_possible = false;

        //  on all outlets
        for (n2 = 0; n2 < N; n2++) {

          if (TAKEN[n2]) {
            continue;
          }

          //DBG("TEST n %d n2 %d o %016llx f %016llx\n", n, n2, OUT[n], FLOW[n]);

          if ((OUT[n2] ^ x) == FLOW[n]) {
            // found outlet (but now taken!)
            TAKEN[n2] = true;
            dev_possible = true;
            break;
          }
          
        }

        // found outlet for this device?
        if (!dev_possible) {
          all_possible = false;
          break;
        }
      }
   
      // check switch conf
      if (all_possible) {

        imp = false;

        int sw = 0;
        // check sw bits used
        int i;
        for (i = 0; i < L; i++) {
          if (x & (1 << (L - i - 1))) {
            sw++;
          }
        }
        if (sw < best_sw) {
          best_sw = sw;          
        }
      }
    }

    if (imp) {
      printf("Case #%d: NOT POSSIBLE\n", ti);
    }
    else {
      printf("Case #%d: %d\n", ti, best_sw);
    }

    ti++;
    tn--;
  }

  return 0;
}
