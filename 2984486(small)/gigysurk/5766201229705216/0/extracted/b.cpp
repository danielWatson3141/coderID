
#include <inttypes.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <tuple>
// #include <climits>
#define INT_MAX 99999

using namespace std;

struct node {
    int num;
    vector<node*> conn;
};

int count_children(node *n, node *parent)
{
    int count = 0;
    int k = n->conn.size();

    // cout << "(cc: " << n->num << " <- " << parent->num << ")";

    if (parent == NULL) 
        count += k;
    else
        count += k-1;

    // cout << "<cc: self " << count << ">";

    for (int i=0; i<n->conn.size(); ++i) {
        // cout << "<cc" << n->num << "->" << n->conn[i]->num << ": ";
        if (n->conn[i] != parent) {
            // cout << "do>";
            count += count_children(n->conn[i], n);
        }
        // else {
        //     cout << "not>";
        // }
    }

    // cout << "<cc:final " << count << ">";

    return count;
}

int make_binary(node *n, node *parent)
{
    size_t sz = n->conn.size();
    vector<tuple<int, node*>> deletes;

    // cout << "(" << n->num << ": ";

    // nothing to do
    if (sz == 0) {
        // cout << "nothing to do) ";
        return 0;
    }
    if (sz == 1 && parent != NULL) {
        // cout << "nothing to do child) ";
        return 0;
    }

    int dels = 0;
    for (size_t i=0; i<sz; ++i) {
        if (n->conn[i] != parent) {
            int c = count_children(n->conn[i], n) + 1;
            deletes.push_back(make_tuple(c, n->conn[i]));
            dels += c;
            // cout << "<" << n->conn[i]->num << ": " << c << "> ";
        }
    }

    // delete all
    if (sz == 1 || (sz == 2 && parent != NULL)) {
        // cout << "delete all " << dels << ") ";
        return dels;
    }

    // remain 2
    sort(deletes.begin(), deletes.end(), 
         [](tuple<int, node*> a, tuple<int, node*> b) { return get<0>(a) - get<0>(b); });

//    cout << "(remain 2 " << dels << " " << deletes[0] << " " << deletes[1] << ") ";

    // cout << "recurse to " << get<1>(deletes[0])->num << ", " << get<1>(deletes[1])->num << ") ";
    dels -= get<0>(deletes[0]) + get<0>(deletes[1]);
    dels += make_binary(get<1>(deletes[0]), n);
    dels += make_binary(get<1>(deletes[1]), n);
    return dels;
}

int solve() 
{
    int n;
    vector<node*> nodes;

    cin >> n;

    // cout << "N=" << n << endl;

    for (int i=0; i<n; ++i) {
        node* n = new node;
        n->num = i+1;
        nodes.push_back(n);
    }
    for (int i=0; i<n-1; ++i) {
        int f, t;

        cin >> f >> t;

        // cout << f << " " << t << endl;

        nodes[f-1]->conn.push_back(nodes[t-1]);
        nodes[t-1]->conn.push_back(nodes[f-1]);
    }

    int min_del = INT_MAX;

    if (n == 2) {
        min_del = 1;
        goto fin;
    }

    for (node* root: nodes) {
        // cout << "node " << root->num << " ";
        if (root->conn.size() == 1) {
            // delete all other
            min_del = min(min_del, n - 1);
            // cout << n-1 << endl;
            continue;
        }

        int del = make_binary(root, NULL);
        // cout << del << endl;
        min_del = min(del, min_del);
    }
fin:
    for (int i=0; i<n; ++i) {
        delete nodes[i];
    }

    return min_del;
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for (int i=1; i<=t; ++i) {
        cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}
