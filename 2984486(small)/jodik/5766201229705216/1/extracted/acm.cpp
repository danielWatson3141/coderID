#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
unsigned const int PRIME = 100000009;
unsigned int POWER = 47;
char vzor[1002];
char kmp[1002];
char text[10002];
int dynamika[1002];
int Ndynamika[1002];
int i,j,k,n,m,K,zaciatok;
unsigned int hash2(char * s, int dlzka){
    unsigned int h = 0;
    while(dlzka--){
        h*=POWER;
        h+=(s[dlzka]);
    }
    return h;
}
unsigned int hash3(char * s, int dlzka){
    unsigned int h = 0;
    while(dlzka--){
        h*=POWER;
        h+=(s[0]);
        s=s+1001;
    }
    return h;
}
int max(int a, int b){
    if(a>=b) return a;
    return b;
}
int min(int a, int b){
    if(a<=b) return a;
    return b;
}

vector<int> cisla1, cisla2;

int CONST = -1000000001;
double C = 5, F = 5, X = 5;
int N, L;
		vector<double> Naomi, Ken;

bool otestuj(int kde){
	if(kde == N)
		return true;
	for(int i = 0; i < N - kde; i++){
		if(Naomi[N - i - 1] < Ken[N - kde - 1 - i])
			return false;
	}
	return true;
}

vector<vector<int> > hrany;
vector<int> pocet, binary;
int vys = 1500;

void poc(int vrchol, int z){
	for(int i = 0; i < hrany[vrchol].size(); i++){
		if(hrany[vrchol][i]!=z)
			poc(hrany[vrchol][i], vrchol);
	}

	int spol = 1;
	for(int i = 0; i < hrany[vrchol].size(); i++){
		if(hrany[vrchol][i]!=z)
			spol+=pocet[hrany[vrchol][i]];
	}

	pocet[vrchol] = spol;
}

void bin(int vrchol, int z){
	for(int i = 0; i < hrany[vrchol].size(); i++){
		if(hrany[vrchol][i]!=z)
			bin(hrany[vrchol][i], vrchol);
	}

	int max1 = 0;
	int max2 = 0;
	int sucet = 0;
	for(int i = 0; i < hrany[vrchol].size(); i++){
		if(hrany[vrchol][i]!=z){
			sucet+=pocet[hrany[vrchol][i]];
			int rozdiel = pocet[hrany[vrchol][i]] - binary[hrany[vrchol][i]];
			if(rozdiel > max1){
				max2 = max1;
				max1 = rozdiel;
			}
			else if(rozdiel > max2){
				max2 = rozdiel;
			}
		}
	}

	int hran = hrany[vrchol].size();
	if(z != -1) hran--;

	if(hran == 0)
		binary[vrchol] = 0;
	else if(hran == 1)
		binary[vrchol] = sucet;
	else if(hran >= 2)
		binary[vrchol] = sucet - max1 - max2;
}

void skus(int vrchol){
	poc(vrchol, -1);
	bin(vrchol, -1);
	vys = min(vys, binary[vrchol]);
}

int main(void)
{
	int a;
	scanf(" %d",&a);
	for(int t = 1; t <= a; t++){
		scanf("%d",&N);

		hrany.clear();
		hrany.resize(N);
		pocet.resize(N);
		binary.resize(N);
		vys = N - 1;

		int a,b;
		for(int i = 0; i < N -1; i++){
			scanf("%d%d", &a, &b); a--; b--;
			hrany[a].push_back(b);
			hrany[b].push_back(a);
		}

		for(int i = 0; i < N; i++){
			skus(i);
		}

		cout<<"Case #"<<t<<": ";
			cout<<vys;
		cout<<endl;
	}
    return 0;
}