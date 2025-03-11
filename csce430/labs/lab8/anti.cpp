#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str_n;
    cin >> str_n;
    
    while (str_n != "0") {
        str_n = str_n.substr(0, str_n.size() - 1);
        // cout << "str_n after formatting: " << str_n << endl;
        int n = stoi(str_n);

        vector<int> numbers(n);
        for(int i = 0; i < n; i++)
            cin >> numbers[i];
        
        vector<int> numbers_seen;
        vector<bool> numbers_found(n, false);

        int a;
        bool antiarith = true;
        for(int i = 0; i < n; i++) {
            a = numbers[i];
            for(unsigned int i = 0; i < numbers_seen.size(); i++) {
                if ((2 * a) - numbers_seen[i] < 0 || (2 * a) - numbers_seen[i] >= n) {
                    continue;
                }
                else if (!numbers_found[(2 * a) - numbers_seen[i]]) {
                    antiarith = false;
                    break;
                }
            }
            if (!antiarith)
                break;
            numbers_seen.push_back(a);
            numbers_found[a] = true;
        }

        if(antiarith)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

        cin >> str_n;
        // str_n = str_n.substr(0, str_n.size() - 1);
        // cout << "str_n after formatting: " << str_n << endl;
    }

    return 0;
}