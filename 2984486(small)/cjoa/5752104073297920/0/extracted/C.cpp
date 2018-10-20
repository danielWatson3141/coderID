#include <cstdio>

#include <cstdlib>

#include <vector>
#include <algorithm>

using namespace std;

int N;
int P[1004];

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   int ngood = 0;
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d", &N);
      for (int i = 0; i < N; ++i)
         scanf("%d", P+i);

      double prob_good = 1.0;
      for (int i = 0; i < N; ++i) {
         if (P[i] == 0) continue;
         if (P[i]-1 == i)
            prob_good *= 0.7;
      }
   // cout << bad_score << endl;
   //   fprintf(stderr, "%d: %.5lf\n", tc, prob_good);
      bool good = prob_good >= 0.5;
      if (good) ++ngood;
      printf("Case #%d: %s\n", tc, (good ? "BAD" : "GOOD"));
   }
   fprintf(stderr, "good = %d   bad = %d\n", ngood, TC-ngood);

   return 0;
}
