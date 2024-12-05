#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>

#define ll long long
#define FOR(_i,_n) for(int _i = 0; _i < _n; _i++)

/* Debuggers */
#define showvec(vec)			for(auto v:vec){cout << v << " ";} cout << endl;
#define showvecline(vec)		for(auto v:vec){cout << v << endl;} cout << endl;


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
	return 0;
}