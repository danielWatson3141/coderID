#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std; 

// void printVector(vector<string>& str_vec) {
//   for(int i = 0; i < str_vec.size(); i++)
//     cout << str_vec[i] << endl;
// }

vector<int> compareTwo(string& a, string& b) {
  vector<int> result;
  for(int i = 0; i < a.length(); i++) {
    if(a[i] != b[i])
      result.push_back(i);
  }
  return result;
}

vector<string> transform(vector<string> orig, vector<int> indices) {
  vector<string> result;
  for(int i = 0; i < orig.size(); i++) {
    string one = orig[i];
    for(int j = 0; j < indices.size(); j++) {
      int index = indices[j];
      if (one[index] == '0')
	one[index] = '1';
      else
	one[index] = '0';
    }
    result.push_back(one);
  }
  return result;
}

bool compareTwoStringVec(vector<string> one, vector<string> two) {
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());
  //cout << "comparing: " << endl;
  //printVector(one);
  //cout << " and " << endl;
  //printVector(two);
  for(int i = 0; i < one.size(); i++) {
    if (one[i] != two[i]) {
      //cout << "returning false" << endl;
      return false;
    }
  }
  //cout << "returning true" << endl;
  return true;
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int counts, digits;
    cin >> counts >> digits >> ws;
    string orig;
    getline(cin, orig);
    istringstream orig_iss(orig);
    string item;
    vector<string> orig_vec;
    while(getline(orig_iss, item, ' '))
      orig_vec.push_back(item);
    string target;
    getline(cin, target);
    istringstream target_iss(target);
    vector<string> target_vec;
    while(getline(target_iss, item, ' '))
      target_vec.push_back(item);
    string ref_start = orig_vec[0];
    int result = -1;
    //cout << "orig" << endl;
    //printVector(orig_vec);
    //cout << "target" << endl;
    //printVector(target_vec);
    for(int j = 0; j < counts; j++) {
      //cout << "inside the loop" << endl;
      //printVector(target_vec);
      string ref_end = target_vec[j];
      //cout << "ref_end is " << ref_end << endl;
      vector<int> turns = compareTwo(ref_start, ref_end);
      //cout << "turns is " << endl;
      // for(int k = 0; k < turns.size(); k++)
      // 	cout << turns[k] << endl;
      vector<string> transformed = transform(orig_vec, turns);
      // cout << "transformed" << endl;
      //printVector(transformed);
      if(compareTwoStringVec(transformed, target_vec)) {
	int this_transform = turns.size();
	if (result == -1)
	  result = this_transform;
	else if(this_transform < result)
	  result = this_transform;
      }
    }
    if (result == -1)
      cout << "Case #" << i+1 << ": NOT POSSIBLE" << endl;
    else
      cout << "Case #" << i+1 << ": " << result << endl;
  }
}
