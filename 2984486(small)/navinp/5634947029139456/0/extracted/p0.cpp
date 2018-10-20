#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int MAX=11,INF=(1<<30);
vector<string> v,f,tmp;

int main()
{
	int T,tc=1;
	cin >> T;
	while(T--){
		int N,L;
		cin >> N >> L;
		int i,j,k;
		v.clear();
		f.clear();
		string s;
		for(i=0;i<N;i++) {
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(),v.end());
		for(i=0;i<N;i++) {
			cin >> s;
			f.push_back(s);
		}
		
		sort(f.begin(),f.end());
		int ans=INF;
		tmp.clear();
		for(i=0;i<(1<<L);i++){
			tmp=v;
			for(k=0;k<tmp.size();k++){
			   for(j=0;j<L;j++){
				if(i&(1<<j)){
				if(tmp[k][j]=='1') tmp[k][j]='0';
				else tmp[k][j]='1';
					}
				}
						}
			sort(tmp.begin(),tmp.end());
			if(tmp==f){
				ans=min(ans,__builtin_popcount(i));
			}
		}



		if(ans<INF)
		printf("Case #%d: %d\n",tc++,ans);
		else printf("Case #%d: NOT POSSIBLE\n",tc++);
	}
	
	return 0;
}
