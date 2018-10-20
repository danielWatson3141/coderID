#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#include <functional>
#include <numeric>

using namespace std;


#define N_MAX 1000

unsigned char M[N_MAX][N_MAX];
unsigned char Mt[N_MAX][N_MAX];

int delete_cost(int root, int N, deque<bool>& checked)
{
    int cost = 1;

    checked[root] = true;

    for (int i = 0; i < N; i++) {
        if (M[root][i] && !checked[i]) {
            cost += delete_cost(i, N, checked);
        }
    }
    return cost;
}

int sum_cost(int root, int N, deque<bool>& checked)
{
    checked[root] = true;

    vector<int> children;
    for (int i = 0; i < N; i++) {
        if (M[root][i] && !checked[i]) children.push_back(i);
    }

    if (children.empty()) return 0; // leaf

    if (children.size() == 1) {
        return delete_cost(children[0], N, checked); // delete child
    }

    // select 2
    vector<int> costs, num;
    for (int i = 0; i < children.size(); i++) {
        deque<bool> c(checked);
        costs.push_back(sum_cost(children[i], N, c));
        num.push_back(delete_cost(children[i], N, deque<bool>(checked)));
    }

    int cost_min = N + 1;
    int sumdel = accumulate(num.begin(), num.end(), 0);
    for (int i = 0; i < children.size(); i++) {
        for (int j = i + 1; j < children.size(); j++) {
            int cost = costs[i] + costs[j] + sumdel - num[i] - num[j];
            cost_min = min(cost, cost_min);
        }
    }

    return cost_min;
}

int min_cut_fromi(int N, int root)
{
    deque<bool> checked(N, false);
    return sum_cost(root, N, checked);
}

int solve(int N)
{
    for (int i = 0; i < N; i++) {
        if (count(M[i], M[i + 1], 1) == 0) {
            return N - 1;
        }
    }

    int r = N + 1;
    for (int i = 0; i < N; i++) {
        int t = min_cut_fromi(N, i);
        r = min(t, r);
    }
    return r;
}


int main(void) {
    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {

        memset(M, 0, N_MAX*N_MAX);

        int N;
        cin >> N;
        for (int j = 0; j < N - 1; j++) {
            int p, q;
            cin >> p >> q;
            M[p-1][q-1] = M[q-1][p-1] = 1;
        }
        int n = solve(N);
        printf("Case #%d: %d\n", i + 1, n);
    }
}