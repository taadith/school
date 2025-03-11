#include <iostream>
#include <vector>
#include <map>

using namespace std;
 
void subset_sums(vector<int> &v)
{
    // there are total 2^n subsets
    long long total = 1 << v.size();
 
    // Consider all numbers from 0 to 2^n - 1
    for (long long i = 0; i < total; i++) {
        long long sum = 0;
        for (unsigned int j = 0; j < v.size(); j++)
            if (i & (1 << j))
                sum += v[j];
 
        // Print sum of picked elements.
        cout << sum << " ";
    }
}
 
int main() {
    int t,n;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":" << endl;

        cin >> n;
        vector<int> v(n);
        map<long long,int> m;
        for(int i = 0; i < n; i++)
            cin >> v[i];
        
        // there are total 2^n subsets
        long long total = 1 << v.size();
    
        // Consider all numbers from 1 to 2^n - 1
        for (long long i = 0; i < total - 1; i++) {
            long long sum = 0;
            for (unsigned int j = 0; j < v.size(); j++) {
                if (i & (1 << j))
                    sum += v[j];
            }
            if (m.count(sum) == 0)
                m.emplace(sum,i);
            else {
                int x = m.at(sum);
                for(unsigned int j = 0; j < v.size(); j++) {
                    if (x & (1 << j))
                        cout << v[j] << " ";
                }
                cout << endl;

                for(unsigned int j = 0; j < v.size(); j++) {
                    if (i & (1 << j))
                        cout << v[j] << " ";
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}