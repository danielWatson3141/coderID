#include <cstdio>
#include <vector>
#include <set>
#define MAX_NODES 1010

int num_tasks;
int num_nodes;

int num_killed;
int root;

std::vector<int> adj_list[MAX_NODES];
int degree[MAX_NODES];
bool alive[MAX_NODES];

struct subtree {
    int weight;
    int parent;
    int node;
    bool operator<(const subtree& other) const {
        return weight < other.weight;
    }
};

std::set<subtree> to_kill;

void kill(int node, int parent);
void kill_degree_2(int node, int parent);
int subtree_weight(int node, int parent);

int main() {
    scanf("%d", &num_tasks);
    for (int t = 0; t < num_tasks; ++t) {
        scanf("%d", &num_nodes);
        for (int i = 1; i <= num_nodes; i++) {
            degree[i] = 0;
            alive[i] = true;
            adj_list[i].clear();
        }
        for (int i = 0; i < num_nodes-1; i++) {
            int from, to;
            scanf("%d %d", &from, &to);
            adj_list[from].push_back(to);
            adj_list[to].push_back(from);
            degree[from]++;
            degree[to]++;
        }

        num_killed = 0;
        
        for (int n = 1; n <= num_nodes; n++) {
            if (!alive[n]) continue;
            to_kill.clear();
            for (int i = 0; i < adj_list[n].size(); i++) {
                if (alive[adj_list[n][i]]) {
                    subtree s;
                    s.weight = subtree_weight(adj_list[n][i], n);
                    s.node = adj_list[n][i];
                    s.parent = n;
                    to_kill.insert(s);
                }
            }
            while (to_kill.size() > 3) {
                num_killed += to_kill.begin()->weight;
                kill(to_kill.begin()->node, n);
                to_kill.erase(*to_kill.begin());
                degree[n]--;
            }
        }

        to_kill.clear();
        
        for (int n = 1; n <= num_nodes; n++) {
            if (degree[n] != 2 || !alive[n]) continue;
            subtree m;
            m.weight = 10000000;
            for (int i = 0; i < adj_list[n].size(); i++) {
                if (alive[adj_list[n][i]]) {
                    subtree s;
                    s.weight = subtree_weight(adj_list[n][i], n);
                    s.node = adj_list[n][i];
                    s.parent = n;
                    if (s.weight < m.weight) {
                        m = s;
                    }
                }
            }
            to_kill.insert(m);
            //printf("%d %d %d\n", m.weight, m.parent, m.node);
        }

        if (to_kill.size() == 0) {
            num_killed++;
        } else {
            root = to_kill.rbegin()->parent;
            //printf("%d\n", root);
            for (int i = 0; i < adj_list[root].size(); i++) {
                if (alive[adj_list[root][i]]) {
                    kill_degree_2(adj_list[root][i], root);
                }
            }
        }
        
        printf("Case #%d: %d\n", t+1, num_killed);
    }
    
    return 0;
}

void kill_degree_2(int node, int parent) {
    for (int i = 0; i < adj_list[node].size(); i++) {
        if (adj_list[node][i] != parent &&
            alive[adj_list[node][i]]) {
            kill_degree_2(adj_list[node][i], node);
        }
    }
    
    if (degree[node]-1 == 0 && degree[parent] == 2 && parent != root) {
        num_killed++;
        degree[parent]--;
    }
}

void kill(int node, int parent) {
    alive[node] = false;
    for (int i = 0; i < adj_list[node].size(); i++) {
        if (adj_list[node][i] != parent && alive[adj_list[node][i]]) {
            kill(adj_list[node][i], node);
        }
    }
}

int subtree_weight(int node, int parent) {
    int total = 1;
    for (int i = 0; i < adj_list[node].size(); i++) {
        if (adj_list[node][i] != parent && alive[adj_list[node][i]]) {
            total += subtree_weight(adj_list[node][i], node);
        }
    }
    return total;
}
