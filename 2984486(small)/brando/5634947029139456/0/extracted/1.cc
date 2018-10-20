#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int count(int x){//计算1个数
	int cnt=0;
	while(x>0){
		int y=x-1;
		x=(y&x);
		cnt++;
	}
	return cnt;
}
bool cmp(vector<int> &a,vector<int>&b){
	if(a.size()!=b.size()) return false;
	rep(i,a.size()){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
int toInt(char *c){
	int t=0;
	for(int i=0;c[i]!=0;i++){
		t*=2;
		if(c[i]=='1') t+=1;
	}
	return t;
}
int main(){
	int cases;cin>>cases;	
	for(int caseI=1;caseI<=cases;caseI++){
		int N,L;
		vector<int> from;vector<int> to;
		cin>>N>>L;char c[100];
		rep(i,N) {cin>>c;from.push_back(toInt(c));}
		rep(i,N) {cin>>c;to.push_back(toInt(c));}
		sort(to.begin(),to.end());
		int least=999;
		for(int i=0;i<(2<<L);i++){
			vector<int> temp(from);
			rep(j,N){
				temp[j]=(temp[j]^i);	
			}
			sort(temp.begin(),temp.end());
			// if(i==1) {
				// rep(j,N) cout<<temp[j]<<" ";
				// cout<<endl;
				// rep(j,N) cout<<to[j]<<" ";
				// cout<<endl;
			// }
			if(cmp(temp,to)) least=std::min(least,count(i));
		}
		printf("Case #%d: ",caseI);
		if(least==999){
			printf("NOT POSSIBLE\n");
		}
		else printf("%d\n",least);
	}
	return 0;
}

