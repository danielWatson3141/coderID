#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
	vector<int> connections;
	int to_delete;
	int sub_tree_size;
	int parent;
	int dist_from_root;
};

void fill(int current, node nodes[], int N, int root) {
	int parent = -1;
	for (int i = 0; i < nodes[current].connections.size(); i++) {
		if (nodes[nodes[current].connections[i]].dist_from_root != -1) {
			parent = nodes[current].connections[i];
			nodes[current].dist_from_root = nodes[nodes[current].connections[i]].dist_from_root + 1;
		}
	}

	int dangling = nodes[current].connections.size() - 1;
	if (current == root) {
		dangling++;
	}

	int curr_down;
	nodes[current].sub_tree_size = 0;
	for (int i = 0; i < nodes[current].connections.size(); i++) {
		curr_down = nodes[current].connections[i];
		if (curr_down != parent) {
			fill(curr_down, nodes, N, root);
			nodes[current].sub_tree_size += nodes[curr_down].sub_tree_size;
		}
	}
	nodes[current].sub_tree_size++;

	if (dangling == 0) {
		nodes[current].sub_tree_size = 1;
		nodes[current].to_delete = 0;
	} else if (dangling == 2) {
		nodes[current].to_delete = 0;
		for (int i = 0; i < nodes[current].connections.size(); i++) {
			curr_down = nodes[current].connections[i];
			if (curr_down != parent) {
				nodes[current].to_delete += nodes[curr_down].to_delete;
			}
		}
	} else if (dangling == 1) {
		for (int i = 0; i < nodes[current].connections.size(); i++) {
			curr_down = nodes[current].connections[i];
			if (curr_down != parent) {
				nodes[current].to_delete = nodes[curr_down].sub_tree_size;
			}
		}
	} else {
		//dangling >= 3
		int min1 = 1001; //min1 < min2
		int index1;
		int min2 = 1002;
		int index2;
		int eff_del;
		for (int i = 0; i < nodes[current].connections.size(); i++) {
			curr_down = nodes[current].connections[i];
			if (curr_down != parent) {
				eff_del = nodes[curr_down].to_delete - nodes[curr_down].sub_tree_size;
			/*	if (current == 4) {
					cout << endl << "HERE!" << endl;
					cout << eff_del << ", ";
					cout << min1 << ", ";
					cout << min2 << ", ";
				}*/
				if (eff_del < min1) {
					min2 = min1;
					index2 = index1;
					min1 = nodes[curr_down].to_delete - nodes[curr_down].sub_tree_size;
					index1 = curr_down;
			/*		if (current == 4) {
						cout << "::, "<< curr_down;
						cout << "/, " << index1 << ", ";

					}*/
				} else if (eff_del < min2) {
					min2 = nodes[curr_down].to_delete - nodes[curr_down].sub_tree_size;
					index2 = curr_down;
				}
			/*	if (current == 4) {
					cout << endl << "choose 13 14" << endl;
					cout << index1 << ", ";
					cout << index2 << ", ";
				}*/
			}
		}
		int to_delete = 0;
		for (int i = 0; i < nodes[current].connections.size(); i++) {
			curr_down = nodes[current].connections[i];
			if ((curr_down != parent) && (curr_down != index1) && (curr_down != index2)) {
			/*	if (current == 4) {
					cout << endl << " @ " << curr_down << endl;
					cout << " to_delete[13] =  " << nodes[13].to_delete << endl;
					cout << " sub_tree_size[13] =  " << nodes[13].sub_tree_size << endl;
					cout << " index1 =  " << index1 << endl;
					cout << " index2 =  " << index2 << endl;
				}*/
				to_delete += nodes[curr_down].sub_tree_size;
			} else if (curr_down != parent ) {
				to_delete += nodes[curr_down].to_delete;
			}
		}

		nodes[current].to_delete = to_delete;
	}


}

int result(int root, node nodes[], int N) {
	for (int i = 1; i <= N; i++) {
		nodes[i].to_delete = -1;
		nodes[i].dist_from_root = -1;
		nodes[i].sub_tree_size = 0;
	}

	nodes[root].dist_from_root = 0;

	fill(root, nodes, N, root);

	return nodes[root].to_delete;
}


int main() {


	ifstream in("input.txt");
	ofstream out("output.txt");


	int T;
	in >> T;

	int N;

	node nodes[1001];
	int X, Y;
	for (int x = 1; x <= T; x++) {
		//cout << "test " << x << endl;
		in >> N;
		for (int i = 0; i < 1001; i++) {
			nodes[i].connections.clear();
		}

		for (int i = 1; i < N; i++) {
			in >> X;
			in >> Y;
			nodes[X].connections.push_back(Y);
			nodes[Y].connections.push_back(X);
		}

		int min = 1001;
		int current = 0;
		for (int root = 1; root <= N; root++) {
			current = result(root, nodes, N);
			//cout << "result for root " << root << " is "<< current << endl;
			/*for (int i = 1; i <= N; i++) {
				cout << i << ": " << nodes[i].to_delete << "; ";
			}*/
			//cout << endl;
			if (current < min) {
				min = current;
			}
		}

		out << "Case #" << x << ": "  << min << endl;
	}

	in.close();
	out.close();

	//cout << "finish" << endl;
	return 0;
}
