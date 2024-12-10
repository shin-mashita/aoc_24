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

#define MAP_SIZE	53

int mmap[MAP_SIZE][MAP_SIZE]; //mmap(y,x)
int scores = 0;

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

void dfs(int val, int posy, int posx) {
	if (val == 9){
		scores++;
		return;
	}

	if(posy - 1 >= 0) {
		if (mmap[posy-1][posx] == val + 1) {
			dfs(val + 1, posy-1, posx);
		}
	}
	if(posx + 1 < MAP_SIZE) {
		if (mmap[posy][posx+1] == val + 1) {
			dfs(val + 1, posy, posx+1);
		}
	}
	if(posy + 1 < MAP_SIZE) {
		if (mmap[posy+1][posx] == val + 1) {
			dfs(val + 1, posy+1, posx);
		}
	}
	if(posx - 1 >= 0) {
		if (mmap[posy][posx-1] == val + 1) {
			dfs(val + 1, posy, posx-1);
		}
	}
	return;
}

int main(void)
{	
	string s;
	FOR(i, MAP_SIZE) {
		getline(cin, s);
		FOR(j, MAP_SIZE) {
			mmap[i][j] = stoi(string(1,s[j]));
		}
	}

	FOR(i, MAP_SIZE){
		FOR(j, MAP_SIZE){
			if(mmap[i][j] == 0){
				dfs(0, i, j);
			}
		}
	}

	// FOR(i, MAP_SIZE)
	// 	showvecline(mmap[i]);
	cout << scores;
}