#include <stdio.h>

int numOfBlocks = 0;
int N = 0, L = 0;
int i = 0, j = 0, k = 0;
long long source[160] = {0};
long long target[160] = {0};
long long copied[160] = {0};
long long tmpNumber = 0;
long long tmpLong = 0;
char inputCharArray[50];
int result = 0;

void quicksort(long long* data, int left, int right)
{
    if (left >= right) { return; }
    long long pivot = data[left];
    long long tmpValue = 0;
    int i = left + 1;
    int j = right;
    while (1)
    {
        while (i <= right)
        {
            if (data[i] > pivot)
            {
                break;
            }

            i = i + 1;
        }

        while (j > left)
        {
            if (data[j] < pivot)
            {
                break;
            }

            j = j - 1;
        }

        if (i > j) { break; }

        tmpValue = data[i], data[i] = data[j], data[j] = tmpValue;
    }

    // exchange data[left] and data[j]
    tmpValue = data[left], data[left] = data[j], data[j] = tmpValue;

    quicksort(data, left, j - 1);
    quicksort(data, j + 1, right);
}

int solveQuest() {
	int bits = 0, bestBits = 50;
	quicksort(target, 0, N - 1);
	for (tmpLong = 0; tmpLong < (1 << L) -1 ; tmpLong++) {
		for (j = 0; j < N; j++) {
			copied[j] = source[j] ^ tmpLong;
		}

		quicksort(copied, 0, N - 1);

#if 0
		// debug
		printf("tmpLong: %lld copied\n", tmpLong);
		for (j = 0; j < N; j++) {
			printf("%lld ", copied[j]);
		}
		printf("\n");
#endif

#if 0
		printf("target\n");
		for (j = 0; j < N; j++) {
			printf("%lld ", target[j]);
		}
		printf("\n");
#endif
		for (j = 0; j < N && copied[j] == target[j]; j++) ;
//		printf("%d %d copied[j]:%lld target[j]:%lld\n", j, N, copied[j-1], target[j-1]);
		if (j == N) {
			if (target[N-1] == copied[N-1]) {
				for (bits = 0, k = 0; k < L; k++) {
					bits +=  (tmpLong & (1 << k)) >> k;
				}
//				printf("bits: %d bestBits: %d \n", bits, bestBits);
				if (bits < bestBits) bestBits = bits;
			}
		}
	}

	return bestBits;
}

int main() {
	scanf("%d", &numOfBlocks);
	for (i = 0; i < numOfBlocks; i++) {
		scanf("%d %d", &N, &L);
		// printf("debug N:%d L:%d\n", N, L);

		// Handle source part
		for (j = 0; j < N; j++) {
			scanf("%lld", &tmpLong);
//			printf("debug: %lld ", tmpLong);

			for (k = 0; k < L && tmpLong != 0; k++) {
				tmpNumber += (tmpLong % 10) << k;
				tmpLong = tmpLong / 10;
			}
//			printf("debug: %lld\n", tmpNumber);
			source[j] = tmpNumber;
			tmpNumber = 0;
		}

		// Handle target part
		for (j = 0; j < N; j++) {
			scanf("%lld", &tmpLong);
//			printf("debug: %lld ", tmpLong);

			for (k = 0; k < L && tmpLong != 0; k++) {
				tmpNumber += (tmpLong % 10) << k;
				tmpLong = tmpLong / 10;
			}
//			printf("debug: %lld\n", tmpNumber);
			target[j] = tmpNumber;
			tmpNumber = 0;
		}

		// algorithm
		result = solveQuest();
		if (result > 40) {
			printf("Case #%d: NOT POSSIBLE\n", i+1);
		} else {
			printf("Case #%d: %d\n", i+1, result);
		}
		
	}
	return 0;
}