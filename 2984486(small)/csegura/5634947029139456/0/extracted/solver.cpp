#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

void convert(int n, vector<string> &original, vector<string> &converted, int &count){
	count = 0;
	converted = original;
	int bit = 0;
	while(n != 0){
		if (n % 2){
			count++;
			if (bit >= converted[0].size()){
				return;
			}
			for (int i = 0; i < converted.size(); i++){
				if (converted[i][bit] == '0'){
					converted[i][bit] = '1';
				} else {
					converted[i][bit] = '0';
				}
			}
		} 
		bit++;
		n /= 2;
	}
}
int main(){
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++){
		int N, L;
		cin >> N >> L;
		vector<string> status;
		for (int j = 0; j < N; j++){
			string tmp;
			cin >> tmp;
			status.push_back(tmp);
		}
		vector<string> desire;
		for (int j = 0; j < N; j++){
			string tmp;
			cin >> tmp;
			desire.push_back(tmp);
		}
		sort(desire.begin(), desire.end());
		vector<string> converted;
		int result = -1;
		for (int j = 0; j < (1 << L); j++){
			int count = 0;
			convert(j, status, converted, count);
			sort(converted.begin(), converted.end());
			if (converted == desire){
				if ((result == -1) || (count < result)){
					if (result == -1){
						result = count;
					} else {
						result = min(result, count);
					}
				}
			}
		}
		if (result == -1){
			cout << "Case #" << (i+1) << ": NOT POSSIBLE" << endl;
		} else {
			cout << "Case #" << (i+1) << ": " << result << endl;
		}
	}
}
