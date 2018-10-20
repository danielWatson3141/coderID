#include <iostream>
#include <cstdio>
using namespace std;

int N, arr[1024];

int main() {
  int cas, u, bad;
  double res;
  scanf("%d",&cas);
  for (int k=1; k<=cas; ++k) {
    scanf("%d", &N); u=0;
    for (int i=0; i<N; ++i) scanf("%d", &arr[i]);
    for (int i=0; i<N/2; ++i) {
      if (arr[i]>N/2) ++u;
    }
    bad = u>=242 && u<=258;
    printf("Case #%d: %s\n",k,bad? "BAD":"GOOD");
  }
  return 0;
}
