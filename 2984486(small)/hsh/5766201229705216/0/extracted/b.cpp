#include <iostream>
#include <unordered_map>
#include <set>
typedef std::unordered_multimap<int, int> EdgesType;

typedef struct Tree{
	int cnt;
	Tree *left, *right;
}Tree;

Tree* build(int parent, int index, const EdgesType &edges){
	auto adjs = edges.equal_range(index);
	Tree* node = new Tree();
	node->cnt = 1;
	for(; adjs.first != adjs.second; adjs.first++){
		if(adjs.first->second == parent) continue;
		Tree *child = build(index, adjs.first->second, edges);
		node->cnt += child->cnt;
		if (node->left == NULL || node->left->cnt < child->cnt){
			node->right = node->left;
			node->left = child;
		}else if(node->right == NULL || node->right->cnt < child->cnt)
			node->right = child;
	}
	node->cnt = 1;
	if(node->left != NULL && node->right == NULL)
		node->left=NULL;
	return node;
}

int count(Tree* tree){
	int cnt = 1;
	if(tree->left != NULL)
		cnt+=count(tree->left);
	if(tree->right != NULL)
		cnt+=count(tree->right);
	return cnt;
}

int build(int root, const EdgesType &edges){
	Tree *tree = build(-1, root, edges);
	return count(tree);
}

int main(){
	int T;
	std::cin >> T;
	for(int cas = 1; cas <= T; cas++){
		EdgesType edges;
		int N;
		std::cin >> N;
		for(int i = 1; i < N; i++){
			int p, q;
			std::cin >> p >> q;
			edges.insert(std::make_pair<int, int>(p, q));
			edges.insert(std::make_pair<int, int>(q, p));
		}
		int best = 0;
		for(int i = 1; i <= N; i++){
			int b = build(i, edges);
			if (b > best) best = b;
		}
		std::cout << "Case #" << cas << ": " << (N - best) << std::endl;
	}
	return 0;
}