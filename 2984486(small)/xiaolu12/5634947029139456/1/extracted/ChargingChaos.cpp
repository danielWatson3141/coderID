#include <fstream>

#define NMAX 151
#define LMAX 41

using namespace std;

char strs[NMAX][LMAX];
char change[NMAX][LMAX];
char outs[NMAX][NMAX];

bool flag[LMAX];
int n, l;
int minl;

ifstream cin;
ofstream cout;
void check(){
	int count = 0;
	char ch = '1'+'0';
	for(int i=0; i<l; ++i){
		if(flag[i]){
			count++;
		}
		for(int j=0; j<n; ++j){
			if(!flag[i]){
				change[j][i] = strs[j][i];
			}else{
				change[j][i] = ch-strs[j][i];
			}
		}
	}
	//cout<<"temp"<<endl;
	for(int j=0; j<n; ++j){
		change[j][l] = '\0';
		//cout<<change[j]<<endl;
	}
	for(int i=0; i<n; ++i){
		bool f = false;
		for(int j=0; j<n; ++j){
			if(strcmp(change[i], outs[j])==0){
				f = true;
			}
		}
		if(!f){
			return ;
		}
	}
	if(minl > count){
		minl = count;
	}
}
/*
void search(int k){
	if(k >= l){
		check();
		return;
	}
	flag[k] = false;
	search(k+1);
	flag[k] = true;
	search(k+1);
	flag[k] = false;
}*/

void search(){
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			for(int k=0; k<l; ++k){
				if(strs[i][k] == outs[j][k]){
					flag[k] = false;
				}else{
					flag[k] = true;
				}
			}
			check();
		}
	}
}

int main()
{
	cin.open("A-large.in");
	cout.open("A-large.out");
	int t;
	cin>>t;
	//t = 1;
	for(int i=1; i<=t; ++i){
		cin>>n>>l;
		for(int j=0; j<n; ++j){
			cin>>strs[j];
		}
		for(int j=0; j<n; ++j){
			cin>>outs[j];
		}
		minl = l+1;
		search();
		if(minl == l+1){
			cout<<"Case #"<<i<<": NOT POSSIBLE"<<endl;
		}else{
			cout<<"Case #"<<i<<": "<<minl<<endl;
		}
	}
	return 0;
}