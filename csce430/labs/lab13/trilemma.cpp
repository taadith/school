#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

double dist_between_points(pair<double, double> &p1, pair<double, double> &p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    int n;
    cin >> n;
    for(int j = 1; j < n + 1; j++) {
        cout << "Case #" << j << ": ";
        
        vector<pair<double, double>> pts(3);
        for(int i = 0; i < 3; i++)
            cin >> pts[i].first >> pts[i].second;
        
        // use shoelace formula to determine if it is a valid triangle
        double area = pts[0].first * (pts[1].second - pts[2].second)
            + pts[1].first * (pts[2].second - pts[0].second)
            + pts[2].first * (pts[0].second - pts[1].second);
        
        if (area == 0) {
            cout << "not a triangle" << endl;
            continue;
        }

        vector<double> side_lengths;
        for(int i = 0; i < 3; i++)
            side_lengths.push_back(dist_between_points(pts[i], pts[(i + 1) % 3]));
        
        sort(side_lengths.begin(), side_lengths.end());
        
        if(side_lengths[0] != side_lengths[1] && side_lengths[0] != side_lengths[2] && side_lengths[1] != side_lengths[2])
            cout << "scalene ";
        else
            cout << "isosceles ";
        
        double pythag_left_side = (side_lengths[0] * side_lengths[0]) + (side_lengths[1] * side_lengths[1]);
        cout << endl <<"left side: " << pythag_left_side << endl;
        double pythag_right_side = side_lengths[2] * side_lengths[2];
        cout << "right side: " << pythag_right_side << endl;
        if (pythag_left_side == pythag_right_side)
            cout << "right ";
        else if (pythag_left_side < pythag_right_side)
            cout << "acute ";
        else
            cout << "obtuse ";

        cout << "triangle" << endl;
    }

    return 0;
}