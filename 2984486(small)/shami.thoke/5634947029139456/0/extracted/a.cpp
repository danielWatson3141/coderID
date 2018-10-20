#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int N, L;
	struct Holder {
	    string str;
	    int	row, col;
	    Holder(string s, int r, int c) : str(s), row(r), col(c) {} 
	};

bool check(int row, int col, const vector<vector<string> > mat)
{
    const string str = mat[row][col];
    set<int> rows, cols;
    rows.insert(row);
    cols.insert(col);
    for (int i = 0; i < N; ++i) {
	if (rows.find(i) != rows.end()) 
	    continue;
	for (int j = 0; j < N; ++j) {
	    if (cols.find(j) != cols.end()) 
	        continue;
	    if (mat[i][j] == str) {
		rows.insert(i);
		cols.insert(j);
	    }
	}
    }
    bool flag = (rows.size() == N) && (cols.size() == N);
    return flag;
}

int bits_diff(string a, string b) 
{
    int cnt = 0;
    for (int i = 0; i < L; ++i) {
	if (a[i] != b[i]) 
	    ++cnt;
    }
    return cnt;
}
string exor(string a, string b)
{
    string s;
    for (int i = 0; i < L; ++i) {
	if (a[i] == b[i]) {
	    s += "0";
	} else {
	    if (a[i] == '1' || b[i] == '1') {
		s += "1";
	    } else {
		s += "0";
	    }
	}
    }
    return s;
}
int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
	cin >> N >> L;
	vector<string>	A, R;
	for (int n = 0; n < N; ++n) {
	    string s;
	    cin >> s;
	    A.push_back(s);
	}
	for (int n = 0; n < N; ++n) {
	    string s;
	    cin >> s;
	    R.push_back(s);
	}
	vector<vector<string> > mat;
	for (int i = 0; i < N; ++i) {
	    vector<string> m;
	    for (int j = 0; j < N; ++j) {
		m.push_back(exor(R[i], A[j]));
	    }
	    mat.push_back(m);
	}
	/*
	for (int i = 0; i < N; ++i) {
	    for (int j = 0; j < N; ++j) {
		cout << mat[i][j] << " ";
	    }
	    cout << endl;
	}
	*/
	vector<Holder> D; 
	set<string> st;
	for (int i = 0; i < N; ++i) {
	    for (int j = 0; j < N; ++j) {
		if (check(i, j, mat)) {
		    if (st.find(mat[i][j]) != st.end())
		    	continue;
		    st.insert(mat[i][j]);
		    Holder h(mat[i][j], i, j);
		    D.push_back(h);
		}
	    }
	}

	cout << "Case #" << t << ": ";
	if (D.size() == 0) {
	    cout << "NOT POSSIBLE" << endl;
	} else {
	    int min_bits = 200;
	    for (int i = 0; i < D.size(); ++i) {
		int mn = bits_diff (R[ D[i].row ], A[ D[i].col ]);
		if (mn < min_bits) {
		    min_bits = mn;
		}
	    }
	    cout << min_bits << endl;
	}


    }
    return 0;
}

