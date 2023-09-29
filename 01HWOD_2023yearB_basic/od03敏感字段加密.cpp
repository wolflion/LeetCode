#include "test.h"

void od03_impl(int k,string input) {
	string d = input;
	while (k) {
		size_t pos = d.find("_");
		k--;
		d = d.substr(pos+1, d.size());
	}
	//cout << d << endl;
	size_t pos = d.find("_");
	string replace = d.substr(0, pos);
	
	pos = input.find(replace);
	string first = input.substr(0, pos);
	string last = input.substr(pos + replace.size(), input.size());
	string res = first + "******" + last;
	cout << res << endl;
}

void od03() {
	int k1 = 1;
	string input1{ "password_a12345678_timeout_100" };
	od03_impl(k1,input1);

	int k2 = 2;
	string input2{ "aaa_password_'a12345678'_timeout_100" };
	od03_impl(k2, input2);
}