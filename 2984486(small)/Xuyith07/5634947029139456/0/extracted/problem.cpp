#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<stdint.h>
#include<map>
using namespace std;

#define MAX(a,b),((a)>(b)?(a):(b))
#define MIN(a,b),((a)<(b)?(a):(b))

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
map<uint64_t,int> hashmap;

int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	//in.open("test.txt");
	in.open("A-small-attempt0.in");
	out.open("out.txt");
	in>>CaseNum;

	int N,L;
	int fro[160];
	int to[160];
	int ans[160],n;
	map<uint64_t,int>::iterator it;

	for(int Case=0;Case<CaseNum;Case++){
	hashmap.clear();
	n=0;

	in>>N>>L;
	int t;
	string s;
	uint64_t tt;
	for(int i=0;i<N;i++){
		fro[i]=0;
		in>>s;
		for(int j=0;j<L;j++){
			t=(s[j]=='1');
			fro[i]<<=1;
			fro[i]|=t;
		}
	}
	for(int i=0;i<N;i++){
		to[i]=0;
		in>>s;
		for(int j=0;j<L;j++){
			t=(s[j]=='1');
			to[i]<<=1;
			to[i]|=t;
		}
	}

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			tt=fro[i]^to[j];
			it=hashmap.find(tt);
			if(it==hashmap.end()){
				hashmap.insert(pair<uint64_t,int>(tt,1));
				if(N==1){
					ans[n]=0;
					while(tt>0){
					ans[n]+=tt&1;
					tt>>=1;
					}
					n++;
				}
			}
			else{
				it->second++;
				if(it->second==N){
					tt=it->first;
					ans[n]=0;
					while(tt>0){
					ans[n]+=tt&1;
					tt>>=1;
					}
					n++;
				}
			}

		}
	if(n>0){
	sort(ans,ans+n);
	}
	
	out<<"Case #"<<Case+1<<": ";
	if(n==0)out<<"NOT POSSIBLE"<<endl;
	else out<<ans[0]<<endl;
	}
	return 0;
}