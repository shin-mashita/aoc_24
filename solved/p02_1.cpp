#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

#define ll long long
#define FOR(_i,_n) for(int _i = 0; _i < _n; i++)

/* Debuggers */
#define showstrvec(svec)		for(string s:svec){cout << s << endl;}
#define showvec(vec)			for(auto v:vec){cout << v << " ";} cout << endl;

using namespace std;

vector<ll> _tokenizer(string s)
{
	vector <ll> v;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        v.push_back(stoll(word));
    }

    return v;
}

bool is_safe(vector <ll> v)
{
	vector <ll> diffs(v.size()-1);

	FOR(i, v.size()-1)
		diffs[i] = v[i+1] - v[i];

	FOR(i, v.size()-1)
		if (abs(diffs[i]) < 1 || abs(diffs[i]) > 3)
			return false;

	if (diffs[0] > 0)
		FOR(i, v.size()-1)
			if (diffs[i] < 0)
				return false;

	if (diffs[0] < 0)
		FOR(i, v.size()-1)
			if (diffs[i] > 0)
				return false;

	return true;
}

int main(void)
{
	ll testcases = 1000;
	vector <ll> v;
	ll ans = 0;
	string s;

	while (testcases--){
		getline(cin, s);
		v = _tokenizer(s);

		if(is_safe(v))
			ans++;
	}

	cout << ans;

	return 0;
}