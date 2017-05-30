#include <iostream>
using namespace std;
string state, fiction;
bool found;
int main(){

    while(1){
        getline(cin, state);
        if(state == "collapse"){
            break;
        }
        getline(cin, fiction);
        for(int i = 0 ; i < state.size() ; ++i){
            if(fiction[0] == state[i]){
                found = 1;
                for(int j = 0, temp_i = i ; j < fiction.size() ; ++j, ++temp_i){
                    if(fiction[j] != state[temp_i]){
                        found = 0;
                        break;
                    }
                }
            }
            if(found == 1){
                state.erase(i, fiction.size());
                while(state[0] == ' '){
                    state.erase(0, 1);
                }
                i = -1;
                found = 0;
            }
            if(i == state.size()-1 and fiction.size() > 1){
                i = -1;
                fiction.erase(0, 1);
                fiction.erase(fiction.size()-1, 1);
            }
        }
        if(state.size() > 0){
            cout << state << endl;
        }else{
            cout << "(void)" << endl;
        }
    }

    return 0;
}
