#include<iostream>
#include<cmath>
using namespace std;

int tc, n, l;
string outlets[152];
string dummy[152];
string need[152];
bool used[152];
	
char change(char c){
	if(c == '1'){
		return '0';
	} else 
		return '1';
}



void initDummy(){
	
	for(int i=0;i<n;i++){
		used[i] = false;
		dummy[i] = outlets[i];
	}
}

int main(){
	//BRUTEFORCE
	cin>>tc;
	for(int i=1;i<=tc;i++){
		cin>>n>>l;
		for(int j=0;j<n;j++){
			cin>>outlets[j];
		}
		for(int j=0;j<n;j++){
			cin>>need[j];
		}
		
		initDummy();
		int switched = 0;
		bool diff;
		while(switched < ceil(pow(2, l))){
			//cout<<"STATE:\n";
			for(int j=0;j<n;j++){
				//cout<<dummy[j]<<" ";
			}
			//cout<<endl;
			//cout<<"switch: "<<switched<<endl;
			//cout<<"-----\n";
			
			for(int j=0;j<n;j++){
				diff = true;
				for(int k=0;k<n;k++){
					if(dummy[j] == need[k] && !used[k]){
						diff = false;
						used[k] = true;
					}
				}
				if(diff){
					break;
				}
			}
			
			if(!diff)
				break;
			switched++;
			int tmp = 1;
			int idx = l-1;
			initDummy();
			while(tmp <= switched){
				if(tmp & switched){
					//cout<<"yes: idx = "<<idx<<endl;
					for(int j=0;j<n;j++){
						dummy[j][idx] = change(dummy[j][idx]);
					}
				}
				tmp *= 2;
				idx--;
			}
		}
		
		if(diff == false){
			int res = 0;
			while(switched > 0){
				if(switched & 1){
					res++;
				}
				switched /= 2;
			}
			cout<<"Case #"<<i<<": "<<res<<endl;
		} else {
			cout<<"Case #"<<i<<": "<<"NOT POSSIBLE"<<endl;
		}
	}
	return 0;
}