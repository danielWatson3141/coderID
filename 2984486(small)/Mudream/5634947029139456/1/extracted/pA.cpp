#include<cstdio>
#include<cstdlib>
#include<algorithm>
struct Line
{
	int arr[100];
	int len;
}line1[200],line2[200];
void fxor(Line a,Line b,Line *ret)
{
	for(int lx = 0;lx < a.len;lx++)
		ret->arr[lx] = (a.arr[lx] != b.arr[lx]);
	ret->len = a.len;
	return;
}
void finit(Line *a,int len)
{
	for(int lx = 0;lx < len;lx++)
		a->arr[lx] = 0;
	a->len = len;
	return;
}
void print(Line a)
{
	for(int lx = 0;lx < a.len;lx++)
		printf("%d",a.arr[lx]);
	puts("");
	return;
}
bool operator<(Line a,Line b)
{
	for(int lx = 0;lx < a.len;lx++)
		if(a.arr[lx] < b.arr[lx])
			return true;
		else if(a.arr[lx] > b.arr[lx])
			return false;
			
	return true;
}
bool operator==(Line a,Line b)
{
	for(int lx = 0;lx < a.len;lx++)
		if(a.arr[lx] != b.arr[lx])
			return false;
	return true;
}
int cnt(Line a)
{
	int cc=0;
	for(int lx = 0;lx < a.len;lx++)
		cc += a.arr[lx];
	return cc;
}
int main()
{
	int T;scanf("%d",&T);
	for(int lT = 1;lT <= T;lT++)
	{
		int N,L;
		Line tb;
		scanf("%d %d",&N,&L);
		finit(&tb,L);
		for(int ln = 0;ln < N;ln++)
		{
			line1[ln].len = L;
			for(int lx = 0;lx < L;lx++)
				scanf("%1d",&line1[ln].arr[lx]);
//			fxor(line1[ln],tb,&tb);
		}
		for(int ln = 0;ln < N;ln++)
		{
			line2[ln].len = L;
			for(int lx = 0;lx < L;lx++)
				scanf("%1d",&line2[ln].arr[lx]);
//			fxor(line2[ln],tb,&tb);
		}
		std::sort(line2,line2 + N);
	//	for(int lx = 0;lx < N;lx++)
	//		print(line2[lx]);
		bool prt = false;
		int pos = 300;
		for(int lp = 0;(lp < N);lp++)
		{
			fxor(line1[0],line2[lp],&tb);
		//	printf("[");print(tb);printf("\n");
			Line line3[200];
			for(int lx = 0;lx < N;lx++) fxor(line1[lx],tb,&line3[lx]);

			std::sort(line3,line3 + N);
			//for(int lx = 0;lx < N;lx++)
			//	print(line3[lx]);

			//printf("---------------\n");

			bool flag = true;
			for(int lx = 0;(lx < N) and (flag);lx++)
				if((line3[lx] == line2[lx]) == false)
					flag = false;
			if(flag)
			{
				prt = true;
				if(pos > cnt(tb))
					pos = cnt(tb);
			}
		}
		if(pos < 300)
			printf("Case #%d: %d\n",lT,pos);
		else
			printf("Case #%d: NOT POSSIBLE\n",lT);
		//printf("=================\n");
	}
	return 0;
}
