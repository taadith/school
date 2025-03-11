#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    string str_n;
    getline(cin, str_n);
    n = stoi(str_n);

    string line;
    for(int i = 0; i < n; i++) {
        getline(cin, line);
        cout << line << endl;
    }

    return 0;
}