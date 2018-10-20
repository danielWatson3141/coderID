// Bullseye.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const char cszInputFileLocation[] = "c:\\temp\\GoogleCodeJam\\Problem1\\A-small-attempt1.in";
const char cszOutputFileLocation[] = "c:\\temp\\GoogleCodeJam\\Problem1\\GoogleOutput.txt";

CWinApp theApp;
using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nNumTestCases=0;
	int nNumDevices; //N
	int nLength; //L
	int i, j, nCaseNum;
	char szOutlets[150][41];
	char szDevices[150][41];
	int nOutletsOn[40];
	int nDevicesOn[40];
	int nSwitchFlip;
	bool bPossible, bMatch;
	FILE *pInputFile = NULL;
	FILE *pOutputFile = NULL;

	HMODULE hModule = ::GetModuleHandle(NULL);
	AfxWinInit(hModule, NULL, ::GetCommandLine(), 0);

	if (fopen_s( &pOutputFile, cszOutputFileLocation, "w") != 0)
		return false;
	if (fopen_s( &pInputFile, cszInputFileLocation, "r") != 0)
		return false;
	fscanf_s(pInputFile, "%d\n", &nNumTestCases);

	for (nCaseNum=1; nCaseNum<=nNumTestCases; nCaseNum++)
	{
		fscanf_s(pInputFile, "%d %d\n", &nNumDevices, &nLength);
		nSwitchFlip = 0;
		bPossible = true;
		for (j=0; j < nLength; j++)
		{
			nOutletsOn[j] = 0;
			nDevicesOn[j] = 0;
		}
		for (i=0; i < nNumDevices; i++)
		{
			if (i == nNumDevices-1)
				fscanf(pInputFile, "%s\n", szOutlets[i]);
			else
				fscanf(pInputFile, "%s ", szOutlets[i]);
			for (j=0; j < nLength; j++)
			{
				if (szOutlets[i][j] == '1')
					nOutletsOn[j]++;
			}
		}
		for (i=0; i < nNumDevices; i++)
		{
			if (i == nNumDevices-1)
				fscanf(pInputFile, "%s\n", szDevices[i]);
			else
				fscanf(pInputFile, "%s ", szDevices[i]);
			for (j=0; j < nLength; j++)
			{
				if (szDevices[i][j] == '1')
					nDevicesOn[j]++;
			}
		}

		for (j=0; j < nLength; j++)
		{
			if (nDevicesOn[j] != nOutletsOn[j])
			{
				if (nNumDevices - nDevicesOn[j] != nOutletsOn[j])
					bPossible = false;
				else
				{
					nSwitchFlip++;
					for (i=0; i < nNumDevices; i++)
					{
						if (szOutlets[i][j] == '1')
							szOutlets[i][j] = '0';
						else
							szOutlets[i][j] = '1';
					}
				}
			}
		}

		for (i=0; (i < nNumDevices) & bPossible; i++)
		{
			bMatch = false;
			for (j=0; (j < nNumDevices) & !bMatch; j++)
			{
				if (strcmp(szDevices[i], szOutlets[j]) == 0)
					bMatch = true;
			}
			if (!bMatch)
				bPossible = false;
		}

		if (bPossible)
			fprintf( pOutputFile, "Case #%u: %u\n", nCaseNum, nSwitchFlip);
		else
			fprintf( pOutputFile, "Case #%u: NOT POSSIBLE\n", nCaseNum);
	}

	fclose( pInputFile);
	fclose( pOutputFile);
	return 0;
}
