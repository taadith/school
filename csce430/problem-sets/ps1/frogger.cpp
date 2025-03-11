#include <iostream>
#include <vector>

using namespace std;

int main() {
    // board: n squares labeled 1-n
    // player rolls n sided die and places frog at that index
    // randomly select magic goal # on one of the cards
    // follow what each square does until you 
    //      (1) fall off <= 0 || >= n + 1
    //      (2) hops on square we've already seen, cycle!
    //      (3) hops on square containing magic #
    // determine fate && number of hops
    int n,s,m;
    int hops = 0;
    cin >> n >> s >> m;

    int in;
    vector<int> squares;
    vector<bool> hoppedHere (n+1,false);
    squares.push_back(0);
    for(int i = 0; i < n; i++) {
        cin >> in;
        squares.push_back(in);
    }

    while (true) {
        if (s < 1) {
            cout << "left\n";
            cout << hops << "\n";
            break;
        }
        if (s > n) {
            cout << "right\n";
            cout << hops << "\n";
            break;
        }
        if (squares.at(s) == m) {
            cout << "magic" << endl;
            cout << hops << endl;
            break;
        }
        if (hoppedHere.at(s) == true) {
            cout << "cycle" << endl;
            cout << hops << endl;
            break;
        }
        
        hoppedHere.at(s) = true;
        s += squares.at(s);
        hops++;
    }

    return 0;
}