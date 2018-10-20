#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <iomanip>

using namespace std;


int N, L;
string flipBit(string s, int n){
	char c = s.at(n);
	string ret = s;
	if(c=='0'){
		ret.replace(n,1,"1");
	}
	else if(c=='1'){
		ret.replace(n,1,"0");
	}
	return ret;
}

vector<string> devices;
vector<string> outlets;

void flipAllBits(int n){
	vector<string>::iterator ii = outlets.begin();
	for(;ii!=outlets.end();ii++){
		string s = *(ii);
		s=flipBit(s,n);
		outlets.erase(ii);
		outlets.insert(ii,s);
	}
}
bool isSolved(){
	sort(devices.begin(),devices.end());
	sort(outlets.begin(),outlets.end());
	vector<string>::iterator ii = devices.begin();
	vector<string>::iterator iii= outlets.begin();
	for(;ii!=devices.end();ii++){
		string s1 = *(ii);
		string s2 = *(iii);
		if(s1!=s2)
			return false;
		iii++;
	}
	return true;
}
vector<int> solutions;
void recurse(int bitNum, int flips){
	if(isSolved()){ //if the outlets match the devices, add number of flips to solutions
		solutions.push_back(flips);
		/*cout<<"current bit: "<<bitNum-1<<endl;
		cout<<"current state of outlets: ";
		vector<string>::iterator ii = outlets.begin();
		for(;ii!=outlets.end();ii++){
			cout<<*(ii)<<" ";
		}
		cout<<endl;
		cout<<"current state of devices: ";
		vector<string>::iterator iii = devices.begin();
		for(;iii!=devices.end();iii++){
			cout<<*(iii)<<" ";
		}
		cout<<endl;
		return;*/
	}
	if(bitNum>=L){//if there are no more bits to try
		return;
	}
	else{
		//try strings with this bit unflipped
		recurse(bitNum+1,flips);

		//try strings with this bit flipped
		flipAllBits(bitNum);
		recurse(bitNum+1,flips+1);

		//unflip this bit after or bad shit will happen
		flipAllBits(bitNum);
		return;
	}
}
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
int main(){
	Rd("A-small-attempt0.in");
	Wt("results.out");
	int t;
	cin>>t;
	for(int o = 1;o<=t;o++){
		cin>>N>>L;
		for(int i=0;i<N;i++){
			string s;
			cin>>s;
			devices.push_back(s);
		}
		for(int i=0;i<N;i++){
			string s;
			cin>>s;
			outlets.push_back(s);
		}

		recurse(0,0);
		cout<<"Case #";
		cout<<o<<": ";
		if(solutions.size()==0){
			cout<<"NOT POSSIBLE"<<endl;
		}
		else{
			sort(solutions.begin(),solutions.end());
			vector<int>::iterator ii = solutions.begin();
			cout<<*(ii)<<endl;
		}
		devices.erase(devices.begin(),devices.end());
		outlets.erase(outlets.begin(),outlets.end());
		solutions.erase(solutions.begin(),solutions.end());

	}
	return 0;
}
