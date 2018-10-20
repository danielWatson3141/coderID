#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

string strs[200];
string reqs[200];

int N,L;

string cur;

string tmp[200];

string add(string s1,string s2){
	string res="";
	for(int i=0;i<L;i++){
		if(s1[i]!=s2[i]) res+='1';
		else res+='0';
	}
	return res;
}

int check(int id){
	//strs[0]->reqs[id];
	cur="";
	for(int i=0;i<L;i++){
		if(strs[0][i]!=reqs[id][i]){
			cur+='1';
		}else cur+='0';
	}
	for(int i=0;i<N;i++){
		tmp[i]=add(strs[i],cur);
	}
	sort(tmp,tmp+N);
	for(int i=0;i<N;i++) if(tmp[i]!=reqs[i]) return -1;
	int ans=0;
	for(int i=0;i<L;i++) if(cur[i]=='1') ans++;
	return ans;
}

int solve(){
	sort(reqs,reqs+N);
	int ans=-1;
	for(int i=0;i<N;i++){
		int tmp=check(i);
		if(tmp!=-1){
			if(ans==-1||ans>tmp) ans=tmp;
		}
	}
	return ans;
}

int main(){
	int T;
	cin>>T;
	for(int datano=0;datano<T;datano++){
		cin>>N>>L;
		for(int i=0;i<N;i++) cin>>strs[i];
		for(int i=0;i<N;i++) cin>>reqs[i];
		int ans=solve();
		if(ans==-1) printf("Case #%d: NOT POSSIBLE\n",datano+1);
		else printf("Case #%d: %d\n",datano+1,ans);
	}
	return 0;
}
