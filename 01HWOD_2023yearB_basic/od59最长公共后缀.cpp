/*
* 编写一个函数来查找 字符串数组 中的最长公共后缀如果不存在公共后缀，返回固定字符串:@Zero.

补充说明:

1、字符串长度范围:[2,1000];



2、字符串中字符长度范围为[1，126]

输入描述

["abc" "bbc" c]

输出描述

"c"



示例1：

输入:

["abc","bbc","c"]

输出:

"c"

说明:

返回公共后缀: c
*/

#include "test.h"

void od59_impl(vector<string> input) {
	for (auto &s : input) {
		reverse(s.begin(), s.end());
	}
	string res;

	for (int i = 0; input[0][i]; ++i) {  //lionel，取第1组的第i个
		for (int j = 1; j < input.size(); j++) {//从第2组开始取，并比较i个
			if (input[0][i] != input[j][i]) {
				res = input[0].substr(0, i);
				if(!res.empty()){
					cout<<res<<endl;
				}else{
					cout << "@Zero" << endl;
				}
				return;
			} 
		}
	}
	cout << input[0] << endl;
}

void od59() {
	//lionel，核心，先反转，还是再求最长公共前缀，主要是后缀的话，没法统计哪个越界？
	vector<string> inputs1{ "abc","bbc","c" };
	od59_impl(inputs1);
	vector<string> inputs2{ "aa","bb","cc" };
	od59_impl(inputs2);
}

