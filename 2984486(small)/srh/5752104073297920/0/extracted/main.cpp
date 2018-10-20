#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

typedef uint64_t ul;
typedef size_t sz;

void build_table(std::vector<std::vector<double> > &table) {
    int N = table.size();
    for (int i = 0; i < N; ++i) {
        table.at(i).at(i) = 1.0;
    }

    double recip_N = 1.0 / N;
    double comp_recip_N = (N - 1.0) / N;

    std::vector<std::vector<double> > t2(N, std::vector<double>(N, 0.0));
    for (int k = 0; k < N; ++k) {
        // select unif rand from 0, N-1.
        // table[i][j] is probability a[i] holds j.
        for (int i = 0; i < N; ++i) {
            if (k == i) {
                for (int j = 0; j < N; ++j) {
                    // P(a[i] holds j after swap) = 1/N.
                    t2[i][j] = recip_N;
                }
            } else {
                // P(a[i] holds j after swap) = (N-1)/N * P(a[i] holds j before swap) + 1/N * P(a[k] holds j before swap).
                for (int j = 0; j < N; ++j) {
                    t2[i][j] = comp_recip_N * table[i][j] + recip_N * table[k][j];
                }
            }
        }

        std::swap(table, t2);
    }
}

int main() {
    int T;
    std::cin >> T;

    int expected_n = 1000;
    // table[i][j] probability a[i] ends up holding j.
    std::vector<std::vector<double> > table(expected_n, std::vector<double>(expected_n, 0.0));
    build_table(table);

    std::vector<double> scores;

    for (int casenum = 1; casenum <= T; ++casenum) {
        int N;
        std::cin >> N;
        if (expected_n != N) {
            std::cerr << "N was wrong value!  " << N << "\n";
            return 1;
        }
        std::vector<int> p;

        for (int i = 0; i < N; ++i) {
            int x;
            std::cin >> x;
            p.push_back(x);
        }

        // Ugh, this math is fake, let's hope it works.

        double norm_prob = 1.0;
        for (int i = 0; i < N; ++i) {
            // p[i] holds p[i].
            norm_prob *= table[i][p[i]];
            norm_prob *= N;
        }

        scores.push_back(norm_prob);
    }

    std::vector<double> sorted_scores = scores;
    std::sort(sorted_scores.begin(), sorted_scores.end());

    double cutoff = sorted_scores[T / 2];

    std::cerr << "cutoff: " << cutoff << "\n";
    for (int casenum = 1; casenum <= T; ++casenum) {
        std::cerr << "for #" << casenum << ":  " << scores[casenum-1] << "\n";
        std::cout << "Case #" << casenum << ": ";
        if (scores[casenum - 1] <= cutoff) {
            std::cout << "GOOD" << std::endl;
        } else {
            std::cout << "BAD" << std::endl;
        }
    }
}
