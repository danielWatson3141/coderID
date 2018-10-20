#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("in.in");
    ofstream ofs("out.out");

    int T;
    ifs >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        int L;

        ifs >> N >> L;

        vector<string> provided;
        vector<string> needed;
        string input;
        for (int i = 0; i < N; ++i) {
            ifs >> input;
            provided.push_back(input);
        }
        for (int i = 0; i < N; ++i) {
            ifs >> input;
            needed.push_back(input);
        }

        char *status = (char *)calloc(L, sizeof(char));

        int minCount = 0;
        for (int i = 0; i < L; ++i) {
            int p1 = 0;
            int n1 = 0;
            for (int j = 0; j < N; ++j) {
                char p = provided[j][i];
                char n = needed[j][i];

                if (p == '1') ++p1;
                if (n == '1') ++n1;
            }

            if (p1 == n1) {
                if (N - p1 != p1) {
                    status[i] = '0';
                } else {
                    status[i] = '2';
                }
            } else if (N == p1 + n1) {
                status[i] = '1';
            } else {
                minCount = INT_MAX;
                break;
            }
        }

        if (minCount != INT_MAX) {
            minCount = INT_MAX;

            int v = 1;
            for (int i = 0; i < L; ++i) {
                if (status[i] == '2') {
                    v *= 2;
                }
            }

            vector<string> statuses;
            statuses.resize(v);
            int vc = v;
            for (int i = 0; i < L; ++i) {
                if (status[i] != '2') {
                    for (int j = 0; j < v; ++j) {
                        statuses[j].push_back(status[i]);
                    }
                } else {
                    for (int j = 0; j < v; ++j) {
                        if ((j % vc) / (vc / 2) == 0) {
                            statuses[j].push_back('0');
                        } else {
                            statuses[j].push_back('1');
                        }
                    }
                    vc /= 2;
                }
            }

            for (int i = 0; i < v; ++i) {
                string theStatus = statuses[i];

                vector<string> processed;
                for (int j = 0; j < N; ++j) {
                    string p = provided[j];
                    for (int k = 0; k < L; ++k) {
                        if (theStatus[k] == '1') {
                            if (p[k] == '0') {
                                p[k] = '1';
                            } else {
                                p[k] = '0';
                            }
                        }
                    }
                    processed.push_back(p);
                }

                char *used = (char *)calloc(N, sizeof(char));
                bool valid = true;
                for (int j = 0; j < N && valid; ++j) {
                    string n = needed[j];
                    valid = false;
                    for (int k = 0; k < N; ++k) {
                        if (used[k] == 1) {
                            continue;
                        }

                        string p = processed[k];
                        if (n == p) {
                            used[k] = 1;
                            valid = true;
                            break;
                        }
                    }
                }
                free(used);

                if (valid) {
                    int theCount = 0;
                    for (int j = 0; j < L; ++j) {
                        if (theStatus[j] == '1') {
                            ++theCount;
                        }
                    }

                    if (theCount < minCount) {
                        minCount = theCount;
                    }
                }
            }
        }

        ofs << "Case #" << t << ": ";
        if (minCount == INT_MAX) {
            ofs << "NOT POSSIBLE" << endl;
        } else {
            ofs << minCount << endl;
        }

        free(status);
    }

    return 0;
}
