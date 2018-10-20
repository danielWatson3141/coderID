#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <list>

using namespace std;

list<string> swilist;

bool testSwi(list<string> ori, set<string> tar, string swi) {
	int chsum = '0' + '1';
	string tmp;
	for (list<string>::iterator it = ori.begin(); it != ori.end(); it++) {
		tmp = *it;
		for (int i = 0; i < swi.length(); i++) {
			if (swi[i] == '1')
				tmp[i] = chsum - tmp[i];
		}

		if (tar.count(tmp) > 0) {
			tar.erase(tmp);
		}
		else {
			return false;
		}
	}

	return true;
}

void getSwi(string swi, int pos, int num) {
	if (num <= 0) {
		swilist.push_back(swi);
		return;
	}

	if (pos >= swi.length())
		return;

	for (int i = pos; i < swi.length() - num + 1; i++) {
		swi[i] = '1';
		getSwi(swi, i + 1, num - 1);
		swi[i] = '0';
	}
}

int findRes(list<string> &ori, set<string> &tar, int len) {
	string res = "imp";
	string swi = "";
	swi.resize(len, '0');

	for (int i = 0; i <= len; i++) {
		swilist.clear();
		getSwi(swi, 0, i);

		for (list<string>::iterator it = swilist.begin(); it != swilist.end(); it++){
			if (testSwi(ori, tar, *it)) {
				return i;
			}
		}
	}

	return -1;
}

void chargechoas() {
	int T;
	int N, L;
	ofstream fileoutput("output.txt");
	ifstream fileinput("input.txt");

	int cnt = 0;
	fileinput >> T;

	string tmp;

	while (cnt < T) {
		fileinput >> N >> L;

		list<string> origin;
		set<string> target;

		for (int i = 0; i < N; i++) {
			fileinput >> tmp;
			origin.push_back(tmp);
		}

		for (int i = 0; i < N; i++) {
			fileinput >> tmp;
			target.insert(tmp);
		}

		string np = "NOT POSSIBLE";
		int r = findRes(origin, target, L);

		fileoutput << "Case #" << (cnt + 1) << ": ";
		if (r < 0)
			fileoutput << "NOT POSSIBLE";
		else
			fileoutput << r;
		fileoutput << endl;

		cnt++;
	}
}