#include "stdio.h"
#include "stdlib.h"
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include "stdint.h"

#define pb push_back

using namespace std;

uint64_t O[200], I[50];
char S[50];

int main() {
  int _N, N, L;
  scanf("%d", &_N);
  for (int TC=1; TC<=_N; TC++) {
    scanf("%d%d", &N, &L);
    for (int i=0; i<N; i++) {
      scanf("%s", S);
      O[i]=0;
      for (int j=0; j<L; j++)
        if (S[j] == '0') O[i] *= 2;
        else O[i] = O[i]*2 + 1;
    }
    for (int i=0; i<N; i++) {
      scanf("%s", S);
      I[i]=0;
      for (int j=0; j<L; j++)
        if (S[j] == '0') I[i] *= 2;
        else I[i] = I[i]*2 + 1;
    }

    vector<uint64_t> a;
    int ans = L+1;
    for (int i=0; i<N; i++) a.pb(O[i]);
    sort(a.begin(), a.end());
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        uint64_t tmp = (O[i] ^ I[j]);
        vector<uint64_t> b;
        for (int k=0; k<N; k++) b.pb(I[k] ^ tmp);
        sort(b.begin(), b.end());
        if (a==b) {
          int cc = 0;
          while (tmp) {
            cc += (tmp&1);
            tmp/=2;
          }
          if (cc < ans)
            ans = cc;
        }
      }
    }

    if (ans == L+1) printf("Case #%d: NOT POSSIBLE\n", TC);
    else printf("Case #%d: %d\n", TC, ans);
  }
}