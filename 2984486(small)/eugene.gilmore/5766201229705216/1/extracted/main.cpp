#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


struct Pair {
	int a,b;
};

struct Node {
	vector<int> links;
	int num;
	bool visited;
};

class Problem {
public:
	//problem variables
	int numNodes;
	vector<Pair> links;
	vector<Node> nodes;
	string answer();
	int traverse(int s);
	void printInput();
private:
	//internal variables/functions
};

void Problem::printInput() {
	for(int i = 0; i<links.size(); ++i)
		printf("%d %d\n", links[i].a, links[i].b);
	printf("\n");
}

int Problem::traverse(int s) {
	vector<int> num;
	nodes[s].visited = true;
	if(nodes[s].links.size() == 0 || nodes[s].links.size() == 1)
		return 1;
	else {
		for(int i = 0; i<nodes[s].links.size(); ++i) {
			if(nodes[nodes[s].links[i]-1].visited == false)
				num.push_back(traverse(nodes[s].links[i]-1));
		}
		sort(num.begin(),num.end());
	}
	if(num.size() < 2)
		return 1;
	else
		return 1 + *(num.end()-1) + *(num.end()-2);
}


string Problem::answer() {
	//solve problem
	Node a;
	for(int i = 0; i<this->numNodes; ++i) {
		a.num = i;
		nodes.push_back(a);
	}
	for(int i = 0; i<this->numNodes-1; ++i) {
		nodes[links[i].a - 1].links.push_back(links[i].b);
		nodes[links[i].b - 1].links.push_back(links[i].a);
	}
	
	vector<int> num;
	for(int i = 0; i<numNodes; ++i) {
		for(int j = 0; j<numNodes; ++j) {
			nodes[j].visited = false;
		}
		num.push_back(traverse(i));
		
	}
	sort(num.begin(), num.end());
	
	//return answer
	char tmp[50];
	sprintf(tmp, "%d", numNodes-*(num.end()-1));
	return string(tmp);
}

Problem* readFile(const char* file, int* numCases) {
	FILE* f = fopen(file, "r");
	fscanf(f, "%d\n", numCases);
	Problem* result = new Problem[*numCases];
	Pair tmp;
	for(int i = 0; i<*numCases; ++i) {
		fscanf(f, "\n%d\n", &result[i].numNodes);
		for(int j = 0; j<result[i].numNodes-2; ++j) {
			fscanf(f, "%d %d\n", &tmp.a, &tmp.b);
			result[i].links.push_back(tmp);
		}
		fscanf(f, "%d %d", &tmp.a, &tmp.b);
		result[i].links.push_back(tmp);
	}
	return result;
}

int main(int argc, char** argv) {
	int numProblems = 0;
	Problem* problems = readFile("input", &numProblems);
	for(int i = 0; i<numProblems; ++i) {
#ifdef TEST_READING
		problems[i].printInput();
#else
		printf("Case #%d: %s\n", i+1, problems[i].answer().c_str());
#endif
	}
}
