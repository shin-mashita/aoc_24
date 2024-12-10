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
#define showvecline(svec)		for(auto s:svec){cout << s << " ";} cout << endl;
#define showvec(vec)			for(auto v:vec){cout << v << endl;}

using namespace std;

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

int main(void)
{	
	string s;
	string t;
	getline(cin, s);
	vector <ll> disk;

	ll count = 0;
	for(int i = 0; i < s.size(); i++) {	
		if (!(i%2)) {
			FOR(j, stoi(string(1,s[i])))
				disk.push_back(count);
			count++;
		} else {
			FOR(j, stoi(string(1,s[i])))
				disk.push_back(-1);
		}
	}

	ll first = 0;
	ll last = disk.size() - 1;

	while (first < last) {
		if (disk[first] == -1) {
			while(disk[last] == -1)
				last--;
			if(first >= last)
				break;

			disk[first] = disk[last];
			disk[last] = -1;
		}

		first++;
	}

	ll ans = 0;
	FOR(i, disk.size()) {
		if (disk[i] > 0)
			ans += i*disk[i];
	}

	showvecline(disk);

	cout<<ans;


	return 0;
}