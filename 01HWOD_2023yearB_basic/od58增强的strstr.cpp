#include "test.h"

void od58_impl(string input_src, string input_target) {
	regex r(input_target);
	smatch m; //lionel�����Ǹ�ɶ
	regex_search(input_src, m, r);
	int res = 0;
	if (m.size()) {
		res = m.position();
	} else
		res = -1;

	cout << res << endl;
}

void od58() {
	//���� abcd��Դ�ַ�����b[cd]��Ŀ���ַ�����
	//���1,ƥ���ַ��൱��Դ�ַ�����λ��
	string inputs_src1("abcd");
	string inputs_target1("b[cd]");
	od58_impl(inputs_src1, inputs_target1);
}


//https://wiki.amoscloud.com/zh/ProgramingPractice/NowCoder/Adecco/Topic0257