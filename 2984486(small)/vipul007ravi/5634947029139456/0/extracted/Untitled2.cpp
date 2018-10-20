#include<bits/stdc++.h>
using namespace std;
void bubblesort(char array[200][200], int n)
{
	int c, d, swap;
	char temp[200];
	for (c = 0 ; c < ( n - 1 ); c++) {
    		for (d = 0 ; d < n - c - 1; d++) {
      			if (strcmp(array[d], array[d+1]) > 0) {
        			//swap       = array[d];
        			//array[d]   = array[d+1];
        			//array[d+1] = swap;
      				strcpy(temp, array[d]);
      				strcpy(array[d], array[d + 1]);
      				strcpy(array[d + 1], temp);
			}
    		}
  	}
}
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("my.out", "w", stdout);
	int n, t, i, j, k, l, y = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &l);
		char arr[200][200];
		char brr[200][200];
		char brrr[200][200];
		//string arr[200];
		//string brr[200];
		for (i = 0; i < n; i++)
			scanf("%s", arr[i]);
		for (i = 0; i < n; i++)
			scanf("%s", brrr[i]);
		int min = -1;
		//sort(arr, arr + n);
		bubblesort(arr, n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				strcpy(brr[j], brrr[j]);
			int crr[200] = {0};
			int ll = 0;
			//printf("%d\n", ll);
			for (j = 0; j < l; j++) {
				//printf("%s %d\n", arr[i], ll);
				if (arr[0][j] != brr[i][j]) {
					crr[j] = 1;
					ll++;
				//	printf("%s %d\n", brr[i], ll);		
				}
			}
			//printf("%d\n", ll);
			for (j = 0; j < n; j++) {
				for (k = 0; k < l; k++) {
					if (crr[k] == 1) {
						if (brr[j][k] == '1')
							brr[j][k] = '0';
						else
							brr[j][k] = '1';
					}
				}
			}
			//sort(brr, brr + n);
			bubblesort(brr, n);
			int f = 0;
			//for (i = 0; i < n; i++)
			//	printf("%s %s\n", arr[i], brr[i]);
			//printf("%d\n", ll);
			
			for (j = 0; j < n; j++) {
				if (strcmp(arr[j], brr[j]) != 0) {
					f = 1;
					break;
				}
			}
			if (f == 0) {
				if (min == -1)
					min = ll;
				else if (ll < min)
					min = ll;
			}
		}
		if (min == -1)
			printf("Case #%d: NOT POSSIBLE\n", y++);
		else
			printf("Case #%d: %d\n", y++, min);
	}
	return 0;
}
