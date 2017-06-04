#include<iostream>
using namespace std;
long long n, q, num[1000000], l, r;
long long smallest[5005][5005];
long long ans[10000005];
int main(){

    cin >> n >> q;
    for(int i = 0 ; i < n ; ++i){
        cin >> num[i];
    }
    for(int i = 0 ; i < n ; ++i){
        smallest[i][i] = num[i];
        for(int j = i+1 ; j < n ; ++j){
            if(num[j] < smallest[i][j-1]){
                smallest[i][j] = num[j];
            }else{
                smallest[i][j] = smallest[i][j-1];
            }
        }
    }

    for(int i = 0 ; i < q ; ++i){
        cin >> l >> r;
        ans[i] = smallest[l][r];
    }
    for(int i = 0 ; i < q ; ++i){
        cout << ans[i] << endl;
    }

    return 0;
}
