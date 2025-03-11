#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_length_passes, num_width_passes;
    double mower_cut;

    cin >> num_length_passes >> num_width_passes >> mower_cut;
    while(num_length_passes != 0 && num_width_passes != 0 && mower_cut != 0) {

        vector<double> length_passes(num_length_passes);
        for(int i = 0; i < num_length_passes; i++)
            cin >> length_passes[i];

        vector<double> width_passes(num_width_passes);
        for(int i = 0; i < num_width_passes; i++)
            cin >> width_passes[i];

        sort(length_passes.begin(), length_passes.end());
        sort(width_passes.begin(), width_passes.end());
        
        bool good_job = true;

        // check boundaries
        if ((length_passes[0] - (mower_cut / 2) > 0) || (length_passes[num_length_passes-1] + (mower_cut / 2) < 75))
            good_job = false;
        if ((width_passes[0] - (mower_cut / 2) > 0) || (width_passes[num_width_passes-1] + (mower_cut / 2) < 100))
            good_job = false;

        // check length passes
        if (good_job) {
            for(unsigned int i = 0; i < length_passes.size() - 1; i++) {
                if(length_passes[i+1] - length_passes[i] > mower_cut) {
                    good_job = false;
                    break;
                }
            }
        }

        // check width passes
        if (good_job) {
            for(unsigned int i = 0; i < width_passes.size() - 1; i++) {
                if(width_passes[i+1] - width_passes[i] > mower_cut) {
                    good_job = false;
                    break;
                }
            }
        }

        if(good_job) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

        cin >> num_length_passes >> num_width_passes >> mower_cut;
    }
}