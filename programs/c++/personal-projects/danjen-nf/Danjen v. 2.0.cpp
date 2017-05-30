#include<iostream>
#include<windows.h>

using namespace std;

int main (){

    char Dungeon1[10][10];
    long long x = 0, y = 0, Hp = 1, Energy = 100, Special = 1, p = 2, q = 7;
    char Rogue = '*', Mage = '*', Knight = '*', Archer = '*', Move;
    char Warrior = 'W', ArchWarrior = 'A', MageWarrior = 'M', Bomber = 'B', Choosechar = 'r', Character = Rogue, Exit = '#';
    string CharName = "Rogue";
    bool Error = false;

    cout << "Hello and welcome to Danjen - an RPG chess-like homemade game!"<< endl << endl ;
    system("PAUSE");
    system("CLS");

    cout << "Now you should choose a character to begin to play : " << endl << endl << "1. Rogue(r) " << endl << "2. Mage(m) " << endl << "3. Knight(k) " << endl << "4. Archer(a) " << endl << endl;
    cin >> Choosechar;
    system("CLS");

    if(Choosechar == 'r'){
        Character = Rogue;
        CharName = "Rogue";
        Energy = 100;
        Special = 1;
        Hp = 1;
    }

    if(Choosechar == 'k'){
        Character = Knight;
        CharName = "Knight";
        Energy = 50;
        Special = 1;
        Hp = 3;
    }

    if(Choosechar == 'm'){
        Character = Mage;
        CharName = "Mage";
        Energy = 0;
        Special = 2;
        Hp = 2;
    }

    if(Choosechar == 'a'){
        Character = Archer;
        CharName = "Archer";
        Energy = 25;
        Hp = 2;
    }

    cout << "Very well... You've chosen " << CharName << endl <<"We wish you an epic adventure!"<< endl << endl;
    system("PAUSE");
    system("CLS");

    while(Character != Exit){
        for(y = 0;y < 8;++y){
            for(x = 0;x < 7;++x){
                Dungeon1[x][y] = '.';
                Dungeon1[p][q] = Choosechar;
                Dungeon1[5][6] = Warrior;
                Dungeon1[1][3] = ArchWarrior;
                Dungeon1[6][4] = Bomber;
                Dungeon1[1][1] = Exit;
                Dungeon1[1][5] = '~';
                Dungeon1[2][5] = '~';
                Dungeon1[1][6] = '~';
                Dungeon1[2][6] = '~';
                Dungeon1[4][1] = '~';
                Dungeon1[4][2] = '~';
                Dungeon1[5][1] = '~';
                Dungeon1[5][2] = '~';
                cout << Dungeon1[x][y] << " ";
            }
            cout << endl << endl;
        }

        if(Dungeon1[p][q] != '#'){
            if(Error == true){
                cout << "Invalid move!" << endl << endl;
            }else{
                cout << endl << endl;
            }

            cout << "Health = " << Hp << endl << "Energy = " << Energy << endl << "Special = " << Special << endl << endl << "Your move : " << endl << p << " " << q << "  ";
            cin >> Move;


            if(Dungeon1[p][q-1] != '.' and Dungeon1[p][q-1] != '#' and Move == 'w'){
                Error = true;
                system("CLS");
            }else if(Dungeon1[p][q-1] = '.' and Move == 'w'){
                --q;
                Dungeon1[p][q+1] = '.';
                Error = false;
                system("CLS");
            }

            if(Dungeon1[p][q+1] != '.' and Dungeon1[p][q+1] != '#' and Move == 's'){
                Error = true;
                system("CLS");
            }else if(Dungeon1[p][q+1] = '.' and Move == 's'){
                ++q;
                Dungeon1[p][q-1] = '.';
                Error = false;
                system("CLS");
            }

            if(Dungeon1[p-1][q] != '.' and Dungeon1[p-1][q] != '#' and Move == 'a'){
                Error = true;
                system("CLS");
            }else if(Dungeon1[p-1][q] = '.' and Move == 'a'){
                --p;
                Dungeon1[p+1][q] = '.';
                Error = false;
                system("CLS");
            }

            if(Dungeon1[p+1][q] != '.' and Dungeon1[p+1][q] != '#' and Move == 'd'){
                Error = true;
                system("CLS");
            }else if(Dungeon1[p+1][q] = '.' and Move == 'd'){
                ++p;
                Dungeon1[p-1][q] = '.';
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
