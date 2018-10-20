#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int neededFlips(string s1, string s2){
	
	int res =0;
	for(int i=0; i<s1.size(); i++){
		
		if(s1[i] != s2[i]) res++;
		
	}
	
	return res;
	
}

bool canPlug(string *s1, string *s2, int N){
	
	vector<string> set1;
	vector<string> set2;
	vector<string> vv(2*N);
	vector<string>::iterator it;
	
	for(int i=0; i<N; i++){
		set1.push_back(s1[i]);
		set2.push_back(s2[i]);
	}
	
	sort(set1.begin(), set1.end());
	sort(set2.begin(), set2.end());
	
	it = set_intersection( set1.begin(), set1.end(), set2.begin(), set2.end(), vv.begin() );
	
	vv.resize(it-vv.begin());
	//cout << "size " << vv.size() << endl; 
	return vv.size() == N;
}

void flip(string *s, int N, int x){
	
	for(int i=0; i<N; i++){
		if(s[i][x]=='0')s[i][x]='1';
		else s[i][x]='0';
	}
	
}

string *copy(string *s, int N){
	string *res= new string[N];
	
	for(int i=0; i<N; i++) res[i]=s[i];
	
	return res;
}

void printss(string *s, int N){
	for(int i=0; i<N; i++) cout << s[i] << " ";
	cout<<endl;
}

int main(){
	
	int nn;
	cin>>nn;
	
	for(int kk=0; kk<nn; kk++){
		
		int N, L;
		cin>>N>>L;
		
		string *enchu = new string[N];
		string *apara = new string[N];
		
		for(int i=0; i<N; i++){
			cin>>enchu[i];
		}
		for(int i=0; i<N; i++){
			cin>>apara[i];
		}
		
		
		int min = numeric_limits<int>::max();
		bool found = false;
		
		for(int i=0; i<N; i++){
			
			if( neededFlips( enchu[0], apara[i]) < min){
				
				string *p1 = copy(enchu, N);
				string *p2 = copy(apara, N);
				
				for(int j=0; j<enchu[0].size(); j++){
					if( enchu[0][j] != apara[i][j]){
						flip(p2, N, j);
					}
				}
				
				if( canPlug(p1,p2,N) ){
					found = true;
					min = neededFlips( enchu[0], apara[i]);
				}
				
				//delete p1;
				//delete p2;
				
			}
			
		}
		cout << "Case #" << kk+1 << ": ";
		if(!found) cout << "NOT POSSIBLE" <<endl;
		else cout <<min <<endl;
		
	}


	/*
	string *enchu = new string[2];
	string *apara = new string[2];
	
	enchu[0]="Hola";
	enchu[1]="Adios";
	apara[0]="Adios";
	apara[1]="Hola";
	
	cout << canPlug(enchu, apara, 2) <<endl;
	*/
	
}
