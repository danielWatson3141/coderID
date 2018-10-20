#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int T,Cas=0;

int N,L;
ll a[160], b[160], c[160];

multiset<ll> words, build;

ll get(const char *s) {
  ll ret=0;
  for (int i=0;s[i];i++)
    ret=(ret<<1)+s[i]-'0';
  return ret;
}

int cnt(ll val) {
  int ret=0;
  while (val) {
    val=val&(val-1);
    ++ret;
  }
  return ret;
}

void disp(multiset<ll> &ss) {
  for (multiset<ll>::iterator it=ss.begin();it!=ss.end();++it)
    printf("(%d) ", *it);
  puts("");
}

int main() {
  static char buf[1000];
	scanf("%d",&T);
	while (T--) {
    scanf("%d%d",&N,&L);
    for (int i=0;i<N;i++) {
      scanf("%s", buf);
      a[i]=get(buf);
    }
    words.clear();
    for (int i=0;i<N;i++) {
      scanf("%s", buf);
      c[i]=get(buf);
      words.insert(c[i]);
    }
    //disp(words);
    int least=0x3fffffff;
    for (int ii=0;ii<N;ii++) {
      int i=a[0]^c[ii];
      build.clear();
      for (int j=0;j<N;j++) {
        b[j]=a[j]^i;
        build.insert(b[j]);
      }
      //disp(build);
      if (words==build) {
        least=min(least, cnt(i));
        //printf(">> %d\n", i);
      }
    }
    printf("Case #%d: ", ++Cas);
    if (least==0x3fffffff)
      puts("NOT POSSIBLE");
    else
      printf("%d\n", least);
	}
}