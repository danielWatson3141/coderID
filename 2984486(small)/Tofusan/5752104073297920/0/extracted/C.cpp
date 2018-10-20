#include <stdio.h>
#include <stdlib.h>

int t,n,tmp;
long long sc,tt,chk;
main()
{
 freopen("C-small-attempt1.in","r",stdin);
 freopen("C-small-attempt1.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%d",&n);
  sc=0;
  for(int i=0;i<n;i++)
  {
   scanf("%d",&tmp);
   tt=(long long)i*tmp*tmp;
   sc=sc+tt;
  }
  chk=169;
  for(int i=1;i<=9;i++)
  {
   chk=(long long)chk*10;
  }
  printf("Case #%d: ",tests);
  if(sc<=chk){printf("GOOD\n");}
  else{printf("BAD\n");}
  //printf("%I64d\n",sc);
  //randomly try
 }
 
 return 0;
}
