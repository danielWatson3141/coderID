/*
 * main.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: blding
 */


#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 150;
const int MAXL = 40;

int caseNum;
int n;
int l;

long long outlets[MAXN];
long long changed[MAXN];
long long devices[MAXN];
char chrs[MAXL + 1];

long long str2long(char str[], int len)
{
	long long s = 0;
	for (int i = 0; i < len; ++i) {
		s <<= 1;
		if (str[i] == '1')
			++s;
//		fprintf(stdout, " %ld ", s);
	}
	str[len] = 0;
//	fprintf(stdout, "%s %ld\n", str, s);
	return s;
}

void action(long long src, long long des, int len, long long & act, int & move)
{
	act = 0;
	move = 0;
	for (int i = len - 1; i >= 0; --i) {
		act <<= 1;
		if ((src & (1 << i)) != (des & (1 << i))) {
			++act;
			++move;
		}
	}
}

void preprocess(FILE * fin)
{
	fscanf(fin, "%d %d ", &n, &l);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < l; ++j) {
			fscanf(fin, "%c ", &chrs[j]);
		}
		chrs[l] = 0;
		outlets[i] = str2long(chrs, l);
//		fprintf(stdout, "%s %ld\n", chrs, outlets[i]);
//		fflush(stdout);
	}
//	fprintf(stdout, "outlets\n");
//	for (int i = 0; i < n; ++i) {
//		fprintf(stdout, "%ld ", outlets[i]);
//	}
//	fprintf(stdout, "\n");

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < l; ++j) {
			fscanf(fin, "%c ", &chrs[j]);
		}
		devices[i] = str2long(chrs, l);
//		fprintf(stdout, "%ld\n", outlets[i]);
//		fflush(stdout);
	}
//	fprintf(stdout, "devices\n");
//	for (int i = 0; i < n; ++i) {
//		fprintf(stdout, "%ld ", devices[i]);
//	}
//	fprintf(stdout, "\n");
}


bool isSame(long long src[], long long des[], int size)
{
	for (int i = 0; i < size; ++i) {
		if (src[i] != des[i])
			return false;
	}
	return true;
}

void work(int caseId, FILE * fout)
{
	sort(devices, devices + n);
	int mini = n + 1;
	long long act;
	int move;
	for (int i = 0; i < n; ++i) {
		// match the device with the first outlet
		action(outlets[i], devices[0], l, act, move);
		if (move < mini) {
			// change
			for (int j = 0; j < n; ++j) {
				changed[j] = (act ^ outlets[j]);
			}
			// sort
			sort(changed, changed + n);
			// validate
			if (isSame(devices, changed, n)) {
				mini = move;
	//			fprintf(stdout, "%d %ld\n", move, act);
			}
		}
	}
	if (mini < n + 1) {
		fprintf(fout, "Case #%d: %d\n", caseId, mini);
//		fprintf(stdout, "Case #%d: %d\n", caseId, mini);
//		fflush(stdout);
	} else {
		fprintf(fout, "Case #%d: NOT POSSIBLE\n", caseId);
//		fprintf(stdout, "Case #%d: %d\n", caseId, mini);
//		fflush(stdout);
	}
}

int main()
{
	FILE * fin;
	FILE * fout;

	fin = fopen("../input", "r");
	fout = fopen("../output", "w");

	fscanf(fin, "%d ", &caseNum);
	for (int caseId = 1; caseId <= caseNum; ++caseId) {
//		fprintf(stdout, "case %d\n", caseId);
//		fflush(stdout);
		preprocess(fin);
		work(caseId, fout);
	}


	fclose(fin);
	fclose(fout);
	return 0;
}
