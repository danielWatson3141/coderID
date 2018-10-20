#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<bool> vb;

const int inf=1000000000;

int n,l;
vector<string>data1,data2;
vector<string>temp;
vb state;
int best;

void calc(int x,int used);
void flip(char &ch);

int main() {
	int cases;
	cin>>cases;
	for(int round=1; round<=cases; round++) {
		cin>>n>>l;
		data1.resize(n);
		for(int i=0; i<n; i++)
			cin>>data1[i];
		data2.resize(n);
		for(int i=0; i<n; i++)
			cin>>data2[i];
		best=inf;
		state.assign(l,false);
		sort(data1.begin(),data1.end());
		calc(0,0);
		cout<<"Case #"<<round<<": ";
		if(best==inf)
			cout<<"NOT POSSIBLE\n";
		else
			cout<<best<<'\n';
	}
	return 0;
}

void calc(int x,int used) {
	if(used>=best)
		return;
	if(x==l) {
		temp=data2;
		for(int i=0; i<l; i++) {
			if(state[i]) {
				for(int j=0; j<n; j++) {
					flip(temp[j][i]);
				}
			}
		}
		sort(temp.begin(),temp.end());
		if(data1==temp)
			best=used;
	} else {
		state[x]=false;
		calc(x+1,used);
		state[x]=true;
		calc(x+1,used+1);
	}
}

void flip(char &ch) {
	if(ch=='0')
		ch='1';
	else
		ch='0';
}
