#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

long long stn(char * str){
	int i=0;
	long long temp=0;
	while (str[i]!='\0'){
		temp=temp<<1;
		if (str[i]=='1') temp++;
		if (str[i]=='0') temp+=0;
		i++;
	}
	return temp;
}

int ct(long long a){
	int co=0;
	while (a!=0){
		if (a%2==1) co++;
		a=a>>1;
	}
	return co;
}
 
int main(){
	map<long long, long long> data;
	vector<long long> cow;
	long long temp,t0;
	int flag;
	int T,ti,ni,N,L,pa,i,j;
	char str[100];FILE * inf, * outf;
	inf=fopen("A-large.in.txt","r");
	outf=fopen("A-large.out","w");
	fscanf(inf,"%d",&T);
	for (ti=0;ti<T;ti++){
		data.clear();
		cow.clear();
		flag=-1;
		fscanf(inf,"%d%d",&N,&L);
		for (i=0;i<N;i++){
			fscanf(inf,"%s",str);
			t0=temp=stn(str);
			data[temp]=0;
		}
		for (i=0;i<N;i++){
			fscanf(inf,"%s",str);
			temp=stn(str);
			cow.push_back(temp);
		}
		for (i=0;i<N;i++){
			ni=0;
			pa=t0^cow[i];
			for (j=0;j<N;j++){
				if (data.find(pa^cow[j])!=data.end()){
					if (data[pa^cow[j]]==0){
						data[pa^cow[j]]=1;
						ni++;
					}
					else break;
				}
				else break;
			}
			for (j=0;j<N;j++){
				if (data.find(pa^cow[j])!=data.end()){
					data[pa^cow[j]]=0;
				}
				else break;
			}
			if (ni==N) 
				if (flag==-1||ct(pa)<flag)
					flag=ct(pa);
			if (flag==0) break;
		}
		if (flag!=-1)
			fprintf(outf,"Case #%d: %d\n",ti+1,flag);
		else 
			fprintf(outf,"Case #%d: NOT POSSIBLE\n",ti+1);
	}
	fclose(inf);
	fclose(outf);
	return 0;
}
