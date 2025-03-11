#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x;
    char first;
    char second;
    bool first_used = true;
    int men = 0;
    int women = 0;

    cin >> x;
    while(cin.eof() != true) {
        if (first_used) {
            cin >> first;
            if (cin.eof())
                break;
        }
            
        if (first == 'M' && abs(men - women + 1) <= x) {
            // cout << "took a man on first" << endl;
            men++;
            first_used = true;
            continue;
        }
            
        else if (first == 'M' && abs(men - women + 1) > x) {
            cin >> second;
            if (cin.eof()) {
                // cout << "no second to read" << endl;
                break;
            }
            if (second == 'W') {
                // cout << "took a woman on second" << endl;
                women++;
                first_used = false;
                continue;
            }
            else {
                // cout << "no woman on second" << endl;
                break;
            }
                
        }
        if (first == 'W' && abs(men - (women + 1)) <= x) {
            // cout << "took a woman on first" << endl;
            women++;
            first_used = true;
            continue;
        }
        else if (first == 'W' && abs(men - (women + 1)) > x) {
            cin >> second;
            if (cin.eof()) {
                // cout << "no second to read" << endl;
                break;
            }
            if (second == 'M') {
                // cout << "took a man on second" << endl;
                men++;
                first_used = false;
                continue;
            }
            else {
                // cout << "no man on second" << endl;
                break;
            }
        }
    }
    cout << men + women << endl;
    return 0;
    
}