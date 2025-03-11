#include <vector>
#include <iostream>
#include <map>

using namespace std;

// amoebas:
int number_of_amoebas = 0;

//union find implementation:
vector<int> parents;
vector<int> maxsize;

int find(int x) {
    if (parents[x] == x)
        return x;
    else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void merge(int x, int y) {
    int a,b;
    a = find(x);
    b = find(y);
    
    if (a == b)
        return;
    
    parents[b] = a;
    maxsize[a]++;
    number_of_amoebas--;

    // if (maxsize[a] == maxsize[b]) {
    //     parents[b] = a;
    //     maxsize[a]++;
    // }
    // else if (maxsize[a] > maxsize[b]) {
    //     parents[b] = a;
    // }
    // else if (maxsize[a] < maxsize[b]) {
    //     parents[a] = b;
    // }
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    // int number_of_amoebas = 0;

    // vector<int> amoebas;
    map<int,int> amoebas;
    char c;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == '#') {
                amoebas.emplace(((i * m) + j),number_of_amoebas);
                number_of_amoebas++;
            }   
        } 
    }

    parents.resize(number_of_amoebas);
    maxsize.resize(number_of_amoebas);

    for(int i = 0; i < number_of_amoebas; i++) {
        parents[i] = i;
        maxsize[i] = 1;
    }

    map<int,int>::iterator mii_iterator;
    for(mii_iterator = amoebas.begin(); mii_iterator != amoebas.end(); mii_iterator++) {
        int cell = (mii_iterator -> first);
        // cout << "At cell: " << cell << ", grid";
        int i = cell / m;
        // cout << "[" << i << "]";
        int j = cell % m;
        // cout << "[" << j << "]" << endl;

        // look to the left
        // cout << "\tlooking to the left..." << endl;
        if (j != 0 && amoebas.count(cell - 1) > 0) {
            merge(amoebas.at(cell - 1), amoebas.at(cell));
            // cout << "\t...merging w/ cell: " << cell - 1 << ", grid[" << i << "][" << j - 1 << "]" << endl;
        }
        
        // look to the right
        // cout << "\tlooking to the right..." << endl;
        if (j != m - 1 && amoebas.count(cell + 1) > 0) {
            merge(amoebas.at(cell + 1), amoebas.at(cell));
            // cout << "\t...merging w/ cell: " << cell + 1 << ", grid[" << i << "][" << j + 1 << "]" << endl;
        }
            
        // look up
        // cout << "\tlooking up..." << endl;
        if (i != 0 && amoebas.count(cell - m) > 0) {
            merge(amoebas.at(cell - m), amoebas.at(cell));
            // cout << "\t...merging w/ cell: " << cell - m << ", grid[" << i - 1 << "][" << j << "]" << endl;
        }

        // look down
        // cout << "\tlooking down..." << endl;
        if (i != n - 1 && amoebas.count(cell + m) > 0) {
            merge(amoebas.at(cell + m), amoebas.at(cell));
            // cout << "\t...merging w/ cell: " << cell + m << ", grid[" << i + 1 << "][" << j << "]" << endl;
        }
            
        // look up & left
        // cout << "\tlooking up & left..." << endl;
        if (i != 0 && j != 0 && amoebas.count(cell - (m + 1)) > 0) {
            merge(amoebas.at(cell - (m + 1)), amoebas.at(cell));
            // cout << "\t...merging w/ cell: " << cell - (m + 1) << ", grid[" << i - 1 << "][" << j - 1 << "]" << endl;
        }

        // look up & right
        // cout << "\tlooking up & right..." << endl;
        if (i != 0 && j != m - 1 && amoebas.count(cell - m + 1) > 0) {
            merge(amoebas.at(cell - m + 1), amoebas.at(cell));
            // cout << "\t...merging w/ cell: " << cell - m + 1 << ", grid[" << i - 1 << "][" << j + 1 << "]" << endl;
        }

        // look down & left
        // cout << "\tlooking down & left..." << endl;
        if (i != n - 1 && j != 0 && amoebas.count(cell + m - 1)) {
            merge(amoebas.at(cell + m - 1), amoebas.at(cell));
            // cout << "\t...merging w/ cell: " << cell + m - 1 << ", grid[" << i + 1 << "][" << j - 1 << "]" << endl;
        }

        // look down & right
        // cout << "\tlooking down & right..." << endl;
        if (i != n - 1 && j != m - 1 && amoebas.count(cell + (m + 1)) > 0) {
            merge(amoebas.at(cell + (m + 1)), amoebas.at(cell));
            // cout << "\t...merging w/ cell: " << cell + (m + 1) << ", grid[" << i + 1 << "][" << j + 1 << "]" << endl;
        }
    }

    // for(unsigned int i = 0; i < parents.size(); i++) {
    //     cout << parents[i] << endl;
    // }
    cout << number_of_amoebas << endl;

    return 0;
}