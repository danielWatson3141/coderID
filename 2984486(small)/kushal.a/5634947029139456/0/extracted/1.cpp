#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;


ifstream fin("small.in");
ofstream fout("small.out");
long long int outlet[150];
long long int device[150];

int main(){
	int nt;
	fin >> nt;
	for(int t=0;t<nt;t++){
		int n,l;
		fin >> n >> l;
		char buff[100];
		for(int i=0;i<n;i++){
			fin >> buff;
			outlet[i] = 0;
			for(int j=0;j<l;j++){
				outlet[i] <<= 1;
				outlet[i] += buff[j] == '1'?1:0;
			}
		}
		for(int i=0;i<n;i++){
			fin >> buff;
			device[i] = 0;
			for(int j=0;j<l;j++){
				device[i] <<= 1;
				device[i] += buff[j] == '1'?1:0;
			}
		}


		set<long long int> set;
		int minNumSwitches = 100;
		for(int i=0;i<n;i++){
			//try device i on outlet 0;
			long long int switches = device[i]  ^ outlet[0];

			//insert outlets
			for(int i=0;i<n;i++){
				set.insert(outlet[i] ^ switches);
			}

			bool succes = true;
			//remove devices
			for(int i=0;i<n;i++){
				if(!set.erase(device[i])){
					set.clear();
					succes = false;
					break;
				}

			}
			if(succes){
				int nSwitches = 0;
				while(switches){
					nSwitches += switches%2;
					switches >>= 1;
				}
				if(nSwitches < minNumSwitches){
					minNumSwitches = nSwitches;
				}
			}
			
		}
		if(minNumSwitches == 100)
			fout << "Case #" << t+1 << ": " << "NOT POSSIBLE" << endl;
		else
			fout << "Case #" << t+1 << ": " << minNumSwitches << endl;

	}
	return 0;
}