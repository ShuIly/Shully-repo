#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
bool turn, found;
class AI {
    public:
        void searchFieldForEnemy(int x, int y){
            if(vis_field[x][y] == 'E'){
                        found = true;
                        if(turn == true){
                            field[x][y] = '.';
                            if(x > playerX and y > playerY and field[x-1][y-1] != 'E'){
                                field[x-1][y-1] = 'E';
                                }else if(x < playerX and y < playerY and field[x+1][y+1] != 'E'){
                                    field[x+1][y+1] = 'E';
                                }else if(x > playerX and y < playerY and field[x-1][y+1] != 'E'){
                                    field[x-1][y+1] = 'E';
                                }else if(x < playerX and y > playerY and field[x+1][y-1] != 'E'){
                                    field[x+1][y-1] = 'E';
                                }else if(abs(playerX-x) >= abs(playerY-y)){
                                if(x > playerX){
                                    field[x-1][y] = 'E';
                                }else if (x < playerX){
                                    field[x+1][y] = 'E';
                                }
                            }else if(abs(playerX-x) < abs(playerY-y)){
                                if(y > playerY){
                                    field[x][y-1] = 'E';
                                }else if(y < playerY){
                                    field[x][y+1] = 'E';
                                }
                            }
                        }
                    }
        }
        bool enemySpotter(bool turn){
            for(int y = playerY ; y < playerY + 7 ; ++y){
                for(int x = playerX ; x < playerX + 7 ; ++x){
                    searchFieldForEnemy(x, y);
                }
            }
            for(int y = playerY ; y > playerY - 7 ; --y){
                for(int x = playerX ; x > playerX - 7 ; --x){
                    searchFieldForEnemy(x, y);
                }
            }
            for(int y = playerY - 1 ; y > playerY - 7 ; --y){
                for(int x = playerX + 1 ; x < playerX + 7 ; ++x){
                    searchFieldForEnemy(x, y);
                }
            }
            for(int y = playerY + 1 ; y < playerY + 7 ; ++y){
                for(int x = playerX - 1 ; x > playerX - 7 ; --x){
                    searchFieldForEnemy(x, y);
                }
            }
            if(field[playerX][playerY] == 'E'){
                player = 'E';
                gameOver = true;
            }
            if(turn == false and found == true){
                return 1;
            }else{
                return 0;
            }
        }
};
