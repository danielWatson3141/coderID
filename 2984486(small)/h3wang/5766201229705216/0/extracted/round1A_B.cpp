#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define DEBUG
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
vector<int> node[1001];
bool used[1001];
int T,N,X,Y,k,minimum;
int ava(int current){
	int sum=0;
	for(int i=0;i<node[current].size();i++){
		if(!used[node[current][i]])
			sum++;
	}
	return sum;
}
int getSize(int current){
	used[current]=true;
	int sum=1;
	for(int i=0;i<node[current].size();i++){
		if(!used[node[current][i]])
			sum+=getSize(node[current][i]);
	}
	used[current]=false;
	return sum;
}
int testRoot(int current){
	used[current]=true;
	vector<int> v,v2;
	int sum=0;
	if(ava(current)==0){
		used[current]=false;
		return 0;
	}
	if(ava(current)==1){
		used[current]=false;
		return getSize(current)-1;
	}
	if(ava(current)==2){
		for(int i=0;i<node[current].size();i++){
			if(!used[node[current][i]])
				sum+=testRoot(node[current][i]);
		}
		used[current]=false;
		return sum;
	}
	for(int i=0;i<node[current].size();i++){
		if(!used[node[current][i]]){
			v.push_back(testRoot(node[current][i]));
			v2.push_back(getSize(node[current][i]));
		}
	}
	for(int i=0;i<v.size();i++)
		sum+=v2[i];
	int fuck=2147483647;
	for(int i=0;i<v.size()-1;i++)
		for(int j=i+1;j<v.size();j++){
			if(sum-v2[i]-v2[j]+v[i]+v[j]<fuck)
				fuck=sum-v2[i]-v2[j]+v[i]+v[j];
		}
    used[current]=false;
	return fuck;
}
int main(){
	redirect();
	cin>>T;
	for(int i=0;i<T;i++){
		cout<<"Case #"<<i+1<<": ";
		cin>>N;
		for(int i=1;i<=N;i++)
			node[i].clear();
		for(int i=0;i<N-1;i++){
			cin>>X>>Y;
			node[X].push_back(Y);
			node[Y].push_back(X);
		}
		minimum=2147483647;
		for(int i=1;i<=N;i++){
			memset(used,false,sizeof(used));
			int k=testRoot(i);
			if(k<minimum){
				minimum=k;
			}
		}
		cout<<minimum<<endl;
	}
	return 0;
}