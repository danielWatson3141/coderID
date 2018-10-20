#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 200
#define MAXL 50

int n, l;
string o[MAXN], d[MAXN], aux[MAXN];
int troca[MAXL];

int main () {
  int teste;
  scanf ("%d", &teste);
  for (int t = 0; t < teste; t++) {
    scanf ("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
      cin >> o[i];
    }
    for (int i = 0; i < n; i++) 
      cin >> d[i];
    int ret = -1;
    sort (d, d + n);
    sort (o, o + n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) 
	aux[j] = o[j];
      int local = 0;
      for (int j = 0; j < l; j++) {
	troca[j] = (o[i][j] != d[0][j]);
	local += troca[j];
	for (int k = 0; k < n; k++) 
	  if (troca[j]) 
	    o[k][j] = (o[k][j] == '1')? '0' : '1';
      }
      sort (o, o + n);
      int flag = 1;
      for (int i = 0; i < n; i++) 
	if (o[i] != d[i]) {
	  flag = 0;
	  break;
	}
      if (flag == 1) {
	if (ret == -1)
	  ret = local;
	else
	  ret = min (ret, local);
      }
      for (int j = 0; j < n; j++) 
	o[j] = aux[j];
    }
    printf ("Case #%d: ", t + 1);
    if (ret == -1)
      printf ("NOT POSSIBLE\n");
    else
      printf ("%d\n", ret);
  }
  return 0;
}
