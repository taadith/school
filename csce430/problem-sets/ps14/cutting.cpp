#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

// pt/vector representation
struct line {
    int x,y;
};

double angle(double x1, double y1, double x2, double y2) {
    return acos((x1 * x2 + y1 * y2) / (hypot(x1, y1) * hypot(x2, y2)));
}

double angle_of_points(line a, line b, line c) {
    int ax = a.x;
    int ay = a.y;

    int bx = b.x;
    int by = b.y;

    int cx = c.x;
    int cy = c.y;
    
    ax -= bx;
    cx -= bx;
    ay -= by;
    cy -= by;
    
    return angle(ax, ay, cx, cy);
}

int main() {
    int n;
    while (cin >> n && n!= 0) {
        vector<line> points(n);
        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        vector<double> angles;
        angles.push_back(angle_of_points(points[points.size() - 1], points[0], points[1]));
        for (unsigned int i = 1; i < points.size(); i++)
            angles.push_back(angle_of_points(points[i - 1], points[i], points[(i + 1) % points.size()]));

        double curr_min = 0;
        line last_removed = {0, 0};
        int last_min_index = 0;

        while (true) {
            double min = 360;
            int min_index = 0;

            for (unsigned int i = 0; i < angles.size(); i++) {
                if (angles[i] < min) {
                    min = angles[i];
                    min_index = i;
                }
            }

            if (min < curr_min) {
                points.insert(points.begin() + last_min_index, last_removed);
                break;
            }

            if (angles.size() == 3)
                break;

            last_removed = points[min_index];
            points.erase(points.begin() + min_index);
            curr_min = min;
            last_min_index = min_index;
            
            angles.clear();
            angles.push_back(angle_of_points(points[points.size() - 1], points[0], points[1]));
            for (unsigned int i = 1; i < points.size(); i++)
                angles.push_back(angle_of_points(points[i - 1], points[i], points[(i + 1) % points.size()]));
        }

        cout << points.size() << " ";
        for (unsigned int i = 0; i < points.size(); i++)
            cout << points[i].x << " " << points[i].y << " ";
        cout << endl;
    }

    return 0;
}
