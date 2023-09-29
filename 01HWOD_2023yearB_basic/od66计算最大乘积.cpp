/*
* 给定一个元素类型为小写字符串的数组，请计算两个没有相同字符的元素长度乘积的最大值.

如果没有符合条件的两个元素，返回 0。

输入描述

输入为一个半角逗号分隔的小写字符串的数组，2<= 数组长度<=100，0< 字符串长度<= 50

输出描述

两个没有相同字符的元素长度乘积的最大值

用例
*/

#include "test.h"

//终于读懂题目了，只有iwdvpbn，与hk没有相同的字符，  hk与kadgpf有相同的k
#if 0

int strLen(string s) {
	int max = 0;
	int first = 0, last = 1;
	while (first < last) {
		if (last > s.size())
			break;

		if (s[first] != s[last]) {
			last++;
			max = last - first > max ? last - first : max;
		}
		first++;
		last++;
	}
	return max;
}

void od66_impl(vector<string> inputs) {
	vector<int> res;
	//两层for循环
	for (int i = 0; i < inputs.size(); i++) {
		for (int j = i + 1; j < inputs.size(); j++) {
			for (int k = 0; k < inputs[i].size(); k++) {
				if (inputs[j].find(inputs[i][k])!=inputs[j].npos) {
					cout << "equal" << endl;
					break;
				} 
			}
			res.emplace_back(inputs[i].size());
			res.emplace_back(inputs[j].size());
		}
	}

	for (auto c : res) {
		cout << c << endl;
	}
}
#endif

int mul(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				return 0;
			}
		}
	}
	return s1.size() * s2.size();
}

void od66_impl(vector<string> inputs) {
	int res=0;
	for (int i = 0; i < inputs.size() - 1; i++) {
		res = max(res, mul(inputs[i], inputs[i + 1]));
	}
	cout << res << endl;
}

void od66() {
	vector<string> inputs1{ "iwdvpbn","hk","iuop","iikd","kadgpf" };  //5个字符中,iwdvpbn与hk没有相同字符，与其它的有相同字符
	od66_impl(inputs1);  //lionel，还是用2层for循环算的
}

//https://blog.csdn.net/jidanzai666/article/details/128348739  参考，自己还是有思路的，只不过没调试出来而已