#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define ll long long

/* Debuggers */
#define showstrvec(svec)		for(string s:svec){cout << s << endl;}

using namespace std;

string xmas[140]; // char *xmas[y][x] which is 140x140 (0,0) to (139, 139)

int get_xmas(int y, int x)
{
	ll count = 0;
	string s;

east:
	if (x + 3 >= 140)
		goto southeast;

	s += xmas[y][x];
	s += xmas[y][x+1];
	s += xmas[y][x+2];
	s += xmas[y][x+3];

	if(!s.compare("XMAS"))
		count++;

	// cout << s << endl;
	s.clear();

southeast:
	if (x + 3 >= 140 || y + 3 >= 140)
		goto south;

	s += xmas[y][x];
	s += xmas[y+1][x+1];
	s += xmas[y+2][x+2];
	s += xmas[y+3][x+3];

	if(!s.compare("XMAS"))
		count++;

	// cout << s << endl;
	s.clear();

south:
	if (y + 3 >= 140)
		goto southwest;

	s += xmas[y][x];
	s += xmas[y+1][x];
	s += xmas[y+2][x];
	s += xmas[y+3][x];

	if(!s.compare("XMAS"))
		count++;

	// cout << s << endl;
	s.clear();

southwest:
	if (y + 3 >= 140 || x - 3 < 0)
		goto west;

	s += xmas[y][x];
	s += xmas[y+1][x-1];
	s += xmas[y+2][x-2];
	s += xmas[y+3][x-3];

	if(!s.compare("XMAS"))
		count++;

	// cout << s << endl;
	s.clear();

west:
	if (x - 3 < 0)
		goto northwest;

	s += xmas[y][x];
	s += xmas[y][x-1];
	s += xmas[y][x-2];
	s += xmas[y][x-3];

	if(!s.compare("XMAS"))
		count++;

	// cout << s << endl;
	s.clear();

northwest:
	if (x - 3 < 0 || y - 3 < 0)
		goto north;

	s += xmas[y][x];
	s += xmas[y-1][x-1];
	s += xmas[y-2][x-2];
	s += xmas[y-3][x-3];

	if(!s.compare("XMAS"))
		count++;

	// cout << s << endl;
	s.clear();

north:
	if (y - 3 < 0)
		goto northeast;

	s += xmas[y][x];
	s += xmas[y-1][x];
	s += xmas[y-2][x];
	s += xmas[y-3][x];

	if(!s.compare("XMAS"))
		count++;

	// cout << s << endl;
	s.clear();

northeast:
	if (y - 3 < 0 || x + 3 >= 140)
		return count;

	s += xmas[y][x];
	s += xmas[y-1][x + 1];
	s += xmas[y-2][x + 2];
	s += xmas[y-3][x + 3];

	if(!s.compare("XMAS"))
		count++;

	// cout << s << endl;
	s.clear();

	return count;
}

int main(void)
{	
	ll ans = 0;
	for(int i = 0; i < 140; i++) {
		cin >> xmas[i];
	}

	for(int i = 0; i < 140; i++) {
		for (int j = 0; j < 140; j++) {
			if(xmas[i][j]=='X')
				ans += get_xmas(i,j);
		}
	}

	cout << ans;

	return 0;
}