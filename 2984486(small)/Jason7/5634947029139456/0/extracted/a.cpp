#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{
	int T, t;
	int arra[4][4];
	int arrb[4][4];
	int rlt[4];
	int s1, s2, i, j;

	cin >> T;
	for(t = 1; t <= T; t++)
	{
		cin >> s1;
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				cin >> arra[i][j];
		cin >> s2;
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				cin >> arrb[i][j];
		
		s1--;
		s2--;		
		int cnt = 0;
		memset(rlt, 0, sizeof(rlt));
		for(i = 0; i < 4; i++)
			 for(j = 0; j < 4; j++)
				if(arra[s1][i] == arrb[s2][j])
					rlt[cnt++] = arra[s1][i];
		cout << "Case #" << t << ": ";
		
		if(cnt == 0)
			cout << "Volunteer cheated!" << endl;
		if(cnt == 1)
			cout << rlt[0] << endl;
		if(cnt > 1)
			cout << "Bad magician!" << endl;
	}
	return 0;
}
