#include "test.h"

/*
* ��Ŀ����

����һ������ǰ׺��һ���ֵ䣬���������ǰ׺�ĵ���

��������

����ǰ׺+�ֵ䳤��+�ֵ�

�ֵ���һ�����򵥴�����

�����������Сд

�������

���а�����ǰ׺�ĵ��ʣ�������ʻ��������û���򷵻�-1
*/

void od_a25() {
	//����ǰ׺+�ֵ䳤��+�ֵ�  b 3 a b c  ���ֵ��Ǹ����򵥴����顿
	//���b  �����к��и�ǰ׺�ĵ��ʡ�

	//abc 4 a ab abc abcd
	//��� abc abcd��������ʻ������

	string in;
	vector<string> input;
	vector<string> res;

	while (cin >> in) {
		input.push_back(in);
		if (cin.get() == '\n')    //lionel������������ȷʵҪ��ʱ����һ��
			break;
	}
	string pre = input[0];
	int len = stoi(input[1]);

	while (len--) {
		//input.push_back(in);
		//lionel��Ҳ����ֱ�Ӵ���
		if (input[len].substr(0, pre.size()) == pre) {
			res.push_back(input[len]);
		}
	}


	if (res.empty()) {
		cout << "null" << endl;
	} else {
		for (auto c : res) {
			cout << c << endl;
		}
	}
}