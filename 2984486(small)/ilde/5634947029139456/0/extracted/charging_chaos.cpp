#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <ios>
#include <vector>
#include <string.h>
#include <algorithm>

/*
 * Input:
 * T cases
 * N L 
 * N bits space-separated strings of length L (outlets)
 * N bits space-separated strings of length L (devices)
 * 
 * L switches that will invert the bit of all outlets.
 * 
 * Firstly, I need to bits that doesn't need change on any device (if any).
 * 
 * 10 to 40 bits (L)
 * 1 to 150 devices (N)
 * 
 * Small dataset is really small, doesn't care.
 * 
 * Output:
 * 
 * Is it possible to charge all devices at the same time?
 * 
 * If so: Find the minimum number of switches that she will need to flip in order to achieve it.
 * 
 * Need to know if, somehow, by combining devices and outlets: is it possible to get a *single* XOR bit mask?
 * 
 * So, for each devices combinations (permutations?) XOR with outlet, and see if *all* masks are the same, if any mask is different
 * move on to next permutation, if all masks are the same, count the number of 1s in the mask, and find the lowest number.
 * 
 * 01 11 10
 * 11 00 10
 * 10 11 00
 * 
 * 01 11 10
 * 00 10 11
 * 01 01 01  <--- possible... is there a better way? ---> keep permuting and doing the same.
 */

int count_1s(long long int a)
{
  int x,c=0;
  for(x=0;x<40;x++) // per problem limits, up to 40 bits.
  {
    if(a & ((long long int)1L)<<x)
      c++;
  }
  return c;
}

int main(int argc, char **argv)
{
  std::ifstream in;
  std::ofstream out;
  std::stringstream buf;
  std::string s;
  int L,N;
  int T,t=0;  // number of test cases.
  int n,nn; // number of bits needing flip.
  int x,b,y,sol;
  long long int o[150],d[150],mask,p_mask; // up to 150 outlets (o) and devices (d).
  if(argc==2)
  {
    in.open(argv[1]);
    out.open((std::string(argv[1]) + ".out").c_str(),std::ofstream::out|std::ofstream::trunc);
    std::getline(in,s); // number of test cases.
    buf.str(s);
    buf >> T;
    buf.clear();
    while(std::getline(in,s))
    {
      t++;
      memset(o,0,sizeof(long long int)*150);
      memset(d,0,sizeof(long long int)*150);
      buf.str(s);
      buf >> N;
      buf >> L;
      buf.clear();
      out << "Case #" << t << ": ";
      std::getline(in,s);
      b=0;
      y=0;
      for(x=0;x<s.length();x++) // read outlets
      {
	// read the N bit strings
	if(s[x]=='1')
	{
	  o[y] |= ((long long int)1L)<<b;
	  b++;
	}
	else
	{
	  
	  if(s[x] == '0')
	  {
	    b++; // advance bit.
	  }
	  else
	  {
	    // likely a white space or whatever, all in all, we advance the string number counter
	    y++;
	    b=0; // reset bit counter.
	  }
	}	  
      }
      std::getline(in,s); // devices
      b=0;
      y=0;
      for(x=0;x<s.length();x++) // read devices
      {
	// read the N bit strings
	if(s[x]=='1')
	{
	  d[y] |= ((long long int)1L)<<b;
	  b++;
	}
	else
	{
	  
	  if(s[x] == '0')
	  {
	    b++; // advance bit.
	  }
	  else
	  {
	    // likely a white space or whatever, all in all, we advance the string number counter
	    y++;
	    b=0; // reset bit counter.
	  }
	}	  
      }
      // Now, check all permutations for outlets and the other thing.  lets order them both.
      std::sort (o,o+N);
      std::sort (d,d+N);
      n=42;
      do
      {
	sol=1;
	// First, XOR device and outlets.
	mask=o[0] ^ d[0];
	p_mask=mask;
	for(x=1;x<N;x++)
	{
	  mask = o[x] ^ d[x];
	  if(mask != p_mask)
	  {
	    // not a candidate solution, go to next one.
	    sol=0;
	    break;
	  }
	}
	if(sol)
	{
	  // if we found a candidate solution, count its number of 1s, and find out if it is the minimum number of ones.
	  nn=count_1s(mask);
	  if(nn < n)
	    n=nn;
	}
      }
      while ( std::next_permutation(d,d+N));
      // if we found a candidate solution, 
      if(n<42) // found a solution
      { 
	out << n << std::endl;
      }
      else
      {
	out << "NOT POSSIBLE" << std::endl;
      }
    }
    in.close();
    out.close();
    return 0;
  }
  // help.
  std::cout << "Usage: \n\n" << argv[0] << " input_file\n\n Output file will be input_file.out\n" << std::endl;
  return 1;
}


