#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

void calcula_peso(int actual, int padre, int n, const std::vector<std::vector<bool>>& adyacencia, std::vector<int>& peso)
{
   peso[actual] = 1;
   
   for (int i = 0; i < n; ++i) {
      if (adyacencia[actual][i] && i != padre) {
         calcula_peso(i, actual, n, adyacencia, peso);
         peso[actual] += peso[i];
      }
   }
}

void borra_hijos(int actual, int padre, int n, const std::vector<std::vector<bool>>& adyacencia, std::vector<int>& peso)
{
   std::vector<int> peso_hijos;
   
   for (int i = 0; i < n; ++i) {
      if (adyacencia[actual][i] && i != padre) {
         borra_hijos(i, actual, n, adyacencia, peso);
         peso_hijos.push_back(peso[i]);
      }
   }
//std::cout << actual + 1 << " tiene " << peso_hijos.size( ) << " hijos\n";
   if (peso_hijos.size( ) == 1) {
//std::cout << "...debe borrar su unico hijo\n";
      peso[actual] = 1;
   }
   else if (peso_hijos.size( ) > 2) {
//std::cout << "...debe elegir sus dos mejores hijos\n";
      std::sort(peso_hijos.begin( ), peso_hijos.end( ), std::greater<int>( ));
      peso[actual] = peso_hijos[0] + peso_hijos[1] + 1;
   }
   else {
//std::cout << "...es hoja o tiene dos hijos\n";
      peso[actual] = std::accumulate(peso_hijos.begin( ), peso_hijos.end( ), 0) + 1;
   }
//std::cout << "despues de borrar " << actual + 1 << " queda con peso " << peso[actual] << '\n';
}

int mejor_arbol(int raiz, int n, const std::vector<std::vector<bool>>& adyacencia)
{
//std::cout << "---usando " << raiz + 1 << " de raiz\n";
   std::vector<int> peso(n, 0);
   
   calcula_peso(raiz, -1, n, adyacencia, peso);
   borra_hijos(raiz, -1, n, adyacencia, peso);
   
   return n - peso[raiz];
}

int main( )
{
   int t;
   std::cin >> t;
   
   for (int ti = 0; ti < t; ++ti) {
      int n;
      std::cin >> n;
      
      std::vector<std::vector<bool>> adyacencia(n, std::vector<bool>(n, false));
      
      for (int i = 0; i < n - 1; ++i) {
         int x, y;
         std::cin >> x >> y;
         
         adyacencia[x - 1][y - 1] = true;
         adyacencia[y - 1][x - 1] = true;    
      }
      
      int minimo = n;
      
      for (int i = 0; i < n; ++i) {
         minimo = std::min(minimo, mejor_arbol(i, n, adyacencia));
      }
      
      std::cout << "Case #" << ti + 1 << ": " << minimo << '\n';
   }
}
