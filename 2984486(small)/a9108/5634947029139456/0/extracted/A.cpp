#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
#include <fstream>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

int n,m;
string a[1000];
string b[1000],c[1000];

int main(int argc,char** argv){
	int T;
	cin>>T;
	for (int r=1;r<=T;r++){
		printf("Case #%d: ",r);
		cin>>n>>m;
		for (int i=0;i<n;i++) cin>>a[i];
		for (int i=0;i<n;i++) cin>>b[i];
		sort(b,b+n);
		int res=100000;
		for (int i=0;i<n;i++){
			int cnt=0;
			for (int j=0;j<n;j++) c[j]=a[j];
			for (int l=0;l<m;l++)
				if (a[0][l]!=b[i][l]){
					cnt++;
					for (int z=0;z<n;z++){
						if (c[z][l]=='1') c[z][l]='0';
						else c[z][l]='1';
					}
				}
			sort(c,c+n);
			bool f=true;
			for (int i=0;i<n;i++) if (c[i]!=b[i]) f=false;
			if (!f) continue;
			res=min(res,cnt); 
		}
		if (res==100000) printf("NOT POSSIBLE\n");
		else printf("%d\n",res);
	}
	
	return 0;
}