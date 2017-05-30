#include <iostream>
#include <deque>
using namespace std;
long long field_w, field_h, field[505][505];
long long changes, c_x[50005], c_y[50005], c_height[50005];
deque<long long> a_x, a_y;
deque<long long> smallest_tree;
int main(){

   cin >> field_h >> field_w >> changes;
   for (int y = 0; y < field_h; y++) {
      for (int x = 0; x < field_w; x++) {
         cin >> field[x][y];
      }
   }

   for (int i = 0; i < changes; i++) {
      cin >> c_y[i] >> c_x[i] >> c_height[i];
   }

   long long tree = -1;
   for (int y = 1; y < field_h-1; y++) {
      for (int x = 1; x < field_w-1; x++) {
         if(field[x][y] > field[x+1][y] && field[x][y] > field[x-1][y] &&
               field[x][y] > field[x][y+1] && field[x][y] > field[x][y-1]){
            tree = field[x][y];
            if (smallest_tree.empty() || tree < smallest_tree.front()) {
               smallest_tree.push_front(tree);
               a_x.push_front(x);
               a_y.push_front(y);
            }else{
               smallest_tree.push_back(tree);
               a_x.push_back(x);
               a_y.push_back(y);
            }
         }
      }
   }

   cout << endl;

   for (int i = 0; i < changes; i++) {
      field[c_x[i]][c_y[i]] = c_height[i];
      int x = c_x[i] - 1;
      int y = c_y[i] - 1;
      int e_x = c_x[i] + 1;
      int e_y = c_y[i] + 1;
      if (x <= 0) {
         x = 1;
      }
      if (y <= 0) {
         y = 1;
      }
      if (e_x >= field_w-1) {
         e_x = field_w-2;
      }
      if (e_y >= field_h-1) {
         e_y = field_h-2;
      }
      while(1){
         if(a_x.front() >= x && a_x.front() <= e_x && a_y.front() >= y && a_y.front() <= e_y){
            if(field[x][y] > field[x+1][y] && field[x][y] > field[x-1][y] &&
                  field[x][y] > field[x][y+1] && field[x][y] > field[x][y-1]){
               break;
            }else{
               smallest_tree.pop_front();
               a_x.pop_front();
               a_x.pop_front();
            }
         }else{
            break;
         }
      }

      cout << endl;
      for(int k = 0 ; k < field_h ; ++k){
         for(int m = 0 ; m < field_w ; ++m){
            cout << field[m][k] << " ";
         }
         cout << endl;
      }

      cout << a_y.front() << " " << a_x.front() << " " << smallest_tree.front() << endl;
   }

   return 0;
}
