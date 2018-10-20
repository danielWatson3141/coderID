/*
ID: Plagapong
LANG: C++
TASK: A
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#define INF 999999999
#define BAD "NOT POSSIBLE"

using namespace std;
int n, l;
char a[200][50];
char b[200][50];

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  
}

inline char anti(char x) {
  return x == '1' ? '0' : '1';
}

inline bool check(char* r, char* s) {
  for (int j = 0; j < l; j++)
    if (r[j] != s[j]) return false;
  return true;
}

void process() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int bestCount = INF;
  for (int i = 0; i < n; i++) {
    // Try chaning a[0] to b[i]
    int count = 0;
    bool flip[50];
    for (int j = 0; j < l; j++) {
      flip[j] = (a[0][j] != b[i][j]);
      count += flip[j];
    }
    if (bestCount <= count) continue;
    bool found[200] = {0};
    // Naive match is fast enough
    for (int u = 0; u < n; u++) {
      char flipped[50];
      for (int j = 0; j < l; j++) {
        flipped[j] = flip[j] ? anti(a[u][j]) : a[u][j];
      }
      for (int v = 0; v < n; v++) {
        if (check(flipped, b[v]))
          found[v] = true;
      }
    }
    bool good = true;
    for (int v = 0; v < n; v++) {
      if (!found[v]) good = false;
    }
    if (good)
      bestCount = count;
  }
  if (bestCount == INF) cout << BAD; else cout << bestCount;
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
