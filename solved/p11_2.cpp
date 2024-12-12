#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <set>
#include <map>

#define ll long long
#define FOR(_i,_n) for(int _i = 0; _i < _n; _i++)
#define LOG(_x) cout << _x << endl

/* Debuggers */
#define showvecline(svec)		{for(auto s:svec){cout << s << " ";} cout << endl;}
#define showvec(vec)			for(auto v:vec){cout << v << endl;}

using namespace std;

map <pair<ll,int>, ll> mmem;

bool is_even(ll x) {
	string s ="";

	s = to_string(x);

	if(s.size()%2) 
		return false;
	else {
		return true;
	}
}

vector <ll> blink(ll num)
{
	vector <ll> v;
	if (num == 0) {
		v.push_back(1);
		return v;
	}

	if (is_even(num)) {
		string s = "";
		s = to_string(num);
		v.push_back(stoll(s.substr(0, s.size()/2)));
		v.push_back(stoll(s.substr(s.size()/2, s.size())));
		return v;
	}

	v.push_back(num*2024);
	return v;
}

ll dfs(ll num, int blinks)
{
	pair <ll, int> p;
	ll count = 0;
	vector <ll> v;

	if(blinks == 0)
		return 1;

	p.first = num;
	p.second = blinks;

	if(mmem.count(p))	
		return mmem[p];


	v = blink(num);

	FOR(i, v.size()) {
		count += dfs(v[i], blinks-1);
	}


	mmem[p] = count;

	return count;
}



int main(void)
{	
	ll t;
	vector <ll> v;
	ll ans = 0;

	while(cin >> t) {
		v.push_back(t);
	}

	FOR(i, v.size()) {
		ans += dfs(v[i], 75);
	};

	cout << ans;


	return 0;
}