#include <iostream>

using namespace std;

int main() {
    int n;
    int drop = 0;
    int take = 0;
    string command;
    int plates;
    cin >> n;
    while (n != 0) {
        for(int i = 0; i < n; i++) {
            cin >> command >> plates;
            if (command == "DROP") {
                drop += plates;
                cout << "DROP 2 " << plates << endl;
            }
            if (command == "TAKE") {
                if (take == 0) {
                    cout << "MOVE 2->1 " << drop << endl;
                    take += drop;
                    drop = 0;
                }
                else if (plates > take) {
                    cout << "TAKE 1 " << take << endl;
                    plates -= take;
                    cout << "MOVE 2->1 " << drop << endl;
                    take = drop;
                    drop = 0;
                }
                take -= plates;
                cout << "TAKE 1 " << plates << endl;
            }
        }
        cout << endl;
        cin >> n;
        drop = 0;
        take = 0;
    }
    return 0;
}