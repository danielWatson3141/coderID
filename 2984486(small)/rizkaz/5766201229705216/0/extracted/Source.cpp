#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<climits>
#include<stack>
#include <iomanip>      // std::setprecision
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
int con[1000][1000] = { {0 } };
int find_dpt(int cur, int prev, int N){
	int child = 0;
	vector<int> childl;
	for (int k = 1; k < N+1; k++){
		if (con[cur][k] == 1 && k != prev)
		{ 
			child++; 
			childl.push_back(k); 
		}
	}
	if (child < 2) return 1;

	else if(child==2)	return 1 + find_dpt(childl[1], cur, N) + find_dpt(childl[0], cur, N);
	else{

		int max = 0;
		int temp;
		for (int p = 0; p < childl.size(); p++){
			for (int i = p+1; i < childl.size(); i++){
				temp = 1 + find_dpt(childl[p], cur, N) + find_dpt(childl[i], cur, N);
				if (temp>max) max = temp;
			}

		}
		return max;
	}
}
int main(){

	int T, N,a,b;
	fin >> T;

	for (int k = 0; k < T; k++){
		fin >> N;
		for (int i = 1; i < N+1; i++)
		for (int j = 1; j < N+1; j++) con[i][j] = 0;
		for (int p = 0; p < N - 1; p++){
			fin>>a >> b;
			con[a][b] = 1;
			con[b][a] = 1;
		}
		int max = 0,temp;
		for (int p = 1; p < N+1; p++){
			temp=find_dpt(p, p,N);
			if (temp>max) max = temp;
		}
		fout << "Case #" << k + 1 << ": " <<N- max << endl;
	}



	return 0;
}