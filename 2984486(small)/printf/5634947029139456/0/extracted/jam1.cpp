#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <assert.h>
#include<string>
#include <cmath>
#include <algorithm>
using namespace std;
char s[155][45], sc[155][45], st[155][45];
int n, l;
int compare (const void * a, const void * b) {
  return strcmp((char*)a, (char*)b);
}
int update(int a, int b) {
    int m[155] = {0}, c = 0;
    memcpy(sc, st, 155*45);
    for(int k = 0; k < l; k++)
        if(s[a][k] != st[b][k]) m[k] = 1, c++;
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < l; j++) {
            if(m[j]) {
                if(sc[i][j] == '0')   sc[i][j] = '1';    
                else if(sc[i][j] == '1')   sc[i][j] = '0';
            }
        }
    }
    qsort(sc, n, sizeof(sc[0]), compare);
    int i;
    for(i = 0; i < n; i++)
        if(strcmp(s[i], sc[i]))
            break;
    if(i == n)
        return c;
    else return 100;
    
}
int main()
{
    int t;
    
	FILE *fp=fopen("in.txt", "r"), *ofp=fopen("out.txt", "w");
    fscanf(fp, "%d", &t);
    for(int k = 1;k <= t; k++) {
       int m[155] = {0}, min = 50;
       fscanf(fp, "%d%d", &n, &l);
       for(int i = 0; i < n; i++)
           fscanf(fp, "%s", &s[i]);
       for(int i = 0; i < n; i++)
           fscanf(fp, "%s", &st[i]);
           
       qsort(s, n, sizeof(s[0]), compare);
       qsort(st, n, sizeof(st[0]), compare);
       
       int u;
       for(u = 0; u < n; u++)
           if(strcmp(s[u], st[u]))
               break;
       if(u == n) {
           min = 0;
           goto res;
       }       
       
       for(int i = 0; i < n; i++) {
           for(int j = 0; j < n; j++) {
                int res = update(i, j);
                if(res < min)
                    min = res;
           }
       }
res:
       if(min == 50)
           fprintf(ofp, "Case #%d: NOT POSSIBLE\n", k);
       else
           fprintf(ofp, "Case #%d: %d\n", k, min);
    }           
    fclose(fp);
    fclose(ofp); 
    system("pause");
    return 0;
}
