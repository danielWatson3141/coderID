#include <iostream>
#include <cstring>

using namespace std;

typedef long double ld;

int n;

ld prob[1024][1024]; // probability of i-th element being in j-th position
ld prob_temp[1024][1024];

void construct_prob(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (i == j) prob[i][j] = 1.;
			else prob[i][j] = 0;
		}
	ld nn = n;
	for (int t = 0; t < n; t++){
		//cout << "t = " << t << endl;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){ // j-th position
				if (j == t){
					prob_temp[i][j] = 1./nn;
					continue;
				}
				prob_temp[i][j] = (nn-1.)/nn * prob[i][j] + prob[i][t] / nn;
			}
		}
		memcpy(prob,prob_temp,sizeof(prob));
	}
}

int main(){
	n = 1000;
	construct_prob();
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			//cout << prob[i][j] << " ";
		}
		//cout << endl;
	}
	
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		int temp; cin >> temp;
		int arr[1024];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		ld ans = 1;
		for (int j = 0; j < n; j++){
			//cout << arr[j] << " " << j << endl;
			ans *= (prob[arr[j]][j] * n);
		}
		//cout << "ans = " << ans << endl;
		if (ans > 1.) cout << "Case #" << zz << ": BAD" << endl;
		else cout << "Case #" << zz << ": GOOD" << endl;
	}
	
	return 0;
}
