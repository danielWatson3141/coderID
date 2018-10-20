#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 155;
const int MAXL = 45;

int n, l;
char A[MAXN][MAXL];
char B[MAXN][MAXL];
int bio[MAXN];
int uzeo[MAXN];

int calc (){
  memset(uzeo, 0, sizeof uzeo);
  int ret = 0;
  for (int i = 0; i < l; ++i)
    if (bio[i]){
      ++ret;
      for (int j = 0; j < n; ++j)
	A[j][i] = ((A[j][i] - '0')^1) + '0';
    }


  for (int i = 0; i < n; ++i){

    bool ok = 0;
    for (int j = 0; j < n; ++j){
      if (uzeo[j]) continue;
      if (strcmp(A[j], B[i]) == 0){ 
	ok = 1;
        uzeo[j] = 1;	
	break;
      }
    }

    if (!ok){
      ret = 1 << 30;
      break;
    }

  }

  for (int i = 0; i < l; ++i)
    if (bio[i])
      for (int j = 0; j < n; ++j)
	A[j][i] = ((A[j][i] - '0')^1) + '0';

  return ret;
}


void solve (){
  scanf("%d%d", &n, &l);
  for (int i = 0; i < n; ++i) scanf("%s", A[i]);
  for (int i = 0; i < n; ++i) scanf("%s", B[i]);
  
  int ret = 1 << 30;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){

      for (int k = 0; k < l; ++k)
	if (A[i][k] != B[j][k]) bio[k] = 1;
	else bio[k] = 0;

	ret = min(ret, calc());
    }
  }

  if (ret >= 10000) printf("NOT POSSIBLE\n");
  else printf("%d\n", ret);
}

int main (void){
  int tc; scanf ("%d", &tc);
  for (int i = 1; i <= tc; ++i){
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}


