#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include <pthread.h>

const bool MULTITHREADED = true;
const int NUM_WORKERS = 8;

using std::string;
using std::vector;

struct input_t {
    void read() {
        int n;
        std::cin >> n;
        graph.resize(n);
        for (int i = 0; i < n-1; i++) {
            int f, t;
            std::cin >> f >> t;
            f--; t--;
            graph[f].push_back(t);
            graph[t].push_back(f);
        }  
    }

    vector<vector<int> > graph;
};

struct output_t {
    void write(const int& case_number) {
        std::printf("Case #%d: %d\n", case_number, answer);
    }

    int answer;
};

int get_value(const vector<vector<int> >& graph, const int& root) {
    const int& n = (int)graph.size();

    vector<int> cost(n);
    vector<int> weight(n);
    vector<int> parent(n, -1);
    vector<int> procd(n, 0);
    vector<int> children(n, 0);

    std::stack<int> q;
    q.push(root);
    while (!q.empty()) {
        int curr = q.top(); q.pop();
        if (procd[curr] == 0) {
            for (int i = 0; i < (int)graph[curr].size(); i++)
                if (graph[curr][i] != parent[curr]) {
                    parent[graph[curr][i]] = curr;
                    q.push(graph[curr][i]);
                    children[curr]++;
                }
            
            if (!children[curr]) {
                cost[curr] = 0;
                weight[curr] = 1;
                if (parent[curr] != -1) {
                    procd[parent[curr]]++;
                    q.push(parent[curr]);
                }
            }
        } else if (procd[curr] == children[curr]) {
            weight[curr] = 0;
            for (int i = 0; i < (int)graph[curr].size(); i++)
                if (graph[curr][i] != parent[curr])
                    weight[curr] += weight[graph[curr][i]];
            weight[curr]++;

            if (graph[curr].size() == 1 + (curr != root)) {
                cost[curr] = weight[curr]-1;
            } else {
                int maxi = -1, maxv = 0;
                for (int i = 0; i < (int)graph[curr].size(); i++)
                    if (graph[curr][i] != parent[curr]) {
                        int cv = weight[graph[curr][i]] - cost[graph[curr][i]];
                        if (cv > maxv) {
                            maxv = cv;
                            maxi = i;
                        }
                    }

                int maxv2 = 0;
                for (int i = 0; i < (int)graph[curr].size(); i++)
                    if (i != maxi && graph[curr][i] != parent[curr]) {
                        int cv = weight[graph[curr][i]] - cost[graph[curr][i]];
                        if (cv > maxv2) maxv2 = cv;
                    }

                cost[curr] = weight[curr]-1 - maxv - maxv2;
            }

            if (parent[curr] != -1) {
                procd[parent[curr]]++;
                q.push(parent[curr]);
            }
        }
    }

    return cost[root];
}

output_t solve(const input_t& input) {
    output_t ret;
    ret.answer = 0x0FFFFFFF;

    const vector<vector<int> >& graph = input.graph;
    const int& n = graph.size();

    for (int root = 0; root < n; root++) {
        int curr = get_value(graph, root);

        if (curr < ret.answer)
          ret.answer = curr;
    }

    return ret;
}

struct environment {
    environment(const vector<input_t>& in, vector<output_t>& out)
        : input(in), output(out), task_queue() {

        for (int i = 0; i < (int)input.size(); i++) task_queue.push(i);
        pthread_mutex_init(&queue_mutex, NULL);
    }

    ~environment() {
        pthread_mutex_destroy(&queue_mutex);
    }

    const vector<input_t>& input;
    vector<output_t>& output;
    std::queue<int> task_queue;
    pthread_mutex_t queue_mutex;
};

void* worker_thread(void* _env) {
    environment& env = *(reinterpret_cast<environment*>(_env));

    while (true) {
        int task = -1;
        pthread_mutex_lock(&env.queue_mutex);
        if (!env.task_queue.empty()) {
            task = env.task_queue.front();
            env.task_queue.pop();
        }
        pthread_mutex_unlock(&env.queue_mutex);
    
        if (task == -1) break;

        env.output[task] = solve(env.input[task]);
    }

    return NULL;
}

void solve_all(const vector<input_t>& input, vector<output_t>& output) {
    environment env(input, output);

    vector<pthread_t> threads(NUM_WORKERS);
    for (int i = 0; i < NUM_WORKERS; i++)
        pthread_create(&(threads[i]), NULL, worker_thread, &env);

    for (int i = 0; i < NUM_WORKERS; i++)
        pthread_join(threads[i], NULL);
}

int main() {
    int tests;
    string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> tests;

    vector<input_t> input(tests);
    vector<output_t> output(tests);
    for (int i = 0; i < tests; i++)
        input[i].read();

    if (MULTITHREADED)
        solve_all(input, output);
    else 
        for (int i = 0; i < tests; i++)
            output[i] = solve(input[i]);

    for (int i = 0; i < tests; i++)
        output[i].write(i+1);

    return 0;
}
