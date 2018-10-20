#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;


int main() {
	
	FILE* fin = fopen("A-large.in", "r");
	FILE* fout = fopen("output.txt" ,"w");

	int cn = 0;
	fscanf(fin, "%d", &cn);

	for(int t = 1; t <= cn; ++t) {
		int ans = -1;
		int n, l;

		fscanf(fin, "%d%d", &n, &l);

		vector<string> src;
		vector<string> dest;
		set<string> pool;

		for(int i = 0; i < n; i++) {
			char s[64];
			fscanf(fin, "%s", s);
			string temp(s);
			src.push_back(temp);
		}

		for(int i = 0; i < n; i++) {
			char s[64];
			fscanf(fin, "%s", s);
			string temp(s);
			dest.push_back(temp);
			pool.insert(temp);
		}

		string god = src[0];

		for(int i = 0; i < n; i++) {
			string theone = dest[i];

			bool flag[64];
			memset(flag, 0, sizeof(flag));

			int step = 0;
			for(int j = 0; j < god.size(); j++) {
				if (god[j] != theone[j]) {
					flag[j] = 1;
					step ++;
				}
			}

			bool found = true;
			for(int j = 0; j < n; j++) {
				char s[64];
				strcpy(s, src[j].c_str());

				for(int k = 0; k<god.size(); k++) {
					if (flag[k]) {
						if (s[k] == '0')
							s[k] = '1';
						else s[k] = '0';
					}
				}
				string cur(s);

				if (pool.find(cur) == pool.end()) {
					found = false;
					break;
				}
			}

			if (found) {
				if (ans == -1 || step < ans) {
					ans = step;
				}
			}
		}
		
		

		fprintf(fout, "Case #%d: ", t);
		if (ans == -1) {
			fprintf(fout, "NOT POSSIBLE\n");
		} else {
			fprintf(fout, "%d\n", ans);
		}
	}
	fclose(fin);
	fclose(fout);
}