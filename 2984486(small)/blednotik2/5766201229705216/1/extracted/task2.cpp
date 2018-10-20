#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define forall(i,n) for(int i=0; i<(int)(n); i++)

template<class T, class T1, class T2> inline bool Within(T x, T1 xMin, T2 xMax)
    {return (x >= xMin && x <= xMax);}
template<class T, class T1> inline bool Within(T x, T1 xMax)
    {return (x >= 0 && x < xMax);}


typedef vector<int> IntVec;
typedef vector<IntVec> IntVV;
typedef vector<bool> BoolVec;
typedef vector<BoolVec> BoolVV;

void PrintVec(const IntVec& v) {
    forall (i, v.size())
	printf("%d ", v[i]);
    printf("\n");
}

void PrintVV(const IntVV& vv) {
    forall (i, vv.size()) {
	printf("    %2d | ", i);
	PrintVec(vv[i]);
    }
}

// graph: (for each vertex, keep vector of neighbours)
void ReadGraph(int& N, IntVV& vv) {
    cin >> N;
    vv.resize(N);
    forall (i, N-1) {
	int v1, v2;
	cin >> v1 >> v2;
	assert(Within(v1, 1, N));
	assert(Within(v2, 1, N));
	v1--;
	v2--;
	vv[v1].push_back(v2);
	vv[v2].push_back(v1);
    }
}


void TreeFromGraph(IntVV& tree, BoolVV& vvChild, const IntVV& graph, int root) {
    const IntVec& vAdj = graph[root];
    forall (i, vAdj.size()) {
	int v = vAdj[i];
	if (vvChild[v][root])
	    continue;
	vvChild[root][v] = true;
	tree[root].push_back(v);
	TreeFromGraph(tree, vvChild, graph, v);
    }
}


// graph: (for each vertex, keep vector of neighbours)
// tree: (for each vertex, keep vector of children)
void TreeFromGraph(IntVV& tree, const IntVV& graph, const int root) {
    const int N = graph.size();
    tree.resize(N);

    // vChild[i][j] is true iff j is a child of i
    BoolVV vvChild(N);
    forall (i, N)
	vvChild[i].resize(N, false);

    TreeFromGraph(tree, vvChild, graph, root);
}


void MinDel(int& minDel, int& size, const IntVV& tree, const int root) {
    size = 1;
    const IntVec& vChild = tree[root];
    if (vChild.empty()) {
	minDel = 0;
	return;
    }
    int nChild = vChild.size();
    IntVec vMinDel(nChild), vSize(nChild);
    forall (i, vChild.size()) {
	MinDel(vMinDel[i], vSize[i], tree, vChild[i]);
	size += vSize[i];
    }
    if (nChild == 1) {
	minDel = vSize[0];
	return;
    }
    assert(nChild >= 2);
    IntVec vLeft(nChild);
    forall (i, nChild)
	vLeft[i] = vSize[i] - vMinDel[i];
    sort(vLeft.begin(), vLeft.end());
    int left = vLeft[nChild-1] + vLeft[nChild-2] + 1;
    minDel = size - left;
}


int MinDel(const IntVV& graph) {
    const int N = graph.size();
    int best = N - 1;
    forall (root, N) {
	IntVV tree;
	TreeFromGraph(tree, graph, root);
	int minDel, size;
	MinDel(minDel, size, tree, root);
	if (minDel < best) best = minDel;
    }
    return best;
}


int main() {
    // cout << setprecision(10);
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int N;
	IntVV graph;
	ReadGraph(N, graph);
	/*
	// DEBUG
	cout << "N=" << N << " :" << endl;
	PrintVV(graph);
	forall (root, N) {
	    cout << "root=" << root << '\n';
	    IntVV tree;
	    TreeFromGraph(tree, graph, root);
	    PrintVV(tree);
	    int minDel, size;
	    MinDel(minDel, size, tree, root);
	    cout << "minDel=" << minDel << " size=" << size << endl;
	}
	*/

	cout << "Case #" << iTask << ": ";
	cout << MinDel(graph) << endl;
    }
}
