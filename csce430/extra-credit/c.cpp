#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 65 is A
    vector<set<char>> ans(N),temp(N);
    set<char> allChars;
    for (int i = 0; i < N; i++) {
        ans[i] = {char(65 + i)};
        allChars.insert(char(65 + i));
        // cout << char(65 + i);
    }
    temp = ans;
    bool sameNum = true;

    int iter_set = 0;
    int iter_char = 2;
    int count = 1;
    int at = 0;
    
    vector<char> intersect = {};
    while (intersect.empty() && N > 3) {
        // cout << "iter_set: " << iter_set << endl;
        auto it = allChars.begin();
        advance(it,(iter_char*count+at)%N);
        ans[iter_set].insert(*it);

        if (iter_set == N-1) {
            std::set_intersection(ans[iter_set].begin(),ans[iter_set].end(),ans[0].begin(),ans[0].end(), back_inserter(intersect));
            iter_set = 0;
            sameNum = true;
            temp = ans;
            count++;
            // cout <<"t" << endl;
        } else {
            
            std::set_intersection(ans[iter_set].begin(),ans[iter_set].end(),ans[iter_set+1].begin(),ans[iter_set+1].end(), back_inserter(intersect));
            // cout << "ans[iter_set]\n";
            // for (auto it = ans[iter_set].begin(); it != ans[iter_set].end(); it++) {
            //     cout << *it << " ";
            // }
            // cout << endl;
            // cout << "ans[iter_set+1]\n";
            // for (auto it = ans[iter_set+1].begin(); it != ans[iter_set+1].end(); it++) {
            //     cout << *it << " ";
            // }
            // cout << endl;
            // cout << "intersect\n";
            // for (auto it = intersect.begin(); it != intersect.end(); it++) {
            //     cout << *it << " ";
            // }
            // cout << endl;
            iter_set++;
            sameNum = false;
            // cout << "f" << endl;
            at++;
        }
    }
    
    if (!sameNum) {
        cout << temp[0].size() << endl;
        for (int i = 0; i < N; i++) {
            for (auto it = temp[i].begin(); it != temp[i].end(); it++) {
                cout << *it;
            }
            cout << endl;
        }
    } else {
        cout << ans[0].size() << endl;
        for (int i = 0; i < N; i++) {
            for (auto it = ans[i].begin(); it != ans[i].end(); it++) {
                cout << *it;
            }
            cout << endl;
        }
    }
    

}