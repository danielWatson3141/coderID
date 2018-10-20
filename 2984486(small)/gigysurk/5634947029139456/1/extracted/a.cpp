
#include <inttypes.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
typedef uint32_t pattern;

pattern make_pattern(const string &s)
{
    size_t sz = s.size();
    uint32_t result = 0;

    for (size_t i=0; i<sz; ++i) {
        if (s[i] == '1')
            result = result*2 + 1;
        else
            result = result*2;
    }

    // cerr << s << " " << result << endl;

    return result;
}

int count_ones(pattern a)
{
    pattern tmp  = (a    & 0x55555555) + ((a    & 0xaaaaaaaa) >> 1);
    pattern tmp2 = (tmp  & 0x33333333) + ((tmp  & 0xcccccccc) >> 2);
    pattern tmp3 = (tmp2 & 0x0f0f0f0f) + ((tmp2 & 0xf0f0f0f0) >> 4);
    pattern tmp4 = (tmp3 & 0x00ff00ff) + ((tmp3 & 0xff00ff00) >> 8);
    pattern tmp5 = (tmp4 & 0x0000ffff) + ((tmp4 & 0xffff0000) >> 16);

    return (int)tmp5;
}

int hamming_dist(pattern a, pattern b)
{
    return count_ones(a ^ b);
}

string solve()
{
    int n, l;
    vector<pattern> flow;
    vector<pattern> req;

    cin >> n >> l;

    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        flow.push_back(make_pattern(s));
    }
    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        req.push_back(make_pattern(s));
    }

    vector<pattern> flow0 = flow;
    pattern req0 = req[0];

    sort(flow0.begin(), flow0.end(),
         [=] (pattern i, pattern j) { return hamming_dist(i, req0) < hamming_dist(j, req0); });

    // fprintf(stderr, "req0 = %x\n", req0);
    // for_each(flow0.begin(), flow0.end(),
    //          [] (pattern i) {
    //              fprintf(stderr, " -> %x\n", i);
    //          });

    for (const pattern &p: flow0) {
        pattern switches = p ^ req0;
        ostringstream os;

        for (const pattern &r: req) {
            pattern r_ = r ^ switches;
            if (find(flow0.begin(), flow0.end(), r_) == flow0.end()) {
                goto nextsw;
            }
        }

        os << count_ones(switches);
        return os.str();

    nextsw:
        ;
    }

    return string("NOT POSSIBLE");
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for (int i=1; i<=t; ++i) {
        auto s = solve();
        cout << "Case #" << i << ": " << s << "\n";
    }

    return 0;
}
