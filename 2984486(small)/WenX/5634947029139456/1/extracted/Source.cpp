#pragma warning(disable:4996)
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstring>
#include <map>
using namespace std;

long long set[2][200];
long long t_set[200];
int num[2][200];//num of 1s in the bits.
char buf[250];
int n,l;

void input(int i, int set_i){
	long long res=0;
	for(int j=0;j<l;j++){
		res*=2;
		if(buf[j]=='1')
			res++;
	}
	set[set_i][i]=res;
}

void calc_num(){
	memset(num,0,sizeof(num));
	for(int set_i=0;set_i<2;set_i++)
		for(int i=0;i<n;i++)
			for(long long j=0;j<l;j++)
				if(set[set_i][i] & (1<<j))
					num[set_i][j]++;
			
}
/*
int final_step;
int ans[200],step;
void search(int lv){
	if(lv==l){
		//finished..check..
		int xor_num=0,yes=1;
		for(long long i=0;i<l;i++)
			if(ans[i])
				xor_num=xor_num+(1<<i);
		for(int i=0;i<n;i++)
			t_set[i]=set[0][i]^xor_num;
		sort(t_set,t_set+n);
		for(int i=0;i<n;i++)
			if(t_set[i]!=set[1][i])
				yes=0;
		if(yes)
			if(final_step==-1 || step<final_step)
				final_step=step;
		return;
	}
	if(num[0][lv]==num[1][lv]){
		ans[lv]=0;
		search(lv+1);
	}
	if(num[0][lv]==(n-num[1][lv])){
		ans[lv]=1;
		step++;
		search(lv+1);
		step--;
	}
}*/

int main(){
	int tt;
	scanf("%d",&tt);
	for(int cc=1;cc<=tt;cc++){
		scanf("%d%d",&n,&l);
		for(int set_i=0;set_i<2;set_i++)
		for(int i=0;i<n;i++){
			scanf("%s",buf);
			input(i,set_i);
		}

		sort(set[1],set[1]+n);
		//calc_num();

		int final_step=-1;
		for(int j=0;j<n;j++){
			unsigned long long xor_num=set[0][0]^set[1][j];
			int yes=1,step=0;
			for(int i=0;i<n;i++)
				t_set[i]=set[0][i]^xor_num;
			sort(t_set,t_set+n);
			for(int i=0;i<n;i++)
				if(t_set[i]!=set[1][i])
					yes=0;
			for(unsigned int i=0;i<l;i++)
				if((xor_num>>i) & 1)
					step++;
			if(yes)
				if(final_step==-1 || step<final_step)
					final_step=step;
		}

		printf("Case #%d: ",cc);
		if(final_step==-1)
			printf("NOT POSSIBLE");
		else
			printf("%d",final_step);
		printf("\n");
	}
	return 0;
}