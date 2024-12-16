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

#define MAP_SIZE 50
#define CMD_GROUPS 20

static inline vector <ll> _tokenize(string s, char del) //todo: make template
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

char mmap[MAP_SIZE][MAP_SIZE];
string cmds[CMD_GROUPS];
ll botx;
ll boty;

void showmap() {
	FOR(i, MAP_SIZE) {
		FOR(j, MAP_SIZE) {
			cout << mmap[i][j];
		}
		cout << endl;
	}
}

static void move(char cmd) {
	switch(cmd) {
	case '^':
		if (mmap[boty-1][botx] == '#')
			break;
		else if (mmap[boty-1][botx] == 'O') {
			int y = boty - 1;
			int x = botx;
			while(mmap[y][x] == 'O') {
				y--;
				if(mmap[y][x] == '#')
					return;
				if(mmap[y][x] == '.') {
					mmap[y][x] = 'O';
					mmap[boty-1][botx] = '@';
					mmap[boty][botx] = '.';
					boty = boty-1;
					botx = botx;

					break;
				}
			}
		} else {
			mmap[boty-1][botx] = '@';
			mmap[boty][botx] = '.';
			boty = boty-1;
			botx = botx;
		}
		break;
	case '>':
		if (mmap[boty][botx+1] == '#')
			break;
		else if (mmap[boty][botx+1] == 'O') {
			int y = boty;
			int x = botx+1;
			while(mmap[y][x] == 'O') {
				x++;
				if(mmap[y][x] == '#')
					return;
				if(mmap[y][x] == '.') {
					mmap[y][x] = 'O';
					mmap[boty][botx+1] = '@';
					mmap[boty][botx] = '.';
					boty = boty;
					botx = botx+1;

					break;
				}
			}
		} else {
			mmap[boty][botx+1] = '@';
			mmap[boty][botx] = '.';
			boty = boty;
			botx = botx+1;
		}
		break;
	case 'v':
		if (mmap[boty+1][botx] == '#')
			break;
		else if (mmap[boty+1][botx] == 'O') {
			int y = boty + 1;
			int x = botx;
			while(mmap[y][x] == 'O') {
				y++;
				if(mmap[y][x] == '#')
					return;
				if(mmap[y][x] == '.') {
					mmap[y][x] = 'O';
					mmap[boty+1][botx] = '@';
					mmap[boty][botx] = '.';
					boty = boty+1;
					botx = botx;

					break;
				}
			}
		} else {
			mmap[boty+1][botx] = '@';
			mmap[boty][botx] = '.';
			boty = boty+1;
			botx = botx;
		}
		break;
	case '<':
		if (mmap[boty][botx-1] == '#')
			break;
		else if (mmap[boty][botx-1] == 'O') {
			int y = boty;
			int x = botx-1;
			while(mmap[y][x] == 'O') {
				x--;
				if(mmap[y][x] == '#')
					return;
				if(mmap[y][x] == '.') {
					mmap[y][x] = 'O';
					mmap[boty][botx-1] = '@';
					mmap[boty][botx] = '.';
					boty = boty;
					botx = botx-1;

					break;
				}
			}
		} else {
			mmap[boty][botx-1] = '@';
			mmap[boty][botx] = '.';
			boty = boty;
			botx = botx-1;
		}
		break;
	default:
		break;
	}
}

int main(void)
{	
	ll ans = 0;

	FOR(i, MAP_SIZE) {
		cin >> mmap[i];
	}

	getline(cin, cmds[0]);
	getline(cin, cmds[0]);

	FOR(i, CMD_GROUPS) {
		getline(cin, cmds[i]);
	}

	FOR(i, MAP_SIZE) {
		FOR(j, MAP_SIZE) {
			if(mmap[i][j] == '@') {
				boty = i;
				botx = j;
			}
		}
	}

	for(auto cmd: cmds) {
		for(char c: cmd) {
			move(c);
		}
	}

	FOR(i, MAP_SIZE) {
		FOR(j, MAP_SIZE) {
			if(mmap[i][j] == 'O') {
				ans += 100*i + j;
			}
		}
	}

	// showmap();

	LOG(ans);

	return 0;
}