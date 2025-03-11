#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n,x,ops = 0;
    cin >> n;
    
    vector<int> v;
    stack<int> original;
    stack<int> aux;
    for(int i = 0; i < (2 * n); i++) {
        cin >> x;
        v.push_back(x);
    }
    for(int i = (2 * n) - 1; i > -1; i--) {
        // cout << v[i] << " ";
        original.push(v[i]);
    }
    while(true) {
        if (original.size() == 0 && aux.size() > 0) {
            cout << "impossible" << endl;
            break;
        }
        else if (original.size() == 0 && aux.size() == 0) {
            cout << ops << endl;
            break;
        }
        else if (aux.size() == 0) {
            aux.push(original.top());
            original.pop();
            ops++;
        }
        else if (aux.top() == original.top()) {
            original.pop();
            aux.pop();
            ops++;
        }
        else if (aux.top() != original.top()) {
            aux.push(original.top());
            original.pop();
            ops++;
        }
    }

    return 0;
}