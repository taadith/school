#include <iostream>

using namespace std;

int main() {
    int n,b,h,w,p,wx;
    cin >> n >> b >> h >> w;
    int minBudget = b + 1000;
    for(int i = 0; i < h; i++) {
        cin >> p;
        if (p * n > b) {
            for (int j = 0; j < w; j++)
                cin >> wx;
            continue;
        }
        else if (p * n <= b) {
            for (int j = 0; j < w; j++) {
                cin >> wx;
                if (wx >= n && (p * n) < minBudget)
                    minBudget = p * n;
            }
        }
    }
    if (minBudget > b)
        cout << "stay home" << endl;
    else {
        cout << minBudget << endl;
    }

    return 0;
}