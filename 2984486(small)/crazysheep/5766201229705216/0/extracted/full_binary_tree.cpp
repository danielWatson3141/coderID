#include <cstdio>
#include <cstdlib>
#include <queue>

#define MAX_NODES 1005
#define INFINITE 1000000000

int graph[MAX_NODES][MAX_NODES];
int treeLevel[MAX_NODES];
int n;

void constructTree(int root);
int numPrune(int curNode);

int main(int arg, char *argv[]) {
  FILE *fin = fopen("in.txt", "r");
  FILE *fout = fopen("out.txt", "w");

  int t;
  fscanf(fin, "%d", &t);

  for (int curCase = 0; curCase < t; curCase++) {
    // Reset graph
    for (int i = 0; i < MAX_NODES; i++) {
      for (int j = 0; j < MAX_NODES; j++) {
        graph[i][j] = 0;
      }
    }

    int curMinPrune = INFINITE;

    // Read in graph
    fscanf(fin, "%d", &n);
    for (int i = 0; i < n-1; i++) {
      int temp1, temp2;
      fscanf(fin, "%d %d", &temp1, &temp2);

      graph[temp1][temp2] = 1;
      graph[temp2][temp1] = 1;
    }

    // for (int i = 1; i <= n; i++) {
    //   // printf("%d", i);
    //   for (int j = 0; j <= n; j++) {
    //     if (graph[i][j]) {
    //       // printf(" %d", j);
    //     }
    //   }
    //   // printf("\n");
    // }

    for (int curNode = 1; curNode <= n; curNode++) {
      for (int i = 1; i <= n; i++) {
        treeLevel[i] = 0;
      }
      constructTree(curNode);

      int curScore = numPrune(curNode);
      if (curScore < curMinPrune) {
        curMinPrune = curScore;
      }
    }

    fprintf(fout, "Case #%d: %d\n", curCase + 1, curMinPrune);
    printf("Case #%d: %d\n", curCase + 1, curMinPrune);
  }

  return EXIT_SUCCESS;
}

void constructTree(int root) {
  int curLevel = 1;

  std::queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int curNode = q.front();
    q.pop();
    if (treeLevel[curNode]) {
      continue;
    }

    treeLevel[curNode] = curLevel;
    curLevel++;

    for (int i = 1; i <= n; i++) {
      if (graph[curNode][i] && treeLevel[i] == 0) {
        q.push(i);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    // printf("%d ", treeLevel[i]);
  }
  // printf("\n");
}

int numNodes(int curNode) {
  int num = 1;
  for (int i = 1; i <= n; i++) {
    if (graph[curNode][i] && treeLevel[i] > treeLevel[curNode]) {
      num += numNodes(i);
    }
  }

  return num;
}

int numPrune(int curNode) {
  // printf("At node %d\n", curNode);
  int numConnected = 0;
  for (int i = 1; i <= n; i++) {
    if (graph[curNode][i] && treeLevel[i] > treeLevel[curNode]) {
      numConnected++;
    }
  }

  if (numConnected == 0) {
    // printf("0 connected\n");
    return 0;
  }
  if (numConnected == 1) {
    int connectedNode;
    for (int i = 1; i <= n; i++) {
      if (graph[curNode][i] && treeLevel[i] > treeLevel[curNode]) {
        connectedNode = i;
        break;
      }
    }

    int result = numNodes(connectedNode);
    // printf("Connected to just %d, returning %d\n", connectedNode, result);

    return result;
  }
  if (numConnected == 2) {
    // printf("Connected to ");
    int returnValue = 0;
    for (int i = 1; i <= n; i++) {
      if (graph[curNode][i] && treeLevel[i] > treeLevel[curNode]) {
        // printf("%d ", i);
        returnValue += numPrune(i);
      }
    }

    // printf("returning %d\n", returnValue);

    return returnValue;
  }
  if (numConnected > 2) {
    int result = 0;
    int totalDelete = 0;
    int biggest = 0;
    int bigger = 0;
    for (int i = 1; i <= n; i++) {
      if (graph[curNode][i] && treeLevel[i] > treeLevel[curNode]) {
        int prune = numPrune(i);
        result += prune;
        int toDelete = numNodes(i) - prune;
        totalDelete += toDelete;

        if (toDelete > bigger) {
          if (toDelete > biggest) {
            biggest = toDelete;
          } else {
            bigger = toDelete;
          }
        }
      }
    }
    // printf("returning %d + %d - (%d + %d)\n", result, totalDelete, biggest, bigger);
    return result + totalDelete - (biggest + bigger);
  }
}