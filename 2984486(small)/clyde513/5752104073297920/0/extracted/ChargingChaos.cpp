// Bullseye.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const char cszInputFileLocation[] = "c:\\temp\\GoogleCodeJam\\ChargingChaos\\C-small-attempt6.in";
const char cszOutputFileLocation[] = "c:\\temp\\GoogleCodeJam\\ChargingChaos\\GoogleOutput.txt";

CWinApp theApp;
using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nNumTestCases=0; int nNumPermutations=0;
	int i, nCaseNum, nValue, nInSameLocation;
	bool bGoodPerm;
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
		fscanf_s(pInputFile, "%d\n", &nNumPermutations);

		nInSameLocation = 0;
		for (i=0; i < nNumPermutations; i++)
		{
			if (i == nNumPermutations-1)
				fscanf_s(pInputFile, "%d\n", &nValue);
			else
				fscanf_s(pInputFile, "%d ", &nValue);

			if ((nValue >= i) && (nValue <= i+500))
				nInSameLocation++;
		}

		//fprintf( pOutputFile, "%u\n", nInSameLocation);

		if (nInSameLocation < 387)
			fprintf( pOutputFile, "Case #%u: GOOD\n", nCaseNum);
		else
			fprintf( pOutputFile, "Case #%u: BAD\n", nCaseNum);
	}

	fclose( pInputFile);
	fclose( pOutputFile);
	return 0;
}
