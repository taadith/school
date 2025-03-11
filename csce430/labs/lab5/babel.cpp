#include <iostream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string,string> m;
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
        {
            break;
        }
        else
        {
            istringstream tmp(line);
            string x,y;
            tmp >> x >> y;
            m.emplace(y,x);
        }
    }

    while (cin >> line) {
        if (m.count(line) > 0)
            cout << m.at(line) << endl;
        else
            cout << "eh" << endl;
    }
    
    return 0;
}