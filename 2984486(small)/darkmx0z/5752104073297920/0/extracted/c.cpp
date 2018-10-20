#include <algorithm>
#include <iostream>
#include <vector>

int main( )
{
   int t;
   std::cin >> t;
   
   for (int ti = 0; ti < t; ++ti) {
      int n;
      std::cin >> n;
      
      std::vector<int> permutacion(n);
      
      for (int i = 0; i < n; ++i) {
         std::cin >> permutacion[i]; 
      }
      
      int mala = 0;
      int buena = 0;
      
      for (int i = 0; i < n; ++i) {
         if (i - (std::lower_bound(permutacion.begin( ), permutacion.end( ), i) - permutacion.begin( )) <= n / 4) {
            mala += 1;     
         }
         
         if (permutacion[i] == i) {
            buena += 1;     
         }
      }
      
      std::cout << "Case #" << ti + 1 << ": ";
      
      if (buena >= mala) {
         std::cout << "GOOD\n";     
      }
      else {
         std::cout << "BAD\n";     
      }
   }
}
