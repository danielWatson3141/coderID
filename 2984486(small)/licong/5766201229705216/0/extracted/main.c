#include <stdio.h>
#include <stdlib.h>

    int T, N;
    int use[16], mark[16],marktemp[16];
    int mat[16][16];
    int wholeflag;

int tryMark(rot)
{
    int l1,deg,flag;
    deg = 0;
    for(l1=0;l1<N;l1++)
        if ( use[l1] && !marktemp[l1] && !mark[l1] && mat[l1][rot]==1 && l1!=rot)
            deg++;
    if (deg==0)
    {
        marktemp[rot] = 1;
        return 1;
    }
    if (deg==2)
    {
        marktemp[rot] = 1;
        flag = 1;
        for (l1=0;l1<N;l1++)
            if ( use[l1] && !marktemp[l1] && !mark[l1] && mat[l1][rot]==1 && l1!=rot)
            {
                flag = flag & tryMark(l1);
                if (flag == 0)
                    return 0;
            }
        return flag;
    }
    if (deg==1)
    {
        wholeflag = 0;
        return 0;
    }
    return 0;
}

int tryMarkRoot( rot )
{
    int l1,flag;
    marktemp[rot] = 1;
    flag = 1;
    for ( l1=0;l1<N;l1++)
        if ( use[l1] && mat[l1][rot]==1 && mark[l1]==0 && l1!=rot)
            flag = flag & tryMark(l1);
    return flag;
}


int main()
{
    int iCase, l1, l2, a, b;

    int s, maxSwitch, temp, num, flag, minnum;
    int deg;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);
    for (iCase=1;iCase<=T;iCase++)
    {
        scanf("%d",&N);
        for (l1=0;l1<N;l1++)
            for (l2=0;l2<N;l2++)
                mat[l1][l2] = 0;

        maxSwitch = 1;
        for (l1=0;l1<N-1;l1++)
        {
            maxSwitch = maxSwitch*2+1;
            scanf("%d%d",&a,&b);
            mat[a-1][b-1] = 1;
            mat[b-1][a-1] = 1;
        }

        minnum = N;
        for (s=0; s<=maxSwitch; s++)
        {
            if (s == 125)
                s = 125;
            temp = s;
            num = 0;
            for (l1=0;l1<N;l1++)
            {
                use[l1] = temp % 2;
                if (use[l1] == 0)
                    num++;
                temp = temp / 2;
                mark[l1] = 0;
            }
            wholeflag = 1;

            for (l1=0;l1<N;l1++)
                if (use[l1]==1 && mark[l1]==0)
                {
                    deg = 0;
                    for (l2=0;l2<N;l2++)
                        if ( mat[l1][l2] == 1 && mark[l2]==0 && use[l2] == 1 && l1!=l2)
                            deg++;
                    if ( deg == 0)
                    {
                        if (num == N-1)
                            flag = 1;
                        else
                            wholeflag = 0;
                        break;
                    }
                    if ( deg == 2)
                    {
                        for (l2=0;l2<N;l2++)
                            marktemp[l2] = 0;
                        if (tryMarkRoot( l1 ))
                            for (l2=0;l2<N;l2++)
                                mark[l2] = mark[l2] | marktemp[l2];
                        flag = 1;
                        for (l2=0;l2<N;l2++)
                            if (use[l2] && !marktemp[l2])
                                flag = 0;
                        if (flag == 1)
                            break;
                    }
                    if (wholeflag==0)
                        break;
                }
            if (wholeflag == 0)
                continue;
            if (flag==1 && num<=minnum)
                minnum = num;
        }
        printf("Case #%d: %d\n",iCase,minnum);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
