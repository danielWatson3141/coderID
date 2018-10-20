#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char outlets[160][50], devices[160][50];
int visited[2000];
int min;
int size, length;
int current[50];
	
int valid(int len) {
	int i, j;
	static char used[160];
	memset(used, 0, sizeof(used));
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size; ++j)
			if (!used[j] && strncmp(outlets[i], devices[j], len + 1) == 0) {
				used[j] = 1;
//				printf("%d: %s match %s\n", len, outlets[i], devices[j]);
				break;
			}
		if (j >= size)
			return 0;
	}
	return 1;
}

void flip_bits(int position) {
	for (int i = 0; i < size; ++i) {
		if (outlets[i][position] == '1')
			outlets[i][position] = '0';
		else
			outlets[i][position] = '1';
	}
}

int DFS(int change, int bit) {
	if (change >= min)
		return 0;
	if (bit >= length) {
		if (change < min)
			min = change;
		return 0;
	}
	if (valid(bit))
		DFS(change, bit + 1);
	flip_bits(bit);
	if (valid(bit))
		DFS(change + 1, bit + 1);
	flip_bits(bit);
}

void run() {
	min = 1000;
	memset(visited, 0, sizeof(visited));
	scanf("%d%d", &size, &length);
	for (int i = 0; i < size; ++i)
		scanf("%s", &outlets[i]);
	for (int i = 0; i < size; ++i)
		scanf("%s", &devices[i]);
	DFS(0, 0);
	if (min == 1000)
		puts("NOT POSSIBLE");
	else
		printf("%d\n", min);
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int t = 1; t <= num_cases; ++t) {
        printf("Case #%d: ", t);
        run();
    }
    return 0;
}

