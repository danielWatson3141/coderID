#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct testcase {
    int n;
    int perm[1000];
};

vector<testcase*> cases;

bool readFile();
void writeFile(vector<string*> towrite);

bool solve(testcase *tc) {
    int forward = 0;
    int back = 0;

    for(int i = 0; i < tc->n; i++) {
        if(tc->perm[i] > i && tc->perm[i] < i+250)
            back++;
        else if(tc->perm[i] < i && tc->perm[i] > i-250)
            forward++;
    }

    if(back > forward + 35)
        return false;
    else return true;
}

int main(int argc, char **argv) {
    readFile();

    vector<string*> towrite;

    for(int i = 0; i < cases.size(); i++) {
        bool result = solve(cases[i]);

        stringstream stream;

        stream << "Case #" << i+1 << ": ";

        if(result)
            stream << "GOOD";
        else stream << "BAD";

        string *s = new string( stream.str() );
        towrite.push_back(s);
    }

    writeFile(towrite);

    return 0;
}


//-------------------------------Helper Functions-------------------------------


bool readFile() {
    std::string line;
    std::ifstream cfile("shuffle.in");

    if(cfile.is_open()) {
        getline(cfile, line);
        int num = std::stoi(line);
        for(int i = 0; i < num; i++) {
            getline(cfile, line);
            testcase *loaded = new testcase();
            std::string::size_type sz = 0;
            loaded->n = std::stoi(line);

            getline(cfile, line);
            for(int j = 0; j < loaded->n; j++) {
                loaded->perm[j] = std::stoi(line, &sz);
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
    out.open("shuffle.out");
    for(unsigned int i = 0; i < towrite.size(); i++) {
        out << *towrite[i] << endl;
    }
    out.close();
}
