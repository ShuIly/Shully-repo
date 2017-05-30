#include <iostream>
#include <conio.h>
#include <windows.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;

class ChooseClass {
    private:
        int curr_class;
    public:
        void startingClass(){
            int chooser = 0, informator = 0;
            while(1){
                cout << "Choose a class: " << endl;

                if(informator == 0){
                    cout << "Thief " << "*";
                    cout << endl << "Warrior ";
                    cout << endl << "Beast Hunter ";
                    cout << endl << "Mage " << "\n\n";
                    cout << " + High Attack Damage \n + Swift \n + Stealthy \n - Low Health \n - Melee \n";
                }
                if(informator == 1){
                    cout << "Thief ";
                    cout << endl << "Warrior " << "*";
                    cout << endl << "Beast Hunter ";
                    cout << endl << "Mage " << "\n\n";
                    cout << " + High Health \n + Deals AOE Damage \n - Slow \n - Melee \n";
                }
                if(informator == 2){
                    cout << "Thief ";
                    cout << endl << "Warrior ";
                    cout << endl << "Beast Hunter " << "*";
                    cout << endl << "Mage " << "\n\n";
                    cout << " + High Awareness \n + Swift \n + Ranged \n -Low Health \n";
                }
                if(informator == 3){
                    cout << "Thief ";
                    cout << endl << "Warrior ";
                    cout << endl << "Beast Hunter ";
                    cout << endl << "Mage " << "*" << "\n\n";
                    cout << " + High Mana \n + Deals Magic Damage \n + Ranged \n -Low Health \n";
                }
                chooser = getch();
                if(chooser == KEY_UP or chooser == 119 or chooser == KEY_LEFT or chooser == 97){
                    if(informator > 0){
                        informator--;
                    }
                }
                else if(chooser == KEY_DOWN or chooser == 115 or chooser == KEY_RIGHT or chooser == 100){
                    if(informator < 3){
                        informator++;
                    }
                }else{
                    curr_class = informator;
                    break;
                }
                system("CLS");
            }
        }
        int returnClass(){
            return curr_class;
        }
};
