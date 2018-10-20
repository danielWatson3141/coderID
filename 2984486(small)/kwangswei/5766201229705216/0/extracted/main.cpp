#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int N;

vector<vector<int>> connection;

class Count {
    public:
    int delCnt;
    int totalCnt;
};

Count calc(int root, int parent) {
    vector<Count> delNode;

    for (int i = 0; i < connection[root].size(); ++i) {
        if (connection[root][i] == parent)
            continue;
        delNode.push_back(calc(connection[root][i], root));
    }

    Count cnt;
    cnt.totalCnt = 1;
    cnt.delCnt = 0;

    if (delNode.size() == 0) {

 //   printf("root: %d, parent: %d, cnt : %d\n", root+1, parent+1, cnt.delCnt);
        return cnt;
    }

    if (delNode.size() == 1) {
        cnt.totalCnt += delNode[0].totalCnt;
        cnt.delCnt = delNode[0].totalCnt;

  //  printf("root: %d, parent: %d, cnt : %d\n", root+1, parent+1, cnt.delCnt);

        return cnt;
    }

    for (int i = 0; i < 2; ++i) {
        cnt.totalCnt += delNode[i].totalCnt;
        cnt.delCnt += delNode[i].delCnt;
    }

    for (int i = 2; i < delNode.size(); ++i) {
        cnt.totalCnt += delNode[i].totalCnt;
        cnt.delCnt += delNode[i].totalCnt;
    }

  //  printf("root: %d, parent: %d, cnt : %d\n", root+1, parent+1, cnt.delCnt);


    return cnt;
}

int solve() {
    int delNodeCnt = 9999999;
    int root = -1;

    for (int i = 0; i < N; ++i) {
        Count cnt = calc(i, -1);

       // printf("root : %d, delCnt : %d\n", i+1, cnt);

        delNodeCnt = min(delNodeCnt, cnt.delCnt);
    }

//    cout << "root : " << root << endl;

    return delNodeCnt;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cin >> N;

        connection = vector<vector<int>>(N);

        for (int i = 0; i < N-1; ++i) {
            int n1, n2;
            cin >> n1 >> n2;

            connection[n1-1].push_back(n2-1);
            connection[n2-1].push_back(n1-1);
        }

        int cnt = solve();
        printf("Case #%d: ", test);
        cout << cnt << endl;
    }

    return 0;
}
