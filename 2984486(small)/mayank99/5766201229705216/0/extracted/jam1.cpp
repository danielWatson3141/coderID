#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<fstream>
#include<math.h>
using namespace std;
int res[1010][1010]={0};
vector<int> con[1010];
int n;
int sol(int l,int j) {
	if(res[l][j]!=0) {
		return res[l][j];
	} else {
		res[l][j]=1;
		if(con[l].size()==1) {
			res[l][j]=1;
		} else if(con[l].size()>=3) {
			int mans =1;
			for(int q=0;q<con[l].size();q++) {
				if(con[l][q]!=j) {
					for(int w=q+1;w<con[l].size();w++) {
						if(con[l][w]!=j) {
							mans= max(mans,1+sol(con[l][q],l)+sol(con[l][w],l));
						}
					}
				}
			}
			res[l][j]=mans;
		}	
		return res[l][j];
	}
}
int main() {
	fstream f;
	fstream x;
	f.open("B-small-attempt1.in",ios::in);
	x.open("output.txt",ios::out);
	int t;
	f>>t;
	for(int i=1;i<=t;i++) {
//		int n;
		f>>n;
		int a,b;
//		vector<int> con[n+1];
		for(int j=1;j<=n;j++) {
			con[j].clear();
			for(int k=1;k<=n;k++) {
				res[j][k]=0;
			}
		}
		for(int j=0;j<n-1;j++) {
			f>>a>>b;
			con[a].push_back(b);
			con[b].push_back(a);
		}
		int mans=1;
		for(int j=1;j<=n;j++) {
			int len = 1;
			int sz = con[j].size();
			if(sz==0) {
				mans= max(mans,1);		
			} else if(sz>=2) {
				for(int k=0;k<con[j].size();k++) {
						for(int l=k+1;l<con[j].size();l++) {
									mans=max(mans,sol(con[j][k],j)+sol(con[j][l],j)+1);
						}	
				}
			}
		}
		mans= n-mans;
		x<<"Case #"<<i<<": "<<mans<<"\n";
	}
	f.close();
	x.close();
	return 0;
}
