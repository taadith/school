#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
	while((cin >> n) && n) {
        vector<double> x_values(n);
        vector<double> y_values(n);
		for(int i = 0; i < n; i++)
			cin >> x_values[i] >> y_values[i];
        
        double left = -200000;
        double right = 200000;
		double middle, third_quartile, middle_distance, third_quartile_distance;
		
		while(abs(left - right) > 1e-10) {
			middle = (left + right) / 2;
			third_quartile = (middle + right) / 2;

            middle_distance = 0;
            for(int i = 0; i < n; i++) {
                middle_distance = max(
                    middle_distance,
                    pow((x_values[i] - middle),2)
                    + pow(y_values[i],2)
                );
            }
			
            third_quartile_distance = 0;
            for(int i = 0; i < n; i++) {
                third_quartile_distance = max(
                    third_quartile_distance,
                    pow((x_values[i] - third_quartile),2)
                    + pow(y_values[i],2)
                );
            }

			if(middle_distance < third_quartile_distance)
				right = third_quartile;
			else
				left = middle;
		}
        
        cout << fixed << setprecision(9) << middle << " " << sqrt(middle_distance) << endl;
	}
	return 0;
}