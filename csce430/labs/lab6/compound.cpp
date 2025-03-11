#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main() {

    set<string> ss;
    vector<string> vs;

    string s;
    while(cin >> s)
        vs.push_back(s);
    
    // for(int i = 0; i < vs.size(); i++)
    //     cout << vs[i] << endl;
    
    for(unsigned int i = 0; i < vs.size(); i++) {
        for(unsigned int j = 0; j < vs.size(); j++) {
            if (i == j)
                continue;
            string compound = vs[i] + vs[j];
            ss.insert(compound);
        }
    }

    set<string>::iterator ssit;
    for(ssit = ss.begin(); ssit != ss.end(); ssit++) {
        cout << *ssit << endl;
    }


    return 0;
}