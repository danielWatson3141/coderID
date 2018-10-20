#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int N = 1005;
struct BigInt {
    const static int mod = 10000;
    const static int DLEN = 4;
    int a[6000],len;
    BigInt() {
        memset(a,0,sizeof(a));
        len = 1;
    }
    BigInt(int v) {
        memset(a,0,sizeof(a));
        len = 0;
        do
        {
            a[len++] = v%mod;
            v /= mod;
        }
        while(v);
    }
    BigInt(const char s[]) {
        memset(a,0,sizeof(a));
        int L = strlen(s);
        len = L/DLEN;
        if(L%DLEN)len++;
        int index = 0;
        for(int i = L-1; i >= 0; i -= DLEN) {
            int t = 0;
            int k = i - DLEN + 1;
            if(k < 0)k = 0;
            for(int j = k; j <= i; j++)
                t = t*10 + s[j] - '0';
            a[index++] = t;
        }
    }
    BigInt operator +(const BigInt &b)const {
        BigInt res;
        res.len = max(len,b.len);
        for(int i = 0; i <= res.len; i++)
            res.a[i] = 0;
        for(int i = 0; i < res.len; i++) {
            res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
            res.a[i+1] += res.a[i]/mod;
            res.a[i] %= mod;
        }
        if(res.a[res.len] > 0)res.len++;
        return res;
    }
    BigInt operator *(const BigInt &b)const {
        BigInt res;
        for(int i = 0; i < len; i++) {
            int up = 0;
            for(int j = 0; j < b.len; j++) {
                int temp = a[i]*b.a[j] + res.a[i+j] + up;
                res.a[i+j] = temp%mod;
                up = temp/mod;
            }
            if(up != 0)
                res.a[i + b.len] = up;
        }
        res.len = len + b.len;
        while(res.a[res.len - 1] == 0 &&res.len > 1)res.len--;
        return res;
    }
    void output() {
        printf("%d",a[len-1]);
        for(int i = len-2; i >=0 ; i--)
            printf("%04d",a[i]);
        printf("\n");
    }
};
int n , a[N] , p[N] , ans[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;scanf ("%d" , &t);
    vector <pair <int , int> > v;
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d" , &a[i]);
            p[i] = 0;
        }
        int cnt = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (p[i] == 0) {
                int q = i;
                while (a[q] != i) {
                    p[q] = 1;
                    q = a[q];
                }
                cnt ++;
            }
        }
        v.push_back (make_pair (cnt , ++ cas));
    }
    sort (v.begin () , v.end ());
    for (int i = 0 ; i < 60 ; i ++) {
        ans[v[i].second] = 1;
    }
    for (int i = 1 ; i <= 120 ; i ++) {
        printf ("Case #%d: %s\n" , i , ans[i] ? "GOOD" : "BAD");
    }
    return 0;
}