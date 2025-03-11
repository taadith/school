#include <iostream>

using namespace std;

int main() {
    int p;
    cin >> p;

    int number;
    long long num,den;
    char slash;
    for(int i = 1; i <= p; i++) {
        cin >> number >> num >> slash >> den;
        if (den == 1) {
            den = num + 1;
            num = 1;
        }
        else {
            long long steps_left = num / den;
            // move up & left until you can't
            num = num % den;
            // move up & right once
            den = den - num;
            // move down & right once
            num = num + den;
            den = den + (num * steps_left);
        }
        
        cout << i << " " << num << slash << den << endl;
    }
}