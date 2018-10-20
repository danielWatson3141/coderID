#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compara (const string c1, const string c2) {
	return c1<c2;
}
int main(void){
	int T;
	cin >> T;
	for (int k = 0; k < T; ++k){
		int N, L;
		cin >> N >> L;
		vector<string> aparelhos(N);
		vector<string> tomadas(N);
		vector<string> tomadasC(N);
		for (int i = 0; i < N; ++i){
			cin >> aparelhos[i];
		}
		for (int i = 0; i < N; ++i){
			cin >> tomadas[i];
			tomadasC[i] = tomadas[i];
		}
		sort(aparelhos.begin(), aparelhos.end(), compara);
		int min = L+1;
		for (int i = 0; i < N; ++i){
			int cont = 0;
			for (int j = 0; j < L; ++j){
				if (aparelhos[i][j] != tomadas[0][j]){
					cont ++;
					for (int l = 0; l < N; ++l){
						tomadas[l][j] = '1'+'0'-tomadas[l][j];
					}
				}
			}
			sort(tomadas.begin(), tomadas.end(), compara);
			bool iqual = true;
			for (int j = 0; j < N; ++j){
				if (tomadas[j] != aparelhos[j]){
					iqual = false;
					break;
				}
			}
			if (iqual){
				if (cont < min) min = cont;
			}
			for (int i = 0; i < N; ++i){
				tomadas[i] = tomadasC[i];
			}
		}
		if (min == L+1){
			cout << "Case #" << k+1 << ": NOT POSSIBLE" << endl;
		} else {
			cout << "Case #" << k+1 << ": " << min << endl;
		}
	}
	return 0;
}
