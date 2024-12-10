include <iostream>
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
	string s, t;

	if (x+1 >= 140 || y+1 >= 140 || x-1 < 0 || y-1 <0)
		return 0;

	s += xmas[y+1][x+1];
	s += xmas[y][x];
	s += xmas[y-1][x-1];

	t += xmas[y-1][x+1];
	t += xmas[y][x];
	t += xmas[y+1][x-1];
	
	if((!s.compare("MAS")) || (!s.compare("SAM")))
		if((!t.compare("MAS")) || (!t.compare("SAM")))
			count++;

	return count;
}

int main(void)
{	
	ll ans = 0;
	for(int i = 0; i < 140; i++) {
		cin >> xmas[i];
	}

	for(int i = 1; i < 139; i++) {
		for (int j = 1; j < 139; j++) {
			if(xmas[i][j]=='A')
				ans += get_xmas(i,j);
		}
	}

	cout << ans;

	return 0;
}