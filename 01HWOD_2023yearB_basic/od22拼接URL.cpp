#include "test.h"

//ÓÃ,·Ö¸î
string check(string value) {
	string str;
	if (value[0] != '/')
		str = "/" + value;
	if (value[value.size()] == '/' && value[value.size() - 1] == '/')
		str = value.substr(0, value.size() - 1);

	if (value[value.size()] == '/') {
		str = value.substr(0, value.size() - 1);
	}

	if (str.size()>0) {
		return str;
	}
	return value;
}

void od22_impl(string input) {
	size_t pos = input.find(",");
	if (pos != input.npos) {
		string first = input.substr(0, pos);
		string last = input.substr(pos+1, input.size());
		string a = check(first);
		string b = check(last);
		string tmp = check(first) + check(last);
		cout << tmp << endl;
	}
}

void od22() {
	string input1 = "acm,/bb";
	od22_impl(input1);
	string input2 = "/abc/,/bcd";
	od22_impl(input2);
	string input3 = "/acd,bef";
	od22_impl(input3);
}