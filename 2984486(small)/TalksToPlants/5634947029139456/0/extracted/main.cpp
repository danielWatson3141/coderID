#include <iostream>
#include <fstream>

using namespace std;

int n;
int l;
bool switchesused[40];
string starts[150];
string ends1[150];
int best;

bool compare(string a, string b)
{
    for (int i = 0; i < a.length(); i++) {
        if (switchesused[i]) {
            if (a[i] == b[i]) {
                return false;
            }
        } else {
            if (a[i] != b[i]) {
                return false;
            }
        }
    }
    return true;
}

void recursion(int on, int flipped)
{
    if (flipped >= best) {
        return;
    }
    if (on == l) {
        for (int i = 0; i < n; i++) {
            bool good = false;
            for (int x = 0; x < n; x++) {
                if (compare(starts[i], ends1[x])) {
                    good = true;
                    break;
                }
            }
            if (good == false) {
                return;
            }
        }
        best = flipped;
    } else {
        switchesused[on] = false;
        recursion(on + 1 , flipped);
        switchesused[on] = true;
        recursion(on + 1 , flipped + 1);
    }
}

int main()
{
    ifstream input;
    input.open("input.txt");
    ofstream output;
    output.open("output.txt");
    int t;
    input >> t;
    string word;
    for (int i = 0; i < t; i++) {
        input >> n;
        input >> l;
        for (int x = 0; x < n; x++) {
            input >> word;
            starts[x] = word;
        }
        for (int x = 0; x < n; x++) {
            input >> word;
            ends1[x] = word;
        }
        best = l + 1;
        recursion(0, 0);
        if (best == l + 1) {
            output << "Case #" << i + 1 << ": NOT POSSIBLE" << endl;
        } else {
            output << "Case #" << i + 1 << ": " << best << endl;
        }
    }
    return 0;
}
