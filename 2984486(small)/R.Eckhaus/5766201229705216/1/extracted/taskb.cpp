#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template<class T>
ostream & operator<<(ostream& o, const vector<T>& v){ 
	for (auto i = v.begin(); i!=v.end(); ++i)
	{ o<<*i; if (i!=v.end()-1) o << " "; }
	return o;
}
int orez(int x, vector<vector<int>> & v, int pred){
	vector<int> vx;
	int sz = 0;
	for (int i=0; i<v[x].size(); i++){
		if ((v[x][i])!=pred)
			vx.push_back(v[x][i]);
	}
	if (vx.size()==2)
		return 1+orez(vx[0],v, x)+orez(vx[1],v, x);
	if (vx.size()<2)
		return 1;
	if (vx.size()>2){
		vector<int> p(0);
		for (int i=0; i<vx.size(); i++)
			p.push_back(orez(vx[i], v, x));
		sort(p.begin(), p.end());
		return p[vx.size()-1]+p[vx.size()-2]+1;
	}
}

int main(){
	int t; cin >> t;
	for (int ti = 0; ti < t; ti++){
		int n; cin >> n;
		vector<vector<int>> v (n+1, vector<int> (0));
		for (int i=0; i<n-1; i++){
			int xi,yi; cin >> xi >> yi;
			v[xi].push_back(yi);
			v[yi].push_back(xi);
		}
		int m = -1;
		for (int i= 1; i<=n; i++){
			int z = orez(i,v,-1);
			m = max(m, z);
		}
		cout << "Case #" << ti + 1 << ": " << n-m << endl;
	}
}

