#include <stdio.h>
#include <string.h>

int T, u, resp, N, limite;
int v[1010];


int abs(int a){
  if(a<0) return -a;
  return a;
}

int main(){
  scanf(" %d", &T);
  limite = 0;
  for(int i=0; i<1000; i++){
    for(int j=0; j<1000; j++){
      limite+=abs(i-j);
    }
  }
  limite/=1000;
  for(int u=1; u<=T; u++){
    resp = 0;
    scanf(" %d", &N);
    for(int i=0; i<N; i++){
      scanf(" %d", &v[i]);
      resp+=abs(v[i]-i);
    }
    
    printf("Case #%d: ", u);
    if(resp<limite) printf("BAD\n");
    else printf("GOOD\n");
  }
  return 0;
}
