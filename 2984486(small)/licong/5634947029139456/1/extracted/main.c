#include <stdio.h>
#include <stdlib.h>

long long num[3][150];

char readnum()
{
    char temp;

    temp = getchar();
    while (temp != '0' && temp != '1')
        temp = getchar();
    return temp;
}

void sortNum( int k, int N )
{
    int l1,l2;
    int temp;

    for ( l1=N-2; l1>=0; l1--)
        for (l2=0; l2<=l1; l2++)
            if (num[k][l2] > num[k][l2+1])
            {
                temp = num[k][l2];
                num[k][l2] = num[k][l2+1];
                num[k][l2+1] = temp;
            }
}

int main()
{
    int T, N, L;
    int iCase;
    int l1,l2,l3;
    int flag, minsnum, snum;
    long long orign,a,b;

    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);
    for (iCase = 1; iCase<=T; iCase++)
    {
        scanf("%d%d",&N,&L);

        for (l1=0; l1<2; l1++)
            for (l2=0; l2<N; l2++)
            {
                num[l1][l2] = 0;
                for (l3=0; l3<L; l3++)
                    num[l1][l2] = num[l1][l2]*2 + readnum() - '0';
            }

        minsnum = L+1;
        orign = num[0][0];
        for (l1=N-1; l1>=0; l1--)
            num[0][l1] = num[0][l1] ^ orign;
        sortNum(0,N);
        for (l1=0; l1<N; l1++)
        {
            for (l2=0; l2<N; l2++)
                num[2][l2] = num[1][l2] ^ num[1][l1];
            sortNum(2,N);
            flag = 1;
            for (l2=0; l2<N; l2++)
                if (num[0][l2]!=num[2][l2])
                {
                    flag = 0;
                    break;
                }
            if (flag==1)
            {
                a = orign;
                b = num[1][l1];
                snum = 0;
                while (a > 0 || b > 0)
                {
                    if ( a % 2 != b % 2)
                        snum++;
                    a = a/2;
                    b = b/2;
                }
                if (snum < minsnum)
                    minsnum = snum;
            }
        }

        printf("Case #%d: ", iCase);
        if (minsnum == L+1)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",minsnum);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
