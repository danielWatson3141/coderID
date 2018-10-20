#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <set>
#include <string>
#include <map>

//#define DEBUG

using namespace std;

typedef long long ll;

int T,Cas=0;

#ifndef DEBUG

int N, a[1005], p[1005], g[1005];

int get(int val, int st) {
  for (int i=st;i<N;i++)
    if (g[i]==val)
      return i;
  return -1;
}

int main() {
  scanf("%d",&T);
  while (T--) {
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
      scanf("%d", a+i);
      g[i]=i;
    }
    bool good=true;
    for (int i=0;i<N;i++) {
      int pos=get(a[i], i);
      if (pos<0) {
        good=false;
        break;
      }
      p[i]=pos;
      swap(g[i], g[pos]);
      //printf("(%d:%d) ",pos-i, N-i-1);
    }
    //puts("");
    printf("Case #%d: ", ++Cas);
    if (good && p[0]>N/2)
      puts("GOOD");
    else
      puts("BAD");
  }
}

#else

int N=4, N2, NF, a[1005];
char build[10];

map<string,int> pos;

int main() {
  NF=N2=1;
  for (int i=0;i<N;i++)
    N2*=N, NF*=i+1;
  pos.clear();
  for (int i=0;i<N2;i++) {
    for (int j=0;j<N;j++)
      a[j]=j;
    for (int k=0,p=i;k<N;k++,p/=N) {
      int r=p%N;
      swap(a[k],a[r]);
    }
    for (int j=0;j<N;j++) {
      build[j]=a[j]+'0';
    }
    build[N]=0;
    pos[build]++;
  }
  for (map<string,int>::iterator it=pos.begin();it!=pos.end();++it) {
    double maybe = it->second*NF/double(N2), range = 1.7;
    //if (maybe<range || maybe>range+1.2)
    //  continue;
    printf("%s: %f\n", it->first.c_str(), maybe);
  }
  return 0;
}

#endif