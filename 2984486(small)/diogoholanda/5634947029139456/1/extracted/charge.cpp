#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int T, N, L, resp;

long long int v1[200];
long long int v2[200];
long long int v3[200];
long long int pot[50];
char s[100];

int check(int a){
  sort(v2, v2+N);
  sort(v3, v3+N);
  for(int i=0; i<N; i++){
    if((v2[i]>>(L-a))!=(v3[i]>>(L-a))) return 0;
  }
  return 1;
}

void f(int pos, long long int mask, int count){
  if(count>=resp) return;
  if(pos==L){
    resp = count;
    return;
  }
  
  for(int i=0; i<N; i++){
    v3[i] = (v1[i] ^ mask);
  }
  if(check(pos+1)) f(pos+1,mask,count);
  for(int i=0; i<N; i++){
    v3[i] = (v1[i] ^ (mask + pot[L-pos-1]));
  }
  if(check(pos+1)) f(pos+1,mask + pot[L-pos-1],count+1);
}

int main(){
  scanf(" %d", &T);
  pot[0] = 1;
  for(int i=1; i<50; i++) pot[i] = 2*pot[i-1];
  
  for(int u=1; u<=T; u++){
    scanf(" %d %d", &N, &L);
    for(int i=0; i<N; i++){
      scanf(" %s", s);
      v1[i] = 0;
      for(int j=0; j<L; j++){
        if(s[j]=='1') v1[i] += pot[L-j-1];
      }
    }
    for(int i=0; i<N; i++){
      scanf(" %s", s);
      v2[i] = 0;
      for(int j=0; j<L; j++){
        if(s[j]=='1') v2[i] += pot[L-j-1];
      }
    }
    
    resp = 1000;
    
    f(0,0,0);
    
    printf("Case #%d: ", u);
    if(resp==1000) printf("NOT POSSIBLE\n");
    else printf("%d\n", resp);
  }
  return 0;
}
