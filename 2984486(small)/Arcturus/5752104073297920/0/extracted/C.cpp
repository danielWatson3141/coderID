#include <stdio.h>
#include <stdlib.h>

int N;
int arr[1010];

void Swap(int &a, int &b){
  int c= a;
  a = b;
  b = c;
}

void Bad(){
  for(int k=0; k<N; k++) arr[k] = k;
  for(int k=0; k<N; k++){
    int r = rand()%N;
    Swap(arr[k], arr[r]);
  }
  
  //for(int i=0; i<N; i++) printf("%2d ", arr[i]);
}

void Good(){
  for(int k=0; k<N; k++) arr[k] = k;
  for(int k=0; k<N; k++){
    int r = rand()%(N-k) + k;
    Swap(arr[k], arr[r]);
  }
  
  //for(int i=0; i<N; i++) printf("%2d ", arr[i]);
  //printf("\n");
}

int CalcScore(int id, int val){
  int half = N/2;
  if(id + half < N){
    int sub = id+half;
    if(val <= id) val += N;
    return sub - val;
  }
  //printf("not return\n");
  //else
  int sub = id - half;
  if(val < id) return sub - val;
  else return val - sub;
}

int main(){
  int jcase;
  int score;
  int half;
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-small-attempt0.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    //N = 1000;
    //Bad();
    //Good();
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    score = 0;
    half = N/2;
    
    for(int i=0; i<N; i++){
      int plus = CalcScore(i, arr[i]);
      score += plus;
      //printf("score %d\n", plus);
    }
    if(score < 55000) printf("Case #%d: GOOD\n", icase+1);
    else printf("Case #%d: BAD\n", icase+1);
  }
  
  return 0;
}
