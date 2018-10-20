// 2014 code jam round 1A Problem C
int v = 0 ;

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <array>

using namespace std ;


int caseNumber;

int runTest() {
  int cutoff = 487 ;
  unsigned long long n;
  cin >> n ; // Always 1000 for actual test
  int i ;
  int deck[n];
  int lessThanCount = 0;
  for (i = 0 ; i < n ; i++) {
    cin >> deck[i];
    lessThanCount += (deck[i] <= i) ;
//    lessThanCount += (deck[i] < i) ;
  }
  cout << "Case #" << caseNumber << ": " ;
  if (lessThanCount < cutoff)
    cout << "BAD" ;
  else
    cout << "GOOD" ;
  cout << endl ;
  
  return 1 ;
}

int randint(int m) {
  return rand() % m ;
}

inline int randint(int a, int b) {
  return a + (rand() % (b-a+1)) ;
}

void shuffle(int *deck, int n) {
  int i;
  for (i = 0 ; i < n ; i++) {
    int p = randint(i,n-1);
    int temp = deck[i];
    deck[i] = deck[p];
    deck[p] = temp;
  }
}

void badshuffle(int *deck, int n) {
  int i;
  for (i = 0 ; i < n ; i++) {
    int p = randint(0,n-1);
    int temp = deck[i];
    deck[i] = deck[p];
    deck[p] = temp;
  }
}

void showdeck(int *deck, int n) {
  int i;
  for (i = 0 ; i < n ; i++) {
    cout << deck[i] << ' ' ;
  }
}

int countSwaps(int *deck, int n) {
  int i;
  int swaps = 0 ;
  for (i = 0 ; i< n ; i++){
    if (deck[i] != i) {
      int j ;
      for (j = i+1 ; j< n ; j++){
        if (deck[j] == i) {
          deck[j] = deck[i];
          deck[i] = i ;
          swaps++;
          break ;
        }
      }
    }
  }
  return swaps ;
}


void testShuffle(int n, int r){
  int deck[n];
  int i;
  int badtotals[n];
  int badTotalsAll = 0 ;
  int numSameCount[n+1];
  int numLessCount[n+1];
  int swapCount[n+1];
  int cutoff = 486 ;
  
  for (i = 0 ; i < n ; i++) {
    numSameCount[i] = 0 ;
    numLessCount[i] = 0 ;
    swapCount[i] = 0 ;
  }
  for (i = 0 ; i < n ; i++) {
    badtotals[i] = 0 ;
  }
  int j ;
  for (j = 0 ; j < r ; j++) {
    for (i = 0 ; i < n ; i++) {
      deck[i] = i ;
    }
    badshuffle(deck,n);
    //showdeck(deck,n);
    //cout << endl;
    int numSame = 0 ;
    int numLess = 0 ;
    for (i = 0 ; i < n ; i++) {
      numSame += (deck[i] == i) ;
      numLess += (deck[i] <= i) ;
      badtotals[i] += (deck[i] == i) ;
      badTotalsAll += (deck[i] == i) ;
    }
    numSameCount[numSame]++;
    numLessCount[numLess]++;
    int swaps = countSwaps(deck,n);
    //showdeck(deck,n);
    //cout << endl;
    swapCount[swaps]++;
  }
  cout << "Probability of card not moving: " << ((double)badTotalsAll)/r << endl ;
  int totalsame1 = 0 ;
  int totalsame2 = 0 ;
  for (i = 0 ; i< n/2 ; i++)
    totalsame1 += badtotals[i] ;
  for (; i< n ; i++)
    totalsame2 += badtotals[i] ;
  cout << "total same low = " << totalsame1 <<  " high = " << totalsame2 << endl ;
//  for (i = 0 ; i < n ; i++)
//    cout << i << ' ' << badtotals[i] << endl ;
  int lessThanCutoff = 0;
  for (i = 0 ; i < cutoff ; i++)
    lessThanCutoff += numLessCount[i];
  cout << "Less than " << cutoff << ": " << lessThanCutoff << endl ;
  
  for (i = n/2-50 ; i < n/2+20 ; i++)
    cout << i << " less " << numLessCount[i] << endl ;
  for (i = 0 ; i < 10 ; i++)
    cout << i << ' ' << numSameCount[i] << endl ;
  for (i = n-20 ; i < n ; i++)
    cout << i << " swaps: " << swapCount[i] << endl ;
}
int main (int argc, const char * argv[])
{
  int testCases ;
  //testShuffle(1000,10000);
  //return 0;
  cin >> testCases ;
  if (v) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  for (caseNumber=1 ; caseNumber <= testCases ; caseNumber++) {
    if (v)
      cout << "// Running case #" << caseNumber << endl ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  return 0;
}

