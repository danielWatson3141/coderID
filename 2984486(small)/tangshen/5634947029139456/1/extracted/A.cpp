#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
string A[200],B[200];
string C[200],D[200];
int main(){
	int T;
	cin >> T;
	int Len[200];
	int idx = 0;
	while(T--){
		++idx;
		int N,L;cin >> N>>L;
		for(int i=0;i<N;++i)
			cin >> A[i];
		for(int i=0;i<N;++i)
			cin >> B[i];
		bool isCor = true;
		for(int i=0;i<L;++i){
			int ca = 0,cb=0;
			for(int j=0;j<N;++j){
				if(A[j][i]=='0')++ca;
				if(B[j][i]=='0')++cb;
			}
			ca = max(ca,N-ca);
			cb = max(cb,N-cb);
			if(ca!=cb){
				isCor=false;
				break;
			}
		}
		int ans = L+10;
		if(isCor){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				C[j]=A[j];
				D[j]=B[j];
			}
			string str=C[0];
			C[0]=C[i];
			C[i]=str;
			int tans = 0;
			for(int j=0;j<L;++j){
				if(C[0][j]==D[0][j])continue;
				++tans;
				for(int k=0;k<N;++k)
					C[k][j] = '1'-C[k][j]+'0';
			}
			sort(C,C+N);
			sort(D,D+N);

			bool allsame = true;
			for(int j=0;j<N&&allsame;++j){
				if(C[j]!=D[j])
					allsame = false;
			}
			if(allsame && tans < ans){
				ans = tans;
			}
		}
		}
		if(ans>L){
			cout << "case #"<<idx<<": NOT POSSIBLE"<<endl;
		}else{
			cout << "case #"<<idx<<": "<<ans<<endl;
		}
	}
	return 0;
}
