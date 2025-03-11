#include <iostream>
#include <queue>

using namespace std;

int main() {
    int c,l,m,l_to_cm;
    cin >> c;
    while(c--) {

        queue<int> left;
        queue<int> right;
        cin >> l >> m;
        l_to_cm = l * 100;
        while(m--) {
            string dir;
            int length;
            cin >> length >> dir;
            if (dir == "left")
                left.push(length);
            else
                right.push(length);
        }
        
        bool on_left = true;
        bool on_right = false;
        bool need_to_move = false;
        int moves = 0;
        while(left.size() != 0 || right.size() != 0) {
            if(on_right) {
                moves++;
                on_left = true;
                on_right = false;
            }
            int on_ferry = 0;
            while(left.size() != 0) {
                need_to_move = true;
                if (left.front() + on_ferry <= l_to_cm) {
                    on_ferry += left.front();
                    left.pop();
                }
                else
                    break;
            }
            if(need_to_move) {
                moves++;
                on_left = false;
                on_right = true;
            }
            need_to_move = false;

            if(on_left) {
                moves++;
                on_left = false;
                on_right = true;
            }
            on_ferry = 0;
            while(right.size() != 0) {
                need_to_move = true;
                if(right.front() + on_ferry <= l_to_cm) {
                    on_ferry += right.front();
                    right.pop();
                }
                else
                    break;
            }
            if(need_to_move) {
                moves++;
                on_left = true;
                on_right = false;
            }
            need_to_move = false;
            
        }
        cout << moves << endl;

    }



    return 0;
}