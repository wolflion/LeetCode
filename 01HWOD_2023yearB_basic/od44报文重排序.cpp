#include "test.h"

//https://blog.csdn.net/Ryan_Garr/article/details/129677277
struct cmp {
	bool operator()(const int &num1, const int &num2) const {  //lionel，这个都需要const，不管是参数，还是 函数，都要是const  【这个还是会报错，const _Tky转成const int】
		return num1 > num2;
	}
};

void od44_impl(int num, vector<string>input) {
	//map<string, int, cmp> strInt;
	map<int,string> intStr;
	for (auto c : input) {
		string s1 = c;
		string s2 = c;
		regex reg1 ("[0-9]") ;
		regex reg2("[a-zA-Z]") ;
		string value = regex_replace(s1, reg1, "");
		string num = regex_replace(s2, reg2, "");
		//cout << value << "," << num << endl;
		//strInt.insert(make_pair(value, stoi(num)));
		intStr.insert(make_pair(stoi(num), value));
	}

	string res;
	//for (auto c : strInt) {
	for (auto c : intStr) {
		res += c.second;
		res += " ";
	}
	cout << res << endl;
}

void od44() {
	int num1 = 4;
	vector<string>inputs1{ "rolling3","stone4","like1","a2" };
	od44_impl(num1, inputs1);
}