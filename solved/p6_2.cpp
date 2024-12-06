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

/* Debuggers */
#define showstrvec(svec)		for(string s:svec){cout << s << endl;}
#define showvec(vec)			for(auto v:vec){cout << v << " ";} cout << endl;

using namespace std;

char map[130][130];
char temp_map[130][130];
int temp_cury;
int temp_curx;
int cury;
int curx;
int d[8] = {0};
vector<int> path_x;
vector<int> path_y;
vector<vector<int>> path_history;
set <vector<int>> unique_paths;

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
		path_x.push_back(curx);
		path_y.push_back(cury);
		while (cury-1 >= 0)
		{
			if(map[cury-1][curx]=='#')
				break;
			map[cury][curx] = 'X';
			cury--;
			path_x.push_back(curx);
			path_y.push_back(cury);
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
			path_x.push_back(curx);
			path_y.push_back(cury);
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
			path_x.push_back(curx);
			path_y.push_back(cury);
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
			path_x.push_back(curx);
			path_y.push_back(cury);
		}

		if (curx-1 < 0)
			return;

		map[cury][curx] = '^';
	}
}

static bool	is_travel_looped(void)
{
	vector <int> coords; //(y,x,direction) d = 0,1,2,3 for N,E,S,W
	while(1){
		while (cury-1 >= 0) //N
		{
			if(map[cury-1][curx]=='#' || map[cury-1][curx]=='O')
				break;
			map[cury][curx] = 'X';
			cury--;
		}

		if (cury-1 < 0)
			return false;

		map[cury][curx] = '>';
		coords.push_back(cury);
		coords.push_back(curx);
		coords.push_back(1);

		path_history.push_back(coords);
		unique_paths.insert(coords);

		coords.clear();

		while (curx+1 <= 129)
		{
			if (map[cury][curx+1]=='#' || map[cury][curx+1]=='O')
				break;
			map[cury][curx] = 'X';
			curx++;
		}

		if (curx+1 > 129)
			return false;

		map[cury][curx] = 'v';
		coords.push_back(cury);
		coords.push_back(curx);
		coords.push_back(2);

		path_history.push_back(coords);
		unique_paths.insert(coords);

		coords.clear();

		while (cury+1 <= 129)
		{
			if (map[cury+1][curx]=='#' || map[cury+1][curx]=='O')
				break;
			map[cury][curx] = 'X';
			cury++;
		}

		if (cury+1 > 129)
			return false;

		map[cury][curx] = '<';
		coords.push_back(cury);
		coords.push_back(curx);
		coords.push_back(3);

		path_history.push_back(coords);
		unique_paths.insert(coords);

		coords.clear();

		while (curx-1 >= 0)
		{
			if (map[cury][curx-1]=='#' || map[cury][curx-1]=='O')
				break;
			map[cury][curx] = 'X';
			curx--;
		}

		if (curx-1 < 0)
			return false;

		map[cury][curx] = '^';
		coords.push_back(cury);
		coords.push_back(curx);
		coords.push_back(0);

		path_history.push_back(coords);
		unique_paths.insert(coords);

		coords.clear();

		if(path_history.size()!=unique_paths.size()) //&& (path_history.size()-unique_paths.size())%4==0
			return true;
	}
}


int main(void)
{
	set<vector<int>> ans;
	vector <int> tempv;
	FOR (y, 130)
		FOR (x, 130) {
			cin >> temp_map[y][x];
			if (temp_map[y][x] == '^'){
				temp_curx = x;
				temp_cury = y;
			}
		}

	memcpy(map, temp_map, 130*130*sizeof(char));
	curx = temp_curx;
	cury = temp_cury;

	travel();

	for (int i =0; i < path_x.size(); i++){
		memcpy(map, temp_map, 130*130*sizeof(char));
		curx = temp_curx;
		cury = temp_cury;

		if (map[path_y[i]][path_x[i]] == '.') {
			map[path_y[i]][path_x[i]] = 'O';

			if (is_travel_looped()){
				tempv.push_back(path_y[i]);
				tempv.push_back(path_x[i]);
				ans.insert(tempv);

				tempv.clear();
			}
		}

		path_history.clear();
		unique_paths.clear();
	}

	


	cout << ans.size();
	return 0;
}