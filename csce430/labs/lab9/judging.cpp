#include <unordered_map>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, int> first;
    for(int i = 0; i < n; i++) {
        string result;
        cin >> result;
        
        if (first.count(result) == 0)
            first.emplace(result, 1);
        else
            first[result]++;
    }

    unordered_map<string, int> second;
    for(int i = 0; i < n; i++) {
        string result;
        cin >> result;
        
        if (second.count(result) == 0)
            second.emplace(result, 1);
        else
            second[result]++;
    }

    long long max_correct = 0;
    unordered_map<string, int>::iterator umit;
    for(umit = first.begin(); umit != first.end(); umit++) {
        // cout << (umit -> first) << ": " << (umit -> second) << endl;

        if (second.count(umit -> first) > 0) {
            max_correct += min(umit -> second, second[umit -> first]);
        }
    }
        
    
    cout << max_correct << endl;

    return 0;
}