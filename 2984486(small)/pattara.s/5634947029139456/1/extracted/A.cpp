#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int n,l;
vector<int> outlet,device;
vector<int> tmp ;
int toInt(string k){
	//printf("toInt %s",k.c_str());
	int ret=0;
	for(int i = 0 ; i< k.size() ; ++ i ){
		ret=ret*2 + (k[i]-'0');
	}
	//printf("return %d\n",ret);
	return ret;
}
void solve(){
	cin >> n >> l ;
	outlet.clear();
	device.clear();
	for(int i = 0 ; i < n ; ++ i ){
		string k;
		cin >> k ;
		outlet.push_back(toInt(k));
	}
	for(int i = 0 ; i < n ; ++ i ){
		string k;
		cin >> k ;
		device.push_back(toInt(k));
		//printf("done pushback\n");
	}
	int ans=1000000;
	sort(device.begin(),device.end());
	for(int i = 0 ; i < n ; ++ i ){
		// match i outlet with first device
		int flipter =  outlet[i]^device[0];
		int ctr = 0 ;
		vector<int> tmp;
		for(int j = 0 ; j < n ; ++ j ){
			tmp.push_back(outlet[j]^flipter);
		}
		sort(tmp.begin(),tmp.end());
		if(tmp==device){
			while(flipter){
				ctr++;
				flipter-=flipter&(-flipter);
			}
			if(ctr<ans)ans=ctr;
		}
	}
	if(ans==1000000)cout << "NOT POSSIBLE" << endl;
	else  cout << ans << endl;
}

int main(){


	int t;
	cin >> t;
	for(int i = 1;  i <=  t ; ++ i ){
		printf("Case #%d: ",i);
		solve();
	}
}
