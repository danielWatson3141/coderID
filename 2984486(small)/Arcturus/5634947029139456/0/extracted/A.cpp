#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXF 1000000

using namespace std;

struct SC{
  char s[50];
};

int N, L;
SC init[160];
SC tgt[160];
SC tgt2[160];
bool isFlip[50];
int nFlip;
int bestFlip;


bool f1(SC a, SC b){
  if(strcmp(a.s, b.s) < 0) return true;
  return false;
}

bool Evaluate(){
  for(int i=0; i<N; i++){
    for(int j=0; j<L; j++){
      if(isFlip[j]){
        if(tgt[i].s[j] == '0') tgt2[i].s[j] = '1';
        else tgt2[i].s[j] = '0';
      }
      else tgt2[i].s[j] = tgt[i].s[j];
    }
  }
  
  sort(tgt2, tgt2+N, f1);
  
  for(int i=0; i<N; i++){
    for(int j=0; j<L; j++){
      if(tgt2[i].s[j] != init[i].s[j]) return false;
    }
  }
  return true;
}

void Work(){
  bestFlip = MAXF;
  sort(init, init+N, f1);
  
  for(int i=0; i<N; i++){
    nFlip = 0;
    for(int j=0; j<L; j++){
      if(tgt[0].s[j] == init[i].s[j]) isFlip[j] = false;
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

int main(){
  int jcase;
  
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++) scanf("%s", init[i].s);
    for(int i=0; i<N; i++) scanf("%s", tgt[i].s);
    
    Work();
    printf("Case #%d: ", icase+1);
    if(bestFlip == MAXF) printf("NOT POSSIBLE\n");
    else printf("%d\n", bestFlip);
  }
  
  return 0;
}
