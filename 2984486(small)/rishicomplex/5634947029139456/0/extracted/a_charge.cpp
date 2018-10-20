#include <cstdio>
#include <cstdlib>
#include <cstring>

char outlets[200][50];
char outlets1[200][50];
char devices[200][50];
int sett[200];
int N, L;

int findmatch(int ind) {
  int i;
  for(i = 0; i < N; i++) {
    sett[i] = 0;
  }
  int j;
  char tempstr1[50], tempstr2[50];
  for(i = 0; i < N; i++) {
    memcpy(tempstr1, &outlets1[i][0], ind + 1);
    tempstr1[ind + 1] = '\0';
    for(j = 0; j < N; j++) {
      if(sett[j] == 1) continue;
      memcpy(tempstr2, &devices[j][0], ind + 1);
      tempstr2[ind + 1] = '\0';
      //printf("comparing %s and %s\n", tempstr1, tempstr2);
      if(strcmp(tempstr1, tempstr2) == 0) {
	sett[j] = 1;
	break;
      }
    }
    if(j == N) return 0;
  }
  return 1;
}

void flip(int ind) {
  int i;
  for(i = 0; i < N; i++) {
    if(outlets1[i][ind] == '1') outlets1[i][ind] = '0';
    else outlets1[i][ind] = '1';
  }
}

void copyoutlets() {
  int i, j;
  for(i = 0; i < N; i++) {
    for(j = 0; j < L + 1; j++) {
      outlets1[i][j] = outlets[i][j];
    }
  }
}
      

void work(int ind) {
  printf("Case #%d: ", ind);
  scanf("%d %d", &N, &L);
  int i;
  for(i = 0; i < N; i++) {
    scanf("%s", outlets[i]);
  }
  for(i = 0 ; i < N; i++) {
    scanf("%s", devices[i]);
  }
  int j;
  
  copyoutlets();
  int ocnt = 0, flag = 0, dcnt = 0, flipcnt = 0, temp, min = L + 1;
  for(i = 0; i < N; i++) {
    copyoutlets();
    flipcnt = 0;
    for(j = 0; j < L; j++) {
      if(devices[N][j] != outlets1[0][j]) {
	flip(j);
	flipcnt++;
      }
    }
    temp = findmatch(N - 1);
    if(temp == 1) {
      if(flipcnt < min) min = flipcnt;
    }
  }
  if(min == L + 1) {
    printf("NOT POSSIBLE\n");
  }
  else {
    printf("%d\n", min);
  }


}
    
    
      
      

int main() {
  int T;
  scanf("%d", &T);
  int cnt;
  for(cnt = 1; cnt <= T; cnt++) {
    work(cnt);
  }
  return 0;
}
