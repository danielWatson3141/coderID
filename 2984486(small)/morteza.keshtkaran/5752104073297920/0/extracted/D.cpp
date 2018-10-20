#include<time.h>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int>	p;
vector<int> all[120];

int res[120] = {0};
int lis[1010] = {0};

string str[2]={"BAD","GOOD"};



int main(){

	srand(time(NULL));

	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);

	int ntc,n;
	cin >> ntc;
	vector<pair<int,int> > r;
	for (int tc=0;tc<ntc;tc++){
		

		cin >> n;
		all[tc].resize(n);
		for (int i=0;i<n;i++) cin >> all[tc][i];
		memset(lis,0,sizeof(lis));
		for (int i=0;i<n;i++){
			lis[i] = 1;
			for (int j=0;j<i;j++) if (all[tc][j]<all[tc][i]) lis[i] = max(lis[i],lis[j]+1);
		}
		int t = 0;
		for (int i=0;i<n;i++) t = max(t,lis[i]);
		r.push_back(make_pair(t,tc));
	}

	sort(r.begin(),r.end());
	for (int i=0;i<ntc/2;i++) res[r[i].second] = 1;


	for (int tc=1;tc<=ntc;tc++){
		cout << "Case #" << tc << ": " << str[res[tc-1]] << endl;
	}

	return 0;
}