#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <math.h>

#define ll long long
#define FOR(_i,_n) for(int _i = 0; _i < _n; _i++)

/* Debuggers */
#define showstrvec(svec)		for(string s:svec){cout << s << endl;}
#define showvec(vec)			for(auto v:vec){cout << v << endl;}

using namespace std;

int main(void)
{
	ll u[1000], v[1000];
	ll count = 0;
	ll ans = 0;

	FOR(i, 1000) {
		cin >> u[i] >> v[i];
	}

	FOR(j, 1000) {
		FOR(k, 1000) {
			if (u[j] == v[k])
				count++;
		}

		ans += u[j] * count;
		count = 0;
	}

	cout << ans;

	return 0;
}