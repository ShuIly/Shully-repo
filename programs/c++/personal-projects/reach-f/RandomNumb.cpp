#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
int main(){

    long long x=0;
    while(x<100){
       srand (x);
       cout << rand()% 10 + 1 << " ";
       ++x;
    }





  return 0;
}
