#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main() {
    int N, max = -1;
 
    vector<int> colors(N);
 
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        cin >> colors[i];
        if (max < colors[i]) {
            max = colors[i];
        }
    }
 
    int num_ppl = 0;
 
    for (int i = 0; i < N; i++) {
        if (colors[i] < max - 1) {
            num_ppl += (max - 1 - colors[i]);
        }
    }
 
    cout << num_ppl << endl;
 
}