#include <algorithm>
#include <queue>
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
        int n, l;
        std::cin >> n >> l;
        outlets.resize(n);
        for (int i = 0; i < n; i++) {
            string s;
            std::cin >> s;
            outlets[i].resize(l);
            for (int j = 0; j < l; j++)
                outlets[i][j] = s[j] == '1';
        }

        devices.resize(n);
        for (int i = 0; i < n; i++) {
            string s;
            std::cin >> s;
            devices[i].resize(l);
            for (int j = 0; j < l; j++)
                devices[i][j] = s[j] == '1';
        }
    }

    vector<vector<bool> > outlets;
    vector<vector<bool> > devices;
};

struct output_t {
    void write(const int& case_number) {
        std::cout << "Case #" << case_number << ": ";
        if (answer == -1)
            std::cout << "NOT POSSIBLE";
        else std::cout << answer;
        std::cout << '\n';
    }

    int answer;
};

bool add1(vector<bool>& mask) {
    int i = 0;
    while (i < (int)mask.size() && mask[i]) mask[i++] = false;
    if (i == (int)mask.size()) return true;
    mask[i] = true;
    return false;
}

output_t solve(const input_t& input) {
    vector<vector<bool> > dev = input.devices;
    const int& n = (int)dev.size();
    const int& l = (int)dev[0].size();

    std::sort(dev.begin(), dev.end());

    int best = -1;

    vector<bool> mask(l, false);
    do {
        vector<vector<bool> > out = input.outlets;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < l; j++)
                out[i][j] = out[i][j] ^ mask[j];

        std::sort(out.begin(), out.end());
        if (out == dev) {
            unsigned int cnt = 0;
            for (int i = 0; i < l; i++)
                if (mask[i])
                    cnt++;

            if (cnt < (unsigned int)best) best = cnt;
        }
    } while (!add1(mask));

    output_t output;
    output.answer = best;
    return output;
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
