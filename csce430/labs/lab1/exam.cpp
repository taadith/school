#include <iostream>

using namespace std;

int main() {
    int n;
    string previous,current;
    cin >> n;
    cin >> current;
    int score = 0;
    for(int i = 1; i < n; i++) {
        previous = current;
        cin >> current;
        if (previous == current)
            score++;
    }
    cout << score << endl;
}