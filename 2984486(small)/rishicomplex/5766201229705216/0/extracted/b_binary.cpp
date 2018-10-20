#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> AdjLists[1003];
int sizes[1003];
int dfs_mark[1003];
int root;

int getAns(int ind) {
  dfs_mark[ind] = 1;
  if(root != ind) {
    if(sizes[ind] == 1) return 1;
  }
  int curr, ret = 1, cnt = 0, temp, max1 = -1, max2 = -1;
  for(vector<int>::iterator it = AdjLists[ind].begin(); it != AdjLists[ind].end(); it++) {
    curr = *it;
    if(dfs_mark[curr] == 1) continue;
    temp = getAns(curr);
    if(temp != 0) {
      cnt++;
      if(cnt == 1) {
	if(temp > max1) max1 = temp;
      }
      else {
	if(temp > max1) {
	  max2 = max1;
	  max1 = temp;
	}
	else if(temp > max2) max2 = temp;
      }
      
    }
  }
  if(cnt == 0 || cnt == 1) return 1;
  if(cnt >= 2) {
    ret = 1 + max1 + max2;
    return ret;
  }
  else return 0;
}

void clear_mark() {
  int i;
  for(i = 1; i <= N; i++) {
    dfs_mark[i] = 0;
  }
}

void work(int ind) {
  printf("Case #%d: ", ind);
  scanf("%d", &N);
  int i;
  for(i = 0; i < 1003; i++) {
    AdjLists[i].clear();
  }
  int a, b;
  for(i = 0; i < N - 1; i++) {
    scanf("%d %d", &a, &b);
    AdjLists[a].push_back(b);
    AdjLists[b].push_back(a);
  }
  for(i = 1; i <= N; i++) {
    sizes[i] = AdjLists[i].size();
  }
  for(i = 1; i <= N; i++) {
    dfs_mark[i] = 0;
  }
  int tempans, maxans = 1;
  for(i = 1; i <= N; i++) {
    if(sizes[i] >= 2) {
      root = i;
      clear_mark();
      tempans = getAns(i);
      if(tempans > maxans) {
	maxans = tempans;
      }
    }
  }
  int pr = N - maxans;
  printf("%d\n", pr);
  
}
  

int main() {
  int T;
  scanf("%d", &T);
  int cnt;
  for(cnt = 1; cnt <= T; cnt++) {
    work(cnt);
  }
  return 0;
}
