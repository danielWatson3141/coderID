#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int resuelve(int i, int n, int s, std::vector<std::string> origen, const std::vector<std::string>& destino)
{
   if (i == s) {
      return 0;     
   }
   
   int minimo = s + 1;

   std::multiset<std::string> origenes;
   std::multiset<std::string> destinos;

   for (int j = 0; j < n; ++j) {
      origenes.insert(origen[j].substr(0, i + 1));
      destinos.insert(destino[j].substr(0, i + 1));
   }

   if (origenes == destinos) {
      minimo = std::min(minimo, resuelve(i + 1, n, s, origen, destino));
   }
   
   origenes.clear( );
   
   for (int j = 0; j < n; ++j) {
      origen[j][i] = !(origen[j][i] - '0') + '0';
      origenes.insert(origen[j].substr(0, i + 1));
   }

   if (origenes == destinos) {
      minimo = std::min(minimo, 1 + resuelve(i + 1, n, s, origen, destino));
   }
   
   return minimo;
}

int main( )
{
   int t;
   std::cin >> t;
   
   for (int ti = 0; ti < t; ++ti) {
      int n, s;
      std::cin >> n >> s;
      
      std::vector<std::string> origen(n);
      std::vector<std::string> destino(n);
      
      for (int i = 0; i < n; ++i) {
         std::cin >> origen[i];     
      }
      
      for (int i = 0; i < n; ++i) {
         std::cin >> destino[i];     
      }
      
      int res = resuelve(0, n, s, origen, destino);
      std::cout << "Case #" << ti + 1 << ": ";
      
      if (res <= s) {
         std::cout << res << '\n';
      }
      else {
         std::cout << "NOT POSSIBLE\n";     
      }
   }
}
