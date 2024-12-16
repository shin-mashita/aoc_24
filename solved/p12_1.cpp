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

#define MAP_SIZE 140

string s[MAP_SIZE];
set <pair <int, int>> mmap;
ll adj = 0;

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
			adj++;
			depth++;
			dfs(y-1, x, depth);
		}
	}

	if(x+1 < MAP_SIZE) {
		if (s[y][x+1] == s[y][x]) {
			// cout << y << " " << x << endl;
			// cout << "right " << s[y][x+1] << endl;
			adj++;
			depth++;
			dfs(y, x+1, depth);
		}
	}

	if(y+1 < MAP_SIZE) {
		if (s[y+1][x] == s[y][x]) {
			// cout << y << " " << x << endl;
			// cout << "down " << s[y+1][x] << endl;
			adj++;
			depth++;
			dfs(y+1, x, depth);
		}
	}

	if(x-1 >= 0) {
		if (s[y][x-1] == s[y][x]) {
			adj++;
			depth++;
			dfs(y, x-1, depth);
		}
	}

	return;
}

ll get_fence_cost()
{
	return mmap.size()*(mmap.size()*4 - adj);
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
				dfs(y, x, 0);

				for(auto p:mmap) {
					s[p.first][p.second] = '-';
				}
				ans += get_fence_cost();
				mmap.clear();
				adj = 0;

				// showgarden();
			}
		}
	}

	cout << ans << endl;
	return 0;
}