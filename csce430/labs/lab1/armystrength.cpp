#include <iostream>

using namespace std;

int main() {
    int t,g,gval,m,mval;
    int maxG,maxM;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> g >> m;

        cin >> maxG;
        for(int j = 1; j < g; j++) {
            cin >> gval;
            if (gval > maxG)
                maxG = gval;
        }

        cin >> maxM;
        for(int j = 1; j < m; j++) {
            cin >> mval;
            if (mval > maxM)
                maxM = mval;
        }
        if (maxG >= maxM)
            cout << "Godzilla" << endl;
        else
            cout << "MechaGodzilla" << endl;
    }

    return 0;
}