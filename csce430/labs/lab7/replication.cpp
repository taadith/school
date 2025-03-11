#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>

using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;

    int min_size = min(s1.size(), s2.size());

    int diff = 0;
    for(int i = 0; i < min_size; i++) {
        if (s1[i] != s2[i])
            diff++;
    }

    if (s1.size() - s2.size() < 0)
        diff -= (s1.size() - s2.size());
    else
        diff += s1.size() - s2.size();

    cout << diff << endl;

    return 0;
}