#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define DPF(fmt,...) printf(fmt,##__VA_ARGS__); fprintf(outf, fmt,##__VA_ARGS__);
const int MAX_STR = 2000;
#define CV(vec, type, x) vector<type> vec; vec.resize(x);
#define CV2(vec, type, x, y) vector<vector<type>> vec; vec.resize(y); for(int i = 0; i < y; i++) {vec[i].resize(x);}
#define RI(val) int val = 0; scanf("%d", &val);
#define RF(val) float val = 0.0f; scanf("%f", &val);
#define RS(val) string val; {char str[2000]; scanf("%s", str); val = str;}
#define RC(val) char val = 0; scanf("%c", &val);
#define RL(val) string val; {char str[MAX_STR]; fgets(str, MAX_STR, stdin); int len = strlen(str); str[len - 1] = '\0'; val = str;}
#define RNL() {char str[MAX_STR]; fgets(str, MAX_STR, stdin);}
#define RLI(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {int val; scanf("%d", &val); (vec)[ii] = val;} RNL();}
#define RLF(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {float val; scanf("%f", &val); (vec)[ii] = val;} RNL();}
#define RLS(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {char val[MAX_STR]; scanf("%s", val); (vec)[ii] = val;} RNL();}
#define RLC(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {char val; scanf("%c", &val); (vec)[ii] = val;} RNL();}

struct Node
{
    int val;
    Node* edges[1000];
    int edgect;
};

struct FileNodes
{
    int l;
    int r;
};

int numNodes;

FileNodes fnodes[1000];
bool fnodes_used[1000];
Node* tree;
Node nodelist[1001];

void InitList()
{
    for (int i = 0; i < 1001; i++)
    {
        nodelist[i].val = i;
        for (int j = 0; j < 1000; j++)
        {
            nodelist[i].edges[j] = NULL;
        }
        nodelist[i].edgect = 0;
    }
}

bool FindNode(Node* node, int n)
{
    for (int i = 0; i < numNodes; i++)
    {
        if ((fnodes[i].l == n ||
            fnodes[i].r == n) &&
            fnodes_used[i] == false)
        {
            int val = (fnodes[i].l == n) ? fnodes[i].r : fnodes[i].l;
            fnodes_used[i] = true;
            for (int i = 0; i < 1000; i++)
            {
                if (node->edges[i] == NULL)
                {
                    node->edges[i] = &nodelist[val];
                    node->edgect++;
                    FindNode(node->edges[i], val);
                    break;
                }
            }
        }
    }
    return true;
}

int CountTree(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    int count = 1;
    for (int i = 0; i < 1000; i++)
    {
        count += CountTree(node->edges[i]);
    }
    return count;
}

bool Rooted(Node* node)
{
    if (node == NULL)
    {
        return false;
    }
    if (node->edgect == 0)
    {
        return true;
    }
    else if (node->edgect == 2)
    {
        bool rooted = false;
        for (int i = 0; i < 1000; i++)
        {
            if (Rooted(node->edges[i]))
            {
                rooted = true;
            }
        }
        return rooted;
    }
    return false;
}

void CheckTree(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    if (node->edgect == 2)
    {
        for (int i = 0; i < 1000; i++)
        {
            CheckTree(node->edges[i]);
        }
    }
    else
    {
        while (node->edgect > 0 && node->edgect != 2)
        {
            int mincount = INT_MAX;
            int minnodeindex = -1;
            for (int i = 0; i < 1000; i++)
            {
                if (node->edges[i] == NULL) continue;
                int ct = CountTree(node->edges[i]);
                if (ct < mincount)
                {
                    mincount = ct;
                    minnodeindex = i;
                }
            }
            node->edgect--;
            node->edges[minnodeindex] = NULL;
        }
        for (int i = 0; i < 1000; i++)
        {
            CheckTree(node->edges[i]);
        }
    }
}

bool ReadTreeWithRoot(int n)
{
    int numused = 0;
    for (int i = 0; i < numNodes; i++)
    {
        fnodes_used[i] = false;
    }
    tree = &nodelist[n];
    return FindNode(tree, n);
}

int main()
{
    FILE* inf = freopen("in.txt", "r", stdin);
    FILE* outf = fopen("out.txt", "w");
    RI(np); RNL();
    for (int pp = 1; pp <= np; pp++)
    {
        DPF("Case #%d: ", pp);
        RI(N); RNL();

        numNodes = N - 1;

        InitList();

        tree = NULL;
        for (int i = 0; i < N - 1; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r); RNL();
            fnodes[i].l = l;
            fnodes[i].r = r;
        }

        int min = INT_MAX;
        for (int i = 1; i <= N; i++)
        {
            InitList();
            if (!ReadTreeWithRoot(i))
            {
                continue;
            }
            CheckTree(tree);
            int c = N - CountTree(tree);
            if (c < min)
            {
                min = c;
            }
        }
        DPF("%d\n", min);
    }
    fclose(inf);
    fclose(outf);
}