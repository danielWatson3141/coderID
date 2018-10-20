#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string reqs[200];
string strs[200];

string tmp[200];
int L;
int N;

bool check(int state){
	for(int i=0;i<N;i++){
		tmp[i]=strs[i];
		for(int j=0;j<L;j++){
			if((state>>j)&1){
				if(tmp[i][j]=='0') tmp[i][j]='1';
				else tmp[i][j]='0';
			}
		}
	}
	sort(tmp,tmp+N);
	for(int i=0;i<N;i++){
		if(reqs[i]!=tmp[i]) return false;
	}
	return true;
}

int main(){
	int T;
	cin>>T;
	for(int datano=0;datano<T;datano++){
		cin>>N>>L;
		for(int i=0;i<N;i++) cin>>strs[i];
		for(int i=0;i<N;i++) cin>>reqs[i];
		sort(reqs,reqs+N);
		int ans=-1;
		for(int stat=0;stat<(1<<L);stat++){
			bool flg=check(stat);
			if(flg){
				int cnt=0;
				for(int i=0;i<L;i++){
					if((stat>>i)&1) cnt++;
				}
				if(ans==-1||ans>cnt) ans=cnt;
			}
		}
		if(ans==-1) printf("Case #%d: NOT POSSIBLE\n",datano+1);
		else printf("Case #%d: %d\n",datano+1,ans);
	}
	return 0;
}
