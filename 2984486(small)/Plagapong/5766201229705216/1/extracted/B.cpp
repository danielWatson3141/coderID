/*
ID: Plagapong
LANG: C++
TASK: B
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#define INF 999999999

using namespace std;
int n;
int edges[1005][1005], etop[1005];

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  for (int i = 0; i < 1005; i++) {
    etop[i] = 0;
  }
}

bool used[1005];

void prepare_dfs() {
  for (int i = 0; i < 1005; i++) {
    used[i] = false;
  }
}

int dfs(int x) {
  used[x] = true;
  int best1 = 0, best2 = 0;
  for (int j = 0; j < etop[x]; j++) {
    int y = edges[x][j];
    if (!used[y]) {
      int score = dfs(y);
      if (score >= best1) {best2 = best1; best1 = score;}
      else if (score >= best2) {best2 = score;}
    }
  }
  //cout << x << " " << best1 << " " << best2 << " | ";
  if (best2 == 0) return 1;
  return best1 + best2 + 1;
}

void process() {
  // Code here!
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    edges[a][etop[a]++] = b;
    edges[b][etop[b]++] = a;
  }
  int best = -1;
  for (int i = 1; i <= n; i++) {
    prepare_dfs();
    int score = dfs(i);
    //cout << score << endl;
    if (score > best) best = score;
  }
  cout << (n - best);
}

int main() {
  preprocess();
  int times;
  cin >> times;
  for (int i = 1; i <= times; i++) {
	cout << "Case #" << i << ": ";
	clearVars();
	process();
	cout << endl;
  }
  return 0;
}
