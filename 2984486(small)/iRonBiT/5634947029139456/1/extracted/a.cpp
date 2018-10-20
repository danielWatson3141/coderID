// clang++ -std=c++11 -stdlib=libc++ -Wall -o a.out a.cpp
// ./a.out < input-small.txt 2>log.txt 1>small.out

#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int size;
    string str;
    vector<unsigned long long int> outlet;
    vector<unsigned long long int> device;
    map<unsigned long long int, int> mymap;
    
    cin >> size;
    for (int index = 1; index <= size; ++index) {
        int N = 0;
        int L = 0;
        cin >> N;
        cin >> L;

        mymap.clear();
        outlet.clear();
        device.clear();

        cerr << "N: " << N << '\n';
        for (int i = 0; i < N; ++i) {
            cin >> str;
            bitset<40> tmp(str);
            outlet.push_back(tmp.to_ullong());
            cerr << "OULET: " << outlet[i] << '\n';
        }
        for (int i = 0; i < N; ++i) {
            cin >> str;
            bitset<40> tmp(str);
            device.push_back(tmp.to_ullong());
        }

        for (int x = 0; x < N; ++x) {
            for(int y = 0; y < N; ++y) {
                auto tmp = device[x] ^ outlet[y];

                auto it = mymap.find(tmp);
                if (it == mymap.end()) {
                    mymap[tmp] = 0;
                    continue;
                }
                
                mymap[tmp]++;
            }
        }

        int counter = 200;
        bool isPossible = false;

        for (auto val : mymap) {
            if (val.second == (N - 1)) {
                bitset<40> tmp(val.first);
                int aux = tmp.count();
                isPossible = true;
                if (counter > aux) {
                    counter = aux;
                }
            }
        }

        if (isPossible == true) {
            cout << "Case #" << index << ": " << counter << "\n";
            continue;
        }

        cout << "Case #" << index << ": " << "NOT POSSIBLE\n";
    }
}


