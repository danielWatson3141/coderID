#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
 
map<int,vector<int> > data;

bool comp(const int &a,const int &b){
	if (a>b) return true;
	else return false;
}

int bt(int f,int s){
	vector<int> num;
	int i=0;
	num.clear();
	if (f==0){
		if (data[s].size()<=1) return 1;
		else if (data[s].size()>=2){
			for (i=0;i<data[s].size();i++){
				if (data[s][i]!=f){
					num.push_back(bt(s,data[s][i]));
				}
			}
			sort(num.begin(),num.end(),comp);
			return num[0]+num[1]+1;
		} 
	}
	else{
		if (data[s].size()<=2) return 1;
		else if (data[s].size()>=3){
			for (i=0;i<data[s].size();i++){
				if (data[s][i]!=f){
					num.push_back(bt(s,data[s][i]));
				}
			}
			sort(num.begin(),num.end(),comp);
			return num[0]+num[1]+1;
		} 
	}
}

int main(){
	int flag;
	int T,ti,N,sum,temp,i,j,xi,yi;
	char str[100];FILE * inf, * outf;
	inf=fopen("B-small-attempt0.in.txt","r");
	outf=fopen("B-small.out","w");
	fscanf(inf,"%d",&T);
	for (ti=0;ti<T;ti++){
		fscanf(inf,"%d",&N);
		for (i=1;i<=N;i++){
			data[i].clear();
		}
		for (i=0;i<N-1;i++){
			fscanf(inf,"%d%d",&xi,&yi);
			data[xi].push_back(yi);
			data[yi].push_back(xi);
		}
		for (i=1,sum=0,temp=0;i<=N;i++){
			sum=bt(0,i);
			if (sum>temp) temp=sum;
		}
		fprintf(outf,"Case #%d: %d\n",ti+1,N-temp);
	}
	fclose(inf);
	fclose(outf);
	return 0;
}
