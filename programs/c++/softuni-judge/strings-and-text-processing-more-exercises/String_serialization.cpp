#include <iostream>
using namespace std;
string a;
bool found[260];
int main(){
    getline(cin, a);
    for(int i = 0 ; i < a.size() ; ++i){
        if(found[a[i]] == 0){
            found[a[i]] = 1;
            cout << a[i] << ":" << i;
            for(int j = i+1 ; j < a.size() ; ++j){
                if(a[j] == a[i]){
                    cout << "/" << j;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
