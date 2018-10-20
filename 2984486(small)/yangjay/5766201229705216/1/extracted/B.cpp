#include <set>
#include <map>
#include <iostream>
#include <cstdio>

using namespace std;

//dp on node and edge to consider "parent" and find the minimum number of nodes to delete

//tree
set<int> tree[1000];

int deleteCost[1000][1000];

int doDeleteCost(int node, int parent){
    if(deleteCost[node][parent]>=0){
        return deleteCost[node][parent];
    }
    set<int> children = tree[node];
    children.erase(parent);
    int cost = 1; //for deleting itself
    for(int i : children){
        cost += doDeleteCost(i,node);
    }
    return deleteCost[node][parent]=cost;
}

int dpArray[1000][1000];

int doDp(int node, int parent){
    if(parent!=-1){//-1 = try as root
        if(dpArray[node][parent]>=0){
            return dpArray[node][parent];
        }
    }
    set<int> children = tree[node];
    children.erase(parent);
    map<int,int> costs;
    map<int,int> delCosts;
    for(int c : children){
        costs[c] = doDp(c,node);
        delCosts[c] = doDeleteCost(c,node);
    }
    int bestCost = 0;
    //cost of deleting all children
    for(int c : children){
        bestCost += delCosts[c];
    }
    int totalDeleteCost = bestCost;

    for(int c1 : children){
        for(int c2 : children){
            if(c1>=c2)
                continue;
            int totalCost = totalDeleteCost - delCosts[c1] - delCosts[c2] + costs[c1] + costs[c2];
            if(totalCost<bestCost){
                bestCost = totalCost;
            }
        }
    }
    //printf("DP: %d %d -> %d\n",node,parent,bestCost);
    if(parent!=-1){
        dpArray[node][parent] = bestCost;
    }
    return bestCost;
}

void clearArrays(){
    for(int i=0;i<1000;i++){
        tree[i].clear();
        for(int j=0;j<1000;j++){
            dpArray[i][j] = -1;
            deleteCost[i][j] = -1;
        }
    }
}

int main(){
    int ncases;
    cin >> ncases;
    for(int c=1;c<=ncases;c++){
        int N;
        cin >> N;
        clearArrays();
        for(int i=0;i<N-1;i++){
            int x,y;
            cin >> x >> y;
            //1 vs 0 indexing
            x--;
            y--;
            //printf("I: %d %d\n",x,y);
            tree[x].insert(y);
            tree[y].insert(x);
        }
        int best = -1;
        for(int i=0;i<N;i++){
            int cost = doDp(i,-1);
            //printf("D: %d %d\n",i,cost);
            if(cost<best || best<0)
                best = cost;
        }
        printf("Case #%d: %d\n",c,best);
    }
}
