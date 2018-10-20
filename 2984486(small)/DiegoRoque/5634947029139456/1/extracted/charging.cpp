#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string outlet[200],answer[200];
string objeto[200],aux;
int stringXor(string& A,string& B,string& C,int& L){
	int cuenta=0;
	for(int i=0;i<L;i++){
		if((A[i]=='1' and B[i]=='0') or (A[i]=='0' and B[i]=='1') ){
			C[i]='1';
			cuenta++;
		}
		else{
			C[i]='0';
		}
	}
	return cuenta;
}	

int main(){
	int T,N,L,mej,t=0,ans;
	cin >> T;
	while(T--){
		t++;
		printf("Case #%d: ",t);
		cin >> N >> L;
		cin >> outlet[0];
		mej=2*L;
		for(int i=1;i<N;i++){
			cin >> outlet[i];
			stringXor(outlet[0],outlet[i],outlet[i],L);
		}
		aux=outlet[0];
		sort(outlet+1,outlet+N);
		for(int i=0;i<N;i++){
			cin >> objeto[i];
			answer[i]=objeto[i];
		}
		for(int i=0;i<N;i++){
			/*el i-esimo objeto va en el primer outlet*/
			ans=stringXor(outlet[0],objeto[i],aux,L);
			for(int j=0,k=1;j<N;j++,k++){
				if(j==i) {k--;continue;}
				stringXor(objeto[i],objeto[j],answer[k],L);
			}
			sort(answer+1,answer+N);
			bool checa=true;
			for(int j=1;j<N and checa;j++) checa = checa && (answer[j]==outlet[j]);
			if(checa and ans<mej){
				mej=ans;
			}
		}
		if(mej>L){
			printf("NOT POSSIBLE\n");
		}
		else{
			printf("%d\n",mej);
		}
	}
}
