#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string.h>

#define SZ(c) c.size()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define SORT(a) sort(a.begin(),a.end())
#define tests int test; scanf("%d",&test); while(test--)
#define dbg(n) cout<<#n<<" = "<<n<<endl;

using namespace std;

int strToInt(string str) {int ans; stringstream s; s<<str; s>>ans; return ans;}
string intToStr(int n) {string str; stringstream s; s<<n; s>>str; return str;}
int MAX(int a,int b) {if(a >b) return a; return b;}
int MIN(int a,int b) {if(a <b) return a; return b;}
int ABS(int a) {if(a >0) return a; return -a;}


 int copyArr[30][30];


 bool check(int index, int root)
 {
     int sum =0;
     vector<int> child;
     int flag =0;
     for(int col =0; col<30; col++)
     {

         if(copyArr[index][col] != -1)
         {

             if(col == root)
             {
                 flag =1;
             }
             else
             {
                 sum++;
             child.push_back(col);
             }
         }
     }
     if(flag == 0)
        return false;
     if( (sum == 0)  )
        return true;
     if(sum == 2)
     {
         return (check(child[0], index) & check(child[1], index));
     }
     return false;
 }

int main()
{
    freopen("treeInput.txt", "r", stdin);
    freopen("tree.txt", "w", stdout);
    int test ;
    cin>>test;
    for(int running =1; running<=test; running++)
    {
        int n;
        cin>>n;
        int arr[30][30];

        for(int i=0; i<30; i++)
            for(int j=0; j<30; j++)
                arr[i][j] =-1;

        int x,y;
        for(int i=1; i<n; i++)
        {
            cin>>x>>y;
           // x--; y--;
            arr[x][y] =1;
            arr[y][x] =1;
        }

        int answer = 1000;
        for(int i=0; i<= (1<<n); i++)
        {
            int counter =0;
            vector<int> toRemove;
            for(int j=0; j<n; j++)
            {
                if(i & (1<<j))
                {
                    counter++;
                    toRemove.push_back(j+1);
                }
            }

            for(int p=0; p<30; p++)
                for(int q=0; q<30; q++)
                    copyArr[p][q] = arr[p][q];

            int len = toRemove.size();
            int row;
            int can =1, amount =0;
            for(int index =0; index <len; index++)
            {
                row = toRemove[index];
                 can =1; amount =0;
               for(int col =0; col<30; col++)
               {
                   if(copyArr[row][col] != -1)
                   {
                        amount++;
                        for(int it=0; it<len; it++)
                   {
                       if(toRemove[it] == col)
                       {
                           amount--;
                           break;
                       }
                   }
                   }

               }
             //  cout<<row<<" "<<amount<<endl;
               if(amount>1)
                can=0;
               if(can ==0 )
                break;
                for(int col=0; col<30; col++)
                {
                    if(copyArr[row][col] != -1)
                    {
                        copyArr[row][col] = -1;
                        copyArr[col][row] = -1;
                    }
                }
            }

            if(can == 0)
                continue;
            int flag =0;

                //find root
                int root = -1;
                for(int row =0; row<=n; row++)
                {
                    int sum =0;
                    for(int col=0; col<=n; col++)
                    {
                        if(copyArr[row][col] !=-1)
                            sum++;
                    }
                    if(sum == 2)
                    {
                        root = row;
                        break;
                    }
                }


                //check if fully tree
                int firstChild, secondChild;
                for(int col =0; col<30; col++)
                {
                   if(copyArr[root][col] != -1)
                   {
                       firstChild = col;
                       break;
                   }
                }

                for(int col = firstChild+1; col<30; col++)
                {
                    if(copyArr[root][col] != -1)
                    {
                        secondChild = col;
                        break;
                    }
                }


                    if( (check(firstChild, root)) && (check(secondChild, root)) )
                    {
                        flag =1;
                      //  cout<<root<<" "<<firstChild<<" "<<secondChild<<endl;
                        answer = MIN(answer, counter);
                    }




            if(flag == 1)
            {
                answer = MIN(answer, counter);
            }

        }
        printf("Case #%d: %d\n",running, answer);
    }

    return 0;
}
