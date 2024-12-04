#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>

#define ll long long
#define FOR(_i,_n) for(int _i; _i < _n; i++)

/* Debuggers */
#define showstrvec(svec)		for(string s:svec){cout << s << endl;}
#define showvec(vec)			for(auto v:vec){cout << v << endl;}

using namespace std;

int main(void)
{	
	ll u[1000], v[1000];
	ll ans = 0;

	FOR(i, 1000) {
		cin >> u[i] >> v[i];
	}

	sort(u, u + sizeof(u)/sizeof(u[0]));
	sort(v, v + sizeof(v)/sizeof(v[0]));

	FOR(i, 1000) {
		ans += abs(u[i]-v[i]);
	}
	
	cout << ans;

	return 0;
}