#include <iostream> 
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <deque>
#include <numeric>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-10;

int main()
{
	int t;
	int n, l;
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	fin >> t;
	for (int ti = 1; ti <= t; ti++) {
		fin >> n >> l;
	//	string s;
		string cur;
		set<string> a;
		vector<string> flow;
		for (int i=0; i<n; i++) {
			fin >> cur;
			a.insert(cur);
		}
		for (int i=0; i<n; i++) {
			fin >> cur;
			flow.push_back(cur);
		}
		int min = l + 1;
		for (int i=0; i < (1 << l); i++) {
			int count = 0;
			vector<string> cur_flow = flow;
			//set<string>::iterator it;
			for (int j=0; j < l; j++) {
				if (i & (1 << j)) {
					count++;
					for (int k=0; k < n; k++) {
						cur_flow[k][j] =(char) ((((int)(cur_flow[k][j] - '0') + 1) % 2) + '0');
					}
				}
			}
			set<string> cur_f(cur_flow.begin(), cur_flow.end());
			vector<string> inters;
			inters.resize(n+1);
			vector<string>::iterator it;
			it=set_intersection (a.begin(), a.end(), cur_f.begin(), cur_f.end(), inters.begin());
			inters.resize(it-inters.begin());
			if (inters.size() == n && count < min) {
				min = count;
			}
		}
		if ( min < l + 1) {
			fout << "Case #" << ti <<": " << min <<endl;
		} else {
			fout << "Case #" << ti <<": " << "NOT POSSIBLE" <<endl;
		}

	}

	fout.close();
	return 0;
}



