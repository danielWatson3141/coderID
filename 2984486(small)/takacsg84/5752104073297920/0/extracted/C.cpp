#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bitset>
#include <time.h>

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define FOR(x,y,n) for(int x=(int)y;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))


using namespace std;
typedef long long LL;

int  _mergeSort(vector<int> &arr, vector<int> &temp, int left, int right);
int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right);

int mergeSort(vector<int> &arr) {
    int array_size = arr.size();
    vector<int> temp(array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
int _mergeSort(vector<int> &arr, vector<int> &temp, int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid;  /* i is index for right subarray*/
    k = left; /* i is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int N = 1000;

void doStuff() {
    vector<int> v(N);
    REP(i, N) cin >> v[i];
    int inv = mergeSort(v);
    if (inv < (249801 + 239974) / 2) cout << "BAD" << endl;
    else cout << "GOOD" << endl;
    //good = 249801
    //bad = 239974
}

int main() {
    int T;
    scanf("%d", &T);
    REP(t, T) printf("Case #%d: ", t + 1), doStuff();
    return 0;
}