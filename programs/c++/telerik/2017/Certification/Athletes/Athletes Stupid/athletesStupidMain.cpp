#include <iostream>
#include <vector>
using namespace std;
int N, M, best_time, best_finisher;
int athlete_pos[100005], athlete_speed[100005], finish_pos[1000005];
int main()
{

   cin >> N >> M;
   for (int i = 0; i < N; i++) {
      cin >> athlete_pos[i] >> athlete_speed[i];
   }
   for (int i = 0; i < M; i++) {
      cin >> finish_pos[i];
   }
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         double time_for_finish = athlete_speed[i] / (abs(athlete_pos[i]) + finish_pos[j]);
         if(best_time < time_for_finish){
            best_time = time_for_finish;
            best_finisher = i;
         }
      }
      cout << best_finisher;
   }
   return 0;
}

