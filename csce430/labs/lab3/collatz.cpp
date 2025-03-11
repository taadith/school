#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    long long a,ax,b,bx;
    cin >> a >> b;
    while(!(a == 0 && b == 0)) {
        unordered_map<long long,long long> aum;
        
        ax = a;
        int steps = 0;
        aum.emplace(ax,steps);
        while (ax != 1) {
            if (ax % 2 == 0) {
                ax /= 2;
            }
            else {
                ax *= 3;
                ax += 1;
            }
            steps++;
            aum.emplace(ax,steps);
        }
        
        steps = 0;
        bx = b;
        while(true) {
            if (aum.count(bx) > 0) {
                cout << a << " needs " << aum.at(bx) << " steps, " << b << " needs " << steps << " steps, they meet at " << bx << endl;
                break;
            }
            if (bx % 2 == 0) {
                bx /= 2;
            }
            else {
                bx *= 3;
                bx += 1;
            }
            steps++;
        }
        cin >> a >> b;
    }

    return 0;
}