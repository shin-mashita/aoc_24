#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

#define ll long long
#define FOR(_i,_n) for(int _i = 0; _i < _n; _i++)

/* Debuggers */
#define showstrvec(svec)		for(string s:svec){cout << s << endl;}
#define showvec(vec)			for(auto v:vec){cout << v << " ";} cout << endl;

using namespace std;

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

bool is_correct(vector<vector<ll>> v, vector<ll> u)
{
	for(int i = 0; i < u.size(); i++){
		for(int j = 0; j < v.size(); j++){
			if (u[i]==v[j][1]) {
				for (int k = i; k < u.size(); k++){
					if(v[j][0]==u[k])
						return false;
				}
			}
		}
	}

	return true;
}

vector <ll> try_correct(vector<vector<ll>> v, vector<ll> u)
{
	ll temp;
	for(int i = 0; i < u.size(); i++){
		for(int j = 0; j < v.size(); j++){
			if (u[i]==v[j][1]) {
				for (int k = i; k < u.size(); k++){
					if(v[j][0]==u[k]){
						temp = u[k];
						u.erase(u.begin() + k);
						u.insert(u.begin() + i, temp);
						return u;
					}
				}
			}
		}
	}

	return u;
}

int main(void)
{
	ll t = 1176;
	ll it = 0;
	ll ans = 0;
	string s;
	vector<vector <ll>> v(1176);
	vector <ll> u;
	bool flag = false;

	while (t--) {
		getline(cin, s);
		v[it++] = _tokenize(s, '|');
	}

	getline(cin,s); //blankline
	t = 190;
	it = 0;

	while(t--) {
		flag = false;
		getline(cin, s);
		u = _tokenize(s, ',');

		while(!is_correct(v,u)){
			flag = true;
			u = try_correct(v, u);
		}

		if (flag)
			ans += u[u.size()/2];
	}

	cout << ans;
	return 0;
}