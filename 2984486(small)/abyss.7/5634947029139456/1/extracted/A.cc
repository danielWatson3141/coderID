#include <iostream>
#include <set>
#include <string>

const std::string not_possible = "NOT POSSIBLE";

std::string outlets[150];
std::string devices[150];
int N, L;

int OutletCount(char s, int i) {
  int result = 0;
  for (int j = 0; j < N; ++j) {
    if (outlets[j][i] == s) ++result;
  }

  return result;
}

int DevicesCount(char s, int i) {
  int result = 0;
  for (int j = 0; j < N; ++j) {
    if (devices[j][i] == s) ++result;
  }

  return result;
}

void Switch(int i) {
  for (int j = 0; j < N; ++j) {
    if (outlets[j][i] == '1') outlets[j][i] = '0';
    else outlets[j][i] = '1';
  }
}

bool CheckPrefix(int i) {
  std::multiset<std::string> o, d;

  for (int j = 0; j < N; ++j) {
    o.insert(outlets[j].substr(0, i+1));
    d.insert(devices[j].substr(0, i+1));
  }

  return o == d;
}

int TrySwitch(int i) {
  if (i == L) return 0;

  int oc0 = OutletCount('0', i);
  int dc0 = DevicesCount('0', i);
  int dc1 = DevicesCount('1', i);
  if (oc0 != dc0 && oc0 != dc1) return -1;

  int result = -1;

  if (oc0 == dc0) {
    if (CheckPrefix(i)) result = TrySwitch(i+1);
  }

  if (oc0 == dc1) {
    Switch(i);
    int tmp_result = -1;
    if (CheckPrefix(i)) tmp_result = TrySwitch(i+1);
    if (tmp_result != -1) tmp_result++;
    Switch(i);

    if (result == -1) result = tmp_result;
    else if (tmp_result != -1 && tmp_result < result) result = tmp_result;
  }

  return result;
}

int main() {
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": ";

    std::cin >> N >> L;


    for (int j = 0; j < N; ++j) std::cin >> outlets[j];
    for (int j = 0; j < N; ++j) std::cin >> devices[j];

    int result = TrySwitch(0);

    if (result == -1) std::cout << not_possible;
    else std::cout << result;

    std::cout << std::endl;
  }
}
