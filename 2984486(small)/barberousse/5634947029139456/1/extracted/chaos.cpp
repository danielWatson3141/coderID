// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

#define DEBUG 0
#define trace if( DEBUG ) printf

//types and constants used in the functions below
 
const uint64_t m1  = 0x5555555555555555; //binary: 0101...
const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
const uint64_t hff = 0xffffffffffffffff; //binary: all ones
const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...
 
//This is a naive implementation, shown for comparison,
//and to help in understanding the better functions.
//It uses 24 arithmetic operations (shift, add, and).
int popcount_1(uint64_t x) {
    x = (x & m1 ) + ((x >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
    x = (x & m2 ) + ((x >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
    x = (x & m4 ) + ((x >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
    x = (x & m8 ) + ((x >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
    x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into those 32 bits 
    x = (x & m32) + ((x >> 32) & m32); //put count of each 64 bits into those 64 bits 
    return x;
}
 
//This uses fewer arithmetic operations than any other known  
//implementation on machines with slow multiplication.
//It uses 17 arithmetic operations.
int popcount_2(uint64_t x) {
    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
    x += x >>  8;  //put count of each 16 bits into their lowest 8 bits
    x += x >> 16;  //put count of each 32 bits into their lowest 8 bits
    x += x >> 32;  //put count of each 64 bits into their lowest 8 bits
    return x & 0x7f;
}
 
//This uses fewer arithmetic operations than any other known  
//implementation on machines with fast multiplication.
//It uses 12 arithmetic operations, one of which is a multiply.
int popcount_3(uint64_t x) {
    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
    return (x * h01)>>56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
}


int compare (const void * a, const void * b)
{
  return ( *(uint64_t*)a - *(uint64_t*)b );
}

int main (int argc, char **argv) {
   if( argc != 2 ) return -1;
   ifstream myfile;
   int ntests;

   myfile.open( argv[1] );
   myfile >> ntests;
   trace( "Ntests = %d\n",  ntests );

   for( int i = 1; i <=  ntests; i++ ) {
      trace( "-----------\n" );
      trace( "| Test %02d |\n", i );
      trace( "-----------\n" );

      uint64_t outlet[150], device[150], mod[150];
      int N, L;
      myfile >> N >> L;
      trace( "N: %d, L: %d\n", N, L );

      for( int k = 0; k < N; k++ )
      {
         char num[41];
         num[40] = '\0';
         myfile >> num;
         outlet[k] = 0;
         for(int j = 0; j < L; j++)
         {
            outlet[k] <<= 1;
            outlet[k] += (num[j] - 48);
         }
         trace( "%.0f ", (double)outlet[k] );
      }
      trace( "\n" );
      for( int k = 0; k < N; k++ )
      {
         char num[41];
         num[40] = '\0';
         myfile >> num;
         device[k] = 0;
         for(int j = 0; j < L; j++)
         {
            device[k] <<= 1;
            device[k] += (num[j] - 48);
         }
         trace( "%.0f ", (double)device[k] );
      }
      trace( "\n" );
      qsort( device, N, sizeof(uint64_t), compare );
      for(int k = 0; k < N; k++ ) { trace( "%0.f ", (double)device[k] ); }
      trace( "\n" );

      int min = 999;
      for( int k = 0; k < N; k++ )
      {
         uint64_t trans = device[0] ^ outlet[k];
         trace( "Trans %d: %.0f\n", k, (double)trans );
         for( int j = 0; j < N; j++ )
         {
            mod[j] = outlet[j] ^ trans;
            trace( "%.0f ", (double)mod[j] );
         }
         trace( "\n" );

         qsort( mod, N, sizeof(uint64_t), compare );
         for(int j = 0; j < N; j++ ) { trace( "%0.f ", (double)mod[j] ); }
         trace( "\n" );

         bool bOK = true;
         for(int j = 0; j < N; j++ )
         {
            if( device[j] != mod[j] ) { bOK = false; break; }
         }

         if( bOK )
         {
            int diff = popcount_2( trans );
            if( diff < min ) { min = diff; }
         }
      }
      if( min < 999 )
         printf( "Case #%d: %d\n", i, min );
      else
         printf( "Case #%d: NOT POSSIBLE\n", i );
   }

   myfile.close();
   return 0;
}
