#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int XY[1000][2], W[1001], Ne[1001][1001];

int rec(int num, int up){
  int i, j, res, max;

  if( W[num] < 2 ){
    return 1;
  }
  if( ( up != -1 ) && ( W[num] < 3 ) ){
    return 1;
  }
  max = 0;
  for( i = 0; i < W[num] - 1; i ++ ){
    if( Ne[num][i] == up ){
      continue;
    }
    for( j = i + 1; j < W[num]; j ++ ){
      if( Ne[num][j] == up ){
        continue;
      }
      res = rec(Ne[num][i], num) + rec(Ne[num][j], num) + 1;
      if( res > max ){
        max = res;
      }
    }
  }
  return max;
}

int Solver(int N){
  int i, j, k, res, max = 0;

  for( i = 0; i <= N; i ++ ){
    W[i] = 0;
  }
  for( i = 0; i < N - 1; i ++ ){
    Ne[XY[i][0]][W[XY[i][0]]] = XY[i][1];
    Ne[XY[i][1]][W[XY[i][1]]] = XY[i][0];
    W[XY[i][0]] ++;
    W[XY[i][1]] ++;
  }

  for( i = 1; i <= N; i ++ ){
    printf("W[%d]=%d ", i, W[i]);
    for( j = 0; j < W[i]; j ++ ){
      printf("Ne[%d][%d]=%d ", i, j, Ne[i][j]);
    }
    printf("\n");
  }

  for( i = 1; i <= N; i ++ ){
    res = rec(i, -1);
    if( res > max )
      max = res;
  }

  return N - max;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i, N;
  __int64 res, r, t1;

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
  printf("%d\n", T);
  for( t = 0; t < T; t ++ ){
    printf("-------------\t=%d\n", t);
    fscanf(filein, "%d\n", &N);
    printf("%d\n", N);
    for( i = 0; i < N - 1; i ++ ){
      fscanf(filein, "%d %d\n", &(XY[i][0]), &(XY[i][1]));
      printf("%d %d\n", XY[i][0], XY[i][1]);
    }

    // Solve & Output
    res = Solver(N);
    fprintf(fileout, "Case #%d: %d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
