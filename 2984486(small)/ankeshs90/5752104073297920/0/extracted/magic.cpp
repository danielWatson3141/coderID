#include <iostream>
#include <cstdio>
#include <cstdlib>

int swaps = 0;
int Partition(int a[], int beg, int end) ;
void QuickSort(int a[], int beg, int end);

int main(){
  srand (time(NULL));
  int T,t=0, n, i, k;
  int a[1000], b[1000];
  scanf("%d", &T);  
  while(t++<T){
    scanf("%d", &n);
    for(i=0;i<n;i++)
      scanf("%d", &(a[i]));
    for (k=0; k<n; k++)
      b[k] = k;
    for (k=0; k<n; k++){
      int p = rand() % (n-k) + k;
      int tm = b[p];
      b[p]=b[k];
      b[k]=tm;
    }
    swaps = 0;
    QuickSort(a, 0, n-1);
    int s1=swaps;
    swaps = 0;
    QuickSort(b, 0, n-1);
    int s2=swaps;
    printf("Case #%d: ",t);
    if(s1>s2) printf("BAD\n");
    else printf("GOOD\n");
  }
}

int Partition(int a[], int beg, int end)          //Function to Find Pivot Point
{
int p=beg, pivot=a[beg], loc;

for(loc=beg+1;loc<=end;loc++)
{
if(pivot>a[loc])
{
a[p]=a[loc];
a[loc]=a[p+1];
a[p+1]=pivot;
swaps++;
p=p+1;
}
}
return p;
}


void QuickSort(int a[], int beg, int end)
{
if(beg<end)
{
int p=Partition(a,beg,end);                       //Calling Procedure to Find Pivot

QuickSort(a,beg,p-1);                             //Calls Itself (Recursion)
QuickSort(a,p+1,end);			              //Calls Itself (Recursion)
}
}