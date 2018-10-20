#include <fstream>
#include <iostream>
#include <vector>
#include<string>
#include <set>
#include <algorithm>
#include <sstream>

struct testcase{
  int n, l;
  std::vector<std::string> outlets, 
          required;
  std::vector<int> out1, req1;
  int caseno;
  testcase() {  }
  bool equals(std::vector<std::string> & orig) {
    std::sort(orig.begin(), orig.end());
    for (int i = 0 ; i < n; i++) {
      if (orig[i] != required[i])
        return false;
    }
    return true;
  }

  bool equals(std::vector<int> & orig) {
    std::sort(orig.begin(), orig.end());
    for (int i = 0 ; i < n; i++) {
      if (orig[i] != req1[i])
        return false;
    }
    return true;
  }
  std::vector<int> z1, z2, o1, o2;

  std::string computed_result() {
    z1.resize(l, 0);
    z2.resize(l, 0);
    o1.resize(l, 0);
    o2.resize(l, 0);

    for (int i = 0 ; i < l; i++) {
      for (int j = 0; j < n; j++) {
        if (outlets[j][i] == '0') {
          z1[i] += 1;
        }
        else {
          o1[i] += 1;
        }
        if (required[j][i] == '0') {
          z2[i] += 1;
        }
        else {
          o2[i] += 1;
        }
        
      }
    }

    std::sort(required.begin(), required.end());
    std::sort(req1.begin(), req1.end());
    if (equals(out1)) 
        return "0"; 
    int k = computed_result1(out1, 0);
    if (k == -1)
      return "NOT POSSIBLE";
    std::stringstream ss;
    ss << k;
    return ss.str();
  }

  int computed_result1(std::vector<std::string> & orig, int start_from) {
    if (start_from == l) {
      if (equals(orig)) 
        return 0; 
      else return -1;
    }
    int score = 0;
    for (int i = start_from ; i < l; i++) {
        //
        if ((z1[i] != z2[i] && o1[i] != o2[i]) && (z1[i]!= o2[i] && z2[i] != o1[i]))
          return -1;
        if (z1[i] == z2[i] && o1[i] == o2[i] && z1[i] != o1[i]) {
          continue;
        }
        if (z1[i] == o2[i] && z2[i] == o1[i] && z1[i] != o1[i]) {
          for (int j = 0; j < n; j++) {
            orig[j][i] = (orig[j][i] == '0' ? '1' : '0');
          }
          score ++;
          continue;
        }
        // 2 cases
        if (z1[i] == o2[i] && z2[i] == o1[i] && z1[i] == o1[i]) {
          std::vector<std::string> rev;
          for (int j = 0; j < n; j++) {
            std::string buf = orig[j];
            buf[i] = (buf[i] == '0' ? '1' : '0');
            rev.push_back(buf);
          }
          int s1 = computed_result1(orig, i + 1);
          int s2 = computed_result1(rev, i + 1);
          if (s1 < 0 && s2 < 0)
            return -1;
          if (s1 < 0)
            return s2 + score + 1;
          if (s2 < 0)
            return s1 + score;
          if (s2 + score + 1 <s1+score)
            return s2 + score + 1;
          else return s1+score;
        }
        
        
        //
    }
    if (equals(orig)) 
      return score;
    return -1;
  }

  int computed_result1(std::vector<int> & orig, int start_from) {
    if (start_from == l) {
      if (equals(orig)) 
        return 0; 
      else return -1;
    }
    int score = 0;
    for (int i = start_from ; i < l; i++) {
        //
        if ((z1[i] != z2[i] && o1[i] != o2[i]) && (z1[i]!= o2[i] && z2[i] != o1[i]))
          return -1;
        if (z1[i] == z2[i] && o1[i] == o2[i] && z1[i] != o1[i]) {
          continue;
        }
        if (z1[i] == o2[i] && z2[i] == o1[i] && z1[i] != o1[i]) {
          for (int j = 0; j < n; j++) {
            orig[j] ^= (1 << i);
          }
          score ++;
          continue;
        }
        // 2 cases
        if (z1[i] == o2[i] && z2[i] == o1[i] && z1[i] == o1[i]) {
          std::vector<int> rev;
          for (int j = 0; j < n; j++) {
            int buf = orig[j];
            buf ^= (1 << i);
            rev.push_back(buf);
          }
          int s1 = computed_result1(orig, i + 1);
          int s2 = computed_result1(rev, i + 1);
          if (s1 < 0 && s2 < 0)
            return -1;
          if (s1 < 0)
            return s2 + score + 1;
          if (s2 < 0)
            return s1 + score;
           if (s2 + score + 1 <s1+score)
            return s2 + score + 1;
          else return s1+score;
        }
        
        
        //
    }
    if (equals(orig)) 
      return score;
    return -1;
  }
};

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cout << "Please, provide input file name as a first parameter, and output file name as a second parameter" << std::endl;
    return 0;
  }
  std::ifstream inputStream(argv[1]);
  if (inputStream.fail()) {
    std::cout << "Please, provide _valid_ file name as first parameter" << std::endl;
    return 0;
  }
  std::ofstream output_file(argv[2]);
  //
  int t;
  inputStream >> t;
  for (int i = 0; i < t; i++) {
    testcase tc;
    tc.caseno = i + 1;
    inputStream >>  tc.n >> tc.l;
    std::string line;
    for (int j = 0; j < tc.n; j ++) {
      inputStream >> line;
      tc.outlets.push_back(line);
      int val = 0;
      for (int k = 0 ; k< tc.l; k++) {
        val ^= ((line[k] == '0' ? 0 : 1) << k);
      }
      tc.out1.push_back(val);
    }
    for (int j = 0; j < tc.n; j ++) {
      inputStream >> line;
      tc.required.push_back(line);
      int val = 0;
      for (int k = 0 ; k< tc.l; k++) {
        val ^= ((line[k] == '0' ? 0 : 1) << k);
      }
      tc.req1.push_back(val);
    }
    output_file << "Case #" << tc.caseno << ": " << tc.computed_result() << std::endl;
  }
 //do smth with input
  inputStream.close();
  
  
  // output smth
  //output_file << "Case #" << (i+1) << ": ";
  output_file.close();
  return 0;
}