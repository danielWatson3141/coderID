#include <climits>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;

int read_binary() {
  char string[15];
  int retval = 0;
  scanf("%s", string);
  for (int i = 0; i < l; i++) {
    if (string[i] == '1') {
      retval += (1 << (l - i - 1));
    }
  }
  return retval;
}

int get_switches(int x) {
  int count = 0;
  int i = l - 1;
  while(i >= 0) {
    if (x >= (1 << i)) {
      count++;
      x -= (1 << i);
    }
    i--;
  }
  return count;
}

bool compare(vector<int> a, vector<int> b) {
  bool retval = true;
  for (int i = 0; i < n && retval; i++) {
    if (a[i] != b[i]) {
      retval = false;
    }
  }
  return retval;
}

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d %d", &n, &l);
    vector<int> outlets, devices;
    for (int j = 0; j < n; j++) {
      outlets.push_back(read_binary());
    }
    for (int j = 0; j < n; j++) {
      devices.push_back(read_binary());
    }
    sort(devices.begin(), devices.end());
    int minimum = INT_MAX;
    for (int j = 0; j < n; j++) {
      int xor_value = outlets[j] ^ devices[0];
      int switches = get_switches(xor_value);
      if (switches < minimum) {
	vector<int> switched;
	for (int k = 0; k < n; k++) {
	  switched.push_back(outlets[k] ^ xor_value);
	}
	sort(switched.begin(), switched.end());
	if (compare(devices, switched)) {
	  minimum = switches;
	}
      }
    }
    printf("Case #%d: ", i);
    if (minimum == INT_MAX) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", minimum);
    }
  }
  return 0;
}
