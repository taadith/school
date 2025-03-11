#include <iostream>
#include <string>

using namespace std;

int main() {
    string start;
    string end;
    cin >> start >> end;

    string end_hr = end.substr(0,2);
    string start_hr = start.substr(0,2);

    string end_min = end.substr(3,2);
    string start_min = start.substr(3,2);

    string end_sec = end.substr(6,2);
    string start_sec = start.substr(6,2);

    int sec = stoi(end_sec) - stoi(start_sec);
    // cout << "diff of sec: " << sec << endl;
    int min = stoi(end_min) - stoi(start_min);
    // cout << "diff of min: " << min << endl;
    int hr = stoi(end_hr) - stoi(start_hr);
    // cout << "diff of hr: " << hr << endl;

    if (sec < 0) {
        sec += 60;
        min--;
    }
    if (min < 0) {
        min += 60;
        hr--;
    }
    if (hr < 0)
        hr += 24;
    
    // didn't include 00:00:00 for last case?
    if (hr == min && min == sec && sec == 0)
        hr = 24;

    if (hr < 10)
        cout << "0";
    cout << hr << ":";

    if (min < 10)
        cout << "0";
    cout << min << ":";

    if (sec < 10)
        cout << "0";
    cout << sec << "\n";
    
    return 0;
}