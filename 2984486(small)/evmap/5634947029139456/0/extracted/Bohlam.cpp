#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
int main(){
	//freopen("InputBohlam.txt","r",stdin);
	//freopen("OutputBohlam.txt","w",stdout);
	int T;
	cin>>T;
	for(int kasus=1;kasus<=T;kasus++){
		int N,L;
		cin>>N>>L;
		string Initial[N];
		string Final[N];
		int InitOne[N],FinalOne[N];
		for(int i=0;i<N;i++){
			cin>>Initial[i];
			InitOne[i]=0;
			for(int j=0;j<L;j++){
				if (Initial[i][j]=='1') InitOne[i]++;
			}
		}
		for(int i=0;i<N;i++){
			cin>>Final[i];
			FinalOne[i]=0;
			for(int j=0;j<L;j++){
				if (Final[i][j]=='1') FinalOne[i]++;
			}
		}
		bool found=false;
		int numswitch=1000;
		for(int i=0;i<N;i++){
			string Temp[N];
			for(int k=0;k<N;k++) Temp[k]=Initial[k];
			//printf("Temp[%d] : %s\n",i,Temp[i].c_str());
			int tempswitch=0;
			for(int j=0;j<L;j++){
				if (Temp[i][j]!=Final[0][j]){
					tempswitch++;
					for(int k=0;k<N;k++){
						if (Temp[k][j]=='1') Temp[k][j]='0';
						else if (Temp[k][j]=='0') Temp[k][j]='1';
					}
				}
			}
			//cout<<"AFTER"<<endl;
			//for(int k=0;k<N;k++) printf("Temp[%d] : %s\n",k,Temp[k].c_str());
			int count=0;
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if (Temp[i]==Final[j]){
						count++;
						break;}
				}
			}
			//cout<<"count : "<<count<<endl;
			if (count==N){
				found=true;
				if (tempswitch<numswitch) numswitch=tempswitch;
			}
		}
		if (found){
			printf("Case #%d: %d\n",kasus,numswitch);}
		else{
			printf("Case #%d: NOT POSSIBLE\n",kasus,numswitch);}
	}
	return 0;}