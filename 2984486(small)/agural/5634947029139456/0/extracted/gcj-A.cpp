/*
LANG: C++
ID: 2012agura1
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <ctime>

using namespace std;
FILE *fin  = fopen("a.in",  "r");
FILE *fout = fopen("gcj-a.out", "w");

int main () {
	int T, N, L;
	char str[80];

	fscanf(fin, "%d", &T);

    for(int t = 1; t <= T; t++) {
        vector<long long> xors;
        vector<long long> in;
        vector<long long> out;
        vector<pair<int, long long> > sols;

        fscanf(fin, "%d %d", &N, &L);

        for(int i = 0; i < N; i++) {
            fscanf(fin, "%s", &str);
            long long c = 0;
            int j = 0;
            while(str[j]) {
                c = c << 1;
                c += (str[j]-'0');
                j++;
            }
            in.push_back(c);
        }
        for(int i = 0; i < N; i++) {
            fscanf(fin, "%s", &str);
            long long c = 0;
            int j = 0;
            while(str[j]) {
                c = c << 1;
                c += (str[j]-'0');
                j++;
            }
            out.push_back(c);
        }
        sort(out.begin(), out.end());

        for(int i = 0; i < in.size(); i++) {
            for(int j = 0; j < out.size(); j++) {
                xors.push_back(in[i] ^ out[j]);
            }
        }

        /*for(int i = 0; i < in.size(); i++) {
            cout << in[i] << " ";
        } cout << endl;
        for(int i = 0; i < out.size(); i++) {
            cout << out[i] << " ";
        } cout << endl;
        for(int i = 0; i < xors.size(); i++) {
            cout << xors[i] << " ";
        } cout << endl;*/

        for(int x = 0; x < xors.size(); x++) {
            vector<long long> temp;
            for(int i = 0; i < in.size(); i++) {
                temp.push_back(xors[x] ^ in[i]);
            }
            sort(temp.begin(), temp.end());

            bool eq = true;
            for(int i = 0; i < out.size(); i++) {
                if(out[i] != temp[i]) {
                    eq = false;
                    break;
                }
            }

            if(eq) {
                int a = 0;
                long long b = xors[x];
                for(int i = 0; i < 64; i++) {
                    a += (b & 1);
                    b = b >> 1;
                }
                sols.push_back(make_pair(a,xors[x]));
            }
        }

        sort(sols.begin(), sols.end());

        /*if(sols.size()) {
            cout << "asdf: " << sols[0].first << " " << sols[0].second << endl;
        } else {
        cout << "BAH" << endl;
        }*/

        if(sols.size())
            fprintf(fout, "Case #%d: %d\n", t, sols[0].first);
        else
            fprintf(fout, "Case #%d: NOT POSSIBLE\n", t);
    }

	return 0;
}


