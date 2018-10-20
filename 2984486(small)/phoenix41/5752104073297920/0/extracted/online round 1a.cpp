#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <deque>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
#include <iterator>

using namespace std;
int t;
int ans = 50000, gr[500][500], n, l;
vector <int> v,v1;
double ans1 = 0, gr1[500][500], n1;
int f[1 << 11];
ifstream fin;
ofstream fout;
int g;
int count1,count2;
int main(){
	ios_base::sync_with_stdio(false);
	fin.open("C-small-attempt1.in");
	fout.open("ss.txt");
	fin >> t;
	for(int k = 0; k < t; k++){
		fout << "Case #" << k+1 << ": ";
		g = 0;
		fin >> n;
		count1 = 0, count2 = 0;
		v.resize(n);
		for(int i = 0; i < n; i++)
			fin >> v[i];
		for(int i = 0; i  < n; i++){
			if(v[i] == i){
				g++;
			}
			if(v[i] == n-1 && i < n-1)
				g++;
			if(v[i] == n-1 && i < 50)
				g = g-2;
			if(v[i] > i)
				count1++;
			else if(v[i] < i)
				count2++;
		}
		g+=(count2*2 - count1 + 45);
		if(g >= n-500)
			fout << "GOOD";
		else fout << "BAD";
		fout << "\n";
	}
	return 0;
}