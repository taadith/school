#include<iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> sc;
    char x;
    bool first_letter = true;
    while(cin >> x) {
        if (x == '{') {
            if (first_letter && sc.size() > 0)
                cout << endl;
            for(unsigned long i = 0; i < sc.size(); i++)
                cout << "  ";
            cout << x;
            sc.push(x);
        }
        else if (x == '}') {
            cout << endl;
            sc.pop();
            for(unsigned long i = 0; i < sc.size(); i++)
                cout << "  ";
            cout << "}";
        }
            
        else if (x == ',') {
            cout << ",";
            first_letter = true;
        }
            
        else {
            if (first_letter) {
                cout << endl;
                for(unsigned long i = 0; i < sc.size(); i++)
                    cout << "  ";
                first_letter = false;
            }
            cout << x;
        }
    }
    cout << endl;
    
}