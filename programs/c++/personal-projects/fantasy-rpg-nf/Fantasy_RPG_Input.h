#include <iostream>
#include <conio.h>

class Controls {
    public:
    void moveLeft(){
        vis_field[playerX][playerY] = '.';
        playerX--;
        vis_field[playerX][playerY] = player;
    }

    void moveRight(){
        vis_field[playerX][playerY] = '.';
        playerX++;
        vis_field[playerX][playerY] = player;
    }

    void moveUp(){
        vis_field[playerX][playerY] = '.';
        playerY--;
        vis_field[playerX][playerY] = player;
    }

    void moveDown(){
        vis_field[playerX][playerY] = '.';
        playerY++;
        vis_field[playerX][playerY] = player;
    }

    void moveUpRight(){
        vis_field[playerX][playerY] = '.';
        playerX++;
        playerY--;
        vis_field[playerX][playerY] = player;
    }

    void moveUpLeft(){
        vis_field[playerX][playerY] = '.';
        playerX--;
        playerY--;
        vis_field[playerX][playerY] = player;
    }

    void moveDownRight(){
        vis_field[playerX][playerY] = '.';
        playerX++;
        playerY++;
        vis_field[playerX][playerY] = player;
    }

    void moveDownLeft(){
        vis_field[playerX][playerY] = '.';
        playerX--;
        playerY++;
        vis_field[playerX][playerY] = player;
    }

    void basicAttackRogue(int slashX, int slashY, int* lastX, int* lastY, int* slashed){
        field[*lastX][*lastY] = *slashed;
        *slashed = field[slashX][slashY];
        field[slashX][slashY] = '/';
        *lastX = slashX;
        *lastY = slashY;
    }

    void basicAttack(int curr_class){
        int slashed[2], chooser, lastX, lastY;
        if(curr_class == 0){
            slashed[0] = field[playerX][playerY-1];
            field[playerX][playerY-1] = '/';
            lastX = playerX;
            lastY = playerY-1;
            refresh();
            while(1){
                chooser = getch();
                if(chooser == 'w'){
                    basicAttackRogue(playerX, playerY-1, &lastX, &lastY, &slashed[0]);
                }
                else if(chooser == 's'){
                    basicAttackRogue(playerX, playerY+1, &lastX, &lastY, &slashed[0]);
                }
                else if(chooser == 'a'){
                    basicAttackRogue(playerX-1, playerY, &lastX, &lastY, &slashed[0]);
                }
                else if(chooser == 'd'){
                    basicAttackRogue(playerX+1, playerY, &lastX, &lastY, &slashed[0]);
                }
                else if(chooser == 'q'){
                    basicAttackRogue(playerX-1, playerY-1, &lastX, &lastY, &slashed[0]);
                }
                else if(chooser == 'e'){
                    basicAttackRogue(playerX+1, playerY-1, &lastX, &lastY, &slashed[0]);
                }
                else if(chooser == 'z'){
                    basicAttackRogue(playerX-1, playerY+1, &lastX, &lastY, &slashed[0]);
                }
                else if(chooser == 'c'){
                    basicAttackRogue(playerX+1, playerY+1, &lastX, &lastY, &slashed[0]);
                }
                else if(chooser == 10){
                    field[lastX][lastY] = slashed[0];
                    break;
                }
                else{
                    field[lastX][lastY] = '.';
                    break;
                }
                refresh();
            }
        }
    }
};
