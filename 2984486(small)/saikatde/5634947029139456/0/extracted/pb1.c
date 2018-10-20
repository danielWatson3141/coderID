#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseInput(char* bufLine, int* numArr)
{
	char tmpStrArr[20];
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

void parseInputStrArr(char* bufLine, char strArr[10][20])
{
	char tmpStrArr[20];
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
		strcpy(strArr[cnt], tmpStrArr);
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

int isMatch(char elecFlow[10][20], char devFlow[10][20], int N)
{
	int i = 0, j = 0, f = 0;
	for (i = 0; i < N; i++)
	{
		f = 0;
		for (j = 0; j < N; j++)
		{
		if (strcmp(elecFlow[j], devFlow[i]) == 0)
		{
			f = 1;
			break; 
		}
		}		
		if (f == 0)
			return 0;
	} 
	return 1;	
}

void flip(char elecFlow[10][20], int N, int i)
{
	int j = 0;
	for (j = 0; j < N; j++)
	{
		elecFlow[j][i] = (elecFlow[j][i] == '0' ? '1' : '0');
	}
}

int getNum(char initFlow[20], char elecFlow[20], int L)
{
	int i = 0, c = 0;
	for (i = 0; i < L; i++)
	{
		if (initFlow[i] != elecFlow[i])
		{
			c++;
		}
	}
	return c;	
}  

// problem specific function definition
void getOutput(char elecFlow[10][20], char devFlow[10][20], char initFlow[20], int N, int L, int i, int* mcnt)
{
	int ns = 0, min1 = 9999, min2 = 9999;
	if (isMatch(elecFlow, devFlow, N))
	{
		ns = getNum(initFlow, elecFlow[0], L);	
		if (*mcnt > ns)
		{
			*mcnt = ns;
		}
		return;
	}

	if (i < L)
	{ 	
		flip(elecFlow, N, i);
		getOutput(elecFlow, devFlow, initFlow, N, L, i+1, &min1);
		flip(elecFlow, N, i);
		getOutput(elecFlow, devFlow, initFlow, N, L, i+1, &min2);
		*mcnt = (min1 < min2 ? min1 : min2);
	}	
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
	FILE* fp = fopen("pb1.in", "r");
	char buf[200];
	char elecFlow[10][20], devFlow[10][20], initFlow[20];
	int numArr[2], N = 0, L = 0, min = 9999; 
	int charRead = 0, lineLength = 0;
	int numOfInput = 0, inputLineNum = 0, totLineNum = 0;
	int caseNo = 0;

	while ((charRead = getLine(fp, buf, &lineLength)) != -1)
	{
		totLineNum++;
		if ((strlen(buf) == 0) || (totLineNum == 1))
		{
			continue;
		}

		inputLineNum++;
		if (inputLineNum % 3 == 1)
		{
			parseInput(buf, numArr);
			N = numArr[0];
			L = numArr[1];
		}	
		else if (inputLineNum % 3 == 2)
		{
			parseInputStrArr(buf, elecFlow);
			strcpy(initFlow, elecFlow[0]);
		}
		else
		{
			parseInputStrArr(buf, devFlow);
			caseNo++;

			// problem specific function call
			getOutput(elecFlow, devFlow, initFlow, N, L, 0, &min);
			if (min == 9999)
				printf("Case #%d: NOT POSSIBLE\n", caseNo);
			else
				printf("Case #%d: %d\n", caseNo, min);

		}
	}
	return 0;
}
