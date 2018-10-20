#include <iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

int main()
{
    FILE *fp;
    fp=fopen("x1.txt","w");
	int s1;
	int *e1;
	int s2, s3=0;
	int *done;

	cin >> s1;
	bool fl2 = true;

	while(s1 > 0)
	{
		fl2= false;
		s3++;
		int del=0;
		int counted = 0;
		cin >> s2;
		e1 = (int *)malloc(sizeof(int)*(2*s2-1));
		done = (int *)malloc(sizeof(int)*(2*s2-1));
		for(int i=0;i<2*(s2-1);i++)
		{
			cin >> e1[i];
		}
		for(int i=0;i<2*(s2-1);i++)
		{
			int cnt=0;
			bool fl = true;
			for(int j=0;j<2*(s2-1);j++)
			{
				for(int k=0;k<counted;k++)
				{
					if(e1[i] == done[k])
					{
						fl = false;
					}
				}
				if(e1[i] == e1[j] && fl)
				{
					cnt++;
				}
			}
			if(cnt>2)
			{
				del++;
				done[counted++] = e1[i];
			}
		}

		int te = s2-del;
		int pow=2;
		while(te >= pow+1)
		{
			pow = pow * 2;
			if(pow + 1 == te)
			{
					fl2 = true;
			}
		}
		pow = pow/2;
		if(!fl2 )
		{
			del += te - pow-1;;
		}


        fprintf(fp,"Case #%d: %d\n",s3,del);


		s1--;
	}

}
