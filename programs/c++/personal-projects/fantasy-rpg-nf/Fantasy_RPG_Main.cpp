#include "Fantasy_RPG_Classes.h"
#include "Fantasy_RPG_Field.h"
#include "Fantasy_RPG_Input.h"
#include "Fantasy_RPG_Enemy.h"
using namespace std;

int main(){

    srand(time(0));
    ChooseClass obj1;
    AI en;
    system("color e");
    obj1.startingClass();
    createField();
    refresh();

    ios_base::sync_with_stdio(false);

    while(gameOver != true){

        Controls pl;
        AI en;
        Move = getch();

        if(Move == 'w'){
            pl.moveUp();
        }
        if(Move == 's'){
            pl.moveDown();
        }
        if(Move == 'a'){
            pl.moveLeft();
        }
        if(Move == 'd'){
            pl.moveRight();
        }
        if(Move == 'e'){
            pl.moveUpRight();
        }
        if(Move == 'q'){
            pl.moveUpLeft();
        }
        if(Move == 'z'){
            pl.moveDownLeft();
        }
        if(Move == 'c'){
            pl.moveDownRight();
        }
        if(Move == '1'){
            pl.basicAttack(obj1.returnClass());
        }
        turn = en.enemySpotter(turn);
        refresh();
    }

    return 0;
}
