#include "ReachHeader.h"

int main(){

    system("color 3e");

    long long x, y, razmer, p = 1 , q = 1 , rnx, c = 6 , j = 7;
    long long rnx1, rcx, CoinNumb = 0, MovesTillEnemyTurn = 1, MovesTillReach, Comp = 1, Fpole[100][100];
    char pole[100][100], Move, player = 1 , enemy = 2, swarm;
    bool MadeMove = false, NCL = true;

    cout << "Hello and welcome to Reach!\n";
    system("pause");
    system("cls");
    cout << "Instructions:\n\nYou can move with the WASD keys.\n1. Collect coins and win.\n2. You lose if the other smiley face catches you\nGood Luck!\n\n";
    system("pause");
    system("cls");

    razmer = 20;

        for(y = 0 ; y < razmer ; ++y){
            rcx = rand() % razmer + 1;
            rnx = rand() % razmer + 1;
            rnx1 = rand() % razmer + 1;
            for(x = 0 ; x < razmer ; ++x){
                pole[x][y] = '.';
                pole[rnx][y] = '#';
                pole[rnx1][y] = '#';
                pole[rcx][y] = '0';
                pole[p][q] = player;
                pole[c][j] = enemy;

                cout << pole[x][y];
                }
                cout << endl;
        }

        while(pole[c][j] != pole[p][q] and CoinNumb != razmer/2){

            /* Where you start moving */

            Move = _getch();

            if(Move == 'w' and (pole[p][q-1] == '.' or pole[p][q-1] == '0')){
                if( pole[p][q-1] == '0'){
                    ++CoinNumb;
                }
                --q;
                pole[p][q] = player;
                pole[p][q+1] = '.';
            }else if(pole[p][q-1] == enemy and Move == 'w'){
                --q;
                pole[p][q] = enemy;
                pole[p][q+1] = '.';
            }

            if(Move == 's' and (pole[p][q+1] == '.' or pole[p][q+1] == '0')){
                if( pole[p][q+1] == '0'){
                    ++CoinNumb;
            }
                ++q;
                pole[p][q] = player;
                pole[p][q-1] = '.';
            }else if(pole[p][q+1] == enemy and Move == 's'){
                ++q;
                pole[p][q] = enemy;
                pole[p][q-1] = '.';
            }

            if(Move == 'a' and (pole[p-1][q] == '.' or pole[p-1][q] == '0')){
                if(pole[p-1][q] == '0'){
                    ++CoinNumb;
            }
                --p;
                pole[p][q] = player;
                pole[p+1][q] = '.';
            }else if(pole[p-1][q] == enemy and Move == 'a'){
                --p;
                pole[p][q] = enemy;
                pole[p+1][q] = '.';
            }

            if(Move == 'd' and (pole[p+1][q] == '.' or pole[p+1][q] == '0')){
                if( pole[p+1][q] == '0'){
                    ++CoinNumb;
                }
                ++p;
                pole[p][q] = player;
                pole[p-1][q] = '.';
            }else if(pole[p+1][q] == enemy and Move == 'd'){
                ++p;
                pole[p][q] = enemy;
                pole[p-1][q] = '.';
            }

            for(y = 0 ; y < razmer ; ++y){
                for(x = 0 ; x < razmer ; ++x){
                    Fpole[x][y] = pole[x][y];
                }
            }

                                    /* Where the enemy starts moving, First comes the map DIGITALIZER! */

            if(MovesTillEnemyTurn > 1){
                MovesTillEnemyTurn = 0;
                MovesTillReach = 1;
                NCL = true;
                swarm = '1';
                Comp = '1';

                while(NCL == true){
                    for(y = 0 ; y < razmer ; ++y){
                        for(x = 0 ; x < razmer ; ++x){
                            if(Fpole[x][y] == enemy or Fpole[x][y] == swarm - 1 and Fpole[x][y] != '0'){

                                if(Fpole[x+1][y] == '.'){
                                Fpole[x+1][y] = swarm;
                                }

                                if(Fpole[x+1][y] == player and MovesTillReach == 1){
                                    MovesTillReach = swarm;
                                    NCL = false;
                                }

                                if(Fpole[x-1][y] == '.'){
                                    Fpole[x-1][y] = swarm;
                                }

                                if(Fpole[x-1][y] == player and MovesTillReach == 1){
                                    MovesTillReach = swarm;
                                    NCL = false;
                                }

                                if(Fpole[x][y+1] == '.'){
                                    Fpole[x][y+1] = swarm;
                                }

                                if(Fpole[x][y+1] == player and MovesTillReach == 1){
                                    MovesTillReach = swarm;
                                    NCL = false;
                                }

                                if(Fpole[x][y-1] == '.'){
                                    Fpole[x][y-1] = swarm;
                                }

                                if(Fpole[x][y-1] == player and MovesTillReach == 1){
                                    MovesTillReach = swarm;
                                    NCL = false;
                                }

                        }
                    }
                }
               ++swarm;
            }

            for(y = 0 ; y < razmer ; ++y){
                for(x = 0 ; x < razmer ; ++x){
                    Fpole[x][y] = pole[x][y];
                }
            }


                                          /* where the new move system starts */


            if(MadeMove == false and (Fpole[c+1][j] == '.' or Fpole[c+1][j] == player)){    /**  1  */
                Comp = 1;
                swarm = '1';
                NCL = true;
                ++c;
                Fpole[c][j] = enemy;

                if(Fpole[c][j] == Fpole[p][q]){
                    NCL = false;
                    pole[c][j] = pole[p][q];
                }

                while(NCL == true){
                    for(y = 0 ; y < razmer ; ++y){
                        for(x = 0 ; x < razmer ; ++x){
                            if(Fpole[x][y] == enemy or Fpole[x][y] == swarm - 1 and Fpole[x][y] != '0'){

                                if(Fpole[x+1][y] == '.'){
                                    Fpole[x+1][y] = swarm;
                                }

                                if(Fpole[x+1][y] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x-1][y] == '.'){
                                    Fpole[x-1][y] = swarm;
                                }

                                if(Fpole[x-1][y] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x][y+1] == '.'){
                                    Fpole[x][y+1] = swarm;
                                }

                                if(Fpole[x][y+1] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x][y-1] == '.'){
                                    Fpole[x][y-1] = swarm;
                                }

                                if(Fpole[x][y-1] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }
                            }
                        }
                    }
                   ++swarm;
                }

                if(Comp < MovesTillReach){
                    pole[c][j] = enemy;
                    pole[c-1][j] = '.';
                    MadeMove = true;

                }else{
                    --c;
                    Fpole[c][j] = enemy;
                    Fpole[c+1][j] = '.';
                }

                for(y = 0 ; y < razmer ; ++y){
                    for(x = 0 ; x < razmer ; ++x){
                        Fpole[x][y] = pole[x][y];
                    }
                }
            }

            if(MadeMove == false and (Fpole[c-1][j] == '.' or Fpole[c-1][j] == player)){   /**  2  */
               Comp = 1;
               swarm = '1';
               NCL = true;
               --c;
               Fpole[c][j] = enemy;

               if(Fpole[c][j] == Fpole[p][q]){
                    NCL = false;
                    pole[c][j] = pole[p][q];
               }


                while(NCL == true){
                    for(y = 0 ; y < razmer ; ++y){
                        for(x = 0 ; x < razmer ; ++x){
                            if(Fpole[x][y] == enemy or Fpole[x][y] == swarm - 1 and Fpole[x][y] != '0'){

                                if(Fpole[x+1][y] == '.'){
                                    Fpole[x+1][y] = swarm;
                                }
                                if(Fpole[x+1][y] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x-1][y] == '.'){
                                    Fpole[x-1][y] = swarm;
                                }

                                if(Fpole[x-1][y] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x][y+1] == '.'){
                                    Fpole[x][y+1] = swarm;
                                }

                                if(Fpole[x][y+1] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x][y-1] == '.'){
                                    Fpole[x][y-1] = swarm;
                                }

                                if(Fpole[x][y-1] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }
                            }
                        }
                    }
                ++swarm;
                }

                if(Comp < MovesTillReach){
                    pole[c][j] = enemy;
                    pole[c+1][j] = '.';
                    MadeMove = true;

                }else{
                    ++c;
                    Fpole[c][j] = enemy;
                    Fpole[c-1][j] = '.';
                }

                for(y = 0 ; y < razmer ; ++y){
                    for(x = 0 ; x < razmer ; ++x){
                        Fpole[x][y] = pole[x][y];
                    }
                }
            }


            if(MadeMove == false and (Fpole[c][j+1] == '.' or Fpole[c][j+1] == player)){     /**  3  */
                Comp = 1;
                swarm = '1';
                NCL = true;
                ++j;
                Fpole[c][j] = enemy;


                if(Fpole[c][j] == Fpole[p][q]){
                    NCL = false;
                    pole[c][j] = pole[p][q];
                }

                while(NCL == true){
                    for(y = 0 ; y < razmer ; ++y){
                        for(x = 0 ; x < razmer ; ++x){
                            if(Fpole[x][y] == enemy or Fpole[x][y] == swarm - 1 and Fpole[x][y] != '0'){

                                if(Fpole[x+1][y] == '.'){
                                    Fpole[x+1][y] = swarm;
                                }

                                if(Fpole[x+1][y] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x-1][y] == '.'){
                                    Fpole[x-1][y] = swarm;
                                }

                                if(Fpole[x-1][y] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x][y+1] == '.'){
                                    Fpole[x][y+1] = swarm;
                                }

                                if(Fpole[x][y+1] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x][y-1] == '.'){
                                    Fpole[x][y-1] = swarm;
                                }

                                if(Fpole[x][y-1] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }
                            }
                        }
                    }
               ++swarm;
                }

                if(Comp < MovesTillReach){
                    MadeMove = true;
                    pole[c][j] = enemy;
                    pole[c][j-1] = '.';

                }else{
                    --j;
                    Fpole[c][j] = enemy;
                    Fpole[c][j+1] = '.';
                }

                for(y = 0 ; y < razmer ; ++y){
                    for(x = 0 ; x < razmer ; ++x){
                        Fpole[x][y] = pole[x][y];
                    }
                }
            }

            if(MadeMove == false and (Fpole[c][j-1] == '.' or Fpole[c][j-1] == player)){     /**  4  */
                Comp = 1;
                swarm = '1';
                NCL = true;
                --j;
                Fpole[c][j] = enemy;

                if(Fpole[c][j] == Fpole[p][q]){
                    NCL = false;
                    pole[c][j] = pole[p][q];
                }

                while(NCL == true){
                    for(y = 0 ; y < razmer ; ++y){
                        for(x = 0 ; x < razmer ; ++x){
                            if(Fpole[x][y] == enemy or Fpole[x][y] == swarm - 1 and Fpole[x][y] != '0'){

                                if(Fpole[x+1][y] == '.'){
                                    Fpole[x+1][y] = swarm;
                                }

                                if(Fpole[x+1][y] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x-1][y] == '.'){
                                    Fpole[x-1][y] = swarm;
                                }

                                if(Fpole[x-1][y] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x][y+1] == '.'){
                                    Fpole[x][y+1] = swarm;
                                }

                                if(Fpole[x][y+1] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }

                                if(Fpole[x][y-1] == '.'){
                                    Fpole[x][y-1] = swarm;
                                }

                                if(Fpole[x][y-1] == player and Comp == 1){
                                    Comp = swarm;
                                    NCL = false;
                                    x = razmer;
                                    y = razmer;
                                }
                            }
                        }
                    }
                ++swarm;
                }

                if(Comp < MovesTillReach){
                    pole[c][j] = enemy;
                    pole[c][j+1] = '.';
                    MadeMove = true;

                }else{
                    ++j;
                    Fpole[c][j] = enemy;
                    Fpole[c][j-1] = '.';
                }

                for(y = 0 ; y < razmer ; ++y){
                    for(x = 0 ; x < razmer ; ++x){
                        Fpole[x][y] = pole[x][y];
                    }
                }
            }
        }

        system("CLS");

        for(y = 0 ; y < razmer ; ++y){
            for(x = 0 ; x < razmer ; ++x){
                cout << pole[x][y];
            }
            cout << endl;
        }
            MadeMove = false;
            cout << "Coins : " << CoinNumb << "/" << razmer/2 << endl;
            cout << "X - " << p << " Y - " << q;
            ++MovesTillEnemyTurn;
        }

        system("cls");
        if(CoinNumb == razmer/2){
            cout << "Good job! You won!\n";
        }else{
            cout << "You lose! Game over.\n";
        }
        system("pause");


return EXIT_SUCCESS;
}
