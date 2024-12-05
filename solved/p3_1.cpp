#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <regex>
#include <typeinfo>

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
// ([mul][(]([0,9]{1,3})[,]([0,9]{1,3})[)])

// ([)])
int main(void)
{
	regex rgx("(mul)([(])([0-9]{1,3})([,])([0-9]{1,3})([)])");
	regex rgx2("([0-9]{1,3})");
	string s = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))";
	string temp;
	smatch match, nums;

	ll x,y, ans=0;
	int t = 6;


	while(t--){
		getline(cin, s);

		string::const_iterator start(s.cbegin());
		while(regex_search(start, s.cend(), match, rgx)){
			temp = (string)match[0];
			regex_search(temp.cbegin(), temp.cend(), nums, rgx2);
			x = stoll(nums[0]);
			regex_search(nums.suffix().first, temp.cend(), nums, rgx2);
			y = stoll(nums[0]);

			ans += x*y;
			start = match.suffix().first;
		}

	}

	cout << ans;

	return 0;
}