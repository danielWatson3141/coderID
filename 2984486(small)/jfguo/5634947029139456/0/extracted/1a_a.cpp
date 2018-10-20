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

void split(const vector<long long> &outlets, vector<long long> &outlets0, vector<long long> &outlets1, int L) {
    for (int i = 0; i < outlets.size(); ++i) {
        if ((outlets[i]>>L)&1) outlets1.push_back(outlets[i]); else outlets0.push_back(outlets[i]);
    }
}

void reverse(vector<long long> &outlets, int L) {
    for (int i = 0; i < outlets.size(); ++i) {
        outlets[i] = ~outlets[i];
        outlets[i] &= (1<<L)-1;
    }
}

int calc(const vector<long long> &outlets, const vector<long long> &required, int L)
{
    if (L == 0 || outlets.size() == 0) return 0;
    L--;

    vector<long long> outlets0;
    vector<long long> outlets1;
    vector<long long> required0;
    vector<long long> required1;

    split(outlets, outlets0, outlets1, L);
    split(required, required0, required1, L);

    int ans = -1;

    if (outlets0.size() == required0.size()) {
        int t1 = calc(outlets0, required0, L);
        int t2 = calc(outlets1, required1, L);
        if (t1 != -1 && t2 != -1) ans = t1 + t2;
    }

    if (outlets0.size() == required1.size()) {
        reverse(outlets0, L);
        reverse(outlets1, L);
        int t1 = calc(outlets0, required1, L);
        int t2 = calc(outlets1, required0, L);
        if (t1 != -1 && t2 != -1) {
            int t = t1 + t2 + 1;
            if (ans == -1 || t < ans) ans = t;
        }
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
    for (int m = 0; m < (1<<L); ++ m) {
        vector<long long> t = outlets;
        for (int i = 0; i < L; ++i) if ((m>>i)&1) {
            for (int j = 0; j < t.size(); ++j) {
                t[j] ^= (1<<i);
            }
        }

        sort(t.begin(), t.end());

        if (t == required) {
            int a = bn(m);
            if (ans == -1 || a < ans) ans = a;
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
