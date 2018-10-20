#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int xor(string& A, string& B){

	int count = 0;

	for (int i = A.length() - 1; i >= 0; i--){

		if (A[i] != B[i])
			count++;

	}
	return count;
}

string flip(string& A, string& B, string& out){

	for (int i = A.length() - 1; i >= 0; i--){
	
		if (A[i] != B[i]){
			out[i] = out[i] == '0' ? '1' : '0';
		}
			
	}

	return out;

}


void main(){




	fstream fin, fout;

	fin.open("input.in", ios::in);
	fout.open("out.txt", ios::out | ios::trunc);
	
	int N, T, L;

	fin >> N;

	for (int n = 1; n <= N; n++){
	
		vector<string> outlets;
		vector<string> devices;

		fin >> T >> L;
		string temp;
		for (int i = 0; i < T; i++){

			fin >> temp;
			outlets.push_back(temp);

		}

		for (int i = 0; i < T; i++){
		
			fin >> temp;
			devices.push_back(temp);

		}

		int min = L + 1;

		int count;

		string flip_seq;

		for (int i = 0; i < T; i++){
		
			count = xor(devices[0], outlets[i]);

			if (count < min){

				int count2 = 0;
				for (int j = 0; j < T; j++){
					
					temp = outlets[j];
					flip(devices[0], outlets[i], temp);
					for (int k = devices.size() - 1; k >= 0; k--){

						if (devices[k] == temp){
						
							count2++;
							break;
					
						}
					}
				
				}
				if (count2 == devices.size())
					min = count;

			}

		}

		fout << "Case #" << n << ": ";
		if (min <= L)
			fout << min << endl;
		else
			fout << "NOT POSSIBLE" << endl;


	}
	system("pause");
}