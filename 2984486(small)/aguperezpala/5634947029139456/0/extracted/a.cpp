#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef std::unordered_set<std::string> HashSet;
//typedef std::unordered_map<std::string> HashMap;


static void
flip(std::vector<std::string>& v, int e)
{
    for (int i = 0; i < v.size(); ++i) {
        (v[i])[e] = (v[i])[e] == '1' ? '0' : '1';
    }
}

static bool
allMatch(std::vector<std::string>& v, const HashSet& f)
{
    for (int i = 0; i < v.size(); ++i) {
        if (f.find(v[i]) == f.end()) return false;
    }
    return true;
}
static long long total = 1<<30;

static long long
process(std::vector<std::string>& i, const HashSet& f, long long count, int current)
{
    if (allMatch(i,f)) {
        return count < total ? count : total;
    }
    if (current >= i[0].size()) return total;
    
    // turn this one and check it
    flip(i, current);
    long long c1 = process(i,f,count+1, current+1);
    // turn it back
    flip(i, current);
    long long c2 = process(i,f,count,current+1);
    return c1 < c2 ? c1 : c2;
}


int main(int argc, char** args)
{
    int count = 0;
    std::vector<std::string> initial;
    HashSet req;
    std::string tmp;

    // Read number of cases
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        // parse case i
        int N, L;
        std::cin >> N;
        std::cin >> L;
        initial.clear(); req.clear();
        
        for (int j = 0; j < N; ++j) {
            tmp.clear();
            std::cin >> tmp;
            initial.push_back(tmp);
        }
        for (int j = 0; j < N; ++j) {
            tmp.clear();
            std::cin >> tmp;
            req.insert(tmp);
        }
        
        
        // process case i
        std::cout << "Case #" << i+1 << ": ";
        const long long totalbad = 1<<30;
        total = totalbad;
        long long result = process(initial, req, 0, 0);
        if (result == totalbad) std::cout << "NOT POSSIBLE";
        else {
            std::stringstream ss;
            ss << result;
            std::cout << ss.str();
        }

        // print case i
        std::cout << "\n";   
    }
    
    
    return 0;
}
