//
//  main.cpp
//  Charging Chaos
//
//  Created by Kotsur on 26.04.14.
//  Copyright (c) 2014 Dmytro Kotsur. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

ifstream in("/Users/userMac/Projects/Contests/Google Code Jam 2014/Round 1A/Charging Chaos/large.txt");
ofstream out("/Users/userMac/Projects/Contests/Google Code Jam 2014/Round 1A/Charging Chaos/large_out.txt");


int T;
int N, L;

int hammingDist(const string &s1, const string &s2) {
    int dist = 0;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i])
            dist++;
    }
    return dist;
}

string change(const string &in, const string &dev, const string &out) {
    char arr[256];
    arr[L] = '\0';
    for (int i = 0; i < L; ++i) {
        if (dev[i] == out[i]) {
            arr[i] = in[i];
        } else {
            arr[i] = (in[i] - '0' + 1) % 2 + '0';
        }
    }
    return string(arr);
}

int main(int argc, const char * argv[])
{
    
    in >> T;
    for (int t = 1; t <= T; ++t) {
        in >> N >> L;
        vector<string> outlets;
        vector<string> devices;
        
        outlets.reserve(N);
        devices.reserve(N);
        string d;
        
        for (int n = 0; n < N; ++n) {
            in >> d;
            outlets.push_back(d);
        }
        for (int n = 0; n < N; ++n) {
            in >> d;
            devices.push_back(d);
        }
        
        out << "Case #" << t << ": ";
        
        int min_dist = INT_MAX;
        string min_device = "", min_outlet = "";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int dist = hammingDist(devices[i], outlets[j]);

                min_device = devices[i];
                min_outlet = outlets[j];
                    
                set<string> check_s;
                for (int k = 0; k < N; ++k) {
                    string tmp = change(outlets[k], min_device, min_outlet);
                    check_s.insert(tmp);
                }
                
                bool is_good = true;
                for (int k = 0; k < N; ++k) {
                    if (check_s.find(devices[k]) == check_s.end()) {
                        is_good = false;
                        break;
                    }
                }
                
                if (is_good && dist < min_dist) {
                    min_dist = dist;
                }
            }
        }
        
        if (min_dist == INT_MAX) {
            out << "NOT POSSIBLE" << endl;
        } else {
            out << min_dist << endl;
        }
        
    }
    
    
    return 0;
}

