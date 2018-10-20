#include <stdio.h>
#include <algorithm>
using namespace std;

struct node {
       char s[50];
} str1[200],str2[200], str3[200];
int pro[50];
int n, l;


int calc(int i,int j) {
    int num = 0;
    for (int k = 0; k < l; ++k) {
        if (str1[i].s[k] != str2[j].s[k]) {
           pro[k] = 1;
           num++;
        }
        else {
             pro[k] = 0;
        }
    }
    return num;
}

int cmp(node a,node b) {
    return strcmp(a.s,b.s) > 0;
}

int verify() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            if (pro[j] == 0) {
               str3[i].s[j] = str2[i].s[j];
            }
            else {
                 str3[i].s[j] = str2[i].s[j]=='0'?'1':'0';
            }
        }
        str3[i].s[l] = 0;
    }
    sort(str3,str3+n,cmp);
    for (int i = 0; i < n; ++i) {
        if (strcmp(str1[i].s,str3[i].s) != 0) {
           return 0;
        }
    }
    return 1;
}


int main() {
    int kase = 0;
    int h = 1;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d", &kase);
    while (kase--) {
          scanf("%d %d", &n, &l);
          for (int i = 0; i < n; ++i) {
              scanf("%s", str1[i].s);
          }
          sort(str1,str1+n,cmp);
          for (int i = 0; i < n; ++i) {
              scanf("%s", str2[i].s);
          }
          int ans = -1;
          for (int i = 0; i < n; ++i) {
              for (int j = i; j < n; ++j) {
                  int num = calc(i,j);
                  if (ans != -1 && num >= ans) {
                     continue;
                  }
                  if ( verify() ) {
                     ans = num;
                  }
              }
          }
          printf("Case #%d:",h++);
          if (ans == -1) {
             printf(" NOT POSSIBLE\n");
          }
          else {
               printf(" %d\n",ans);
          }
    }
    return 0;    
}
