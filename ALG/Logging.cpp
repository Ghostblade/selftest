#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

long double eps = 1e-15;

void solve(ifstream& in, ofstream& f) {
	int n;
	in >> n;
	vector<int> x(n), y(n);
	forn(i, n)
		in >> x[i] >> y[i];
	vector<long double> a(2 * n); 
	forn(i, n) {
		int an = 0, ans = n - 1;
		forn(j, n)
		if (j != i)
			a[an++] = atan2l(y[j] - y[i], x[j] - x[i]);
		sort(a.begin(), a.begin() + an);
		forn(k, an)
			a[k + an] = a[k] + 2 * M_PI;  

		int l = 0, r = 0;
		forn(k, an) {
			while (l < 2 * an-1 && a[l] - a[k] < eps)
				l++;
			while (r < 2 * an && a[r] - a[k] < M_PI - eps)
				r++;
			ans = min(ans, r - l);
		}
		//printf("%d\n", ans);
		f << ans << "\n";
	}
}

int main() {
	int tn;
	ofstream f;
	f.open("out.txt");

	ifstream in;
	in.open("in.in");

	in>>tn;
	forn(t, tn) {
		//printf("Case #%d:\n", t + 1);
		f << "Case #" << t + 1 << ":\n";
		solve(in, f);
	}
	f.close();
	in.close();
	return 0;
}
