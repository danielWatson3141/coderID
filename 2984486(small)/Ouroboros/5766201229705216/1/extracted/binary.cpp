#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<vector <int> > node;
vector<int > children;
vector<int > answer;
vector<bool> visited;
int N;

void readData() {
  cin >> N;
  node.resize(N+1);
  visited.resize(N+1);
  answer.resize(N+1);
  children.resize(N+1);
  for (int i = 1;i <= N;i++) node[i].clear();
  for (int i = 0;i < N-1;i++) {
    int a,b;
    cin >> a >> b;
    node[a].push_back(b);
    node[b].push_back(a);
  }
}

int dfs(int idx) {
  visited[idx] = true;
  vector<int> child;
  //printf(" at %d\n",idx);
  children[idx] = 1;
  for (size_t i = 0;i < node[idx].size();i++) {
    int next = node[idx][i];
    if (!visited[next]) {
      //printf("  check  %d\n",next);
      answer[next] = dfs(next);
      children[idx] += children[next];
      child.push_back(next);
    }
  }
  int result;
  if (child.size() == 0) {
    result = 0;
  } else if (child.size() == 1) {
    result = children[child[0]];
  } else {
    int t1 = child[0]; // the best benefit child
    int t2 = child[1]; // the next best
    if ((children[t2] - answer[t2] > children[t1] - answer[t1])) swap(t1,t2);
    for (int i = 2;i < (int)child.size();i++) {
      int childIdx = child[i];
      if ((children[childIdx] - answer[childIdx] > children[t2] - answer[t2])) t2 = childIdx;
      if ((children[t2] - answer[t2] > children[t1] - answer[t1])) swap(t1,t2);

    }

    result = 0;
    for (int i = 0;i < (int)child.size();i++) {
      if (t1 == child[i] || t2 == child[i]) {
       result += answer[child[i]];
      } else {
       result += children[child[i]];
      }
    }
  }
  //printf(" at %d, result is %d\n",idx,result);
  return result;
}

int result;

void process() {
  result = N+1; 
  for (int i = 1;i <= N;i++) {
    for (int j = 1;j <= N;j++) {
      visited[j] = false;
      children[j] = 0;
      answer[j] = -1;
    }
    int ans;
    ans = dfs(i);
    //printf("root at %d, ans = %d\n",i,ans);
    if (ans < result) result = ans;
  }
}


int main() {
  freopen("B-large(1).in","r",stdin);
  int T;
  cin >> T;
  int case_id = 0;
  while (T--) {
    case_id++;
    readData();
    process();
    cout << "Case #" << case_id << ": " << result << endl; 
  }
}
