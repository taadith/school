#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string line;
    cin >> line;
    int len = line.length();
    float white = 0;
    float lower = 0;
    float upper = 0;
    float symbol = 0;
    char c;
    for(int i = 0; i < line.length(); i++) {
        c = line[i];
        if (c == '_')
            white += 1.0;
        else if (c >= 65 && c <= 90)
            upper += 1.0;
        else if (c >= 97 && c <= 122)
            lower += 1.0;
        else
            symbol += 1.0;
    }
    cout << setprecision(7) << white / len << endl;
    cout << setprecision(7) << lower / len << endl;
    cout << setprecision(7) << upper / len << endl;
    cout << setprecision(7) << symbol / len << endl; 

    return 0;
}