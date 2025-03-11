#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#include <iostream>

int main() {
    int t,n,m;
    cin >> t;
    while(t--) {
        map<string,set<string>> ingredients_and_their_pizzas;
        set<string> set_unknown_ingredients;
        set<string> set_known_ingredients;

        cin >> n;
        while(n--) {
            string pizza_name;
            cin >> pizza_name;
            
            cin >> m;
            // vector<string> unknown_ingredients(m);
            string ui_name;
            for(int i = 0; i < m; i++) {
                cin >> ui_name;
                set_unknown_ingredients.insert(ui_name);

                if (ingredients_and_their_pizzas.count(ui_name) == 0) {
                    set<string> pizzas;
                    ingredients_and_their_pizzas.emplace(ui_name,pizzas);
                }
                
                ingredients_and_their_pizzas.at(ui_name).insert(pizza_name);
            }
                

            cin >> m;
            // vector<string> known_ingredients(m);
            string ki_name;
            for(int i = 0; i < m; i++) {
                cin >> ki_name;
                set_known_ingredients.insert(ki_name);

                if (ingredients_and_their_pizzas.count(ki_name) == 0) {
                    set<string> pizzas;
                    ingredients_and_their_pizzas.emplace(ki_name,pizzas);
                }
                
                ingredients_and_their_pizzas.at(ki_name).insert(pizza_name);
            } 
        }

        set<string>::iterator ui_ssit;
        set<string>::iterator ki_ssit;
        for(ui_ssit = set_unknown_ingredients.begin(); ui_ssit != set_unknown_ingredients.end(); ui_ssit++) {
            for(ki_ssit = set_known_ingredients.begin(); ki_ssit != set_known_ingredients.end(); ki_ssit++) {
                if (ingredients_and_their_pizzas.at(*ui_ssit) == ingredients_and_their_pizzas.at(*ki_ssit))
                    cout << "(" << *ui_ssit << ", " << *ki_ssit << ")" << endl;
            }
        }
        cout << endl;
    }

    return 0;
}