#include <iostream>
using namespace std;
int main(){

    // a*x + b*y = c
    long long a, b, c;
    cin >> a >> b >> c;
    long long a1 = 1, a2 = 0, b1 = 0, b2 = 1;
    if(a > b){
        swap(a, b);
        swap(a1, b1);
        swap(a2, b2);
    }
    while(b != 0){
        long long h = a % b, h1 = a1-(a/b)*b1, h2 = a2-(a/b)*b2;
        a = b; a1 = b1; a2 = b2;
        b = h; b1 = h1; b2 = h2;
    }
    if(c%a) cout << "No solution\n";
    else cout << c/a*a1 << " " << c/a*a2 << endl;
    return 0;
}
