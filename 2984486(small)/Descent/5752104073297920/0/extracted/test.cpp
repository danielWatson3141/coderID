#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int n, p[1005], pp[1005], buf[1005];
double A, B, AA, BB;
int place[1005], place2[1005];
int BIT[1005], sol[1005];

double Est(){
	double T = 0, R = 0;
	FOR(i,0,n) T += abs(i - sol[p[i]]), R += abs(i - 500);
	return T - R;
}



int main(){
	FILE *f = fopen("data.cpp", "r");
	FOR(i,0,1000) fscanf(f, "%*d%d%*d", &sol[i]);
	fclose(f);

	srand(time(0));
	n = 1000;
	FOR(i,0,100000){
		FOR(j,0,n) p[j] = j;
		FOR(j,0,n) swap(p[j], p[rand() % (j + 1)]);
		double a = Est();
		A += a;
		AA += a * a;
		FOR(j,0,n) place2[p[j]] += j;
	}
	
	FOR(i,0,100000){
		FOR(j,0,n) p[j] = j;
		FOR(j,0,n) swap(p[j], p[rand() % n]);
		double b = Est();
		B += b;
		BB += b * b;
		FOR(j,0,n) place[p[j]] += j;
	}
	

	A /= 100000.;
	B /= 100000.;
	// variance  = E[x^2] - E[x]^2
	double varA = sqrt(AA / 100000. - A * A);
	double varB = sqrt(BB / 100000. - B * B);

	printf("%f %f %f %f\n", A, B, A / B, (A + B) / 2);
	printf("%f %f\n", varA / A, varB / B);
	printf("Score = %f\n", abs(A / B - 1.) - varA / A - varB / B);
	
	//FOR(i,0,n) printf("%d %d % d\n", i, place[i] / 100000, place2[i] / 100000);
	return 0;
}
