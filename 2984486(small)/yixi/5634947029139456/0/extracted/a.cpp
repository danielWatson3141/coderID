#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int TT,n,L,e[200];
string ss,a[200],b[200],c[200];


int main(){
	scanf("%d",&TT);
	for (int TTT=1; TTT<=TT; TTT++){
		printf("Case #%d: ",TTT);
		scanf("%d%d",&n,&L);
		for (int i=0; i<n; i++) {
			cin>>a[i];
		//	for (int j=0; j<L; j++) a[i][j]=ss[j]-'0';
		}
		for (int i=0; i<n; i++) {
			cin>>b[i];
			c[i]=b[i];
		//	for (int j=0; j<L; j++) b[i][j]=ss[j]-'0';
		}
		
		
		e[0]=1;
		for (int i=1; i<=L; i++) e[i]=e[i-1]*2;
		
		sort(a,a+n);
		//for (int i=0; i<n; i++) cout<<a[i]<<endl;
		
		int best=L+1;
		for (int s=0; s<e[L]; s++){
			int cnt=0;
			for (int i=0; i<L; i++) if (s&e[i]) cnt++;
			if (cnt>=best) continue;
		
			for (int i=0; i<n; i++) 
				for (int j=0; j<L; j++)
					c[i][j]=((b[i][j]-'0')^((s&e[j])?1:0))+'0';
			sort(c,c+n);
			//for (int i=0; i<n; i++) cout<<"c "<<c[i]<<endl;
			//cout<<"s "<<s<<endl;
			bool equal = true;
			for (int i=0; i<n; i++) {
				for (int j=0; j<L; j++)
					if (a[i][j]!=c[i][j]) {
						equal = false; break;
					}
				if (!equal) break;
			}
			if (!equal) continue;
			
			
			best = cnt;
		}
		
		if (best>L) printf("NOT POSSIBLE\n");
		else printf("%d\n",best);
		
	}
}