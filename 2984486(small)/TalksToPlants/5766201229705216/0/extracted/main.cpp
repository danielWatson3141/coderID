#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;
bool connected[15][15];
bool deleted[15];
int best;
int parent[15];

bool check(int node, int del)
{
    //start at node and check children
    int nodesintree = n - del;
    vector<int> states;
    states.push_back(node);
    int visited = 0;
    parent[node] = -1;
    while (states.size() > 0) {
        vector<int> newstates;
        for (int i = 0; i < states.size(); i++) {
            visited++;
            int count = 0;
            for (int t = 0; t < n; t++) {
                if (t != parent[states[i]]) {
                    if (deleted[t] == false) {
                        if (connected[states[i]][t]) {
                            count++;
                            parent[t] = states[i];
                            newstates.push_back(t);
                        }
                    }
                }
            }
            if (count != 0) {
                if (count != 2) {
                    return false;
                }
            }
        }
        states = newstates;
    }
    if (visited < nodesintree) {
        return false;
    }
    return true;
}

void recursion(int on, int done)
{
    if (done >= best) {
        return;
    }
    if (on == n) {
        bool good = false;
        for (int i = 0; i < n; i++) {
            if (deleted[i] == false) {
                if (check(i, done)) {
                    good = true;
                    break;
                }
            }
        }
        if (good) {
            best = done;
        }
    } else {
        deleted[on] = false;
        recursion(on + 1, done);
        deleted[on] = true;
        recursion(on + 1, done + 1);
    }
}

int main()
{
    ifstream input;
    input.open("input.txt");
    ofstream output;
    output.open("output.txt");
    int t;
    input >> t;
    for (int i = 0; i < t; i++) {
        input >> n;
        for (int c = 0; c < n; c++) {
            for (int p = 0; p < n; p++) {
                connected[c][p] = false;
            }
        }
        int a, b;
        for (int x = 1; x < n; x++) {
            input >> a >> b;
            connected[a - 1][b - 1] = true;
            connected[b - 1][a - 1] = true;
        }
        best = n - 1;
        recursion(0 , 0);
        output << "Case #" << i + 1 << ": " << best << endl;
    }
    return 0;
}
