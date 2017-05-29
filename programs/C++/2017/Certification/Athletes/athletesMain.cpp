#include <iostream>
#include <vector>
using namespace std;
int N, M;
int athlete_pos[100005], athlete_speed[100005], finish_pos[1000005], athlete_time_till_last[1000005];
vector<int>fastest_athletes, fastest_pos;
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
      athlete_time_till_last[i] = athlete_speed[i] / (abs(athlete_pos[i]) + finish_pos[M-1]);
   }
   
   return 0;
}
