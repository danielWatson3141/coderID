#include<iostream>
#include<cstdio>
using namespace std;
int a[1000];

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int n; scanf("%d",&n);
	  for(int i=0; i<n; i++) scanf("%d",&a[i]);
	  int inv=0;
	  for(int i=0; i<n; i++){
	     for(int j=i+1; j<n; j++){
		    if (a[i]>a[j]) inv++;
		 }
	  }
	  int tmp=n*(n-1); tmp/=2;
	  if (2*inv>=tmp) printf("Case #%d: BAD\n",cs+1);
	  else printf("Case #%d: GOOD\n",cs+1);
   }
}