#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int sum[1010][1010];
int memo[1010][1010];
int memo2[1010];
vector<int> suc[1010];
int T;
int N;

int dp(int nod, int pad){
	int &ref = memo[nod][pad];
	if(ref!=-1) return ref;
	ref =0;
	int &ref2 = sum[nod][pad];
	ref2=0;
	int c=0;
	for(int i=0;i<suc[nod].size();i++){
		if(pad!=suc[nod][i]){
			dp(suc[nod][i],nod);
			/*if(mini1==-1) mini1=tmp;
			else if(mini2==-1) {mini2=tmp; if(mini1>mini2) swap(mini1,mini2);}
			else if(tmp<mini1) {mini2=mini1;mini1=tmp;}
			else if(tmp<mini2) mini2=tmp;*/
			
			ref2+=sum[suc[nod][i]][nod];
			c++;
		}
	}
	if(c>=2){
		ref=0x3f3f3f3f;
		for(int i=0;i<suc[nod].size();i++){
			for(int j=i+1;j<suc[nod].size();j++){
				if(suc[nod][i]!=pad && suc[nod][j]!=pad)
					ref= min(ref,ref2-sum[suc[nod][i]][nod]-sum[suc[nod][j]][nod]+dp(suc[nod][i],nod)+dp(suc[nod][j],nod));
			}
		}
	}
	if(c==1) ref = ref2;
	ref2++;
//	cout << nod << " " <<pad << " ref2=" << ref2 << " "<< ref << endl;
	return ref;
}

int main(){
	cin >> T;
	for(int t=0;t<T;t++){
		cout << "Case #" << t+1 << ": ";
		cin >> N;
		for(int i=0;i<N;i++) suc[i].clear();

		for(int i=0;i<N-1;i++){
			int t1,t2;
			cin >> t2 >> t1;
			t2--,t1--;
			suc[t2].push_back(t1);
			suc[t1].push_back(t2);
		}
		memset(memo,-1,sizeof memo);
		memset(sum,0,sizeof sum);
		int mini = 10000;
		for(int i=0;i<N;i++)
				mini = min(mini,dp(i,i));
		

		cout << mini << endl;
	}
	
	

	return 0;
}
