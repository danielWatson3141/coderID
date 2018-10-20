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
void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

//	Pair
struct Pair(S, T) {
	S x; T y;
	int opCmp(    const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
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



void prepare() {
	
}

class Solver : Thread {
	int caseId;
	this(int caseId) {
		this.caseId = caseId;
		super(&main);
	}
	void main() {
		try {
			run;
			stderr.writeln("DONE  Case #", caseId);
		} catch (Throwable e) {
			stderr.writeln("ERROR Case #", caseId, ": ", e.msg);
		} finally {
			stderr.flush;
		}
	}
	
	int N;
	int[] A, B;
	int[][] G;
	int ans;
	
	Pair!(int, int) solve(int u, int p) {
		int sz = 1;
		int opt;
		Pair!(int, int)[] subs;
		foreach (v; G[u]) if (v != p) {
			subs ~= solve(v, u);
		}
		if (subs.length < 2) {
			foreach (sub; subs) {
				sz += sub.x;
				opt += sub.x;
			}
		} else {
			sort!"a.x - a.y > b.x - b.y"(subs);
			foreach (i, sub; subs) {
				sz += sub.x;
				opt += (i < 2) ? sub.y : sub.x;
			}
		}
		return pair(sz, opt);
	}
	
	void run() {
		G = new int[][N];
		foreach (i; 0 .. N - 1) {
			G[A[i]] ~= B[i];
			G[B[i]] ~= A[i];
		}
		ans = N + 1;
		foreach (u; 0 .. N) {
			auto res = solve(u, -1);
// writeln(u," ",res);
			chmin(ans, res.y);
		}
	}
	
	void input() {
		N = readInt;
		A = new int[N - 1];
		B = new int[N - 1];
		foreach (i; 0 .. N - 1) {
			A[i] = readInt - 1;
			B[i] = readInt - 1;
		}
	}
	
	void output() {
		writeln("Case #", caseId, ": ", ans);
		stdout.flush;
	}
}

void main(string[] args) {
	bool parallel = false;
	foreach (arg; args) if (arg == "-p") parallel = true;
	prepare;
	auto solvers = new Solver[readInt];
	foreach (caseId, ref solver; solvers) solver = new Solver(caseId + 1);
	if (parallel) {
		foreach (solver; solvers) solver.input, solver.start;
		foreach (solver; solvers) solver.join, solver.output;
	} else {
		foreach (caseId, solver; solvers) {
			solver.input;
			solver.run;
			solver.output;
			stderr.writeln("DONE  Case #", caseId + 1);
			stderr.flush;
		}
	}
}

