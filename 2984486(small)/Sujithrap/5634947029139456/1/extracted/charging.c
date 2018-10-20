#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *ip = NULL, *op = NULL;

int countSetBits(unsigned long n)
{
  unsigned long count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

void compute_number(int tc, unsigned long *ol, unsigned long *ds, int N, int L)
{
  unsigned long result[150][150];
  unsigned long count = 0, n1 = 0, n2 = 0;
  unsigned long sns[150], small = 0xFFFFFFFF, index = 0;
  int i,j,k;
  char ops[100];
	

  for(i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      result[i][j] = ol[i] ^ ds[j];
    }
  }

  i = 0;
  while(i < N) {
    n1 = result[0][i];
    for(j = 1; j < N; j++) {
      for(k = 0; k < N; k++) {
	n2 = result[j][k];
	if (n1 == n2) {
	  count++;
	  break;
	}
      }
    }
    if (count == N-1) {
      sns[index++] = n1;
      if (small > n1) {
	small = n1;
      }
    }
    count = 0;
    i++;
  }

  if (index == 0) {
     sprintf(ops, "Case #%d: NOT POSSIBLE\n", tc);
  }
  else {
    sprintf(ops, "Case #%d: %u\n", tc, countSetBits(small)); 
  }
  fputs(ops, op);

}

int main()
{
  int T = 0;
  int N = 0, L = 0, i = 0, j = 0, k = 0;
  char c, *ptr;
  char line[10240];
  unsigned long *outlet, *desired, bp;

  ip = fopen("input.txt", "r");
  op = fopen("output.txt", "w");
  fscanf(ip, "%d\n", &T);

  for(i = 0; i < T; i++) {
    fscanf(ip, "%d %d\n", &N, &L);
    fgets(line, 10240, ip);
    outlet = malloc(sizeof(unsigned long)*N);
    ptr = &line[0];
    for(j = 0; j < N; j++) {
      outlet[j] = 0;
      bp = 0;
       for(k = 0; k < L; k++) {
	 c = ptr[k];
	 if (c == '1') {
	   bp = bp | ( 1 << (L - k -1));
	 }
       }
       outlet[j] = bp;
       ptr += L+1;
    }

    fgets(line, 10240, ip);
    desired = malloc(sizeof(unsigned long)*N);
    ptr = &line[0];
    for(j = 0; j < N; j++) {
      desired[j] = 0;
      bp = 0;
       for(k = 0; k < L; k++) {
	 c = ptr[k];
	 if (c == '1') {
	   bp = bp | ( 1 << (L - k -1));
	 }
       }
       desired[j] = bp;
       ptr += L+1;
    }

    compute_number(i+1, outlet, desired, N, L);
  }

  return 0;
}
