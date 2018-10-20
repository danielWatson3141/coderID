#include <iostream>

using namespace std;

int T;
int N;

int seq[1000];

int reverse_order_count()
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (seq[i] > seq[j])
				count++;
		}
	}
	return count;

}
int main()
{
	int good = 0;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> seq[j];

		cout << "Case #" << i << ": " ;

		if (reverse_order_count() < N * (N - 1) / 4.0)
			cout << "BAD" << endl;
		else 
			cout << "GOOD" << endl;
		
	}
}
