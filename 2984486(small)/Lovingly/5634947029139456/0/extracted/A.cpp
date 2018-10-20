#include <iostream>
#include <vector>

using namespace std;

bool Matching( vector<unsigned int> const init, vector<unsigned int> const final, unsigned int size, unsigned int mask )
{
   vector<bool> checked(size);

   for( auto a : init )
   {
      unsigned int tempA = a ^ mask;
      for( size_t i = 0; i < size; ++i )
      {

	 if( checked.at(i) == true )
	    continue;
	 
	 unsigned int tempB = final.at(i);
	 if( tempA == tempB )
	 {
	    checked.at(i) = true;
	    break;
	 }
      }
   }

   for( auto check : checked )
   {
      if( !check )
      {
	 return false;
      }
   }
   return true;
}

unsigned int NumSwitches( unsigned int n )
{
   unsigned int num = 0;
   while( n > 0 )
   {
      if( n % 2 == 1 )
	 ++num;
      n = n / 2;
   }
   
   return num;
}

unsigned int StringToBin( string&& s )
{
   unsigned int num = 0;
   for( auto j : s )
   {
      num = num * 2 + ( j - '0' );
   }
   
   return num;
}

int NewMask(unsigned int mask, unsigned int maxMask, unsigned int& numSwitches, unsigned int length)
{
   if(numSwitches > length)
      return -1;
   bool newSet = false;
   for( unsigned int newN = mask + 1; newN <= maxMask; ++newN )
   {
      if( NumSwitches(newN) == numSwitches )
      {
	 mask = newN;
	 newSet = true;
	 break;
      }
   }
   if( ! newSet )
   {
      ++numSwitches;
      return NewMask(0, maxMask, numSwitches, length);
   }

   return mask;
}


int main()
{
   unsigned int testCases;
   cin >> testCases;
   for( size_t t = 1; t <= testCases; ++t )
   {
      unsigned int n, l;
      cin >> n >> l;
      vector<unsigned int> init;
      vector<unsigned int> final;

      string tempS;
      unsigned int tempN;
      for( size_t i = 0; i < n; ++i )
      {
	 cin >> tempS;
	 tempN = StringToBin(move(tempS));
	 init.push_back(tempN);
      }

      for( size_t i = 0; i < n; ++i )
      {
	 cin >> tempS;
	 tempN = StringToBin(move(tempS));
	 final.push_back(tempN);
      }


      unsigned int maxMask = 1;
      for( size_t i = 0; i < l; ++i )
      {
	 maxMask = maxMask * 2;
      }
      --maxMask;

      
      cout << "Case #" << t << ": ";

      unsigned int mask = 0;
      int tempMask = 0;
      unsigned numSwitches = 0;
      bool matched = false;
      while( tempMask != -1 )
      {
	 mask = tempMask;

      	 matched = Matching(init, final, n, mask);

	 if( matched )
	 {
	    cout << numSwitches;
	    break;
	 }
	 tempMask = NewMask(mask, maxMask, numSwitches, l);
      }
      if( !matched )
	 cout << "NOT POSSIBLE";


      cout << endl;
      
      
   }
   return 0;
}
