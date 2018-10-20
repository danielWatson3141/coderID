#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

typedef struct node
{
    vector<int> neighbors;
    int id;
} node;

vector<bool> done;
vector<node *> graph;

map< pair<int, int>, int > hm;
map< pair< pair<int, int>, bool >, int > cu;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int trythis();
int cleanup(int id, int dont, bool spec);
int howmany(int id, int dont);

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    for (int _t = 0; _t < t; _t++)
    {
        int n;
        cin >> n;
        done.resize(n);
        hm.clear();
        cu.clear();
        graph.clear();
        for (int i = 0; i < n; i++)
        {
            node *n = new node;
            n->id = i + 1;
            done[i] = false;
            graph.push_back(n);
        }
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x - 1]->neighbors.push_back(y);
            graph[y - 1]->neighbors.push_back(x);
        }

        printf("Case #%d: %d\n", _t + 1, trythis());

        for (int i = 0; i < n; i++)
            delete graph[i];
    }
}

int trythis() {
    int min = cleanup(1, -1, true);
    for (int i = 2; i <= graph.size(); i++)
    {
        if (min <= 0) break;
        int c = cleanup(i, -1, true);
        if (c < min) {
            min = c;
        }
    }
    return min;
}

int cleanup(int id, int dont, bool spec) {

    // printf("cleanup %d %d %d\n", id, dont, spec ? 1 : 0);
    if (id == dont) return 0;
    if (cu.find(make_pair(make_pair(id, dont), spec)) != cu.end())
    {
        return cu[make_pair(make_pair(id, dont), spec)];
    }
    node *n = graph[id - 1];
    int c = 0;
    if (n->neighbors.size() == (spec ? 0 : 1)) {
        // printf("ZERO AT LINE %d\n", __LINE__);
        return 0;
    }

    if (n->neighbors.size() == (spec ? 1 : 2)) {
        int m = (n->neighbors[0] == dont ? 0 :
                howmany(n->neighbors[0], id)) +
            (spec || n->neighbors[1] == dont ? 0 :
                howmany(n->neighbors[1], id));
        // printf("m = %d\n", m);
        cu[make_pair(make_pair(id, dont), spec)];
        return m;
    }

    vector< pair<int, int> > trials(n->neighbors.size());
    for (int i = 0; i < n->neighbors.size(); i++) {
        if (n->neighbors[i] != dont)
            trials[i] = make_pair(n->neighbors[i],
                howmany(n->neighbors[i], id) -
                cleanup(n->neighbors[i], id, false));
        else
            trials[i] = make_pair(n->neighbors[i], 10000000);
    }

    sort(trials.begin(), trials.end(), cmp);
    if (spec) { // take 2
        for (int i = 0; i < trials.size() - 2; i++)
            c += howmany(trials[i].first, id);
        c += cleanup(trials[trials.size() - 2].first, id, false);
        c += cleanup(trials[trials.size() - 1].first, id, false);
    } else { // take 3
        for (int i = 0; i < trials.size() - 3; i++)
            c += howmany(trials[i].first, id);
        for (int i = 1; i <= 3; i++)
            if (trials[trials.size() - i].second != 10000000)
                c += cleanup(trials[trials.size() - i].first, id, false);

    }
    // printf("cleanup %d %d %d\n", id, dont, spec ? 1 : 0);

    // printf("c = %d\n", c);

    cu[make_pair(make_pair(id, dont), spec)] = c;

    return c;
}

int howmany(int id, int dont) {
    // printf("howmany %d %d\n", id, dont);
    if (hm.find(make_pair(id, dont)) != hm.end())
        return hm[make_pair(id, dont)];
    if (id == dont) return 0;
    node *n = graph[id - 1];
    int c = 0;
    for (vector<int>::iterator it = n->neighbors.begin();
            it != n->neighbors.end(); ++it) {
        if (*it != dont)
            c += howmany(*it, id);
    }
    // printf("howmany %d %d\n", id, dont);
    // printf("%d\n", 1 + c);
    hm[make_pair(id, dont)] = 1 + c;
    return 1 + c; // for node [id]
}
