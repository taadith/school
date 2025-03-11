#include <unordered_map>
#include <vector>
#include <string>

#include <iostream>

using namespace std;

int main() {
    int n,l,q;
    cin >> n >> l >> q;

    unordered_map<string, string> english_to_spanish;
    unordered_map<string, string> spanish_to_english;

    string english_word, spanish_word;
    for(int i = 0; i < n; i++) {
        cin >> english_word >> spanish_word >> spanish_word;

        english_to_spanish.emplace(english_word, spanish_word);
        spanish_to_english.emplace(spanish_word, english_word);
    }

    vector<string> spanish_convo(l);
    for(int i = 0; i < l; i++) {
        cin >> spanish_convo[i];
    }
    
    for(int query = 0; query < q; query++) {
        vector<string> english_convo(l);
        for(int i = 0; i < l; i++)
            cin >> english_convo[i];
        
        bool yes = true;
        for(int i = 0; i < l; i++) {
            // known spanish word w/ english to spanish translation
            if (spanish_convo[i] != "???" && english_to_spanish.count(english_convo[i]) > 0) {
                // spoken spanish matches transated english word
                if (spanish_convo[i] == english_to_spanish[english_convo[i]])
                    continue;
                else {
                    yes = false;
                    break;
                }
            }
            // known spanish word w/ no english to spanish translation
            else if (spanish_convo[i] != "???" && english_to_spanish.count(english_convo[i]) == 0) {
                yes = false;
                break;
            }
            // unknown spanish word w/ english to spanish translation
            else if (spanish_convo[i] == "???" && english_to_spanish.count(english_convo[i]) > 0) {
                yes = false;
                break;
            }
            // unknown spanish word w/ no english to spanish translation
            else if (spanish_convo[i] == "???" && english_to_spanish.count(english_convo[i]) == 0) {
                continue;
            }
        }

        if (yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
        

    return 0;
}