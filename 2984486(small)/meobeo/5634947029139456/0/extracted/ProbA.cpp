#include <iostream>
#include <fstream> 
#include <set> 
#include <vector>
#include <string>
using namespace std;

ofstream outFile;
ifstream inFile;

long long int stringToInt(std::string s); 

int main(int argc, const char* argv[]) {
	std::vector<long long int> outLet;
	std::set<long long int> devices;
	int T;
	int N;
	int L;
	int a[100];
	inFile.open(argv[1]);
	std::string s;
 	inFile >> T;
	outFile.open("out.txt");

	for (int i = 1; i <= T; i++) {
		inFile >> N;
		inFile >> L;
		outLet.clear();
		devices.clear();
		for (int j = 1; j <= N; j++){
			inFile >> s;
			outLet.push_back(stringToInt(s));
		}
		long long int first;
		for (int j = 1; j <= N; j++) {
			inFile >> s;
			first = stringToInt(s);
			devices.insert(first);
		}
		
		int minTime = 1000;
		for (int j=0; j < N; j++) {
			long long int diff = (first ^ outLet[j]);
			int pos = 0;
			int index = 0;
			while (diff != 0) {
				if ((diff & 1) == 1) {
					a[index] = pos;
					index++;
				}
				diff = (diff >> 1);
				pos++;
			}
			if (minTime < index) continue;
			bool correct = true;
		        for (int k = 0; k < N; k++) {
				long long int newNum = outLet[k];
				for (int l = 0; l < index; l++)
					newNum ^= 1 << a[l];
				if (devices.find(newNum) == devices.end()) {
					correct = false;
					break;
				}
						
			}
			if (correct) minTime = index; 
		}
	        outFile << "Case #" << i << ": ";
		if (minTime < 1000) outFile << minTime << std::endl;
		else outFile << "NOT POSSIBLE" << std::endl;;
	}	

	outFile.close();
	inFile.close();
	return 0;

}	

long long int stringToInt(std::string s) {
 	long long int num = 0;
	int L = s.size();
	for (int k = L-1; k >= 0; k--){
		num = (num << 1);
		if (s[k] == '1') num = (num | 1);
        }
	return num;
}
	
