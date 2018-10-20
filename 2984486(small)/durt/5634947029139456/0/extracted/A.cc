#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 100000

int N, L;
vector<string> outlets;
vector<string> devs;

string get_switch_config(string dev, string outlet) {
	string res = "";
	for (int i = 0; i < L; i++) {
		int xord = dev[i] ^ outlet[i];
		res += (char)('0' + xord);
	}
	return res;
}

int count_flips(string config) {
	int res = 0;
	for (int i = 0; i < L; i++)
		if (config[i] == '1')
			res++;
	return res;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> N >> L;
		int i, j;
		string tmp;
		outlets.clear();
		devs.clear();
		for (i = 0; i < N; i++) {
			cin >> tmp;
			outlets.push_back(tmp);
		}
		for (i = 0; i < N; i++) {
			cin >> tmp;
			devs.push_back(tmp);
		}
		     // devid,config ,outletid
		map<pair<int,string>,int> dev2out; //map an dev,switch_config pair to an outlet
		//for each pair, consider switch configuration (N^2)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				string switch_config = get_switch_config(devs[i], outlets[j]);
				pair<int,string> key = pair<int,string>(i, switch_config);
				dev2out.insert(pair<pair<int,string>,int>(key, j));
			}
		
		int res = INF;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				string switch_config = get_switch_config(devs[i], outlets[j]);
				int nfound = 0;
				for (int k = 0; k < N; k++) {
					if (dev2out.end() == dev2out.find(pair<int,string>(k, switch_config)))
						break;
					nfound++;
				}
				if (nfound == N) {
					//count number of flips.. see if best solution
					int nflips = count_flips(switch_config);
					res = min(res, nflips);
				}
			}
		
		cout << "Case #" << icase << ": ";
		if (res == INF)
			cout << "NOT POSSIBLE";
		else
			cout << res;
		cout << endl;
	}
	return 0;
}
