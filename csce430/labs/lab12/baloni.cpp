#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

// clever use of 1D histogram array to decompose the shots as per requirement

int main() {
    int n;
    cin >> n;

    // vector<int> heights(n);
    int arrows = 0;
    unordered_multiset<int> umulti;
    unordered_map<int, int> umap;
    for(int i = 0; i < n; i++) {
        int height;
        cin >> height;
        
        if (umap.count(height + 1) == 0 || (umap.count(height + 1) > 0 && umap[height + 1] == 0)) {
            umap[height] = 1;
            arrows++;
        }
        else if (umap[height])
        }
    }

    cout << arrows << endl;

    return 0;
}