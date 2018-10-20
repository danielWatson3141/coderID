#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <utility>
#include <map>
using namespace std;

int n;
//int linkmap[1001][1001];
vector<int> linklist[1001];
int known[1001];




int traverse(int root){
	int ret = 0;
	for( int i = 0; i < linklist[root].size(); i++){
		int nownum = linklist[root][i];
		if( !known[nownum] ){
			ret++;
			known[nownum] = 1;
			ret += traverse(nownum);
		}
	}
	return ret;
}

int ct(int root){
	for(int i = 0; i < 1001; i++)
		known[i] = 0;
	known[root] = 1;
	return 1+traverse(root);
}



int work(int root){
	if( linklist[root].size() == 0 )
		return 0;
	if( linklist[root].size() == 1 )
	{
		int child = linklist[root][0];
		for( vector<int>::iterator it = linklist[child].begin(); it!= linklist[child].end(); it++) if( *it == root){
			linklist[child].erase(it);
			break;
		}
		int ctnum = ct(child);
		linklist[child].push_back(root);
		return ctnum;		
	}
	if( linklist[root].size() == 2 ){
		int child = linklist[root][0];
		for( vector<int>::iterator it = linklist[child].begin(); it!= linklist[child].end(); it++) if( *it == root){
			linklist[child].erase(it);
			break;
		}
		int total = work(child);
		linklist[child].push_back(root);
		child = linklist[root][1];
		for( vector<int>::iterator it = linklist[child].begin(); it!= linklist[child].end(); it++) if( *it == root){
			linklist[child].erase(it);
			break;
		}
		total += work(child);
		linklist[child].push_back(root);
		return total;
	}
	else{

		int minret = 2000;
		vector<int> cts;
		vector<int> pfs;
		for( int ii = 0; ii < linklist[root].size(); ii++){
			int child0 = linklist[root][ii];
			for( vector<int>::iterator it = linklist[child0].begin(); it!= linklist[child0].end(); it++) if( *it == root){
				linklist[child0].erase(it);
				break;
			}
			cts.push_back(ct(child0));
			pfs.push_back(work(child0));
			linklist[child0].push_back(root);
		}

		int nownow = 0;
		for( int ii = 0; ii < linklist[root].size(); ii++){
			nownow+= cts[ii];
		}
		for( int i1 = 0; i1 < linklist[root].size(); i1++)
			for( int i2 = 0; i2 < linklist[root].size(); i2++)
				if( i1!=i2){
					int now = nownow;
					now += (pfs[i1]-cts[i1]);
					now += (pfs[i2]-cts[i2]);
					if( now < minret)
						minret = now;
				}
		return minret;

	}

}


int main(){
	ifstream is("r22.in");
//	std::istream& is = std::cin;
	ofstream os("answer.txt");
	int t;
	is >> t;
	for( int i = 1; i<=t; i++){
		is >> n;
		map<int,int> input;
		for(int j = 1; j <= n; j++){
			linklist[j].clear();
		}
		for(int j = 1; j < n; j++){
			int a, b;
			is >> a >> b;
			linklist[a].push_back(b);
			linklist[b].push_back(a);
			input[a] = 0;
			input[b] = 0;
		}
		int nowmin = 2000;
		int cnode = -1;
		for( map<int,int>::iterator it = input.begin(); it!= input.end(); it++){
			int now = work(it->first);
			if( now < nowmin ){
				nowmin = now;
				cnode = it->first;
			}
		}
		os << "Case #"<<i<<": "<<nowmin<<endl;
		
		cout << "Case #"<<i<<": "<<nowmin<<" " << cnode << endl;
	}
//	 is.close();
	 os.close();
}