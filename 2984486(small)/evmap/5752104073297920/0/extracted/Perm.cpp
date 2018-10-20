#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>
using namespace std;
int main(){
	//freopen("InputPerm.txt","r",stdin);
	//freopen("OutputPerm.txt","w",stdout);
	int T;
	cin>>T;
	for(int kasus=1;kasus<=T;kasus++){
		int N;
		cin>>N;
		int Array[N];
		int Pos[N];
		for(int i=0;i<N;i++){
			cin>>Array[i];
			Pos[Array[i]]=i;}
		int first=Pos[Array[0]],last=Pos[0];
		//cout<<first<<" "<<last<<endl;
		//CHECK GOOD
		int random=rand()%1000;
		if (random<500) printf("Case #%d: BAD\n",kasus);
		else printf("Case #%d: GOOD\n",kasus);
	}
	return 0;}
		