#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int origArr[1000][1000];

void parseInput(char* bufLine, int* numArr)
{
	char tmpStrArr[1002];
	char* tmp = bufLine; 	
	int len = 0, cnt = 0;
	while (*tmp)
	{
		while ((*tmp) && (*tmp != ' '))
		{
			tmpStrArr[len] = (*tmp);
			tmp++;
			len++;	
		}
		tmpStrArr[len] = '\0';
		numArr[cnt] = atoi(tmpStrArr);
		cnt++;		

		if (*tmp)
		{
			len = 0;
			tmp++;
		}
		else
		{
			break;	
		}
	}
}

void populateOrig(int N)
{
	int i = 0, j = 0, k = 0, t = 0, c = 0, tmp[1000];
	for (i = 0; i < 1000; i++)
	{
		tmp[i] = i;
	}
	
	for (i = 0; i < 1000; i++)
	{
		k = rand()%(1000 - i);
		t = tmp[i];
		tmp[i] = tmp[k];
		tmp[k] = t;
		for (j = 0; j < 1000; j++)
		{
			origArr[c][j] = tmp[j];
		}
		c++;	
	}	
		
}

// problem specific function definition
int getOutput(int* numArr, int numOfInput)
{
	int i = 0, j = 0, f = 1, isGood = 0;
	for (i = 0; i < numOfInput; i++)  
	{
		f = 1;	
		for (j = 0; j < numOfInput; j++)
		{
			if (origArr[i][j] != numArr[j])
			{
				f = 0;
				break;
			} 
		}
	}
	return f;
}

int getLine(FILE* fp, char* buf, int* numOfChar)
{
	char ch;
	*numOfChar = 0;
	while ((ch = fgetc(fp)) != -1)
	{
		if (ch == '\n')
			break;
		buf[*numOfChar] = ch;
		++*numOfChar;
	}
	buf[*numOfChar] = '\0';
	return ch;
}

int main()
{
	FILE* fp = fopen("pb2.in", "r");
	char buf[6000];
	int numArr[1000];
	int charRead = 0, lineLength = 0;
	int numOfInput = 0, inputLineNum = 0, i = 0;
	int caseNo = 0, isGood = 0;

	populateOrig(1000);

	while ((charRead = getLine(fp, buf, &lineLength)) != -1)
	{
		inputLineNum++;
		if ((strlen(buf) == 0) || (inputLineNum == 1))
		{
			continue;
		}

		if (inputLineNum % 2 == 0)
		{
			numOfInput = atoi(buf);
		}	
		else
		{
			parseInput(buf, numArr);
			caseNo++;

			// problem specific function call
			isGood = getOutput(numArr, numOfInput);
			if (isGood)
				printf("Case #%d: GOOD\n", caseNo);
			else
				printf("Case #%d: BAD\n", caseNo);
		}
	}
	return 0;
}
