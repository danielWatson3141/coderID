#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <clocale>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
using namespace std;

string was_str;
string need_str;
long long was[155];
long long need[155];

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    ios_base::sync_with_stdio(false);

    int test; cin >> test;
    for (int i = 0; i < test; i++) {
        int n, l; cin >> n >> l;
        for (int j = 0; j < n; j++) {
            cin >> was_str;
            long long num = 0;
            for (int k = 0; k < was_str.size(); k++) {
                if (was_str[k] == '1') num = num * 2LL + 1;
                else                   num = num * 2LL + 0;
            }
            was[j] = num;
        }
        for (int j = 0; j < n; j++) {
            cin >> need_str;
            long long num = 0;
            for (int k = 0; k < need_str.size(); k++) {
                if (need_str[k] == '1') num = num * 2LL + 1;
                else                    num = num * 2LL + 0;
            }
            need[j] = num;
        }
        map<long long, int> edges_count;
        for (int j = 0; j < n; j++) {
            set<long long> e;
            for (int k = 0; k < n; k++) {
                long long edge = was[j]^ need[k];
                e.insert(edge);
            }
            for (set<long long>::iterator it = e.begin(); it != e.end(); it++) {
                long long edge = *it;
                if (edges_count.find(edge) == edges_count.end())
                    edges_count[edge] = 1;
                else
                    edges_count[edge]++;
            }
        }
        sort(need, need + n);
        vector<long long> edges;
        for (map<long long, int>::iterator it = edges_count.begin(); it != edges_count.end(); it++) {
            if ((it->second) == n) edges.push_back((it->first));
        }
        vector<long long> edges_answer;
        for (int j = 0; j < edges.size(); j++) {
            long long current[155];
            memset(current, 0, sizeof(current));
            for (int k = 0; k < n; k++) {
                current[k] = was[k] ^ edges[j];
            }
            sort(current, current + n);
            bool ok = true;
            for (int k = 0; k < n && ok; k++) {
                if (current[k] == need[k]) ;
                else ok = false;
            }
            if (ok) edges_answer.push_back(edges[j]);
        }
        int answer = 1000000000;
        for (int j = 0; j < edges_answer.size(); j++) {
            if (edges_answer[j] == 0) answer = 0;
            int count = 0;
            for (long long bytiks = 1; bytiks < (1LL << 42LL); bytiks = bytiks << 1LL) {
                if (edges_answer[j] & bytiks) count++;
            }
            answer = min(answer, count);
        }
        cout << "Case #" << i + 1 <<": ";
        if (answer == 1000000000) cout << "NOT POSSIBLE";
        else cout << answer;
        cout << endl;
        cout.flush();
    }

    return 0;
}
