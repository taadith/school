#include <vector>
#include <iostream>

using namespace std;

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
    if (maxsize[a] == maxsize[b]) {
        parents[b] = a;
        maxsize[a]++;
    }
    else if (maxsize[a] > maxsize[b]) {
        parents[b] = a;
    }
    else if (maxsize[a] < maxsize[b]) {
        parents[a] = b;
    }
}

int main() {
    

    return 0;
}