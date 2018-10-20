#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>

int flip(int x, int bit) {
  return x^(bit);
}

bool same_set(std::set<int> &s, std::set<int> &t) {
  int n = s.size();
  std::set<int>::iterator its = s.begin();
  std::set<int>::iterator itt = t.begin();
  for (int i = 0; i < n; i++) {
    if(*its != *itt) {
      return false;
    }
    its++;
    itt++;
  }
  return true;
}

int count_ones(int x) {
  int c;
  for (c = 0; x; c++) 
    x &= x - 1;
  return c;
}

int flips(std::set<int> &flow_given, std::set<int> &flow_target, int bits) {
  if (same_set(flow_given, flow_target)) {
    return 0;
  }
  int n = (int) pow(2, bits);
  int num_flips = 200;
  for(int i = 1; i < n; i++) {
    std::set<int> manip;
    std::set<int>::iterator it = flow_given.begin();
    while (it != flow_given.end()) {
      manip.insert(flip(*it, i));
      it++;
    }
    if (same_set(manip, flow_target)) {
      int nf = count_ones(i);
      if (num_flips > nf) {
        num_flips = nf;
      }
    }
  }
  if (num_flips < 200) {
    return num_flips;
  }
  return -1;
}


int bin_to_num(std::string &str) {
  int num = 0;
  int two = 1;
  int n = str.length();
  for (int i = n - 1; i >= 0; i--) {
    if (str[i] == '1') {
      num += two;
    }
    two *= 2;
  }
  return num;
}

int main(int argc, char** argv) {
  std::string line;
  int cases;
  std::getline(std::cin, line);
  std::istringstream iss(line);
  iss >> cases;

  for (int case_id = 1; case_id < cases + 1; case_id++) {
    int outs = 0;
    int bits = 0;

    std::getline(std::cin, line);
    std::istringstream iss(line);

    iss >> outs;
    iss >> bits;
    std::set<int> flow_given;
    std::set<int> flow_target;

    std::string bin;
    std::getline(std::cin, line);
    std::istringstream iss1(line);
    for (int i = 0; i < outs; i++) {
      iss1 >> bin;
      flow_given.insert(bin_to_num(bin));
    }

    std::getline(std::cin, line);
    std::istringstream iss2(line);
    for (int i = 0; i < outs; i++) {
      iss2 >> bin;
      flow_target.insert(bin_to_num(bin));
    }
    int f = flips(flow_given, flow_target, bits);
    if (f < 0) {
      std::cout << "Case #" << case_id << ": NOT POSSIBLE" << std::endl;
    } else {
      std::cout << "Case #" << case_id << ": " << f << std::endl;
    }
  }
}
