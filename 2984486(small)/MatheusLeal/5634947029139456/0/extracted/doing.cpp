#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> v1;
vector <string> v2;
int ans;
int lim;
int n;
ofstream myfile;
  ifstream input;

int backtracking(vector<string> v, int jog, int l){
	
	vector<string> vau = v;
	sort(vau.begin(), vau.end());

	if(jog>ans && ans!=0){
		return 50;
	}else if(vau==v2){
		ans = jog;
		return jog;	
	}else if(l==lim){
		return 50;
	}else{
		vector<string> vaux = v;
		for(int i=0; i<v.size(); i++){
			if(v[i][l]=='0'){
				vaux[i][l]='1';
			}else{
				vaux[i][l]='0';
			}
		}
			int a = backtracking(vaux, jog+1, l+1);
			int b = backtracking(vau, jog, l+1);
			
			if(a>b){
				return b;
			}else{
				return a;
			} 
		}		
	
	
}


int main () {
	 
  input.open("file.in");
   myfile.open ("example.txt");
	int tot;
	input>>tot;
	for(int i=1; i<=tot; i++){
			int l;
			input>>n>> l;
			string a;
			ans = 0;
			lim=l;
		
			for(int j=0; j<n; j++){
				input>>a;
				v1.push_back(a);
			}
			for(int j=0; j<n; j++){
				input>>a;
				v2.push_back(a);
			}
			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end());
			if(v1==v2){
				myfile<<"Case #"<<i<<": "<<0<<endl;
			}else{

				int ok = backtracking(v1, 0, 0);
				if(ok>40){
					myfile<<"Case #"<<i<<": "<<"NOT POSSIBLE"<<endl;
				}else{
					myfile<<"Case #"<<i<<": "<<ok<<endl;
				}
				
			}
			v1.clear();
			v2.clear();
	}
	 myfile.close();
  input.close();
	  return 0;
}
