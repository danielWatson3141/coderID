#include <iostream>
#include <set>
using namespace std;

int N,L;
string F[150];
string D[150];


int R;
bool changes[150][40];
int countchanges[150];

void set_initial() {
	for(int i = 0; i < N; i++) {
		countchanges[i] = 0;
		for(int j = 0; j < L; j++) {
			changes[i][j] = false;
			if(F[i][j] != D[0][j]) {
				changes[i][j] = true;
				countchanges[i]++;
			}
		}
	}
}

bool valid(int x) {
	for(int i = 0; i < N; i++) {
		bool found = false;
		for(int j = 0; j < N && !found; j++) {
			bool same = true;
			for(int k = 0; k < L && same; k++) {
				if(changes[x][k] && F[i][k] == D[j][k])
					same = false;
				else if(!changes[x][k] && F[i][k] != D[j][k])
					same = false;
			}
			if(same == true) {
				found = true;
			}
		}
		if(!found)
			return false;
	}	
	return true;
}

void handle_input() {
	cin >> N >> L;
	
	R = 0;
	for(int i = 0; i < N; i++)
		cin >> F[i];
	for(int i = 0; i < N; i++)
		cin >> D[i];

}

void process_testcase() {
	set_initial();
	int best = 155;
	for(int i = 0; i < N; i++)
		if(valid(i))
			best = min(best, countchanges[i]);

	if(best == 155)
		cout << "NOT POSSIBLE" << endl;
	else
		cout << best << endl;
}
	
int main() {
	int T; 
	cin >> T;
	for(int Z = 1; Z <= T; Z++) {
		cout << "Case #" << Z << ": ";
		handle_input();
		process_testcase();
	}
}