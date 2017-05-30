#include <iostream>
using namespace std;
string nilapdrome, new_nilapdrome;
bool found;
int rep_begin, rep_end;
int main(){

    while(1){
        getline(cin, nilapdrome);
        if(nilapdrome == "end"){
            break;
        }
        for(int i = nilapdrome.size()/2+1 ; i < nilapdrome.size() and found == 0 ; ++i){
            if(nilapdrome[0] == nilapdrome[i] and (i - nilapdrome.size())*2 != nilapdrome.size()){
                for(int j = 0, temp_i = i ; nilapdrome[j] == nilapdrome[temp_i] ; ++j, ++temp_i){
                    if(temp_i == nilapdrome.size()-1){
                        found = 1;
                        rep_end = j+1;
                        rep_begin = nilapdrome.size() - rep_end;
                        break;
                    }
                }
            }
        }
        if(found == 1){
            for(int i = rep_end ; i < rep_begin ; ++i){
                new_nilapdrome += nilapdrome[i];
            }
            for(int i = 0 ; i < rep_end ; ++i){
                new_nilapdrome += nilapdrome[i];
            }
            for(int i = rep_end ; i < rep_begin ; ++i){
                new_nilapdrome += nilapdrome[i];
            }
            cout << new_nilapdrome << endl;
        }
        found = 0;
        new_nilapdrome.clear();
    }

    return 0;
}
