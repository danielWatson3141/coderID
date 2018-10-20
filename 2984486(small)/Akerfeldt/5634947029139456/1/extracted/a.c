#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

__int64 seta[150];
__int64 setb[150];
__int64 setaa[150];
__int64 setbb[150];
int numCandidates;
__int64 *candidates;
int numNewCandidates;
__int64 *newCandidates;

int compare (const void * a, const void * b)
{
  return ( *(__int64*)a - *(__int64*)b );
}


int solve(int N, int L)
{
	int suma, sumb, i, j, k, mink;
	__int64 diff, *temp;

	k=0;
	diff=0;
	for(i=0; i<L; i++)
	{
		suma = sumb = 0;
		for(j=0; j<N; j++)
		{
			if(setaa[j] & 1 == 1)
				suma++;
			if(setbb[j] & 1 == 1)
				sumb++;
			
			setaa[j] /= 2;
			setbb[j] /= 2;
		}
		if(suma != sumb)
		{
			if(suma != (N - sumb))
			{
				return -1;
			}
			else
			{
				k++;
			}
		}
	}
	
	numCandidates=0;
	candidates = setaa;
	newCandidates = setbb;
	for(i=0; i<N; i++)
	{
		numNewCandidates=0;
		for(j=0; j<N; j++)
		{
			diff = seta[i] ^ setb[j];
			if(i == 0)
			{
				candidates[numCandidates] = diff;
				numCandidates++;
			}
			else
			{
				if(bsearch (&diff, candidates, numCandidates, sizeof(__int64), compare) != NULL)
				{
					newCandidates[numNewCandidates] = diff;
					numNewCandidates++;
				}
			}
		}

		if(i != 0)
		{
			numCandidates = numNewCandidates;
			if(numCandidates == 0)
			{
				printf("%d %d\n",i, N);
				return -1;
			}
			else
			{
				temp = candidates;
				candidates = newCandidates;
				newCandidates = temp;
				qsort(candidates, numCandidates, sizeof(__int64), compare);
			}
		}
		else
			qsort(candidates, numCandidates, sizeof(__int64), compare);
	}

	mink = L;
	for(i=0; i<numCandidates; i++)
	{
		k=0;
		for(j=0; j<L; j++)
		{
			if(candidates[i] & 1 == 1)
			{
				k++;
			}
			candidates[i] /= 2;
		}
		if(k < mink) mink = k;
	}

	return mink;
}

int main(int argc, char *argv[])
{
	char buf[65536];
	char *pch;
	int  i, j, k, T, N, L;
	int a,b, res;
	__int64 temp;

	gets(buf);
	sscanf(buf, "%d", &T);
	for(i=0; i<T; i++)
	{
		gets(buf);
		sscanf(buf, "%d %d", &N, &L);
		
		j=0;
		gets(buf);
		pch = strtok (buf," ");
		while (pch != NULL)
		{
			temp = 0;
			for(k=0; k<L; k++)
			{
				if(pch[k] == '1')
					temp += (1 << (L-(k+1)));
			}
			setaa[j] = seta[j] = temp;
			pch = strtok (NULL, " ");
			j++;
		}

		j=0;
		gets(buf);
		pch = strtok (buf," ");
		while (pch != NULL)
		{
			temp = 0;
			for(k=0; k<L; k++)
			{
				if(pch[k] == '1')
					temp += (1 << (L-(k+1)));
			}
			setbb[j] = setb[j] = temp;
			pch = strtok (NULL, " ");
			j++;
		}

		res = solve(N, L);
		if(res == -1)
			printf("Case #%d: NOT POSSIBLE\n",i+1);
		else
			printf("Case #%d: %d\n",i+1, res);
	}

	return 0;
}