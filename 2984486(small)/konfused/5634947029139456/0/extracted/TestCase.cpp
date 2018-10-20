#include "StdAfx.h"
#include "TestCase.h"


TestCase::TestCase(void)
{
	scanf("%d", &N);
	scanf("%d", &L);

	for(int i = 0; i < N; i++)
		scanf("%s", ip[i]);

	for(int i = 0; i < N; i++)
		scanf("%s", op[i]);

	for(int i = 0; i< N;i++)
	{
		for(int j = i+1; j< N; j++)
		{
			char temp[11];
			if(strcmp(ip[i],ip[j])> 0)
			{
				strcpy(temp,ip[i]);
				strcpy(ip[i],ip[j]);
				strcpy(ip[j],temp);
			}

			if(strcmp(op[i],op[j])> 0)
			{
				strcpy(temp,op[i]);
				strcpy(op[i],op[j]);
				strcpy(op[j],temp);
			}
		}
	}
}


TestCase::~TestCase(void)
{
}



bool TestCase::equals()
{
	for(int i = 0; i < N; i++)
		if(strcmp(ip[i],op[i]))
			return false;
	return true;
}


int TestCase::solve()
{
	if(equals())
		return 0;

	int range = 1 << L;
	for(int i = 1; i < range; i++)
	{
		char bkp[10][11];
		for(int j = 0; j < N; j++)
			strcpy(bkp[j],ip[j]);

		for(int k = 0; k < L; k++)
		{
			int bit = 1 << k;
			int bitOn = i&bit;
			if(bitOn)
			{
				for(int j = 0; j < N; j++)
				{
					if(ip[j][k] == '1')
						ip[j][k] = '0';
					else
						ip[j][k] = '1';
				}
			}
		}

			//Sort ip
		for(int k = 0; k< N;k++)
		{
			for(int j = k+1; j< N; j++)
			{
				char temp[11];
				if(strcmp(ip[k],ip[j])> 0)
				{
					strcpy(temp,ip[k]);
					strcpy(ip[k],ip[j]);
					strcpy(ip[j],temp);
				}
			}
		}

		if(equals())
		{
			int count = 0;
			for(int k = 0; k < L; k++)
			{
				int bit = 1 << k;
				int bitOn = i&bit;
				if(bitOn)
					count ++;
			}
			return count;
		}

		for(int j = 0; j < N; j++)
			strcpy(ip[j],bkp[j]);
	}

	return -1;
}