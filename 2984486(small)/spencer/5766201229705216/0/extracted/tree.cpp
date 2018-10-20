#include <cstdio>
#include <vector>
using namespace std;


#define MAX_N 1000


int N;
vector<int> edges[MAX_N];
int subtree_size[MAX_N];


void setup()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        edges[i].clear();

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}


void compute_subtree_size(int vertex, int parent)
{
    subtree_size[vertex] = 1;

    for (int i = 0; i < (int)edges[vertex].size(); i++)
    {
        int next = edges[vertex][i];
        if (next == parent) continue;

        compute_subtree_size(next, vertex);
        subtree_size[vertex] += subtree_size[next];
    }
}


int min_cost(int vertex, int parent)
{
    int delete_all = 0;
    int best = -1, second_best = -1;

    for (int i = 0; i < (int)edges[vertex].size(); i++)
    {
        int next = edges[vertex][i];
        if (next == parent) continue;

        delete_all += subtree_size[next];

        int difference = subtree_size[next] - min_cost(next, vertex);
        if (difference > best)
        {
            second_best = best;
            best = difference;
        }
        else if (difference > second_best)
            second_best = difference;
    }

    if (best != -1 && second_best != -1)
        return delete_all - best - second_best;
    else return delete_all;
}


int try_root(int root)
{
    compute_subtree_size(root, -1);

    return min_cost(root, -1);
}


void solve_case(int test_case)
{
    setup();

    int minimum = N - 1;
    for (int i = 0; i < N; i++)
        minimum = min(minimum, try_root(i));

    printf("Case #%d: %d\n", test_case, minimum);
}


int main()
{
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++)
        solve_case(t);

    return 0;
}
