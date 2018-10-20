#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> II;
typedef std::vector<int> VI;
typedef std::vector<II> VII;
typedef std::vector<VI> VVI;
typedef std::vector<VII> VVII;

II cost(VVI &adj, int in, int from) {
    VII costs;
    int sum = 0;
    for(auto i : adj[in]) {
        if(i == from) continue;
        costs.push_back(cost(adj, i, in));
        sum += costs.back().second;
    }
    if(costs.size() < 2) return II(sum, sum+1);

    int best = 1<<20;
    for(int a = 0; a < costs.size(); a ++) {
        for(int b = 0; b < costs.size(); b ++) {
            if(a == b) continue;

            int cost = sum - costs[a].second - costs[b].second + costs[a].first + costs[b].first;
            best = std::min(best, cost);
        }
    }

    return II(std::min(best, sum),sum+1);
}

int main() {
    int T;
    std::cin >> T;
    int C = 1;
    while(T--) {
        int N;
        std::cin >> N;

        VVI adj(N, VI());
        for(int i = 0; i < N-1; i ++) {
            int x, y;
            std::cin >> x >> y;
            x --; y --;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int best = 1<<20;
        for(int r = 0; r < N; r ++) {
            auto c = cost(adj, r, -1);
            best = std::min(best, std::min(c.first, c.second));
        }

        std::cout << "Case #" << C << ": "; C ++;
        std::cout << best << std::endl;
    }
    return 0;
}
