#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int chk_equ(char a[10][15],char b[10][15],int N,int L) {
	int i,j,k,flag;
	int arr[N];
	for(i=0;i<N;i++)
		arr[i]=0;
	for(i=0;i<N;i++) {
		//printf(" temp=%s ",a[i]);
		flag=0;
		for(j=0;j<N;j++) {
			if(strcmp(a[i],b[j])==0) {
				//printf(" res=%s ",b[i]);
				flag=1;
				//printf("Equal");
				break;
			}
		}
		//printf("\n");
		if(flag==0)
			return 0;
	}
	return 1;
}
void change_bit(char a[10][15],int p,int N,int len) {
	int i,j,k=0;
	while(p) {
		if(p&1) {
			for(j=0;j<N;j++) {
				if(a[j][k]=='1')
					a[j][k]='0';
				else
					a[j][k]='1';
			}
		}
		k++;
		p=p>>1;
	}
}
int cnt_bit(int x) {
	int i=0;
	while(x) {
		if(x&1==1)
			i++;
		x=x>>1;
	}
	return i;
}
int main() {
	int T,N,L,i,j,k,l_cnt=100000,cnt;
	char combi[10][15],res[10][15],temp[10][15];
	scanf("%d",&T);
	for(i=1;i<=T;i++) {
		scanf("%d%d",&N,&L);
		l_cnt=100000;
		for(j=0;j<N;j++) {
			scanf("%s",combi[j]);
			strcpy(temp[j],combi[j]);
		}
		/*for(k=0;k<N;k++)
				printf("%c %c %c\n",temp[0][k],temp[1][k],temp[2][k]);
		printf("\n//////");*/
		for(j=0;j<N;j++)
			cin>>res[j];
		for(k=0;k<N;k++)
			strcpy(temp[k],combi[k]);
		//start combination
		for(j=1;j<pow(2,L);j++) {
			//copy
			if(chk_equ(temp,res,N,L)) {
				cnt=cnt_bit(j-1);
				//printf("\ncnt=%d %d\n",cnt,j);
				if(l_cnt>cnt)
					l_cnt=cnt;
			}
			for(k=0;k<N;k++)
				strcpy(temp[k],combi[k]);
			//printf("befre\n");
			//for(k=0;k<L;k++)
				//printf("%c %c %c\n",temp[0][k],temp[1][k],temp[2][k]);
			//change the bit
			change_bit(temp,j,N,L);
			//printf("Change bit\n");
			//for(k=0;k<L;k++)
				//printf("%c %c %c\n",temp[0][k],temp[1][k],temp[2][k]);
		}
		if(l_cnt==100000)
			printf("Case #%d: NOT POSSIBLE\n",i);
		else
			printf("Case #%d: %d\n",i,l_cnt);
	}
	return 0;
}
