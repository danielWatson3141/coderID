#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char Outlets[150][41], Devices[150][41];
__int64 Outlets64[150], Devices64[150];

int compare( const void *arg1, const void *arg2 ){
  if( *(__int64*)arg1 > *(__int64*)arg2 )
    return 1;
  if( *(__int64*)arg1 < *(__int64*)arg2 )
    return -1;
  return 0;
}


int Solver(int N, int L){
  int i, j, k, res, res1;
  __int64 sw;
  bool flag;

  for( i = 0; i < N; i ++ ){
    Outlets64[i] = 0;
    Devices64[i] = 0;
    for( j = 0; j < L; j ++ ){
      Outlets64[i] = Outlets64[i] * 2 + (Outlets[i][j] == '1' ? 1 : 0);
      Devices64[i] = Devices64[i] * 2 + (Devices[i][j] == '1' ? 1 : 0);
    }
//    printf("Outlets[%d] = %I64d, Devices[%d] = %I64d\n", i, Outlets64[i], i , Devices64[i]);
  }

  qsort(Outlets64, N, sizeof(__int64), compare);
  qsort(Devices64, N, sizeof(__int64), compare);
//  for( i = 0; i < N; i ++ ){
//    printf("Outlets[%d] = %I64d, Devices[%d] = %I64d\n", i, Outlets64[i], i , Devices64[i]);
//  }

  res = -1;
  for( i = 0; i < N; i ++ ){
    qsort(Outlets64, N, sizeof(__int64), compare);
    qsort(Devices64, N, sizeof(__int64), compare);
    sw = Devices64[i] ^ Outlets64[0];
    for( j = 0; j < N; j ++ ){
      Outlets64[j] ^= sw;
    }
    qsort(Outlets64, N, sizeof(__int64), compare);
    flag = true;
    for( j = 0; j < N; j ++ ){
      if( Devices64[j]  != Outlets64[j] ){
        flag = false;
        break;
      }
    }
    if( flag ){
      res1 = 0;
      for( j = 0; j < L; j ++ ){
        if( sw & ( 1ul << j ) ){
          res1 ++;
        }
      }
      if( ( res == -1 )||( res1 < res ) ){
        res = res1;
      }
    }
    for( j = 0; j < N; j ++ ){
      Outlets64[j] ^= sw;
    }
  }

  return res;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, N, L, i, res;

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
    fscanf(filein, "%d %d\n", &N, &L);
    printf("%d %d\n", N, L);
    for( i = 0; i < N - 1; i ++ ){
      fscanf(filein, "%s ", Outlets[i]);
      printf("%s ", Outlets[i]);
    }
    fscanf(filein, "%s\n", Outlets[N-1]);
    printf("%s\n", Outlets[N-1]);
    for( i = 0; i < N - 1; i ++ ){
      fscanf(filein, "%s ", Devices[i]);
      printf("%s ", Devices[i]);
    }
    fscanf(filein, "%s\n", Devices[N-1]);
    printf("%s\n", Devices[N-1]);

    // Solve & Output
    res = Solver(N, L);
    if( res == -1 ){
      fprintf(fileout, "Case #%d: NOT POSSIBLE\n", t + 1, res);
    }
    else{
      fprintf(fileout, "Case #%d: %d\n", t + 1, res);
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
