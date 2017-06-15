#include <iostream>
using namespace std;
int N, best_pyramid, curr_pyramid;
int how_many[260][1000];
bool which_ones[1000];
string layer;
char ans;
int main(){

    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        cin >> layer;
        for(int j = 0 ; j < layer.size() ; ++j){
            how_many[layer[j]][i]++;
            if(which_ones[layer[j]] == 0){
                which_ones[layer[j]] = 1;
            }
        }
    }
    for(int i = 0 ; i < 257 ; ++i){
        if(which_ones[i] == 1){
            for(int j = 0, n = 1 ; j < N ; ++j, n += 2){
                if(how_many[i][j] >= n){
                    ++curr_pyramid;
                }else{
                    if(curr_pyramid > best_pyramid){
                        best_pyramid = curr_pyramid;
                        ans = i;
                    }
                    curr_pyramid = 0;
                    n = -1;
                }
            }
            if(curr_pyramid > best_pyramid){
                best_pyramid = curr_pyramid;
                ans = i;
            }
            curr_pyramid = 0;
        }
    }
    for(int i = 0 ; i < best_pyramid ; ++i){
        for(int j = 0 ; j < 1 + i*2 ; ++j){
            cout << ans;
        }
        cout << endl;
    }

return 0;
}
