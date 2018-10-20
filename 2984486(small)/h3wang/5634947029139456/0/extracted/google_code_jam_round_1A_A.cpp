#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define DEBUG
#include <fstream>
using namespace std;
#ifdef DEBUG
ifstream fin("test.in");
ofstream fout("test.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
vector<string> v[2];
vector<string> vp;
int T,N,L;
bool current[40];
string s;
bool found;
int minimum;
void flip(int i){
	for(int j=0;j<N;j++)
		vp[j][i]=(vp[j][i]=='1')?'0':'1';
}
bool check(){
	vp=v[0];
	for(int i=0;i<L;i++){
		if(current[i]){
			flip(i);
		}
	}
	sort(vp.begin(),vp.end());
	for(int i=0;i<N;i++)
		if(vp[i]!=v[1][i])
			return false;
	return true;
}
void search(int i,int sum){
	if(i==L){
		if(check()){
			found=true;
			if(sum<minimum)
				minimum=sum;
		}
		return;
	}
	if(sum>minimum)
		return;
	current[i]=true;
	search(i+1,sum+1);
	current[i]=false;
	search(i+1,sum);
}
int main(){
	redirect();
	cin>>T;
	for(int i=0;i<T;i++){
		memset(current,false,sizeof(current));
		cout<<"Case #"<<i+1<<": ";
		v[0].clear();
		v[1].clear();
		cin>>N>>L;
		for(int k=0;k<2;k++)
			for(int j=0;j<N;j++){
				cin>>s;
				v[k].push_back(s);
			}
		sort(v[1].begin(),v[1].end());
		minimum=2147483647;
		found=false;
		search(0,0);
		if(!found)
			cout<<"NOT POSSIBLE"<<endl;
		else
			cout<<minimum<<endl;
	}
	return 0;
}