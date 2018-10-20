#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

long long s2i(string s) {
    long long ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        ans <<= 1;
        if (s[i] == '1') ans++;
    }
    return ans;
}

int bn(long long a) {
    int ans = 0;
    while (a) {
        ++ans;
        a &= a-1;
    }
    return ans;
}
void print(vector<long long> a) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

string calc() {
    int N, L;
    cin >> N >> L;
    vector<long long> outlets;
    vector<long long> required;
    string s;
    for (int i = 0; i < 2*N; ++i) {
        cin >> s;
        if (i < N) {
            outlets.push_back(s2i(s));
        } else {
            required.push_back(s2i(s));
        }
    }

    sort(required.begin(), required.end());

    int ans = -1;
    for (int i = 0; i < N; ++i) {
        vector<long long> o1 = outlets;

        int a = outlets[0];
        int b = required[i];

        for (int i = 0; i < outlets.size(); ++i) {
            o1[i] ^= (a^b);
            long long one = 1;
            o1[i] &= (one<<L)-1;
        }

        sort(o1.begin(), o1.end());
        if (o1 == required) {
            int t = bn(a^b);
            if (ans == -1 || t < ans) ans = t;
        }
    }

    if (ans == -1) return "NOT POSSIBLE";
    stringstream ss;
    ss << ans;
    return ss.str();
}

int main(void)
{
	int T;
	cin >> T;

	for (int ca=1; ca<=T; ++ca) {
		cout << "Case #" << ca << ": " << calc() << endl;
	}
	return 0;
}
