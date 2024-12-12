#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <set>

#define ll long long
#define FOR(_i,_n) for(int _i = 0; _i < _n; _i++)
#define LOG(_x) cout << _x << endl

/* Debuggers */
#define showvecline(svec)		{for(auto s:svec){cout << s << " ";} cout << endl;}
#define showvec(vec)			for(auto v:vec){cout << v << endl;}

using namespace std;

#define MAP_SIZE 10

string s[MAP_SIZE];
set <pair <int, int>> mmap;

void showgarden()
{
	FOR(i, MAP_SIZE)
		LOG(s[i]);
}

void dfs(int y, int x, int depth) {
	pair <int , int> yx;
	yx.first = y;
	yx.second = x;

	if(mmap.count(yx))
		return;
	else
		mmap.insert(yx);

	if(y-1 >= 0) {
		if (s[y-1][x] == s[y][x]) {
			// cout << y << " " << x << endl;
			// cout << "up " << s[y+1][x] << endl;
			depth++;
			dfs(y-1, x, depth);
		}
	}

	if(x+1 < MAP_SIZE) {
		if (s[y][x+1] == s[y][x]) {
			// cout << y << " " << x << endl;
			// cout << "right " << s[y][x+1] << endl;
			depth++;
			dfs(y, x+1, depth);
		}
	}

	if(y+1 < MAP_SIZE) {
		if (s[y+1][x] == s[y][x]) {
			// cout << y << " " << x << endl;
			// cout << "down " << s[y+1][x] << endl;
			depth++;
			dfs(y+1, x, depth);
		}
	}

	if(x-1 >= 0) {
		if (s[y][x-1] == s[y][x]) {
			depth++;
			dfs(y, x-1, depth);
		}
	}

	return;
}

ll get_fence_cost()
{
	ll lmax = 0, lmin = MAP_SIZE - 1;
	ll wmax = 0, wmin = MAP_SIZE - 1;
	for(auto p:mmap) {
		wmax = (p.second > wmax) ? p.second : wmax;
		wmin = (p.second < wmin) ? p.second : wmin;
		lmax = (p.first > lmax) ? p.first : lmax;
		lmin = (p.first < lmin) ? p.first : lmin;
	}

	return 2*((wmax - wmin + 1) + (lmax - lmin + 1)) * mmap.size();
}

int main(void)
{	
	ll ans = 0;
	FOR(i, MAP_SIZE) {
		getline(cin, s[i]);
	}

	FOR(y, MAP_SIZE) {
		FOR(x, MAP_SIZE) {
			if (s[y][x] != '-') {
				cout << s[y][x] << endl;
				dfs(y, x, 0);

				for(auto p:mmap) {
					s[p.first][p.second] = '-';
				}

				cout << get_fence_cost() << endl;
				ans += get_fence_cost();
				mmap.clear();

				showgarden();
			}
		}
	}

	cout << ans << endl;
	return 0;
}