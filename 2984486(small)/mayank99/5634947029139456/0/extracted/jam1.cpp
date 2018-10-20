#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<fstream>
#include<math.h>
using namespace std;
int main() {
	fstream f;
	fstream x;
	f.open("A-small-attempt1.in",ios::in);
	x.open("output.txt",ios::out);
	int t;
	f>>t;
	for(int i=1;i<=t;i++) {
		int n;
		int l;
		f>>n>>l;
		string a[n];
		string b[n];
		for(int j=0;j<n;j++) {
			f>>a[j];
		//	cout<<a[j]<<"\n";
		}
		for(int j=0;j<n;j++) {
			f>>b[j];
		//	cout<<b[j]<<"\n";
		}
		int zc[l];
		int zb[l];
		for(int j=0;j<l;j++) {
			zc[j]=0;
			zb[j]=0;
		}
		vector<int> bl;
		vector<int> al;
		for(int j=0;j<n;j++) {
			int tmp=0;
			int tmpa=0;
			for(int k=0;k<l;k++) {
					tmpa*=2;
					if(a[j][k]=='0') {
						zc[k]++;
						tmpa+=0;
					} else {
						tmpa+=1;
					}
					tmp*=2;
					if(b[j][k]=='0') {
						zb[k]++;
						tmp+=0;
					} else {
						tmp+=1;
					}
			}
			bl.push_back(tmp);
			al.push_back(tmpa);
		}
		int conf =0;
		for(int j=0;j<l;j++) {
			if((zc[j]!=zb[j])&&(zc[j]+zb[j]!=n)) {
				conf=1;
			}
		}
		//cout<<"conf"<<conf<<"\n";
		if(conf==1) {
			x<<"Case #"<<i<<": NOT POSSIBLE"<<"\n";
		} else {
		    sort(bl.begin(),bl.end());
			sort(al.begin(),al.end());
			int cc=0;
			for(int j=0;j<n;j++) {
				if(al[j]==bl[j]) {
					cc++;
				}
			}
			if(cc==n) {
					x<<"Case #"<<i<<": 0"<<"\n";		
			} else {
				int mans=l+1;
				int rang = pow(2,l);
			//	cout<<"rang"<<rang<<"\n";
				for(int k=0;k<rang;k++) {
						vector<int> tm;
				
						for(int j=0;j<n;j++) {
							tm.push_back(al[j]^k);
						}
						sort(tm.begin(),tm.end());
						int cc=0;
						for(int j=0;j<n;j++) {
							if(tm[j]==bl[j]) {
								cc++;
							} else{ cc=n+1; }
						}
			//			cout<<"k"<<k<<"cc"<<cc<<"\n";
						if(cc==n) {
							cc=k;	
						    int yy=0;
							 while(cc!=0) {
								if(cc%2!=0) {
									yy++;
								}
								cc/=2;
							} 
							mans=min(mans,yy);
						}
				}
				if(mans==l+1) {
				 	x<<"Case #"<<i<<": NOT POSSIBLE"<<"\n";
				} else {
					x<<"Case #"<<i<<": "<<mans<<"\n";
				}
		
			}

		}
	}
	f.close();
	x.close();
	return 0;
}
