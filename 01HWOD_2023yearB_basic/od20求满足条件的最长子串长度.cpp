/*
����һ���ַ�����ֻ������ĸ�����֣���Ҫ���ҳ��ַ����е��(����)�Ӵ��ĳ��ȣ��ַ���������������Ӵ����Ӵ�Ҫ��:

1��ֻ���� 1 ����ĸ(a~z,A~Z)���������������:

2����ĸ�������Ӵ��е�����λ��;

����Ҳ�������Ҫ����Ӵ�����ȫ����ĸ��ȫ�����֣��򷵻�-1��

��������

�ַ���(ֻ������ĸ������)

�������

�Ӵ��ĳ���

����
*/

#include "test.h"

#if 0
//����������Ӵ��ĳ��ȣ��ַ������������Ӵ�
void od20_impl(string input) {
	int first = 0, last = 1;
	while (first < last) {
		if (last > input.size())
			break;
		
		if (!isdigit(input[first])) {
			if (!isdigit(input[last])) {
				last++;
			}
		} else {
			if (isdigit(input[last])) {
				first = last;
				last++;
			}
		}
	}
}
#endif

#if 0
void od20_impl(string input) {
	int sum = 0;
	int first = 0, last = first + 1;
	while (first < last) {
		if (last > input.size())
			break;

		if (isalpha(input[first++])) {
			last++;
			sum++;
		} else {
			sum = 0;
		}
	}

	cout << sum << endl;
}
#endif

bool check(string str) {
	regex r("[0-9]");
	string replace = regex_replace(str,r, "");
	//cout << str << "," << replace << endl;
	/*
	*
	ab, ab 
	bC1, bC
	C124, C
��124A, ����
124ACb, ACb
24ACb, ACb
4ACb, ACb 
ACb, ACb
	*/
	return replace.size() != str.size() && replace.size() <= 1; //lionel�����Ҳû��
}

void od20_impl(string input) {
	int left = 0, right = 1;
	int res = -1;
	while (left < input.size() && right < input.size()) {
		right++;
		string subStr = input.substr(left, right); //lionel�������ɶ��˼
		//cout << subStr << endl;
		if (check(subStr)) {
			res = max(res, (int)subStr.size());
		} else {
			left++;
		}
	}
	cout << res << endl;
}

void od20() {
	string input1 = "abC124ACb";
	od20_impl(input1);
}


//https://zhuanlan.zhihu.com/p/645553376

//https://wiki.amoscloud.com/zh/ProgramingPractice/NowCoder/Adecco/Topic0138