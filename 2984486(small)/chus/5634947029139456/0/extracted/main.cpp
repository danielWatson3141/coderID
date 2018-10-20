#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <bitset>
using namespace std;
static_assert(sizeof(long long) == 8, "Invalid data size");

template<typename IN>
void skip_line(IN &fin)
{
    string line;
    getline(fin, line);
}
int count_num_ones(int64_t num)
{
    std::bitset<sizeof(int64_t) * 8> b(num);
    return b.count();
}
template<typename IN>
int read_number(IN &fin)
{
    int number;
    fin >> number;
    skip_line(fin);
    return number;
}
template<typename IN>
void read_number_list(vector<int64_t> &list, int n, IN &fin)
{
    string line;
    for(int i=0;i<n;++i) {
        fin >> line;
        list.push_back(strtoll(line.c_str(), nullptr, 2));
    }
    skip_line(fin);
}

template<typename IN, typename OUT>
void solve_charging(IN &fin, OUT &fout, int t)
{
    // Read data
    int n, l;
    fin >> n >> l;
    skip_line(fin);
    vector<int64_t> a, b;
    read_number_list(a, n, fin);
    read_number_list(b, n, fin);

    // Brute force!
    vector<set<int64_t>> options(n);
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            options[i].insert(a[i] ^ b[j]);
        }
    }
    set<int64_t> solution = options[0];
    for(int i=1;i<n;++i) {
        set<int64_t> intersect;
        set_intersection(solution.begin(),solution.end(),
                         options[i].begin(), options[i].end(),
                         std::inserter(intersect, intersect.begin()));
        solution = intersect;
    }

    // Output
    if(solution.size() == 0){
        fout << "Case #" << t << ": NOT POSSIBLE" << endl;
    }
    else {
        vector<int> num_ops(solution.size());
        transform (begin(solution), end(solution), begin(num_ops), count_num_ones);
        fout << "Case #" << t << ": " << *min_element(begin(num_ops), end(num_ops)) << endl;
    }
}

int main()
{
    const int t = read_number(cin);
    for(int i=0;i<t;++i) {
        solve_charging(cin, cout, i+1);
    }
    return 0;
}
