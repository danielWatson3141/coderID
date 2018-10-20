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

vector<vector<int> > mapovanie;
vector<string > veci, zastrcky;
bool rozhodnute[45];

int vys = 1500;

bool moze(int pokial){
	sort(zastrcky.begin(),zastrcky.end());
	for(int i = 0; i< N; i++){
		for(int j = 0; j <= pokial; j++){
			if(zastrcky[i][j]!=veci[i][j])
				return false;
		}
	}
	return true;
}

void zrotuj(int ktory){
	for(int i = 0; i< N; i++){
		if(zastrcky[i][ktory] == '1')
			zastrcky[i][ktory] = '0';
		else
			zastrcky[i][ktory] = '1';
	}
}

void dasa(int ktory, int pocet){
	//cout<<ktory<<" "<<pocet<<" "<<N<<endl;
	if(ktory == L){
		vys = min(vys, pocet);
		return;
	}
	if(moze(ktory))
		dasa(ktory+1,pocet);
	zrotuj(ktory);
	if(moze(ktory))
		dasa(ktory+1,pocet+1);
	zrotuj(ktory);


}


int main(void)
{
	int a;
	scanf(" %d",&a);
	for(int t = 1; t <= a; t++){
		scanf("%d%d",&N,&L);
		veci.resize(N);
		zastrcky.resize(N);

		for(int i = 0; i < N; i++){
			cin>>zastrcky[i];
		}
		for(int i = 0; i < N; i++){
			cin>>veci[i];
		}
		
		sort(veci.begin(),veci.end());

		vys = 1500;

		dasa(0, 0);

		cout<<"Case #"<<t<<": ";
		if(vys == 1500)
			cout<<"NOT POSSIBLE";
		else 
			cout<<vys;
		cout<<endl;
	}
    return 0;
}