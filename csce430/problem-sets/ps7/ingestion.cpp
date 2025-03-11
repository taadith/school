#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// value not needed
// #define NEG_INFTY -1

int findMaxCaloriesConsumed(vector<vector<int>> &memo, vector<int> &courses, int calories,int course) {
    int numOfCourses = courses.size() - 1;
    int startingCalories = memo.size() - 1;
    //cout << "starting calories " << startingCalories << endl;
    if (course > numOfCourses)
        return 0;
    if (memo[calories][course] != -1)
        return memo[calories][course];
    memo[calories][course] = 
        min(courses[course],calories) +
        max(
            findMaxCaloriesConsumed(memo, courses, floor((calories * 2)/3),course + 1),
            max(
                findMaxCaloriesConsumed(memo, courses, calories,course + 2),
                findMaxCaloriesConsumed(memo, courses, startingCalories,course + 3)
            )
        );
    // cout << "current calories consumed at calories " << calories << " and course " << course << ": " << memo[calories][course] << endl;
    return memo[calories][course];
}

int main() {
    //fast input && output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int> courses (n + 1,0);
    for(int i = 1; i < n + 1; i++)
        cin >> courses[i];
    
    vector<vector<int>> memo;
    for(int i = 0; i < m + 1; i++) {
        vector<int> courseNumberCombos (n + 1, -1);
        memo.push_back(courseNumberCombos);
    }

    int maxCaloriesConsumed = 
        max(
            findMaxCaloriesConsumed(memo, courses, m, 1),
            max(
                findMaxCaloriesConsumed(memo, courses, m, 2),
                findMaxCaloriesConsumed(memo, courses, m, 3)
            )
        );
    cout << maxCaloriesConsumed << endl;

    return 0;
}