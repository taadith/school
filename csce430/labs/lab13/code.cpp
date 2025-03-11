#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int dirt = 0;
    int dirty_pushes = 0;
    int clean_up = 0;
    int prev_day_push = 0;
    int curr_day_push = 0;
    for(int i = 0; i < n; i++) {
        cin >> curr_day_push;
        // cout << "on day " << curr_day_push << endl;

        dirt += (curr_day_push - prev_day_push) * dirty_pushes;
        // cout << "current dirt: " << dirt << endl;

        if (dirt >= 20) {
            // cout << "bc dirt was 20 or more, we had to clean up";
            // cout << " " << dirty_pushes << " pushes" << endl;
            
            clean_up++;
            dirty_pushes = 0;
            dirt = 0;
        }

        dirty_pushes++;
        
        // cout << "dirty pushes left to clean: " << dirty_pushes << endl;
        // cout << endl;
        
        prev_day_push = curr_day_push;
    }

    clean_up++;
    // cout << "clean-ups: ";
    cout << clean_up << endl;

    return 0;
}