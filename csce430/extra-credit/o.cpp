#include <iostream>
#include <set>
#include <cmath>

using namespace std;

long gcd(long a, long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    long n, teamx, teamy;
    cin >> n >> teamx >> teamy;
    

    set<pair<long, long>> sp;
    for(long i = 0; i < n; i++) {
        long x, y;
        cin >> x >> y;

        long diffx = teamx - x;
        long diffy = teamy - y;

        long cd;
        if (diffx < 0 && diffy < 0)
            cd = gcd(-diffx, -diffy);
        else if (diffx < 0)
            cd = gcd(-diffx, diffy);
        else if (diffy < 0)
            cd = gcd(diffx, -diffy);
        else
            cd = gcd(diffx, diffy);

        diffx /= cd;
        diffy /= cd;

        // cout << "diff: <" << diffx << ", " << diffy << ">" << endl;
        
        sp.insert({diffx, diffy});
    }

    // set<pair<long, long>>::iterator sp_it;
    // for(sp_it = sp.begin(); sp_it != sp.end(); sp_it++)
    //     cout << sp_it -> first << " " << sp_it -> second << endl;

    std::cout << sp.size() << endl;
}