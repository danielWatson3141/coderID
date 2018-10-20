#include <stdio.h>
#include <algorithm>
#define MAXF 1000000

using namespace std;


int N, L;
long long init[160];
long long tgt[160];
long long tgt2[160];
bool isFlip[50];
int nFlip;
int bestFlip;


bool Evaluate(){
  for(int i=0; i<N; i++){
    long long bit = 1;
    tgt2[i] = tgt[i];
    
    for(int j=0; j<L; j++){
      if(j > 0) bit <<= 1;
      if(isFlip[j]) tgt2[i] ^= bit;
    }
  }
  
  sort(tgt2, tgt2+N);
  
  /*for(int i=L-1; i>=0; i--){
    if(isFlip[i]) printf("1");
    else printf("0");
  }
  printf("\n");
  for(int i=0; i<N; i++) printf("%lld\n", tgt2[i]);
  printf("\n");
  */
  for(int i=0; i<N; i++) if(tgt2[i] != init[i]) return false;
  return true;
}

void Work(){
  bestFlip = MAXF;
  sort(init, init+N);
  
  for(int i=0; i<N; i++){
    nFlip = 0;
    long long bit = 1;
    
    for(int j=0; j<L; j++){
      if(j>0) bit <<= 1;
      long long tbit = tgt[i] & bit;
      long long ibit = init[0] & bit;
      
      if(tbit == ibit) isFlip[j] = false;
      else {
        isFlip[j] = true;
        nFlip++;
      }
    }
    
    if(nFlip < bestFlip){
      if(Evaluate()){
        bestFlip = nFlip;
      }
    }
  }
}

char istr[50];

int main(){
  int jcase;
  
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++){
      scanf("%s", istr);
      init[i] = 0;
      for(int j=0; j<L; j++){
        init[i] <<= 1;
        if(istr[j] == '1') init[i] |= 1;
      }
    }
    for(int i=0; i<N; i++){
      scanf("%s", istr);
      tgt[i] = 0;
      for(int j=0; j<L; j++){
        tgt[i] <<= 1;
        if(istr[j] == '1') tgt[i] |= 1;
      }
    }
    
    Work();
    printf("Case #%d: ", icase+1);
    if(bestFlip == MAXF) printf("NOT POSSIBLE\n");
    else printf("%d\n", bestFlip);
  }
  
  return 0;
}
