#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool eq(vector <string> vs1, vector <string> vs2) {
	sort(vs1.begin(), vs1.end());
	sort(vs2.begin(), vs2.end());
	for (int i=0; i<vs1.size(); i++)
		if (vs1[i]!=vs2[i])
			return false;
	return true;
}

int nr(int i) {
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

void solve(int N, int L, vector <string> vs1, vector <string> vs2) {
	int mn = 1<<30;
	for (int i=0; i<1<<L; i++) {
		vector <string> t1 = vs1;
		for (int j=0; j<t1.size(); j++)
			for (int k=0; k<L; k++)
				if (i&1<<k)
					t1[j][k] = (t1[j][k]=='0' ? '1' : '0');
		if (eq(vs2,t1))
			mn = min(mn, nr(i));
	}
	if (mn==1<<30)
		cout << "NOT POSSIBLE";
	else
		cout << mn;
}

int main() {
    freopen("A-small-attempt0.in", "rt", stdin);
    freopen("A-small.out", "wt", stdout);
    //freopen("A-large.in", "rt", stdin);
    //freopen("A-large.out", "wt", stdout);
   
    int T,N,L;
    cin>>T;

    for (int i=1; i<=T; i++) {
        cin >> N >> L;
		vector <string> vs1, vs2;
		string tmp;
        for (int n=0; n<N; n++) {
			cin >> tmp;
            vs1.push_back(tmp);
		}
        for (int n=0; n<N; n++) {
			cin >> tmp;
            vs2.push_back(tmp);
		}
        cout << "Case #" << i << ": ";
		solve(N, L, vs1, vs2);
		cout << endl;
    }
}