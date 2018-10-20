int N;

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int count_bits(const int64_t& vv) {
  int64_t v = vv;
  int n=0;
  while (v>0) {
    if ((v&1) != 0) n++;
    v=v>>1;
  }
  return n;
}

int main(int argc, char* argv[])
{
  if (argc>1) freopen(argv[1],"r",stdin);
  if (argc>2) freopen(argv[2],"w",stdout);

  // Input
  scanf("%d\n",&N);
  fprintf(stderr,"N = %d: \n",N);

  // Output
  for (int x=1; x<=N; x++) {
    fprintf(stderr,"Case #%d: \n",x);

    string str;
    getline(cin,str);
    stringstream ss(str);
    int N, L;
    ss >> N >> L;
    int64_t plug[N];
    vector<int64_t> dev(N);
    getline(cin,str);
    for (int d=0; d<N; d++) {
      plug[d] = 0;
      for (int i=0; i<L; i++) {
        plug[d] += (str[d*(L+1) + i] == '1') << (L-1-i);
      }
      fprintf(stderr,"%llo ",plug[d]);
    }
    fprintf(stderr,"\n");
    getline(cin,str);
    for (int d=0; d<N; d++) {
      dev[d]=0;
      for (int i=0; i<L; i++) {
        dev[d] += (str[d*(L+1) + i] == '1') << (L-1-i);
      }
      fprintf(stderr,"%llo ",dev[d]);
    }
    fprintf(stderr,"\n");
    sort(dev.begin(),dev.end());
    for (int i=0; i<N; i++) fprintf(stderr,"%llo ", dev[i]);
    fprintf(stderr,"\n");

    int best = L+1;
    for (int i=0; i<N; i++) {
      int64_t flip = dev[0] ^ plug[i];
      if (count_bits(flip) > best) continue;
      fprintf(stderr,"try flip %llo (cost %d)\n", flip, count_bits(flip));
      bool found = true;
      for (int p=0; p<N; p++) {
        // fprintf(stderr,"Look for plug %d: %llo -> %llo\n",p, plug[p], plug[p]^flip);
        if (!binary_search(dev.begin(), dev.end(), plug[p] ^ flip)) {
          fprintf(stderr,"Could not find device for plug %d: %llo -> %llo\n",p, plug[p], plug[p]^flip);
          found = false;
          break;
        }
      }
      if (found) {
        fprintf(stderr,"FOUND solution at cost %d\n",count_bits(flip));
        if (count_bits(flip)<best) {
          best = count_bits(flip);
        }
      }
    }

    printf("Case #%d: ",x);
    if (best == L+1) {
        fprintf(stderr,"DID NOT FIND ANY solution\n");
        printf("NOT POSSIBLE\n");
    }
    else printf("%d\n",best);
  }
  return 0;
}
