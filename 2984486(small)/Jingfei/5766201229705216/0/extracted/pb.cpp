#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int ar[1010][1010];
int Ans;
int Trace(int,int,int);

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		memset(ar,0,sizeof(ar));
		scanf("%d",&N);
		for(int i=1; i<N; ++i){
			int X,Y; scanf("%d%d",&X,&Y);
			ar[X][++ar[X][0]]=Y; 
			ar[Y][++ar[Y][0]]=X;
		}
		Ans=N-1;
		for(int i=1; i<=N; ++i){
			int tmp=N-1;
			if(ar[i][0]==2)
				tmp=Trace(i,0,0);
			else if(ar[i][0]>2)
				tmp=Trace(i,0,-1);
//			printf("%d: %d\n",i,tmp);
			if(tmp<Ans) Ans=tmp;
		}
		printf("Case #%d: %d\n",Case,Ans);
	}
	return 0;
}

int Trace(int x, int No, int Add){
	int Num=0;
	int X[1010],Y[1010][2],xn=0;
	for(int i=1; i<=ar[x][0]; ++i){
		int I=ar[x][i];
		if(I==No) continue;
		if(Add==-1){
			Y[xn][0]=Trace(I,x,1);
			Y[xn][1]=Trace(I,x,0);
			X[xn++]=Y[xn][0]-Y[xn][1];
			continue;
		}
		else if(Add==1){
			++Num;
			if(ar[I][0]!=1) Num+=Trace(I,x,1);
			continue;
		}
		if(ar[I][0]==1) continue;
		if(ar[I][0]==3) Num+=Trace(I,x,0);
		else if(ar[I][0]==2) Num+=Trace(I,x,1);
		else Num+=Trace(I,x,-1);
	}
	if(Add==-1){
		sort(X,X+xn);
		for(int i=0; i<xn-2; ++i) Num+=Y[i][0];
		Num+=Y[xn-1][1]; Num+=Y[xn-2][1];
	}
//	printf(" %d: %d\n",x,Num);
	return Num;
}

