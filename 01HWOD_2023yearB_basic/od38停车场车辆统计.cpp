#include "test.h"

string subString(string src, string oldStr, string newStr) {
	string dest_str = src;
	string::size_type pos = 0;
	while ((pos = dest_str.find(oldStr)) != string::npos) {
		dest_str.replace(pos, oldStr.size(), newStr);
	}
	return dest_str;
}

void od38_impl(vector<int> input) {
	string res_helper;
	for (auto n : input) {
		res_helper += to_string(n);
	}

#if 0
	//auto val = res_helper.find("111");
	//replace_all(res_helper, "111", "x");

	//string tmp1 = res_helper.replace(res_helper.find("111"),3,"x"); //lionel，这个地方没找到111，返回的位置不对，没法替换
	//string tmp2 = tmp1.replace(tmp1.find("11"), 2, "x");
	string tmp3 = res_helper.replace(res_helper.find("1"), 1, "x"); //lionel，这里只把第1个输出来了，其实不对
#endif

	string tmp1 = subString(res_helper, "111", "x");
	string tmp2 = subString(tmp1, "11", "x");
	string tmp3 = subString(tmp2, "1", "x");
	int res = 0;
	for (auto c : tmp3) {
		if (c == 'x')
			res++;
	}

	cout << res << endl;
}

void od38() {
	vector<int> inputs1{ 1,0,1 };
	od38_impl(inputs1);
}