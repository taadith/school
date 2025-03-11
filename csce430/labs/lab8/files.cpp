#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int hash_message(const string &message) {
    unsigned long long h = 0;
    for(unsigned int i = 0; i < message.length(); i++)
        h ^= message[i];
    return h;
}

int main() {
    string str_n;
    int n;
    getline(cin,str_n);
    while(str_n != "0") {
        n = stoi(str_n);

        vector<string> files(n);
        unordered_set<string> unique_files;
        unordered_map<int,int> hash_occurences;
        for(int i = 0; i < n; i++) {
            getline(cin, files[i]);
            unique_files.emplace(files[i]);
        }

        vector<int> hashes;
        for(int i = 0; i < n; i++) {
            int h = hash_message(files[i]);
            // cout << "hash value at " << i << " is " << h << endl;
            hashes.push_back(h);
        }

        // hash collision - diff strings, same hash
        
        // sort(hashes.begin(), hashes.end());

        int pairs = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // cout << "comparing " << hashes[i] << " with " << hashes[j] << endl;
                if ((files[i] != files[j]) && hashes[i] == hashes[j])
                    pairs++;
            }      
        }

        cout << unique_files.size() << " " << pairs << endl;

        getline(cin, str_n);
    }

    return 0;
}