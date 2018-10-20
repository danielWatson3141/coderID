#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 160
#define eps 1e-7
using namespace std;

#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

char GOOD[] = "GOOD";
char BAD[] = "BAD";

int ans;
void mergearray(int a[], int first, int mid, int last, int temp[]) {
    int i = first, j = mid + 1;
    int m = mid, n = last,k = 0;
    while (i <= m && j <= n) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            ans+=(m-i+1);
            temp[k++] = a[j++];
        }
    }
    while (i <= m) {
        temp[k++] = a[i++];
    }
    while (j <= n)
        temp[k++] = a[j++];
    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[]) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergesort(a,first,mid,temp);
        mergesort(a,mid+1,last,temp);
        mergearray(a, first, mid, last, temp);
    }
}
void MergeSort(int a[], int n) {
    ans=0;
    int *p = new int[n];
    mergesort(a, 0, n - 1, p);
    delete[] p;
}

int str[maxn];

int main() {
    freopen("C-small-attempt4.in","r",stdin);
    freopen("out.out","w",stdout);
    int cas=0,i,j,k;
    int t;
    int n,l;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&str[i]);
        }
        MergeSort(str,n);
        printf("Case #%d: ",++cas);
        if(ans>=n*(n-1)/2/2){
            puts(GOOD);
        }else{
            puts(BAD);
        }
    }
    return 0;
}
