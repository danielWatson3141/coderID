#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip> 
#include <algorithm>
#include <functional>
#include <cmath>

using std::vector;
using std::string;
using std::cout;
using std::endl;

string flip_switch(string flow, int position)
{
  if(flow.compare(position, 1, "0") == 0) {
    flow.replace(position, 1, "1");
  } else if(flow.compare(position, 1, "1") == 0) {
    flow.replace(position, 1, "0");
  } else {
    cout << "Error, string at position " << position << " is " << flow.at(position) << endl;
  }

  return flow;
}

bool match_possible(vector<string> outlet_flows, 
                    vector<string> device_flows,
                    vector<bool> positions_changed)
{

  for(int j = 0; j < positions_changed.size(); ++j) {
    //    cout << positions_changed.at(j) << endl;
  }


  for(int i = 0; i < outlet_flows.size(); ++i) {
    for(int j = 0; j < positions_changed.size(); ++j) {
      if(positions_changed.at(j)) {
        //        cout << "before out " << outlet_flows.at(i) << endl;
        outlet_flows.at(i) = flip_switch(outlet_flows.at(i), j);
        //        cout << "after out " << outlet_flows.at(i) << endl;
        // cout << "before dev " << device_flows.at(i) << endl;
        // device_flows.at(i) = flip_switch(device_flows.at(i), j);        
        // cout << "after dev " << device_flows.at(i) << endl;
      }
    }
  }
  
  std::sort(outlet_flows.begin(), outlet_flows.end());
  std::sort(device_flows.begin(), device_flows.end());

  bool match_possible = true;
  for(int i = 0; i < outlet_flows.size(); ++i) {
      // cout << "out: " << outlet_flows.at(i) << endl;
      // cout << "dev: " << device_flows.at(i) << endl;
    if(outlet_flows.at(i) != device_flows.at(i)) {
      // cout << "out fail: " << outlet_flows.at(i) << endl;
      // cout << "dev fail: " << device_flows.at(i) << endl;
      match_possible = false;
    }
  }
  return match_possible;
}

int find_result(vector<string> outlet_flows, vector<string> device_flows)
{
  int result = -1;
  string first_device = device_flows.at(0);
  //cout << "trying first device with " << endl;
  for (int j = 0; j < outlet_flows.size(); ++j) {
    //cout << j << ". outlet" << endl;
    int prelim_result = 0;
    string changed_outlet = outlet_flows.at(j);
    vector<bool> positions_changed;
    for(int i = 0; i<first_device.size(); ++i) {
      //cout << "checking at position " << i << " for " << changed_outlet << " and " << first_device << endl;
      //cout << first_device.at(i) << changed_outlet.at(i) << endl;
      if(first_device.at(i) != changed_outlet.at(i)) {
        //cout << "checking at position " << i << endl;
        changed_outlet = flip_switch(changed_outlet, i);
        //cout << "flipped switch" << endl;
        ++prelim_result;
        positions_changed.push_back(true);
      } else {
        //cout << "nothing to do." << endl;
        positions_changed.push_back(false);
      }
    }

    if(match_possible(outlet_flows, device_flows, positions_changed)) {
      //cout << "match possible" << endl;
      if(prelim_result < result || result == -1) {
        result = prelim_result;
        if(result == 0) {
          return result;
        }
      }
    }
  }
  return result;
}

int main()
{
  std::string filename = "testFile_small.in";
  std::ifstream file(filename.c_str());
  int numCases;

  file >> numCases;

  for(int i = 0; i < numCases; ++i) {
    int N, L;
    file >> N >> L;

    vector<string> outlets;
    for (int j = 0; j < N; ++j) {
      string outlet_flow;
      file >> outlet_flow;
      outlets.push_back(outlet_flow);
    }
    vector<string> devices;
    for (int j = 0; j < N; ++j) {
      string device_flow;
      file >> device_flow;
      devices.push_back(device_flow);
    }
    int result;
    result = find_result(outlets, devices);

    if(result == -1) {
      std::cout << "Case #" << i+1 << ": NOT POSSIBLE" << std::endl;
    } else {
      std::cout << "Case #" << i+1 << ": " << result << std::endl;
    }
  }
}
