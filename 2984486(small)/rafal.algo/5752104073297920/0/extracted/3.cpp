#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int tab[1001];

int main()
{
	srand(time(NULL));
	
	int T;
	cin >> T;
	
	for(int i = 1; i <= T; i++)
	{
		int n;
		cin >> n;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> tab[i];
		}
		
		if(tab[1] == 0 )
			cout << "Case #" << i << ": BAD" << endl;
		else
		{
			bool tt = rand() % 2; 
			
			if(tt == true)
			{
				cout << "Case #" << i << ": GOOD" << endl;
			}
			else
			{
				cout << "Case #" << i << ": BAD" << endl;
			}
		}
	}

	return 0;
}
