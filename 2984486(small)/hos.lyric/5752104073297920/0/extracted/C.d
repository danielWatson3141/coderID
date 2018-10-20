import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

//	Input
string[] tokens;
int tokenId = 0;
string readToken() { for (; tokenId == tokens.length; ) tokens = readln.split, tokenId = 0; return tokens[tokenId++]; }
int readInt() { return to!int(readToken); }
long readLong() { return to!long(readToken); }
real readReal() { return to!real(readToken); }

//	chmin/chmax
void chmin(T)(ref T t, const T f) { if (t > f) t = f; }
void chmax(T)(ref T t, const T f) { if (t < f) t = f; }

//	Pair
struct Pair(S, T) {
	S x; T y;
	int opCmp(ref const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	string toString() const { return "(" ~ to!string(x) ~ ", " ~ to!string(y) ~ ")"; }
}
auto pair(S, T)(S x, T y) { return Pair!(S, T)(x, y); }

//	Array
int binarySearch(T)(T[] as, bool delegate(T) test) {
	int low = -1, upp = as.length; for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp;
}
int lowerBound(T)(T[] as, T val) { return as.binarySearch((T a){ return (a <  val); }); }
int upperBound(T)(T[] as, T val) { return as.binarySearch((T a){ return (a <= val); }); }
T[] unique(T)(T[] as) { T[] bs; foreach (a; as) if (bs == null || bs[$ - 1] != a) bs ~= a; return bs; }



void main(string[] args) {
	immutable N = 1000;
	real[][] dp = new real[][](N, N);
	foreach (i; 0 .. N) foreach (j; 0 .. N) {
		dp[i][j] = (i == j) ? 1.0 : 0.0;
	}
	foreach (i; 0 .. N) {
		foreach (j; 0 .. N) if (j != i) {
			dp[j][] = (dp[j][] * (N - 1) + dp[i][]) / N;
		}
		dp[i][] = 1.0 / N;
	}
// writeln(dp);
	struct Test {
		int id;
		real val;
		string ans;
	}
	Test[] tests;
	for (int TC = readInt, tc = 1; tc <= TC; ++tc) {
		readInt;
		int[] A = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
		}
		real sum = 0.0;
		foreach (i; 0 .. N) {
			sum += dp[i][A[i]];
		}
		tests ~= Test(tc, sum, "?");
	}
	sort!"a.val > b.val"(tests);
	foreach (int i, ref test; tests) {
		test.ans = (i < tests.length / 2) ? "BAD" : "GOOD";
	}
	sort!"a.id < b.id"(tests);
	foreach (test; tests) {
		writeln("Case #", test.id, ": ", test.ans);
	}
}

