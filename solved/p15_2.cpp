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

vector<vector<char>> mmap;
string cmds[CMD_GROUPS];
ll botx;
ll boty;

void showmap() {
	FOR(i, mmap.size()) {
		FOR(j, mmap[i].size()) {
			cout << mmap[i][j];
		}
		cout << endl;
	}
}

void scalemap() {
	FOR(i, mmap.size()) {
		int j = 0;
		while (j < mmap[i].size()) {
			if(mmap[i][j] == '#') {
				mmap[i].insert(mmap[i].begin() + j + 1, '#');
				j++;
			} else if(mmap[i][j] == 'O') {
				mmap[i].erase(mmap[i].begin() + j);
				mmap[i].insert(mmap[i].begin() + j, '[');
				mmap[i].insert(mmap[i].begin() + j + 1, ']');
				j++;
			} else {
				mmap[i].insert(mmap[i].begin() + j + 1, '.');
				j++;
			}
			j++;
		}
	}
}

set <pair<int,int>> s_left;
set <pair<int,int>> s_right;
bool is_blocked = false;

void move_boxes_up(int y1, int x1, int y2, int x2)
{
	pair<int,int> p_left(y1,x1);
	pair<int,int> p_right(y2,x2);

	s_left.insert(p_left);
	s_right.insert(p_right);

	if(mmap[y1-1][x1] == '#' || mmap[y2-1][x2] == '#') {
		s_left.clear();
		s_right.clear();
		is_blocked = true;
		return;
	}

	if(mmap[y1-1][x1] == '.' && mmap[y2-1][x2] == '.' && !is_blocked) {
		return;
	}

	if(mmap[y1-1][x1] == '[' && mmap[y2-1][x2] == ']' && !is_blocked) {
		move_boxes_up(y1-1, x1, y2-1, x2);
	} 

	if(mmap[y1-1][x1] == ']' && mmap[y1-1][x1-1] == '[' && !is_blocked) {
		move_boxes_up(y1-1, x1-1, y1-1, x1);
	}

	if(mmap[y2-1][x2] == '[' && mmap[y2-1][x2+1] == ']' && !is_blocked) {
		move_boxes_up(y2-1, x2, y2-1, x2+1);
	}

	return;
}

void move_boxes_down(int y1, int x1, int y2, int x2)
{
	pair<int,int> p_left(y1,x1);
	pair<int,int> p_right(y2,x2);

	s_left.insert(p_left);
	s_right.insert(p_right);

	if(mmap[y1+1][x1] == '#' || mmap[y2+1][x2] == '#') {
		s_left.clear();
		s_right.clear();
		is_blocked = true;
		return;
	}

	if(mmap[y1+1][x1] == '.' && mmap[y2+1][x2] == '.' && !is_blocked) {
		return;
	}

	if(mmap[y1+1][x1] == '[' && mmap[y2+1][x2] == ']' && !is_blocked) {
		move_boxes_down(y1+1, x1, y2+1, x2);
	} 

	if(mmap[y1+1][x1] == ']' && mmap[y1+1][x1-1] == '[' && !is_blocked) {
		move_boxes_down(y1+1, x1-1, y1+1, x1);
	}

	if(mmap[y2+1][x2] == '[' && mmap[y2+1][x2+1] == ']' && !is_blocked) {
		move_boxes_down(y2+1, x2, y2+1, x2+1);
	}

	return;
}

void move(char cmd) {
	switch(cmd) {
	case '^':
		if (mmap[boty-1][botx] == '#') {
			break;
		} else if (mmap[boty-1][botx] == '[') {
			move_boxes_up(boty-1, botx, boty-1, botx+1);
			if(!is_blocked) {
				for(auto p: s_left) {
					mmap[p.first][p.second] = '.';
				}
				for(auto p: s_right) {
					mmap[p.first][p.second] = '.';
				}
				for(auto p: s_left) {
					mmap[p.first - 1][p.second] = '[';
				}
				for(auto p: s_right) {
					mmap[p.first - 1][p.second] = ']';
				}
				s_left.clear();
				s_right.clear();
				mmap[boty-1][botx] = '@';
				mmap[boty][botx] = '.';
				boty = boty-1;
				botx = botx;
			} else {
				is_blocked = false;
				return;
			}
		} else if (mmap[boty-1][botx] == ']') {
			move_boxes_up(boty-1, botx-1, boty-1, botx);
			if(!is_blocked) {
				for(auto p: s_left) {
					mmap[p.first][p.second] = '.';
				}
				for(auto p: s_right) {
					mmap[p.first][p.second] = '.';
				}
				for(auto p: s_left) {
					mmap[p.first - 1][p.second] = '[';
				}
				for(auto p: s_right) {
					mmap[p.first - 1][p.second] = ']';
				}
				s_left.clear();
				s_right.clear();
				mmap[boty-1][botx] = '@';
				mmap[boty][botx] = '.';
				boty = boty-1;
				botx = botx;
			} else {
				is_blocked = false;
				return;
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
		else if (mmap[boty][botx+1] == '[') {
			int y = boty;
			int x = botx+1;
			while(mmap[y][x] == '[') {
				x+=2;
				if(mmap[y][x] == '#')
					return;
				if(mmap[y][x] == '.') {
					int tempx = x;
					while(tempx>botx+1) {
						mmap[y][tempx--] = ']';
						mmap[y][tempx--] = '[';
					}
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
		if (mmap[boty+1][botx] == '#') {
			break;
		} else if (mmap[boty+1][botx] == '[') {
			move_boxes_down(boty+1, botx, boty+1, botx+1);
			if(!is_blocked) {
				for(auto p: s_left) {
					mmap[p.first][p.second] = '.';
				}
				for(auto p: s_right) {
					mmap[p.first][p.second] = '.';
				}
				for(auto p: s_left) {
					mmap[p.first + 1][p.second] = '[';
				}
				for(auto p: s_right) {
					mmap[p.first + 1][p.second] = ']';
				}
				s_left.clear();
				s_right.clear();
				mmap[boty+1][botx] = '@';
				mmap[boty][botx] = '.';
				boty = boty+1;
				botx = botx;
			} else {
				is_blocked = false;
				return;
			}
		} else if (mmap[boty+1][botx] == ']') {
			move_boxes_down(boty+1, botx-1, boty+1, botx);
			if(!is_blocked) {
				for(auto p: s_left) {
					mmap[p.first][p.second] = '.';
				}
				for(auto p: s_right) {
					mmap[p.first][p.second] = '.';
				}
				for(auto p: s_left) {
					mmap[p.first + 1][p.second] = '[';
				}
				for(auto p: s_right) {
					mmap[p.first + 1][p.second] = ']';
				}
				s_left.clear();
				s_right.clear();
				mmap[boty+1][botx] = '@';
				mmap[boty][botx] = '.';
				boty = boty+1;
				botx = botx;
			} else {
				is_blocked = false;
				return;
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
		else if (mmap[boty][botx-1] == ']') {
			int y = boty;
			int x = botx-1;
			while(mmap[y][x] == ']') {
				x-=2;
				if(mmap[y][x] == '#')
					return;
				if(mmap[y][x] == '.') {
					int tempx = x;
					while(tempx<botx-1) {
						mmap[y][tempx++] = '[';
						mmap[y][tempx++] = ']';
					}
					mmap[boty][botx-1] = '@';
					mmap[boty][botx] = '.';
					boty = boty;
					botx = botx - 1;
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
	char cinput;
	vector <char> cinputs;

	FOR(i, MAP_SIZE) {
		FOR(j, MAP_SIZE) {
			cin >> cinput;
			cinputs.push_back(cinput);
		}
		mmap.push_back(cinputs);
		cinputs.clear();
	}

	scalemap();

	getline(cin, cmds[0]);
	getline(cin, cmds[0]);

	FOR(i, CMD_GROUPS) {
		getline(cin, cmds[i]);
	}

	FOR(i, mmap.size()) {
		FOR(j, mmap[i].size()) {
			if(mmap[i][j] == '@') {
				boty = i;
				botx = j;
				break;
			}
		}
	}

	for(auto cmd: cmds) {
		for(char c: cmd) {
			move(c);
		}
	}

	FOR(i, mmap.size()) {
		FOR(j, mmap[i].size()) {
			if(mmap[i][j] == '[') {
				ans += 100*i + j;
			}
		}
	}
	showmap();

	LOG(ans);

	return 0;
}