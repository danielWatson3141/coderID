#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;
vector<string> powerSource;
vector<string> powerMatch;
int match(int level, vector<vector<int> > matches);
int N,L;
typedef unsigned long long ll;
int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    
    int K;
    in>>K;
    for(int k=0;k<K;k++) {
        in>>N>>L;
        powerSource.clear();
        powerMatch.clear();
        for(int i=0;i<N;i++) {
            string str;
            in>>str;
            powerSource.push_back(str);
        }
        for(int i=0;i<N;i++) {
            string str;
            in>>str;
            powerMatch.push_back(str);
        }
        vector<vector<int> > matches;
        for(int i=0;i<N;i++) {
            matches.push_back(vector<int>());
            for(int i2=0;i2<N;i2++)
                matches[i].push_back(i2);
        }
        out << "Case #"<<(k+1)<<": ";
        int result = match(0, matches);
        if(result == -1)
            out << "NOT POSSIBLE";
        else
            out << result;
        out << "\n";
    }
    out.close();
}
int match(int level, vector<vector<int> > matchesO) {
    if(level == L) {
        bool* taken = new bool[N];
        for(int i=0;i<N;i++)
            taken[i] = false;
        for(int i=0;i<N;i++)
            for(vector<int>::iterator iter = matchesO[i].begin();iter!=matchesO[i].end();iter++)
                taken[*iter] = true;
        for(int i=0;i<N;i++)
            if(!taken[i])
                return -1;
        return 0;
    }
    vector<vector<int> > matches = vector<vector<int> >();
    vector<vector<int> > matches2 = vector<vector<int> >();
    for(int i=0;i<N;i++) {
        matches.push_back(vector<int>());
        for(vector<int>::iterator iter = matchesO[i].begin(); iter!= matchesO[i].end();iter++)
            matches[i].push_back(*iter);
    }
    for(int i=0;i<N;i++) {
        matches2.push_back(vector<int>());
        for(vector<int>::iterator iter = matches[i].begin(); iter!= matches[i].end();iter++)
            matches2[i].push_back(*iter);
    }
    bool skip = false;
    for(int i=0;i<N;i++) {
        for(vector<int>::iterator iter = matches[i].begin();iter != matches[i].end();) {
            if(powerSource[i].at(level) != powerMatch[*iter].at(level))
                iter = matches[i].erase(iter);
            else
                iter++;
        }
        if(matches[i].empty()) {
            skip = true;
            break;
        }
    }
    int first = -1;
    if(!skip) {
        int match1 = match(level+1,matches);
        if(match1 != -1) {
            first = match1;
        }
    }
    skip = false;
    for(int i=0;i<N;i++) {
        for(vector<int>::iterator iter = matches2[i].begin();iter != matches2[i].end();) {
            if(powerSource[i].at(level) == powerMatch[*iter].at(level))
                iter = matches2[i].erase(iter);
            else
                iter++;
        }
        if(matches2[i].empty()) {
            skip = true;
            break;
        }
    }
    if(!skip) {
    int match2 = match(level+1,matches2);
        if(match2 != -1) {
            if(first != -1)
                return min(match2 + 1,first);
            else
                return match2 + 1;
        }
    }
    return max(-1, first);
}