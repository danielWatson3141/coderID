/*************************************************************************
    > File Name: A.cpp
    > Author: csy
    > Mail: chshaoyi7@gmail.com 
    > Created Time: Sat 26 Apr 2014 09:06:42 AM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<cstring>
#include<fstream>
using namespace std;

#include <string>

int main(){

	int t, n, l;
	int counter;
	bool flag;
	string start_status[200], target_status[200];
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");

	fin >> t;
	for(int k = 1; k <= t; k ++){
		fin >> n >> l;
		for(int i = 0; i < n; i ++)
			fin >> start_status[i];
		
		map<string, int> M;
		for(int i = 0; i < n; i ++){
			fin >> target_status[i];
			if(M.count(target_status[i]) == 0){
				M[target_status[i]] = 1;
			}else M[target_status[i]] ++;

		}
		
		bool possible = true;
		counter = 0;
		int min = 5000;
		map<string, int> N;
		map<string, int>::iterator iter,iter1;
		string next;
		for(int i = 0; i < n; i ++){
			N.clear();
				counter = 0;
				for(int j = 0; j < l; j ++)
					if(start_status[0][j] != target_status[i][j]) counter ++;

				for(int p = 0; p < n; p ++){
					next = start_status[p];
					
					for(int q = 0; q < l; q ++){
						if(start_status[0][q] != target_status[i][q]){
							if(next[q] == '0') next[q] = '1';
							else               next[q] = '0';
						}
					}


					if(N.count(next) == 0) N[next] = 1;
					else                   N[next] ++;
				
				}
				possible = true;
				for(iter = M.begin(); iter != M.end(); iter ++){

					if(N.count(iter->first) != 0 && N[iter->first] == iter->second) ;
					else {
						possible = false;
						break;
					}
				}
			
				if(possible){
					if(counter < min) min = counter;
				}

		}
		fout << "Case #"  << k << ": ";
		if(min < 5000) fout << min << endl;
		else         fout << "NOT POSSIBLE" << endl;
	}

}
