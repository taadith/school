#include <stdio.h> 
#include <math.h>
#include <algorithm>
using namespace std;

double x_values[65536], y_values[65536];
int n;
double calc(double x) {
	double ret = 0;
	for(int i = 0; i < n; i++)
		ret = max(ret, (x_values[i] - x)*(x_values[i] - x) + y_values[i] * y_values[i]);
	return ret;
}
int main() {
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 0; i < n; i++)
			scanf("%lf %lf", &x_values[i], &y_values[i]);
		double l, r, mid, midmid, md, mmd;
#define INF 200000
#define eps 1e-10
		l = -INF, r = INF;
		while(fabs(l - r) > eps) {
			mid = (l + r)/2;
			midmid = (mid + r)/2;
			md = calc(mid);
			mmd = calc(midmid);
			if(md < mmd)
				r = midmid;
			else
				l = mid;
		}
		printf("%.9lf %.9lf\n", mid, sqrt(md));
	}
	return 0;
}