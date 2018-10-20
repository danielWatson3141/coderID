#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Connected[1001][3];

void AddLine(int x, int y)
{
	if( Connected[x][0] == 0 )
		Connected[x][0] = y;
	else if(Connected[x][1] == 0)
		Connected[x][1] = y;
	else if(Connected[x][2] == 0)
		Connected[x][2] = y;
}

int isLeaf(int x)
{
	if( Connected[x][1] == 0)
		return 1;
	else
		return 0;
}

void deleteLine(int x, int y)
{
	if( Connected[x][0] == y)
	{
		Connected[x][0] = Connected[x][1];
		Connected[x][1] = Connected[x][2];
		Connected[x][2] = 0;
	}
	else if( Connected[x][1] == y)
	{
		Connected[x][1] = Connected[x][2];
		Connected[x][2] = 0;
	}
	else if( Connected[x][2] == y)
		Connected[x][2] = 0;
}

void deleteNode(int x)
{
	if( Connected[x][0] != 0)
		deleteLine(Connected[x][0], x);
	if( Connected[x][1] != 0)
		deleteLine(Connected[x][1], x);
	if( Connected[x][2] != 0)
		deleteLine(Connected[x][2], x);

	Connected[x][0] = 0;
	Connected[x][1] = 0;
	Connected[x][2] = 0;

}

int isAvailable(int x)
{
	if( Connected[x][0] == 0)
		return 0;
	else
		return 1;
}
int isDelete(int x)
{
	int parent1;
	int parent2;
	int parent3;

	if( isLeaf(x) == 0)
		return 0;

	parent1 = Connected[x][0];

	if( Connected[parent1][2] != 0)		// is full tree
		return 0;

	if( Connected[parent1][0] == x)
		parent2 = Connected[parent1][1];
	else
		parent2 = Connected[parent1][0];

	if( isLeaf(parent2))
		return 0;

	if( Connected[parent2][2] != 0)
		return 0;

	return 1;
}
int main()
{
	int T;
	int N;
	
	int i,j,k;
	int testcase;

	scanf("%d", &T);

	for(testcase = 0; testcase < T; testcase++)
	{
		int deleteCnt = 0;
		int deleteCicle = 0;
		memset(Connected, 0, sizeof(Connected));
		scanf("%d", &N);
		for(i = 0; i < N -1 ; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			
			AddLine(x, y);
			AddLine(y, x);
		}
		
		do
		{
			deleteCicle = 0;
			// Find Leaf
			for(i = 1; i <= N; i++)
			{
				if( isAvailable(i) == 0)
					continue;

				if( isLeaf(i) && isDelete(i))	// leaf
				{
					deleteNode(i);
					deleteCicle = 1;
					deleteCnt++;
					break;
				}

			}
		} while(deleteCicle > 0);

		printf("Case #%d: %d\n", testcase + 1, deleteCnt);
	}

	return 0;
}