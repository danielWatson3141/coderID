/**
	Author: Floris Kint
  **/


#include <cstdio>
#include <bitset>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

#define PI atan2(0,-1)

using namespace std;
#define MAXN 1000
list<int> neighbours[MAXN];
map<pair<int, int>, int> nodes_to_delete;
map<pair<int, int>, int> sub_nodes;
int get_sub_nodes(int curr_node, int prev_node){
    pair<int, int> p = make_pair(curr_node, prev_node);
    if(sub_nodes.find(p) != sub_nodes.end()){
        return sub_nodes[p];
    }
    int counter = 0;
    for(list<int>::iterator it = neighbours[curr_node].begin(); it != neighbours[curr_node].end(); ++it){
        if(*it == prev_node)
            continue;
        counter += 1+get_sub_nodes(*it, curr_node);   
    }
    sub_nodes[p]=counter;
    return counter;
}
int optimal(int curr_node, int prev_node){
    pair<int, int> p = make_pair(curr_node, prev_node);
    if(nodes_to_delete.find(p) != nodes_to_delete.end()){
        return nodes_to_delete[p];
    }
    int lowest= MAXN;
    int lowest2=MAXN;
    int total = 0;
    int counter = 0;
    for(list<int>::iterator it = neighbours[curr_node].begin(); it != neighbours[curr_node].end(); ++it){
        if(*it == prev_node){
            continue;
        }
        ++counter;
        int tmp = optimal(*it, curr_node);
        int nodes = get_sub_nodes(*it, curr_node)+1;
        int score = tmp-nodes;
        total += nodes;
        if(score < lowest){
            lowest2 = lowest;
            lowest = score;
        }else if(score < lowest2){
            lowest2 = score;
        }
    }
    int result;
    if(counter == 0){
        result = 0;
    }else if(counter == 1){
        result = total;
    }else{
        result = total+lowest+lowest2;
    }
    nodes_to_delete[p] = result;
    return result;
}
int main(){
	int T;
	scanf("%d", &T);
	//cin >> T;
	for(int current_case = 1; current_case <= T; ++current_case){
		//read input
        int N;
        scanf("%d", &N);
        sub_nodes.clear();
        nodes_to_delete.clear();

        for(int i = 0; i < N; ++i){
            neighbours[i].clear();
        }
        for(int i = 0; i < N-1; ++i){
            int a, b;
            scanf("%d%d", &a, &b);--a; --b;
            neighbours[a].push_back(b);
            neighbours[b].push_back(a);
        }
		//process
        int best = N;
        for(int i = 0; i < N; ++i){
            int tmp = optimal(i, i);
            best = min(tmp, best);
        }

		printf("Case #%d:", current_case);
		//cout << "Case #" << current_case << ":";

        printf(" %d", best);


		//output answer
		printf("\n");
		//cout << endl;
	}
    return 0;
}
