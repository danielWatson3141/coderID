#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair < int, int > pii;
const int MAX = 1020;

int n;
vector < int > to[MAX];

int nodeCount(int root, int ignore){
	int i, ret = 1;
	for(i = 0; i<to[root].size(); i++){
		if(to[root][i] != ignore)
			ret += nodeCount(to[root][i], root);
	}

	return ret;
}

int makeRoot(int root, int ignore){
	int i, ret = MAX, childrenCount = 0;
	vector < pii > list;
	for(i = 0; i<to[root].size(); i++){
		if(to[root][i] != ignore){
			int f = nodeCount(to[root][i], root), s = makeRoot(to[root][i], root);
			childrenCount += f;
			list.push_back(pii(f, s));
		}
	}

	if(list.size() == 0){
		return 0;
	} else if(list.size() == 1){
		return list[0].first;
	} else {
		int j;
		for(i = 0; i<list.size(); i++){
			for(j = i+1; j<list.size(); j++){
				int t = childrenCount - list[i].first - list[j].first + list[i].second + list[j].second;
				if(ret == -1 || ret > t)
					ret = t;
			}
		}
	}

	return ret;
}

int main(){
	freopen("output.txt", "w", stdout);

	int numCase;
	scanf("%d", &numCase);

	int cc;
	for(cc = 1; cc <= numCase; cc++){
		printf("Case #%d: ", cc);

		scanf("%d", &n);

		int i;
		for(i = 0; i<n-1; i++){
			int f, s;
			scanf("%d%d", &f, &s);

			to[f].push_back(s);
			to[s].push_back(f);
		}

		int res = MAX;
		for(i = 1; i<=n; i++)
			res = min(res, makeRoot(i, 0));
		
		printf("%d\n", res);

		for(i = 1; i<=n; i++)
			to[i].clear();
	}

	return 0;
}