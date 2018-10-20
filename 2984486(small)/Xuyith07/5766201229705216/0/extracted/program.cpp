#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<stdint.h>
//#include<map>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

/*
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("test.txt");
	out.open("out.txt");
	in>>CaseNum;
	for(int Case=0;Case<CaseNum;Case++){



	out<<"Case #"<<Case+1<<":";
	}
	return 0;
}
*/

int map[1003][1003];
int edg[1003][1003];
int edgN[1003];

int sum_t(int id){
	int t=0;
	for(int i=0;i<edgN[id];i++){
		if(map[id][edg[id][i]]){
			map[id][edg[id][i]]=0;
			map[edg[id][i]][id]=0;
			t+=sum_t(edg[id][i]);
			map[id][edg[id][i]]=1;
			map[edg[id][i]][id]=1;
		}
	}
	return t+1;
}
int full_t(int id){
	int t=0;
	int n=0;
	for(int i=0;i<edgN[id];i++){
		if(map[id][edg[id][i]]){
			n++;
		}
	}
	if(n==2){
		for(int i=0;i<edgN[id];i++){
		if(map[id][edg[id][i]]){
			map[id][edg[id][i]]=0;
			map[edg[id][i]][id]=0;
			t+=full_t(edg[id][i]);
			map[id][edg[id][i]]=1;
			map[edg[id][i]][id]=1;
		}
		}
		return t;
	}
	if(n==1){
		for(int i=0;i<edgN[id];i++){
		if(map[id][edg[id][i]]){
			map[id][edg[id][i]]=0;
			map[edg[id][i]][id]=0;
			t+=sum_t(edg[id][i]);
			map[id][edg[id][i]]=1;
			map[edg[id][i]][id]=1;
		}
		}
		return t;
	}
	return 0;
}

int frk(int id){
	int t=0,s;
	int n=0;
	int b[2]={0};
	b[0]=0;
	b[1]=0;
	for(int i=0;i<edgN[id];i++){
		if(map[id][edg[id][i]]){
			n++;
		}
	}
	if(n<2)return 1;
		for(int i=0;i<edgN[id];i++){
		if(map[id][edg[id][i]]){
			map[id][edg[id][i]]=0;
			map[edg[id][i]][id]=0;
			s=frk(edg[id][i]);
			if(b[0]<s){b[1]=b[0];b[0]=s;}
			else if(b[1]<s)b[1]=s;

			map[id][edg[id][i]]=1;
			map[edg[id][i]][id]=1;
		}
		}
	return b[0]+b[1]+1;
}

int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	//in.open("test.txt");
	in.open("B-small-attempt2.in");
	out.open("out2.txt");
	in>>CaseNum;
	int N,ans;
	for(int Case=0;Case<CaseNum;Case++){
		if(Case==78)
			Case=Case;
		in>>N;
		cout<<"**************"<<endl;
		cout<<N<<endl;
		int fro,to;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				map[i][j]=0;
			}
		for(int i=0;i<N;i++){
			edgN[i]=0;
		}
		for(int i=0;i<N-1;i++){
			in>>fro>>to;
			cout<<fro<<" "<<to<<endl;
			fro--;
			to--;
			map[fro][to]=1;
			map[to][fro]=1;
			edg[fro][edgN[fro]]=to;
			edg[to][edgN[to]]=fro;
			edgN[fro]++;
			edgN[to]++;
		}
		cout<<"!!!!!!!!!!!!!!!!"<<endl;
		ans=5000;
		int cans,cans1;
		for(int root=0;root<N;root++){
			//if(edgN[root]>2)continue;
			cans=full_t(root);
			cans1=N-frk(root);
			cout<<root+1<<" "<<cans<<" "<<cans1<<endl;
			ans=MIN(ans,cans1);
		}



	out<<"Case #"<<Case+1<<": "<<ans<<endl;
	}
	return 0;
}