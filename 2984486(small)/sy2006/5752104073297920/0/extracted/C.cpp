#include <cstdio>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

inline void R(int &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0'; ch=getchar());
	for (; ch>='0'; ch=getchar()) x = x*10 + ch-'0';
}
const int N = 1005;
int a[N], c[N], n = 1000, half = 500;
int sum(int a[], int n) {
	int ans = 0;
	for (int i=0; i<n; ++i)
		ans += a[i];
	return ans;
}
namespace cenbo{
	int c[10000], n = 1000;
	int query(int x){
		int ret(0);
		for (; x; x -= x&-x) ret += c[x];
		return ret;
	}
	void modify(int x){
		for (; x <= n; x += x&-x) ++c[x];
	}
	int inv(int *a, int _n){
		int ret(0);
		for (int i=0; i<=n; ++i) c[i] = 0;
		for (int i = 0; i < _n; ++i){
			ret += query(n-a[i]);
			modify(n-a[i]);
		}
		return ret;
	}
}
int big(int a[], int n) {
	int ans = 0;
	for (int i=0; i<n; ++i)
		ans += a[i] > i;
	return ans;
}
struct info {
	int s1, s2, s3, i1, i2, i3, b;
	void get() {
		s1 = sum(a, half);
		s2 = sum(a+250, half);
		s3 = sum(a+half, half);
		i1 = cenbo::inv(a, n);
		i2 = cenbo::inv(a, half);
		i3 = cenbo::inv(a+half, half);
		b = big(a, n);
	}
	bool check() {
		if (b >= 517) return 0;
		if (b < 510) return 1;
		if (i1 > 250000) return 1;
		if (i1 < 240000) return 0;
		if (s1 > s2 && s2 > s3) return 1;
		if (s2 - s1 > 2000 && s2 < s3) return 0;
		if (s3 - s2 > 2000 && s1 < s2) return 0;
		if (s3 - s2 > 1000 && s2 - s1 > 1000) return 0;
		return rand() & 1;
	}
} q[N];
int main() {
	int T; R(T);
	for (int i=1; i<=T; ++i) {
		R(n);
		for (int j=0; j<n; ++j) R(a[j]);
		q[i].get();
	}
	for (int i=1; i<=T; ++i) {
		printf("Case #%d: ", i);
		puts(q[i].check() ? "GOOD" : "BAD");
	}
	return 0;
}
