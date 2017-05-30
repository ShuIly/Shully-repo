#include <iostream>
using namespace std;
int N, Q;
int from[1000000], to[1000000];
int path_without_box = -1, first_pos, second_pos, ans;
int main()
{

   cin >> N >> Q;
   for (int i = 0; i < Q; i++) {
      cin >> from[i] >> to[i];
      if(from[i] != to[i-1] && i != 0 && path_without_box < abs(from[i] - to[i-1])){
         path_without_box = abs(from[i] - to[i-1]);
         second_pos = from[i];
         cout << "second begins at: " << second_pos << endl;
      }
   }
   first_pos = from[0];
   for (int i = 0; i < Q; i++) {
      if(abs(first_pos - from[i]) < abs(second_pos - from[i])){
         cout << "first: " << first_pos << " -> " << to[i] << endl;
         ans += abs(first_pos - from[i]) + abs(from[i] - to[i]);
         first_pos = to[i];
      }else{
         cout << "second: " << second_pos << " -> " << to[i] << endl;
         ans += abs(second_pos - from[i]) + abs(from[i] - to[i]);
         second_pos = to[i];
      }
   }
   cout << ans << endl;

   return 0;
}
