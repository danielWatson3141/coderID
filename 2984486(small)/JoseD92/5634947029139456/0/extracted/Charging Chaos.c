/*
Problem

Shota the farmer has a problem. He has just moved into his newly built farmhouse, but it turns out that the outlets haven't been configured correctly for all of his devices. Being a modern farmer, Shota owns a large number of smartphones and laptops, and even owns a tablet for his favorite cow Wagyu to use. In total, he owns N different devices.

As these devices have different specifications and are made by a variety of companies, they each require a different electric flow to charge. Similarly, each outlet in the house outputs a specific electric flow. An electric flow can be represented by a string of 0s and 1s of length L.

Shota would like to be able to charge all N of his devices at the same time. Coincidentally, there are exactly N outlets in his new house. In order to configure the electric flow from the outlets, there is a master control panel with L switches. The ith switch flips the ith bit of the electric flow from each outlet in the house. For example, if the electric flow from the outlets is:

Outlet 0: 10
Outlet 1: 01
Outlet 2: 11

Then flipping the second switch will reconfigure the electric flow to:

Outlet 0: 11
Outlet 1: 00
Outlet 2: 10

If Shota has a smartphone that needs flow "11" to charge, a tablet that needs flow "10" to charge, and a laptop that needs flow "00" to charge, then flipping the second switch will make him very happy!

Misaki has been hired by Shota to help him solve this problem. She has measured the electric flows from the outlets in the house, and noticed that they are all different. Decide if it is possible for Shota to charge all of his devices at the same time, and if it is possible, figure out the minimum number of switches that needs to be flipped, because the switches are big and heavy and Misaki doesn't want to flip more than what she needs to.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of three lines. The first line contains two space-separated integers N and L. The second line contains N space-separated strings of length L, representing the initial electric flow from the outlets. The third line also contains N space-separated strings of length L, representing the electric flow required by Shota's devices.
Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the minimum number of switches to be flipped in order for Shota to charge all his devices. If it is impossible, y should be the string "NOT POSSIBLE" (without the quotes). Please note that our judge is not case-sensitive, but it is strict in other ways: so although "not  possible" will be judged correct, any misspelling will be judged wrong. We suggest coping/pasting the string NOT POSSIBLE into your code.
Limits

1 = T = 100.
No two outlets will be producing the same electric flow, initially.
No two devices will require the same electric flow.
Small dataset

1 = N = 10.
2 = L = 10.
Large dataset

1 = N = 150.
10 = L = 40. 
*/
/***********************************************************************************************************
*                                            By JoseD92                                                    *
***********************************************************************************************************/
#include <stdio.h>
#include <string.h>

char enchufes[151][41];
char aparatos[151][41];
int bool[151];
int bool2[41];

int cerdo(int N, int L, int recur){
   int resul, i, j, flag = 1, min = 42, caso;
   for (i=0;i<N;i++){bool[i]=0;}
   for (i=0;i<N;i++){
      for (j=0;j<N;j++){
         if ((bool[j]==0) && (!strcmp(aparatos[i],enchufes[j]))){
            bool[j]=1;
            break;
         }
      }
   }
   for (i=0;i<N;i++){if(bool[i]==0){flag = 0; break;}}
   if (flag){return 0;}
   else{
      for(i=recur;i<L;i++){
         if(bool2[i]==0){
            bool2[i]=1;
            for(j=0;j<N;j++){
               enchufes[j][i] = (enchufes[j][i]=='1'?'0':'1');
            }
            caso = cerdo(N, L, i);
            min = ((caso<min&&caso!=-1)?caso:min);
            for(j=0;j<N;j++){
               enchufes[j][i] = (enchufes[j][i]=='1'?'0':'1');
            }
            bool2[i]=0;
         }
         if (min != 42){flag = 1;}
      }
   }
   if (flag){return (min+1);}
   else{return -1;}
}

int main(){
   int casos, N, L, i, j=0, resul;
   scanf("%d",&casos);
   while (j++ != casos)
   {
      scanf("%d %d",&N,&L);
      for (i = 0; i < N-1; i++){
         scanf("%s ",enchufes[i]);
      }
      scanf("%s ",enchufes[i]);
      for (i = 0; i < N-1; i++){
         scanf("%s ",aparatos[i]);
      }
      scanf("%s",aparatos[i]);
      
      for (i=0;i<L;i++){bool2[i]=0;}
      resul = cerdo(N, L, 0);
     // resul = resul==0?0:resul-1;

      if (resul > -1){printf("Case #%d: %d\n",j,resul);}
      else{printf("Case #%d: NOT POSSIBLE\n",j);}

   }
}












