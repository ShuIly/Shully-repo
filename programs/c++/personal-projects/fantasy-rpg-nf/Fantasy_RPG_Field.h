#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "Fantasy_RPG_Player.h"
using namespace std;

char field[10001][10001], vis_field[10001][10001], Move, player = 'P';
int playerX = 5000, playerY = 5000;
PlayerStats obj;

void createRocks(int rockX, int rockY, int rockSize){
    for(int j = 0 ; j < rockSize ; ++j){
        for(int i = 0 ; i < 4 ; ++i){
            if(rand()%2 + 1 == 2 and i == 0 and field[rockX][rockY-1] == '.'){
                field[rockX][rockY-1] = '#';
                createRocks(rockX, rockY-1, rockSize-1);
            }
            if(rand()%2 + 1 == 2 and i == 1 and field[rockX][rockY+1] == '.'){
                field[rockX][rockY+1] = '#';
                createRocks(rockX, rockY+1, rockSize-1);
            }
            if(rand()%2 + 1 == 2 and i == 2 and field[rockX-1][rockY] == '.'){
                field[rockX-1][rockY] = '#';
                createRocks(rockX-1, rockY, rockSize-1);
            }
            if(rand()%2 + 1 == 2 and i == 3 and field[rockX+1][rockY] == '.'){
                field[rockX+1][rockY] = '#';
                createRocks(rockX+1, rockY, rockSize-1);
            }
        }
    }
}

void createField(){
    int load = 0;
    system("CLS");
    cout << "Now Loading: 0%";
    for(int y = 0 ; y < 10000 ; ++y){
        for(int x = 0 ; x < 10000 ; ++x){
            field[x][y] = '.';
            vis_field[x][y] = ' ';
        }
    }
    system("CLS");
    cout << "Now Loading: 33%";
    int enemyX;
    for(int y = 0 ; y < 10000 ; ++y){
        for(int x = 0 ; x < 10000 ; x += 200){
            enemyX = rand()% 10000 + 1;
            field[enemyX][y] = 'E';
        }
    }
    system("CLS");
    cout << "Now Loading: 66%";
    int rockX, rockSize;
    for(int y = 0 ; y < 10000 ; ++y){
        for(int x = 0 ; x < 10000 ; x += 600){
            rockX = rand()% 10000 + 1;
            rockSize = rand()%7 + 1;
            if(rockX != playerX or y != playerY){
                field[rockX][y] = '#';
                createRocks(rockX, y, rockSize);
            }
        }
    }
}

void refresh(){
    system("CLS");
    cout << "HP: "; obj.showHP(); cout << " MP: "; obj.showMP();
    cout << " ST: "; obj.showST(); cout << " Coins: "; obj.showCO(); cout << endl;

    for(int y = playerY - 6 ; y < playerY + 7 ; ++y){
        for(int x = playerX - 6 ; x < playerX + 7 ; ++x){
            if(vis_field[x][y] != ' '){
                vis_field[x][y] = field[x][y];
            }
        }
    }
    for(int y = playerY - 4 ; y < playerY + 5 ; ++y){
        for(int x = playerX - 4 ; x < playerX + 5 ; ++x){
            vis_field[x][y] = field[x][y];
        }
    }
    vis_field[playerX][playerY] = player;
    for(int y = playerY - 11 ; y < playerY + 12 ; ++y){
        for(int x = playerX - 38 ; x < playerX + 38 ; ++x){
            cout << vis_field[x][y];
        }
        cout << endl;
    }

}
