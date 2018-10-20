#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int T, N, L, temp, resp;

long long int v1[200];
long long int v2[200];
long long int v3[200];
long long int pot[50];
char s[100];

int check(){
  sort(v2, v2+N);
  sort(v3, v3+N);
  for(int i=0; i<N; i++){
    if(v2[i]!=v3[i]) return 0;
  }
  return 1;
}

int count(long long int a){
  int ret = 0;
  for(int i=0; i<50; i++){
    if((a & pot[i]) != 0) ret++;
  }
  return ret;
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
    for(long long int mask = 0; mask<pot[L]; mask++){
      for(int i=0; i<N; i++){
        v3[i] = v1[i] ^ mask;
      }
      if(check()){
        //printf("%lld\n", mask);
        temp = count(mask);
        if(temp<resp) resp = temp;
      }
    }
    
    printf("Case #%d: ", u);
    if(resp==1000) printf("NOT POSSIBLE\n");
    else printf("%d\n", resp);
  }
  return 0;
}
