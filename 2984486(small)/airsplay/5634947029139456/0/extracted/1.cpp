#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int n, l;
const int maxn = 200;
long long outlet[maxn];
long long elec[maxn];

int main(){
	ifstream in("1.in");
	ofstream out("1.out");
	int testSum;
	in >> testSum;
	for (int test = 1; test <= testSum; test++){
		in >> n >> l;
		string str;
		for (int i = 1; i <= n; i++){
			in >> str;
			long long tmp = 0;
			for (int j = 0; j < str.length(); j++){
				if (str[j] == '1'){
					tmp = tmp * 2 +1;
				}
				else tmp = tmp * 2;
			}
			outlet[i] = tmp;
		}

		for (int i = 1; i <= n; i++){
			in >> str;
			long long tmp = 0;
			for (int j = 0; j < str.length(); j++){
				if (str[j] == '1'){
					tmp = tmp * 2 +1;
				}
				else tmp = tmp * 2;
			}
			elec[i] = tmp;
		}

		sort(elec+1, elec+n+1);
//		for (int i = 1; i <= n; i++){
//			cout << elec[i] << ' ';
//		}
//		cout << endl;
		long long transfer;
		vector<long long> vOut;
		vOut.clear();
		bool flag = false;
		int ans = 1232123212;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){

				transfer = elec[i] ^ outlet[j];
				vOut.clear();
				for (int k = 1; k <= n; k++){
					vOut.push_back(outlet[k] ^ transfer);
				}
				sort(vOut.begin(), vOut.end());
//				cout << i << ' ' << j << endl;
//				for (int p = 0; p <= n-1; p++){
//			cout << vOut[p] << ' ';
//		}
//		cout << endl;

				bool equal = true;
				for (int k = 1; k <= n; k++){
					if (vOut[k-1] != elec[k]) {
						equal = false;
						break;
					}
				}
				if (equal){
					flag = true;
					int tmp = 0;
					while (transfer != 0){
						tmp ++;
						transfer -= (transfer & (- transfer));
					}
					if (tmp < ans)
						ans = tmp;
				}
			}
		}
		out << "Case #" << test << ": ";
		if (flag){
			out << ans << endl;
		}
		else {
			out << "NOT POSSIBLE" << endl;
		}
	}
}
