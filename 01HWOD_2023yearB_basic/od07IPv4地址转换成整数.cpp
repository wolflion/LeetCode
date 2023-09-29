#include "test.h"

string num2hex(int num) {
	std::ostringstream ss;
	if (num >= 0 && num <= 255) {
		ss << std::hex <<setw(2) <<setfill('0') << num;//没有头文件iomainip，所以不能用setw
		//string tmp = ss.str();
	}
	return ss.str();
}

void od07_impl(string input) {
	vector<int> data;
	string res;
	int start = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '#') {
			//cout << start <<"," << i << endl;
			data.emplace_back(stoi(input.substr(start, i)));
			start = i+1;//lionel，这个地方写错了，应该是i+1是start，调试出来的
		}
	}
	data.emplace_back(stoi(input.substr(start, input.size())));
	for (auto i : data) {
		res += num2hex(i);
	}
	string newres("0x");
	newres += res;
	//cout << newres << endl;
	cout << stoll(newres, NULL, 16) << endl;//lionel，要stoll才行，stoi和stol都越界了
}

void od07() {
	string input1{ "128#0#255#255" };
	od07_impl(input1);//2147549183

	string input2{ "1#0#0#0" };
	od07_impl(input2);//16777216
}