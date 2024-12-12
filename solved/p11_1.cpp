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

vector <ll> v;

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

bool is_even(ll x, int idx) {
	string s ="";

	s = to_string(x);

	if(s.size()%2) 
		return false;
	else {
		v[idx] = stoll(s.substr(0, s.size()/2));
		v.insert(v.begin() + idx + 1, stoll(s.substr(s.size()/2, s.size())));
		return true;
	}
}

int main(void)
{
	ll t; 

	while(cin >> t) {
		v.push_back(t);
	}

	// showvecline(v);
	// cout << is_even(v[5], 5);
	FOR(i, 25) {
		int j = 0;
		while (j < v.size()) {
			if(v[j] == 0)
				v[j] = 1;
			else if(is_even(v[j], j)){
				j++;
			} else {
				v[j] *= 2024;
			}
			j++;
		}
	}

	cout << v.size();

	return 0;
}