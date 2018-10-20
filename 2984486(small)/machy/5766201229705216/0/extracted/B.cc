#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

struct Node{
    int e1;
    int e2;
    int e3;
    Node(int e1_, int e2_, int e3_):e1(e1_),e2(e2_),e3(e3_){}
    Node(){}
};

int countMin(vector<Node>& node, int pos, int parent){
    if(pos == -1) return 0;
    Node& n = node[pos];
    //cerr << "pos=" << pos << ", " << n.e1 <<", " << n.e2 << ", " << n.e3 << endl;
    if(n.e2 == -1){
        return 0;
    }
    if(n.e3 == -1){
        int cnt = 1;
        if(parent != n.e1) cnt += countMin(node, n.e1, pos);
        if(parent != n.e2) cnt += countMin(node, n.e2, pos);
        return cnt;
    }
    int cnt = 0;
    if(parent != n.e1) cnt += countMin(node, n.e1, pos);
    if(parent != n.e2) cnt += countMin(node, n.e2, pos);
    if(parent != n.e3) cnt += countMin(node, n.e3, pos);
    return cnt; //min(2, cnt);
}

void appendNode(Node& n, int pos){
    if(n.e1 == -1){
        n.e1 = pos;
        return;
    }
    if(n.e2 == -1){
        n.e2 = pos;
        return;
    }
    n.e3 = pos;
}

int main(){
    int T;
    int N;

    cin >> T;
    for(size_t t = 1; t <= T; t++){
        cin >> N;
        vector<Node> node(N+1, Node(-1,-1, -1));
        for(int i = 0; i < N-1; i++){
            int x1, x2;
            cin >> x1 >> x2;
            appendNode(node[x1], x2);
            appendNode(node[x2], x1);
        }
        int res = N*N;
        for(int root = 1; root <= N; root++){
            if(node[root].e2 == -1) continue;
            int v = 0;
            v += countMin(node, node[root].e1, root);
            v += countMin(node, node[root].e2, root);
            v += countMin(node, node[root].e3, root);
            res = min(res, v);
            //cerr << "root=" << node[root].e1 << ", " << node[root].e2 << ", " << node[root].e3 << endl;
            //cerr << root << " : " << v << endl;
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}

