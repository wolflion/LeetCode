/*
给定一个字符串，只包含字母和数字，按要求找出字符串中的最长(连续)子串的长度，字符串本身是其最长的子串，子串要求:

1、只包含 1 个字母(a~z,A~Z)，其余必须是数字:

2、字母可以在子串中的任意位置;

如果找不到满足要求的子串，如全是字母或全是数字，则返回-1。

输入描述

字符串(只包含字母和数字)

输出描述

子串的长度

用例
*/

#include "test.h"

#if 0
//最长（连续）子串的长度，字符串本身就最长的子串
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
С124A, СА
124ACb, ACb
24ACb, ACb
4ACb, ACb 
ACb, ACb
	*/
	return replace.size() != str.size() && replace.size() <= 1; //lionel，这个也没懂
}

void od20_impl(string input) {
	int left = 0, right = 1;
	int res = -1;
	while (left < input.size() && right < input.size()) {
		right++;
		string subStr = input.substr(left, right); //lionel，求这个啥意思
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