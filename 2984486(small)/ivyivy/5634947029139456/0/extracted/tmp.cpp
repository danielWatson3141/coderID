#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std ;

int L , N;
string A[155];
string B[155];

int backtrack(int id, int nowans)
{
    if(id == L)
    {
        /*sort*/
        sort(A,A+N);
        sort(B,B+N);
        
        int lose = 0;
        for(int i = 0 ; i < N ; i++)
        {
            if(!strcmp(A[i].c_str(),B[i].c_str()))
                continue ;
            else
            {
                lose = 1 ;
                break;
            }
        }

        if(lose)
        {
            return nowans + N + 100;
        }
        else
        {
            return nowans;
        }
    }
    
    else
    {
        /*not switch*/
        int AAA = backtrack(id+1,nowans);
        
        /*switch*/
        for(int i = 0 ; i < N ; i++)
        {
            if(A[i][id]=='1') A[i][id]='0';
            else A[i][id]='1';
        }
        int BBB = backtrack(id+1,nowans+1);
        for(int i = 0 ; i < N ; i++)
        {
            if(A[i][id]=='1') A[i][id]='0';
            else A[i][id]='1';
        }
        
        int finalans = min(AAA,BBB);
        
        return finalans;
    }
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("smallA.output","w",stdout);

    int cases ;
    scanf("%d",&cases);
    

    for(int c = 1 ; c <= cases ; c++)
    {
        int success = 0 ;
        scanf("%d%d",&N,&L);
        
        for(int i = 0 ; i < N ; i++)
            cin >> A[i];
        
        for(int i = 0 ; i < N ; i++)
            cin >> B[i];

        success = backtrack(0,success);
        
        if(success<0 || success > L) printf("Case #%d: NOT POSSIBLE\n",c);
        else printf("Case #%d: %d\n",c,success);
        
    }

    return 0;
}