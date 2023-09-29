#include "test.h"

void od58_impl(string input_src, string input_target) {
	regex r(input_target);
	smatch m; //lionel，这是个啥
	regex_search(input_src, m, r);
	int res = 0;
	if (m.size()) {
		res = m.position();
	} else
		res = -1;

	cout << res << endl;
}

void od58() {
	//输入 abcd，源字符串，b[cd]，目标字符串，
	//输出1,匹配字符相当于源字符串的位置
	string inputs_src1("abcd");
	string inputs_target1("b[cd]");
	od58_impl(inputs_src1, inputs_target1);
}


//https://wiki.amoscloud.com/zh/ProgramingPractice/NowCoder/Adecco/Topic0257