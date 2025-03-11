#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

struct node {
    int next_letter[ALPHABET_SIZE];
    // bool output = false;
    int occurences = 0;

    node() {
        for(int i = 0; i < ALPHABET_SIZE; i++)
            next_letter[i] = -1;
    }
};

void add_string(vector<node> &trie, string const &s) {
    int v = 0;

    for(unsigned int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (trie[v].next_letter[c] == -1) {
            trie[v].next_letter[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next_letter[c];

        if (i == s.size() - 1) {
            cout << trie[v].occurences << endl;
        }
        trie[v].occurences++;
            
    }
    // trie[v].output = true;
}

int main() {
    vector<node> trie(1);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string search;
        cin >> search;
        add_string(trie, search);
    }

    return 0;
}