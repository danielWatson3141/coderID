#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Node
{
    Node(int id) : id(id), edges() {}
    int id;
    vector<Node*> edges;
    int count_subtree(int fromEdge)
    {
        int count = 1;
        for (auto node : edges)
        {
            if (node->id != fromEdge)
            {
                count += node->count_subtree(id);
            }
        }
        return count;
    }
    int how_many_prune(int fromEdge)
    {
        //cerr << "how_many_prune[" << id << "] from " << fromEdge << endl;
        int N = int(edges.size());
        bool iAmRoot = fromEdge == 0;
        int childCount = iAmRoot ? N : N - 1;
        if (childCount == 0)
        {
            //cerr << "no children, no prune" << endl;
            return 0;
        }
        if (childCount == 1)
        {
            Node *child = nullptr;
            if (iAmRoot)
            {
                child = edges[0];
            }
            else
            {
                child = (edges[0]->id == fromEdge) ? edges[1] : edges[0];
            }
            //cerr << "1 child, prune the full subtree of child:" << child->id
            //     << ", that is, " << child->count_subtree(id) << " nodes"
            //     << endl;
            return child->count_subtree(id);
        }
        //cerr << "at least 2 children, do the full thing" << endl;
        vector<pair<int,Node*>> prune_counts;
        for (int i = 0; i < N; i++)
        {
            if (edges[i]->id == fromEdge)
            {
                continue;
            }
            int count = edges[i]->how_many_prune(id);
            prune_counts.push_back(make_pair(count, edges[i]));
        }
        sort(prune_counts.begin(), prune_counts.end());
        int sum = 0;
        sum += prune_counts[0].first;
        sum += prune_counts[1].first;
        for (int i = 2; i < int(prune_counts.size()); i++)
        {
            sum += prune_counts[i].second->count_subtree(id);
        }
        return sum;
    }
};

int solve()
{
    int N;
    cin >> N;
    Node* nodes[1000];
    for (int i = 0; i < N; i++)
    {
        nodes[i] = new Node(i+1);
    }
    for (int i = 0; i < N-1; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes[x-1]->edges.push_back(nodes[y-1]);
        nodes[y-1]->edges.push_back(nodes[x-1]);
    }

    vector<int> counts;
    for (int i = 0; i < N; i++)
    {
        counts.push_back(nodes[i]->how_many_prune(0));
    }
    sort(counts.begin(), counts.end());

    for (int i = 0; i < N; i++)
    {
        delete nodes[i];
    }
    return counts[0];
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}

