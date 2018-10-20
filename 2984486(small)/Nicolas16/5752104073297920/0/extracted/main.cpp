#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <time.h>  

using namespace std;


int main()
{
	int T;
	int N = 1000;
	
	/*
	
	double proba[100][1001][1000]; // proba que après x coup, 0 soit en position y
	
	for(int h = 0; h < 100; h++)
	{
		fprintf(stderr, "Calcul %d\n", h);
		for(int i = 0; i < N; i++) proba[h][0][i] = 0;
		proba[h][0][h] = 1;
	
		for(int c = 0; c < N; c++)
		{
			// (c+1)eme coup : on intervertit c avec un autre
			// proba 1/1000 de mettre 0 en c
			// proba 999/1000 de le laisser où il est
		
			// Si 0 est en c (proba[c][c]), alors il va aller quelque part n'importe ou
			// Sinon, il a 1/N d'aller en c et (N-1)/N de rester là
	
			for(int i = 0; i < N; i++)
			{
				proba[h][c+1][i] = 0;
			}
		
			for(int i = 0; i < N; i++)
			{
				if(i == c)
				{
					for(int j = 0; j < N; j++) proba[h][c+1][j] += proba[h][c][c]/(double)N;
				}
				else
				{
					proba[h][c+1][i] += proba[h][c][i]*(N-1)/(double)N;
					proba[h][c+1][c] += proba[h][c][i]/(double)N;
				}
			}
		}
		
		
		printf("Probas pour %d : \n", h);
		
		for(int i = 0; i < N; i++)
		{
			printf("En %d : proba %lf\n", i, proba[h][N][i]);
		}
		
	}
	
	*/
	
	
	int x;
	
	scanf("%d", &T);
	
	
	vector<int> e;
	

	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		
		scanf("%d", &N);
		
		int evidence = 0;
		
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &x);
			if(x < 500)
			{
				if(i < x)
				{
					evidence++;
				}
			}
		}
		
		e.push_back(evidence);
		
		//printf("Nb evidences : %d/100\n", evidence);
		
		if(evidence <= 137) printf("GOOD\n");
		else printf("BAD\n");
		
	}
	
	/*
	sort(e.begin(), e.end());
	
	for(int i = 0; i < e.size(); i++)
	{
		printf("%d : %d\n", i, e[i]);
	}
	*/
	


	return 0;
}
