#include <string>
#include <iostream>
#include <cmath>

using namespace std;

char hex_code[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char dec_code[] = {'0','1','2','3','4','5','6','7','8','9'};
int main() {
    string o;
    cin >> o;

    string dec = "";
    
    for(unsigned long long i = 0; i < o.length(); i++) {
        dec += (o[i] - '0') * pow(8, o.length() - 1 - i);
    }

    string hex;
    while (dec != 0) {
        hex = hex_code[dec % 16]+ hex;
        dec /= 16;
    }

    cout << hex << endl;
}