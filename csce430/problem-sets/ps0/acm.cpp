#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map <string,int> question_attempts;
    int time;
    string question;
    string solved;
    
    int problems_solved = 0;
    int total_time = 0;
    cin >> time;
    while (time != -1) {
        cin >> question >> solved;
        if (question_attempts.count(question) == 0) {
            if (solved == "right") {
                question_attempts.emplace(question,-1);
                total_time += time;
                problems_solved++;
            }
            else
                question_attempts.emplace(question,1);
        }
        else if (question_attempts.count(question) > 0) {
            if (solved == "right") {
                total_time += time + (question_attempts.at(question) * 20);
                problems_solved++;
            }
            else if (solved == "wrong")
                question_attempts.at(question)++;
        }
        
        cin >> time;
    }
    
    cout << problems_solved << " " << total_time << endl;
    
    return 0;
}