#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> k(n);
    vector<long long> profNums(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
        profNums[i] = i + 1;
    }

    long long currentOpus = k[0];
    long long currentIndex = 0;
    int removeIndex;

    // for(int i = 0; i < n; i++)
    //     cout << k[i] << " ";
    // cout << "\n";

    while(n > 1) {
        //set removeIndex
        removeIndex = ((currentOpus + currentIndex) % n) - 1;

        //
        if (removeIndex == -1) {
            removeIndex = n - 1;
            currentIndex = 0;
        }
        else {
            currentIndex = removeIndex;
        }
        
        //remove the prof
        k.erase(k.begin() + removeIndex);
        profNums.erase(profNums.begin() + removeIndex);
        currentOpus = k[currentIndex];
        n--;

        // for(int i = 0; i < n; i++)
        //     cout << k[i] << " ";
        // cout << "\n";
    }

    cout << profNums[0] << endl;
    return 0;
}