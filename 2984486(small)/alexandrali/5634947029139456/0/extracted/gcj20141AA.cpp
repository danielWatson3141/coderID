#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <time.h>
#define LL long long
#define MXN 152
#define MXL 42
using namespace std;
int T,n,L,minn=MXN;
LL aa[MXN],bb[MXN];
char ch[MXN][MXL],ch2[MXN][MXL],tmp[MXN][MXL],tmp2[MXN][MXL];
bool flag[MXL];
inline void Init(){
	scanf("%d%d\n",&n,&L);
	for(int i=1;i<=n;i++) {
		while((ch[i][0]=getchar())<'0'||ch[i][0]>'1');
		for(int j=1;j<L;j++) scanf("%c",&ch[i][j]);
		//printf("%s\n",ch[i]);
	}
	for(int i=1;i<=n;i++) {
		while((ch2[i][0]=getchar())<'0'||ch2[i][0]>'1');
		for(int j=1;j<L;j++) scanf("%c",&ch2[i][j]);
		//printf("%s\n",ch2[i]);
	}
}
inline bool cmp(LL a,LL b) {
	return a<b;
}
inline void solve(){
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++) {
	   Init();
	   minn=MXN; ///
	   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
	   	  for(int k=0;k<L;k++) flag[k]=0;
	   	  int total=0;
	   	  for(int k=0;k<L;k++) if(ch[i][k]!=ch2[j][k]){
	   	  	flag[k]=1;total++;
	   	  }
	   	  //printf("%d\n",total);
	   	  for(int k=0;k<=n;k++) aa[k]=bb[k]=0;
	   	  for(int k=1;k<=n;k++) {
	   	  	for(int l=0;l<L;l++) {
	   	  		tmp[k][l]=ch[k][l];tmp2[k][l]=ch2[k][l];
	   	  		if(flag[l]) tmp2[k][l]='1'-tmp2[k][l]+'0';
	   	  	}
	   	  	//printf("%s %s\n",tmp[k],tmp2[k]);
	   	  }
	   	  for(int k=1;k<=n;k++) {
	   	  	LL noww=1;
	   	  	for(int l=0;l<L;l++) {
		         aa[k]=aa[k]+noww*(tmp[k][l]-'0');
		         //printf("%I64d",tmp2[k][l]-'0');
		         bb[k]=bb[k]+noww*(tmp2[k][l]-'0');
		         noww*=2;
		     }
		     //printf("\n");
	   	  }
	   	  //printf("\n");
	   	  sort(aa+1,aa+n+1,cmp);sort(bb+1,bb+n+1,cmp);
	   	  //for(int k=1;k<=n;k++) printf("%I64d %I64d\n",aa[k],bb[k]);
	   	  bool ok=0;
	   	  for(int k=1;k<=n;k++) {
	   	  	if(aa[k]!=bb[k]) {ok=1;break;}
	   	  }
	   	  if(!ok) minn=min(minn,total);
	   }
	   if(minn<MXN) printf("Case #%d: %d\n",ii,minn);
	   else printf("Case #%d: NOT POSSIBLE\n",ii);
    }
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("gcj20141AA.in","r",stdin);freopen("gcj20141AA.out","w",stdout);
	#endif
	solve();
    return 0;
}

