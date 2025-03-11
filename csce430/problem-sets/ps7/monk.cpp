#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {

    int a,d;
    float dist,time, distPerSecond;
    float runningHeight = 0;
    cin >> a >> d;
    
    float totalDistance = 0;
    float totalTime = 0;
    vector<pair<float,float>> ascend;
    ascend.push_back({0,0});
    for(int i = 0; i < a; i++) {
        cin >> dist >> time;
        totalDistance += dist;
        totalTime += time;
        ascend.push_back({dist,time});
    }
    
    vector<pair<float,float>> descend;
    descend.push_back({0,0});
    //runningTime = 0;
    // descend.push_back({0,runningHeight});
    for(int i = 0; i < d; i++) {
        cin >> dist >> time;
        descend.push_back({dist,time});
    }

    // // Debug Print Statements
    // cout << "ascend:" << endl;
    // for(int i = 0; i < ascend.size(); i++)
    //     cout << setprecision(6) << ascend[i].first << " " << ascend[i].second << endl;
    
    // cout << endl << "descend:" << endl;
    // for(int i = 0; i < descend.size(); i++)
    //     cout << setprecision(6) << descend[i].first << " " << descend[i].second << endl;
    // cout << endl;

    float min = 0;
    float max = totalTime;
    float mid = 0;
    while (/*max - min > 10e-6*/ abs(mid - ((max + min)/2.0)) > 10e-7) {
        mid = (min + max) / 2.0;
        
        float ascendTime = 0;
        float ascendDist = 0;
        for (int i = 0; i < ascend.size(); i++) {
            if (ascendTime < mid && (ascend[i].second + ascendTime) < mid) {
                ascendDist += ascend[i].first;
                ascendTime += ascend[i].second;
            }
            else {
                ascendDist += (ascend[i].first / ascend[i].second * (mid - ascendTime));
                break;
            }
        }

        float descendTime = 0;
        float descendDist = 0;
        for(int i = 0; i < descend.size(); i++) {
            if (descendTime < mid && (descend[i].second + descendTime) < mid) {
                descendDist += descend[i].first;
                descendTime += descend[i].second;
            }
            else {
                descendDist += (descend[i].first / descend[i].second * (mid - descendTime));
                break;
            }
        }
        descendDist = totalDistance - descendDist;

        if (ascendDist >= descendDist)
            max = mid;
        else if (ascendDist < descendDist)
            min = mid;
    }

    // Precision standard
    cout << setprecision(7);
    cout << mid << endl;
    
    return 0;
}