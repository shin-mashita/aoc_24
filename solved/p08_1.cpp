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

set <vector <int>> antinodes;
char mmap[MAP_SIZE][MAP_SIZE];

void get_antinodes(char c, int posy, int posx)
{
	// cout << "Getting on " << posy << " " << posx << endl;
	vector <int> tempv;
	int diffy, diffx;
	FOR(i, MAP_SIZE) {
		FOR(j, MAP_SIZE) {
			if (i == posy && j == posx)
				continue;
			if(mmap[i][j] == c && i != posy && j != posx){
				diffy = i - posy;
				diffx = j - posx;

				if(i + diffy >= MAP_SIZE || j + diffx>= MAP_SIZE || i + diffy < 0 || j + diffx < 0) {
					continue;
				}

				tempv.push_back(i + diffy);
				tempv.push_back(j + diffx);
				antinodes.insert(tempv);

				// cout << "added: "<< i + diffy << " " << j + diffx << endl;

				tempv.clear();

				if(posy - diffy >= MAP_SIZE || posx - diffx>= MAP_SIZE || posy - diffy < 0 || posx - diffx < 0) {
					continue;
				}

				tempv.push_back(posy - diffy);
				tempv.push_back(posx - diffx);
				antinodes.insert(tempv);

				// cout << "added: "<< posy - diffy << " " << posx - diffx << endl;

				tempv.clear();
			}
		}
	}

	cout << endl;
}

int main(void)
{	

	FOR(i, MAP_SIZE)
		cin >> mmap[i];

	FOR(i, MAP_SIZE) {
		FOR(j, MAP_SIZE) {
			if(mmap[i][j]!='.') {
				get_antinodes(mmap[i][j], i, j);
			}
		}
	}

	for(auto a: antinodes){
		showvecline(a);
	}

	cout << antinodes.size();

	return 0;
}