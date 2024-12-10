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
	ll spaces_count = 0;
	ll sizes[10000];
	ll offsets[10000];
	ll spaces[10000];
	ll spaces_offsets[10000];
	for(int i = 0; i < s.size(); i++) {	
		if (!(i%2)) {
			offsets[count] = disk.size();
			FOR(j, stoi(string(1,s[i])))
				disk.push_back(count);
			sizes[count] = stoi(string(1,s[i]));
			count++;
		} else {
			spaces_offsets[spaces_count] = disk.size();
			FOR(j, stoi(string(1,s[i])))
				disk.push_back(-1);
			spaces[spaces_count] = stoi(string(1,s[i]));
			spaces_count++;
		}
	}

	for (int i = 9999; i >= 0; i--) {
		for(int j = 0; j <= 9999; j++) {
			if (offsets[i] < spaces_offsets[j])
				break;

			if(sizes[i] <= spaces[j]) {
				//swap
				if(i == 510)
					cout << "here" << endl;
				FOR(k, sizes[i]){
					disk[spaces_offsets[j] + k] = i;
					disk[offsets[i] + k] = -1;
				}

				spaces[j]-=sizes[i];
				spaces_offsets[j]+=sizes[i];

				break;
			}
		}
	}

	ll ans = 0;
	FOR(i, disk.size()) {
		if (disk[i] > 0)

			ans += i*disk[i];
	}

	cout<<ans;


	return 0;
}