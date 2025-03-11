#include <iostream>
#include <deque>

using namespace std;

int main() {
    unsigned long n,x,a;
    
    deque<unsigned long> front_half;
    // long long front_size = 0;
    deque<unsigned long> back_half;
    // long long back_size = 0;

    cin >> n;

    string op;
    for(unsigned long i = 0; i < n; i++) {
        cin >> op >> x;
        if (op == "push_front") {
            // cout << "pushing " << x;
            
            front_half.push_front(x);
            // front_size++;
            
            // cout  << " to front" << endl;
        }
        else if (op == "push_middle") {
            // cout << "pushing " << x;
            
            back_half.push_front(x);
            // front_size++;
            
            // cout << " to middle" << endl;
        }
        else if (op == "push_back") {
            // cout << "pushing " << x;
            
            back_half.push_back(x);
            // back_size++;
            
            // cout << " to back" << endl;
        }
        else if (op == "get") {
            if (x <= front_half.size() - 1)
                cout << front_half[x] << endl;
            else
                cout << back_half[x - front_half.size()] << endl;
            continue;
        }

        

        // cout << "front_half.size(): " << front_half.size() << ", back_half.size(): " << back_half.size() << endl;
        // rebalancing
        if ((long long)front_half.size() - 1 > (long long)back_half.size()) {
            // cout << "removing ";
            
            a = front_half.back();
            
            // cout << a << " ";
            
            front_half.pop_back();
            // front_size--;
            
            // cout << " from back of front half ";
            
            back_half.push_front(a);
            // back_size++;
            
            // cout << " and moving to front of back half" << endl;
        }
        else if ((long long)front_half.size() - 1 == (long long)back_half.size())
            continue;
        else if (front_half.size() == back_half.size())
            continue;
        else if (front_half.size() < back_half.size()) {
            // cout << "removing ";
            
            a = back_half.front();
            
            // cout << a << " ";
            
            back_half.pop_front();
            // back_size
            
            // cout << " from front of back half ";
            
            front_half.push_back(a);
            
            // cout << " and moving to back of front half" << endl;
        }
    }

    return 0;
}