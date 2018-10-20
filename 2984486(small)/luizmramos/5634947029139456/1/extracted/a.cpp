#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n,l;
string outlet[200];
string device[200];

bool isequal(string* a, string* b){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])return false;
	}
	return true;
}

int main(){
	int t;
	scanf("%d\n",&t);
	for(int xxx=0;xxx<t;xxx++){
		scanf("%d %d\n",&n,&l);
		for(int i=0;i<n;i++){
			cin>>outlet[i];
		}
		for(int i=0;i<n;i++){
			cin>>device[i];
		}
		string aux[200];
		int minflip=1000;
		sort(device,device+n);
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				aux[k]=outlet[k];
			}
			int flip=0;
			for(int j=0;j<l;j++){
				if(device[0][j]!=aux[i][j]){
					flip++;
					for(int z=0;z<n;z++){
						aux[z][j]=aux[z][j]=='0'?'1':'0';
					}
				}
			}
			sort(aux,aux+n);
			if(isequal(aux,device)){
				if(flip<minflip)minflip=flip;	
			}
			
		}
		printf("Case #%d: ",xxx+1);
		if(minflip==1000){
			printf("NOT POSSIBLE\n");
		}else{
			printf("%d\n",minflip);
		}
	}
}