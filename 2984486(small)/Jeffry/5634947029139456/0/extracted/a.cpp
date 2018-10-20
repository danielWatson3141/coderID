#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

bool debug=false;

char init[150][40];
char dest[150][40];
char temp[150][40];

int b2i(const char* str, int len){
	int ret=0;
	for(int i=0;i<len;i++){
		if(*(str+i)=='1'){
			ret += 1<<(len-1-i);
		}
	}
	return ret;
}

bool check(map<int,bool>& mapDest,int N,int L){
	for(int i=0;i<N;i++){
		int t = b2i(temp[i],L);
		if(mapDest[t]==false)
			return false;
	}
	return true;
}

int count1(int value){
	int ret=0;
	while(value>0){
		if(value%2==1)
			ret++;
		value = value/2;
	}
	return ret;
}

void solve(int c)
{
	int N,L;
	cin>>N>>L;
	if(debug)cout<<"N,L= "<<N<<","<<L<<endl;
	map<int,bool> mapDest;

	memset(init,0,sizeof(init));
	memset(dest,0,sizeof(dest));
	memset(temp,0,sizeof(temp));

	for(int i=0;i<N;i++){
		cin>>init[i];
		if(debug)cout<<init[i]<<" ";
	}
	if(debug)cout<<endl;
	memcpy(temp,init,sizeof(init));

	for(int i=0;i<N;i++){
		cin>>dest[i];
		int t=b2i(dest[i],L);
		mapDest[t]=true;
		if(debug)cout<<dest[i]<<"("<<t<<") ";
	}
	if(debug)cout<<endl;

	int maxTry=1<<L;
	if(debug)cout<<"maxTry="<<maxTry<<endl;
	int idx=0;
	vector<int> ans;
	while(idx<maxTry){
		if(check(mapDest,N,L)){
			ans.push_back(idx);
			if(debug)cout<<"!!found an answer."<<idx<<endl;
		}
		idx++;

		memcpy(temp,init,sizeof(init));
		
		if(debug)cout<<"idx="<<idx<<endl;
		for(int j=0;j<N;j++){
			for(int i=0;i<L;i++){
				if(debug)cout<<"idx&(1<<i)"<<(idx&(1<<i))<<endl;
				if((idx&(1<<i))>0){
					if(debug)cout<<"["<<j<<"]before "<<temp[j]<<endl;
					temp[j][i]=(temp[j][i]=='1'?'0':'1');
					if(debug)cout<<"["<<j<<"]after "<<temp[j]<<endl;
				}
			}
		}
	}
	
	if(ans.size()==0)
		cout<<"Case #"<<c<<": NOT POSSIBLE"<<endl;
	else{
		int minF=L;
		for(int i=0;i<ans.size();i++){
			minF=min(minF,count1(ans[i]));
		}
		cout<<"Case #"<<c<<": "<<minF<<endl;
	}
}

int main(int argc, char** args)
{
	if(argc>1&&args[1][0]=='d'){
		debug=true;
	}
	int T;
	cin>>T;
	int c=0;
	while((++c)<=T){
		solve(c);
	}
}

