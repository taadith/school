#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    long long zeroes = 0;
    long long ones = 0;
    for(unsigned int i = s.size() - 1; i > -1; i++) {
        if (s[i] == '0')
            zeroes++;
        if (s[i] == '1' || s[i] == '?')
            ones++;
    }



    return 0;
}