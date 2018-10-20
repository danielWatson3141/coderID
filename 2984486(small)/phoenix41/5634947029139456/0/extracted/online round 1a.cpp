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
vector <string> v;
double ans1 = 0, gr1[500][500], n1;
int debasify(int i);
vector <string> v1;
int f[1 << 11];
ifstream fin;
ofstream fout;
int main(){
	ios_base::sync_with_stdio(false);
	int gcj = 0;
	fin.open("A-small-attempt1.in");
	fout.open("ss.txt");
	fin >> t;
	for(int k = 0; k < t; k++){
		fout << "Case #" << k+1 << ": ";
		fin >> n >> l;
		v.resize(n);
		v1.resize(n);
		for(int i = 0; i < n; i++)
			fin >> v[i];
		for(int i = 0; i < n; i++)
			fin >> v1[i];
		for(int i = 0; i < (1 << 11); i++)
			f[i] = 0;
		for(int i = 0; i < n; i++){
		   for(int j = 0; j < n; j++){
			   for(int c = 0; c < l; c++){
				   if(v[i][c] != v1[j][c])
					   gcj+=(1 << c);
			   }
			   f[gcj]++;
			   gcj = 0;
		   }
		}
		for(int i = 0; i < (1 << 11); i++)
			if(f[i] == n){
				ans = min(ans,debasify(i));
			}
		if(ans > l)
			fout << "NOT POSSIBLE";
		else fout << ans;
		ans = 500000;
		fout << "\n";
	}
	return 0;
}
int debasify(int i){
	int k = 0;
   while(i > 0){
	  if(i%2!=0){
		k++;
	   }
	   i/=2;
   }
   return k;
}