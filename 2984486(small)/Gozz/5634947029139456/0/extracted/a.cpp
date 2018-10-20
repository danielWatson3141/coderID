#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define forl(i,a,b) for(int i = a; i < b; ++i)

int main()
{
	int numcases = 0;
	cin >> numcases;
	forl(casei, 0, numcases) {
		int ndevices, lencurr;
		cin >> ndevices >> lencurr;
		vector<string> devs(ndevices);
		vector<string> curs(ndevices);
		forl(i, 0, ndevices) {
			cin >> devs[i];
		}
		sort(devs.begin(), devs.end());
		forl(i, 0, ndevices) {
			cin >> curs[i];
		}
		int nswitches = 41;
		bool swcs[40];
		vector<string> mods(curs);
		forl(i, 0, ndevices) {
			int nsw = 0;
			forl(j, 0, lencurr) {
				if (devs[0][j] != curs[i][j]) {
					swcs[j] = true;
					nsw++;
				} else swcs[j] = false;
			}
			if (nsw >= nswitches) continue;
			forl(j, 0, ndevices) {
				forl(k, 0, lencurr) {
					if (swcs[k]) {
						if (curs[j][k] == '0') mods[j][k] = '1';
						else mods[j][k] = '0';
					} else mods[j][k] = curs[j][k];
				}
			}
			sort(mods.begin(), mods.end());
			/*forl(j, 0, lencurr) {
				if (swcs[j]) cout << '1';
				else cout << '0';
			}
			cout << endl;
			forl(j, 0, ndevices) cout << devs[j] << '\t' << mods[j] << endl;
			cout << endl;
			cout << nswitches << '\t' << nsw << '\t' << endl;
			forl(j, 0, lencurr) {
				if (swcs[j]) cout << '1';
				else cout << '0';
			}
			cout << endl;*/
			if (equal(mods.begin(), mods.end(), devs.begin())) nswitches = nsw;
		}
		if (nswitches == 41) {
			cout << "Case #" << (casei+1) << ": NOT POSSIBLE" << endl;
		} else {
			cout << "Case #" << (casei+1) << ": " << nswitches << endl;
		}
	}
	return 0;
}
