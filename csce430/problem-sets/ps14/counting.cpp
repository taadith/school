#include <vector>
#include <iostream>

using namespace std;

struct line_segment {
    double x1;
    double y1;
    double x2;
    double y2;
};

// is point a (ax, ay) on line segment (bx, by, cx, cy)
bool point_on_line_segment(double ax, double ay, double bx, double by, double cx, double cy) {
    return (min(ax, bx) <= cx) && (cx <= max(ax, bx)) && (min(ay, by) <= cy) && (cy <= max(ay, by));
}

int orientation(double ax, double ay, double bx, double by, double cx, double cy) {
    double val = (by - ay) * (cx - bx) - (bx - ax) * (cy - by);
    // colinear: line segments form a bigger line segment
    if (val == 0) 
        return 0;
    // clockwise
    else if (val > 0)
        return 1;
    // counter clockwise
    else
        return 2;
}

bool line_intersects(line_segment &l1, line_segment &l2) {
    int o1 = orientation(l1.x1, l1.y1, l1.x2, l1.y2, l2.x1, l2.y1);
    int o2 = orientation(l1.x1, l1.y1, l1.x2, l1.y2, l2.x2, l2.y2);
    int o3 = orientation(l2.x1, l2.y1, l2.x2, l2.y2, l1.x1, l1.y1);
    int o4 = orientation(l2.x1, l2.y1, l2.x2, l2.y2, l1.x2, l1.y2);

    // intersects
    if (o1 != o2 && o3 != o4)
        return true;

    // intersects
    if (o1 == 0 && point_on_line_segment(l1.x1, l1.y1, l1.x2, l1.y2, l2.x1, l2.y1)) 
        return true;
    else if (o2 == 0 && point_on_line_segment(l1.x1, l1.y1, l1.x2, l1.y2, l2.x2, l2.y2)) 
        return true;
    else if (o3 == 0 && point_on_line_segment(l2.x1, l2.y1, l2.x2, l2.y2, l1.x1, l1.y1)) 
        return true;
    else if (o4 == 0 && point_on_line_segment(l2.x1, l2.y1, l2.x2, l2.y2, l1.x2, l1.y2)) 
        return true;

    // doesn't intersect
    return false;
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<line_segment> lines(n);
        for(int i = 0; i < n; i++) {
            cin >> lines[i].x1 >> lines[i].y1;
            cin >> lines[i].x2 >> lines[i].y2;
        }
        
        int triangles = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if (line_intersects(lines[i], lines[j]) && line_intersects(lines[i], lines[k]) && line_intersects(lines[j], lines[k]))
                        triangles++;
                }
            }
        }

        cout << triangles << endl;
    }
    return 0;
}