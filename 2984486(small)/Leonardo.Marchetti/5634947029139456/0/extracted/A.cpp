#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int caso=1;caso<=t;caso++) {
		int A[200], B[200], C[200], n ,l;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		scanf("%d %d", &n, &l);
		for(int i=0;i<n;i++) {
			for(int j=0;j<l;j++) {
				char cc;
				scanf(" %c", &cc);
				if(cc=='1') 
					A[i] = (A[i] | (1<< j));
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<l;j++) {
				char cc;
				scanf(" %c", &cc);
				if(cc=='1') 
					B[i] = (B[i] | (1<< j));
			}
		}
	  set<int> S;
		for(int i =0; i<n;i++) 
			S.insert(B[i]);
		int mi = 100;
		for(int m=0; m < (1<<l) ;m++) {
			for(int i=0;i<n;i++)
				for(int j=0;j<l;j++) {
					C[i] = A[i];
				}
			int cnt=0;
			for(int j=0;j<l;j++) {
				if( (m&(1<<j))) {
					cnt++;
					for(int i=0;i<n;i++) {
						C[i] = (C[i] ^ (1<<j));
					}
				} 
			}
		  bool ok = true;
			/*
			printf("m:%d cnt:%d\n", m, cnt);
			for(int i =0; i<n;i++) 
				printf("%d ",C[i]);
			printf("\n");
			*/
			for(int i =0; i<n;i++) 
				if(!S.count(C[i])){
					ok=false;
					break;
				}
			if(!ok) continue;
			mi = min(mi,cnt);
		}	
		if(mi==100) printf("Case #%d: NOT POSSIBLE\n", caso);
		else printf("Case #%d: %d\n", caso, mi);
	}
	return 0;
}
