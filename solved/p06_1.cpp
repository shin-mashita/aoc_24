#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

#define ll long long
#define FOR(_i,_n) for(int _i = 0; _i < _n; _i++)

/* Debuggers */
#define showstrvec(svec)		for(string s:svec){cout << s << endl;}
#define showvec(vec)			for(auto v:vec){cout << v << " ";} cout << endl;

using namespace std;

char map[130][130];
int cury;
int curx;

static inline void showmap(void)
{
	FOR(t, 130) {
		FOR(v, 130)
			cout << map[t][v];
		cout << "\n";
	}
}

vector <ll> _tokenize(string s, char del)
{
	vector <ll> v;
	stringstream ss(s);
	string word;
	while (!ss.eof()) {
		getline(ss, word, del);
		v.push_back(stoll(word));
	}

	return v;
}

static void	travel(void)
{
	while(1){
		while (cury-1 >= 0)
		{
			if(map[cury-1][curx]=='#')
				break;
			map[cury][curx] = 'X';
			cury--;
		}

		if (cury-1 < 0)
			return;

		map[cury][curx] = '>';

		while (curx+1 <= 129)
		{
			if (map[cury][curx+1]=='#')
				break;
			map[cury][curx] = 'X';
			curx++;
		}

		if (curx+1 > 129)
			return;

		map[cury][curx] = 'v';

		while (cury+1 <= 129)
		{
			if (map[cury+1][curx]=='#')
				break;
			map[cury][curx] = 'X';
			cury++;
		}

		if (cury+1 > 129)
			return;

		map[cury][curx] = '<';

		while (curx-1 >= 0)
		{
			if (map[cury][curx-1]=='#')
				break;
			map[cury][curx] = 'X';
			curx--;
		}

		if (curx-1 < 0)
			return;

		map[cury][curx] = '^';
	}
}


int main(void)
{
	ll ans = 0;
	FOR(y, 130)
		FOR(x, 130){
			cin >> map[y][x];
			if (map[y][x] == '^'){
				curx = x;
				cury = y;
			}
		}

	travel();
	// showmap();
	FOR(y, 130)
		FOR(x, 130)
			if (map[y][x] == 'X')
				ans++;

	cout << ans+1;
	return 0;
}