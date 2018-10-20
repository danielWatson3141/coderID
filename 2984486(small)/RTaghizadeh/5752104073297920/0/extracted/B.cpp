#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream fout;
	fout.open("d:\\ans.txt");
	cout.rdbuf(fout.rdbuf());

	ifstream fin;
	fin.open("d:\\1.in");
	cin.rdbuf(fin.rdbuf());
	int t,te;
	int i,j,k,l,n;
	cin>>t;
	for(te=1;te<=t;te++){
		cin>>n;
		cin>>j;
		cout<<"Case #"<<te<<(j>600||j<400?": GOOD":": BAD")<<endl;
		for(k=1;k<n;k++)
			cin>>j;

	}
	return 0;
}