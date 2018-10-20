#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define		INF		200

vector<string> res;
vector<string> out;
vector<string> dev;

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);

	int ntc,n,l;
	cin >> ntc;
	for (int tc=1;tc<=ntc;tc++){
		cout << "Case #" << tc << ": ";
		cin >> n >> l;
		out.resize(n);
		dev.resize(n);
		for (int i=0;i<n;i++) cin >> out[i];
		for (int i=0;i<n;i++) cin >> dev[i];
		sort(dev.begin(),dev.end());
		int best = INF,b;
		for (int i=0;i<n;i++){
			res = out;
			b = 0;
			for (int k=0;k<l;k++){
				if (res[i][k]!=dev[0][k]){
					b++;
					for (int r=0;r<n;r++)
						res[r][k] = '1'-res[r][k]+'0';
				}
				if (b>best) break;
			}
			if (b>best) continue;
			sort(res.begin(),res.end());
			if (res == dev) best = min(best,b);
		}

		if (best == INF) cout << "NOT POSSIBLE" << endl;
		else cout << best << endl;

	}

	return 0;
}