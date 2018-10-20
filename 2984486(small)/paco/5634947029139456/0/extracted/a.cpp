#include<iostream>
#include<cstdlib>

using namespace std;

int num_ones(unsigned long long n) {
	int q=0;
	for(int i=0;i<8*sizeof(unsigned long long);i++) {
		q+=(n&1);
		n=n>>1;
	}
	return q;
}


int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=0; n<nCases; n++) {
		cout<<"Case #"<<n+1<<": ";
		int L,N;
		cin>>N;cin>>L;
		unsigned long long outlets[N];
		unsigned long long devices[N];
		for(int i=0;i<N;i++) {
			std::string str;
			cin>>str;
			outlets[i]=strtoull(str.c_str(),NULL,2);
		}
		for(int i=0;i<N;i++) {
			std::string str;
			cin>>str;
			devices[i]=strtoull(str.c_str(),NULL,2);
		}
		unsigned long long m[N][N];
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				m[i][j]=outlets[i]^devices[j];
			}
		}
		if(N==1) {
			cout<<num_ones(m[0][0])<<endl;
			continue;
		}
		int q[N];
		int changes=-1;
		bool found;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) q[j]=0;
			q[i]=1;
			for(int j=1;j<N;j++) {
				found = false;
				for(int k=0;k<N;k++) {
					if(q[k]==1) continue;
					if(m[j][k]==m[0][i]) {
						found=true;
						q[k]=1;
						break;
					}
				}
				if(!found) break;
			}
			if(found) {
				if(changes==-1) changes=num_ones(m[0][i]);
				else {
					if(num_ones(m[0][i])<changes) 
						changes=num_ones(m[0][i]);
				}
			}
		}
		if(changes==-1) 
			cout<<"NOT POSSIBLE"<<endl;
		else
			cout<<changes<<endl;
		
	}
	
	return 0;
	
}
