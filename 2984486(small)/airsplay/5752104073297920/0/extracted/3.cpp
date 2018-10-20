#include<iostream>
#include<fstream>
using namespace std;
const int maxn = 1005;
int a[maxn];
int n;
int main(){
	ifstream in("3.in");
	ofstream out ("3.out");
	int testSum;
	in >> testSum;
	int cnt = 0;
	for (int test = 1; test <= testSum; test++){
//		cout << test << endl;
		in >> n;
		int character = 0;
		for (int i = 0; i < n; i++){
			in >> a[i];
			if (a[i] == i) character++;
		}
		cout << character << endl;

		out << "Case #"<<test<< ": ";

		if (character >= 1){
			out << "BAD" << endl;
			cnt ++;
		}
		else {
			out << "GOOD" << endl;
		}
	}
	cout << cnt << endl;
}
