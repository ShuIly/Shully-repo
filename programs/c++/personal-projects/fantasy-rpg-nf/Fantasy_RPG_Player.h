#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
bool gameOver;
class PlayerStats{
    private:
        int health_points, mana_points, stamina, experience, coins;
    public:
        void showHP(){
            cout << health_points;
        }
        void showMP(){
            cout << mana_points;
        }
        void showST(){
            cout << stamina;
        }
        void showEXP(){
            cout << experience;
        }
        void showCO(){
            cout << coins;
        }
        void takeDamage(char enemyType){
            if(enemyType == 'E'){
                health_points -= 5;
            }
        }
        void gainHP(int value){
            health_points += value;
        }
        void gainMP(int value){
            mana_points += value;
        }
        void gainST(int value){
            stamina += value;
        }
        void gainEXP(int value){
            experience += value;
        }
        void gainCO(int value){
            coins += value;
        }
};
