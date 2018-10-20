#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int P[1000];

int Solver(int N){
  int i, r1=0, r2=0;
  for( i = 0; i < N; i ++ ){
    if( P[i] == i ){
      r1 ++;
    }
    r2 += i * (P[i]-N/2);
  }
  printf("%d\t%d\n", r1, abs(r2));

  if( abs(r2) < 2000000 ){
    return 0;
  }
  else{
    return 1;
  }
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i, N, res;

  if( argc < 3 ){
    printf("Usage is: task1 filein fileout\n");
    return 0;
  }

  // Input 

  filein = fopen(argv[1], "r");
  if( filein == NULL ){
    printf("Error open(); filein\n");
    return 0;
  }
  fileout = fopen(argv[2], "w");
  if( fileout == NULL ){
    printf("Error open(); fileout\n");
    return 0;
  }

  fscanf(filein, "%d\n", &T);
//  printf("%d\n", T);
  for( t = 0; t < T; t ++ ){
//    printf("-------------\t=%d\n", t);
    fscanf(filein, "%d\n", &N);
//    printf("%d\n", N);
    for( i = 0; i < N - 1; i ++ ){
      fscanf(filein, "%d ", &(P[i]) );
//      printf("%d ", P[i]);
    }
    fscanf(filein, "%d\n", &(P[N - 1]) );
//    printf("%d\n", P[N - 1]);

    // Solve & Output
    res = Solver(N);
    if( res == 0 ){
      fprintf(fileout, "Case #%d: GOOD\n", t + 1);
    }
    else{
      fprintf(fileout, "Case #%d: BAD\n", t + 1);
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
