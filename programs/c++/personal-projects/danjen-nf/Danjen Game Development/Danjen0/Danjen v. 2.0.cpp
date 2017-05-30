#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

int main (){

    char Dungeon[20][20];
    long long x = 0, y = 0, Hp = 1, Energy = 100, Special = 1, p = 2, q = 7;
    char Rogue, Mage, Knight, Archer, Move;
    char Warrior = 'W', ArchWarrior = 'A', MageWarrior = 'M', Bomber = 'B', Choosechar = 'r', Character = Rogue, Exit = '#';
    string CharName = "Rogue";
    bool Error = false;

    cout << "Hello and welcome to Danjen - an RPG chess-like homemade game!"<< endl << endl ;
    system("PAUSE");
    system("CLS");

    cout << "Now you should choose a character to begin to play : " << endl << endl << "1. Rogue (r) " << endl << "2. Mage (m) " << endl << "3. Knight (k) " << endl << "4. Archer (a) " << endl << endl;
    cin >> Choosechar;
    system("CLS");

    if(Choosechar == 'r' or '1'){
        Character = Rogue;
        CharName = "Rogue";
        Energy = 100;
        Special = 1;
        Hp = 1;
    }

    if(Choosechar == 'k' or '3'){
        Character = Knight;
        CharName = "Knight";
        Energy = 50;
        Special = 1;
        Hp = 3;
    }

    if(Choosechar == 'm' or '2'){
        Character = Mage;
        CharName = "Mage";
        Energy = 0;
        Special = 2;
        Hp = 2;
    }

    if(Choosechar == 'a' or '4'){
        Character = Archer;
        CharName = "Archer";
        Energy = 25;
        Hp = 2;
    }

    cout << "Very well... You've chosen " << CharName << endl <<"We wish you an epic adventure!"<< endl << endl;
    system("PAUSE");
    system("CLS");

    while(Character != Exit){
        for(y = 0 ; y < 8 ; ++y){
            for(x = 0 ; x < 7 ; ++x){
                Dungeon[x][y] = '.';
                Dungeon[p][q] = Choosechar;
                Dungeon[5][6] = Warrior;
                Dungeon[1][3] = ArchWarrior;
                Dungeon[6][4] = Bomber;
                Dungeon[1][1] = Exit;
                Dungeon[1][5] = '~';
                Dungeon[2][5] = '~';
                Dungeon[1][6] = '~';
                Dungeon[2][6] = '~';
                Dungeon[4][1] = '~';
                Dungeon[4][2] = '~';
                Dungeon[5][1] = '~';
                Dungeon[5][2] = '~';
                cout << Dungeon[x][y] << " ";
            }
            cout << endl << endl;
        }

        if(Dungeon[p][q] != '#'){
            if(Error == true){
                cout << "Invalid move!" << endl << endl;
            }else{
                cout << endl << endl;
            }

            cout << "Health = " << Hp << endl << "Energy = " << Energy << endl << "Special = " << Special << endl << endl << "Your move : " << endl << p << " " << q << "  ";
            Move = getch();


            if(Dungeon[p][q-1] != '.' and Dungeon[p][q-1] != '#' and Move == 'w'){
                Error = true;
                system("CLS");
            }else if(Dungeon[p][q-1] = '.' and Move == 'w'){
                --q;
                Dungeon[p][q+1] = '.';
                Error = false;
                system("CLS");
            }

            if(Dungeon[p][q+1] != '.' and Dungeon[p][q+1] != '#' and Move == 's'){
                Error = true;
                system("CLS");
            }else if(Dungeon[p][q+1] = '.' and Move == 's'){
                ++q;
                Dungeon[p][q-1] = '.';
                Error = false;
                system("CLS");
            }

            if(Dungeon[p-1][q] != '.' and Dungeon[p-1][q] != '#' and Move == 'a'){
                Error = true;
                system("CLS");
            }else if(Dungeon[p-1][q] = '.' and Move == 'a'){
                --p;
                Dungeon[p+1][q] = '.';
                Error = false;
                system("CLS");
            }

            if(Dungeon[p+1][q] != '.' and Dungeon[p+1][q] != '#' and Move == 'd'){
                Error = true;
                system("CLS");
            }else if(Dungeon[p+1][q] = '.' and Move == 'd'){
                ++p;
                Dungeon[p-1][q] = '.';
                Error = false;
                system("CLS");
            }
        }else{
            Character = Exit;
            cout << "Good job! You've reached the exit!" << endl;
        }
    }
    return 0;
}
