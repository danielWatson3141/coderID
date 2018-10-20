#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define u64 unsigned long long

const u64 MASK[64] = {
0x0000000000000001, 0x0000000000000002, 0x0000000000000004, 0x0000000000000008,
0x0000000000000010, 0x0000000000000020, 0x0000000000000040, 0x0000000000000080,
0x0000000000000100, 0x0000000000000200, 0x0000000000000400, 0x0000000000000800,
0x0000000000001000, 0x0000000000002000, 0x0000000000004000, 0x0000000000008000,
0x0000000000010000, 0x0000000000020000, 0x0000000000040000, 0x0000000000080000,
0x0000000000100000, 0x0000000000200000, 0x0000000000400000, 0x0000000000800000,
0x0000000001000000, 0x0000000002000000, 0x0000000004000000, 0x0000000008000000,
0x0000000010000000, 0x0000000020000000, 0x0000000040000000, 0x0000000080000000,
0x0000000100000000, 0x0000000200000000, 0x0000000400000000, 0x0000000800000000,
0x0000001000000000, 0x0000002000000000, 0x0000004000000000, 0x0000008000000000,
0x0000010000000000, 0x0000020000000000, 0x0000040000000000, 0x0000080000000000,
0x0000100000000000, 0x0000200000000000, 0x0000400000000000, 0x0000800000000000,
0x0001000000000000, 0x0002000000000000, 0x0004000000000000, 0x0008000000000000,
0x0010000000000000, 0x0020000000000000, 0x0040000000000000, 0x0080000000000000,
0x0100000000000000, 0x0200000000000000, 0x0400000000000000, 0x0800000000000000,
0x1000000000000000, 0x2000000000000000, 0x4000000000000000, 0x8000000000000000,
};

struct testcase {
    int n, l;
    u64 init[10];
    u64 req[10];
};

vector<testcase*> cases;

bool readFile();
void writeFile(vector<string*> towrite);
void sort(vector<u64> &v, int left, int right, bool ascend);
int partition(vector<u64> &v, int lefti, int righti, int pivoti, bool ascend);
void swap(vector<u64> &v, int firstindex, int secondindex);

// counts # with bit on
int count(testcase *tc, bool out, int sw) {
    int result = 0;
    if(out) {
        for(int i = 0; i < tc->n; i++) {
            if(tc->init[i] & MASK[sw])
                result++;
        }
    }
    else {
        for(int i = 0; i < tc->n; i++) {
            if(tc->req[i] & MASK[sw])
                result++;
        }
    }
    return result;
}

void flip(testcase *tc, int sw) {
    for(int i = 0; i < tc->n; i++) {
        tc->init[i] ^= MASK[sw];
    }
}

int solve(testcase *tc) {
    int result = 0;

    for(int i = 0; i < tc->l; i++) {
        int curr = count(tc, true, i);
        int required = count(tc, false, i);
        if(curr != required) {
            if(tc->n - curr == required) {
                result++;
                flip(tc, i);
            }
            else
                return -1;
        }
    }

    vector<u64> outlets;
    vector<u64> gadgets;
    for(int i = 0; i < tc->l; i++) {
        outlets.push_back(tc->init[i]);
        gadgets.push_back(tc->req[i]);
    }

    sort(outlets, 0, tc->l-1, true);
    sort(gadgets, 0, tc->l-1, true);

    for(int i = 0; i < tc->l; i++) {
        if(outlets[i] != gadgets[i])
            return -1;
    }

    return result;
}

int main(int argc, char **argv) {
    readFile();

    vector<string*> towrite;

    for(int i = 0; i < cases.size(); i++) {
        int result = solve(cases[i]);

        stringstream stream;

        stream << "Case #" << i+1 << ": ";

        if(result != -1)
            stream << result;
        else stream << "NOT POSSIBLE";

        string *s = new string( stream.str() );
        towrite.push_back(s);
    }

    writeFile(towrite);

    return 0;
}


//-------------------------------Helper Functions-------------------------------


void sort(vector<u64> &v, int left, int right, bool ascend) {
    if(left < right) {
        int pivotindex = left;

        int newpivotindex = partition(v, left, right, pivotindex, ascend);

        sort(v, left, newpivotindex - 1, ascend);
        sort(v, newpivotindex + 1, right, ascend);
    }
}

int partition(vector<u64> &v, int lefti, int righti, int pivoti, bool ascend) {
    u64 pivot = v[pivoti];
    swap(v, pivoti, righti);

    int tempindex = lefti;

    for(int i = lefti; i < righti; i++) {
        if(ascend ? (v[i] < pivot) : (v[i] > pivot)) {
            swap(v, i, tempindex);
            tempindex++;
        }
    }

    swap(v, tempindex, righti);
    return tempindex;
}

void swap(vector<u64> &v, int firstindex, int secondindex) {
    u64 temp = v[firstindex];
    v[firstindex] = v[secondindex];
    v[secondindex] = temp;
}

bool readFile() {
    std::string line;
    std::ifstream cfile("charge.in");

    if(cfile.is_open()) {
        getline(cfile, line);
        int num = std::stoi(line);
        for(int i = 0; i < num; i++) {
            getline(cfile, line);
            testcase *loaded = new testcase();
            std::string::size_type sz = 0;
            loaded->n = std::stoi(line);
            line = line.substr(sz);
            loaded->l = std::stoi(line);

            getline(cfile, line);
            for(int j = 0; j < loaded->n; j++) {
                loaded->init[j] = std::stoull(line, &sz, 2);
                line = line.substr(sz);
            }

            getline(cfile, line);
            for(int j = 0; j < loaded->n; j++) {
                loaded->req[j] = std::stoull(line, &sz, 2);
                line = line.substr(sz);
            }

            cases.push_back(loaded);
        }
        cfile.close();
    }
    else return false;

    return true;
}

void writeFile(vector<string*> towrite) {
    ofstream out;
    out.open("charge.out");
    for(unsigned int i = 0; i < towrite.size(); i++) {
        out << *towrite[i] << endl;
    }
    out.close();
}
