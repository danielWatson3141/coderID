#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
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

//change outlet 1 to outlet 2
string getAction(string outlet1, string outlet2){
	string res = "";
	for(int i=0;i<l;i++){
		if(outlet1[i] != outlet2[i]){
			res += "1";
		} else {
			res += "0";
		}
	}
	return res;
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
		
		vector<vector<string> > poss; 
		for(int j=0;j<n;j++){
			vector<string> tmp;
			for(int k=0;k<n;k++){
				tmp.push_back(getAction(outlets[j], need[k]));
			}
			poss.push_back(tmp);
		}
		
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				//cout<<poss[j][k]<<" ";
			}
			//cout<<endl;
		}
		
		bool found = true;
		int curVal = 99999;
		vector<int> past;
		string res;
		for(int j=0;j<n;j++){
			//cout<<"Trying "<<j<<endl;
			past.clear();
			past.push_back(j);
			for(int x=1;x<n;x++){
				found = false;
				for(int y=0;y<n;y++){
					//cout<<"Trying with index "<<x<<", "<<y<<": "<<poss[0][j]<<" "<<poss[x][y]<<endl;
					if(poss[x][y] == poss[0][j]){
						//cout<<"sama"<<endl;
						if(find(past.begin(), past.end(), y) == past.end()){
							past.push_back(y);
							found = true;
							break;
						} else {
							//cout<<"udah ada"<<endl;
						}
					}
				}
				if(!found){
					//cout<<"not found at: "<<x<<endl;
					past.clear();
					break;
				}
			}
			if(found){
				res = poss[0][j];
				int ans = 0;
				for(int j=0;j<res.length();j++){
					if(res[j] == '1'){
						ans++;
					}
				}
				if(ans < curVal){
					curVal = ans;
				}
			}
		}
		
		if(curVal != 99999){
			cout<<"Case #"<<i<<": "<<curVal<<endl;
		} else 
			cout<<"Case #"<<i<<": "<<"NOT POSSIBLE"<<endl;
		
		
	}
	return 0;
}