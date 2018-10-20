#include <cstdio>

int T,N,L;
int chflg[48];
char ol[152][48];
char ef[152][48];
void rev(int dig) {
	chflg[dig]=1-chflg[dig];
	for(int i=0;i<N;i++) {
		if(ol[i][dig]=='0') {
			ol[i][dig]='1';
		} else {
			ol[i][dig]='0';
		}
	}
}
int iseq(int i,int j) {
	for(int k=0;k<L;k++) {
		if(ol[i][k]!=ef[j][k]) return 0;
	}
	return 1;
}
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%d%d",&N,&L);
		for(int i=0;i<N;i++) scanf("%s",ol[i]);
		for(int i=0;i<N;i++) scanf("%s",ef[i]);
		for(int i=0;i<L;i++) chflg[i]=0;
		int minv=L+1;
		for(int st=0;st<N;st++) {
			int kmin=0;
			for(int i=0;i<L;i++) if(ol[0][i]!=ef[st][i]) {
				rev(i);
				kmin++;
			}
			for(int i=0;i<N;i++) {
				int flg=1;
				for(int j=0;j<N;j++) if(iseq(i,j)) flg=0;
				if(flg) kmin=minv;
			}
			for(int i=0;i<L;i++) if(chflg[i]) rev(i);
			if(kmin<minv) minv=kmin;
		}
		if(minv>L) {
			printf("Case #%d: NOT POSSIBLE\n",ts);
		} else {
			printf("Case #%d: %d\n",ts,minv);
		}
	}
	return 0;
}
