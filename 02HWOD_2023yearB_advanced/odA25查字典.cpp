#include "test.h"

/*
* 题目描述

输入一个单词前缀和一个字典，输出包含该前缀的单词

输入描述

单词前缀+字典长度+字典

字典是一个有序单词数组

输入输出都是小写

输出描述

所有包含该前缀的单词，多个单词换行输出若没有则返回-1
*/

void od_a25() {
	//单词前缀+字典长度+字典  b 3 a b c  【字典是个有序单词数组】
	//输出b  【所有含有该前缀的单词】

	//abc 4 a ab abc abcd
	//输出 abc abcd，多个单词换行输出

	string in;
	vector<string> input;
	vector<string> res;

	while (cin >> in) {
		input.push_back(in);
		if (cin.get() == '\n')    //lionel，这个输入输出确实要花时间整一下
			break;
	}
	string pre = input[0];
	int len = stoi(input[1]);

	while (len--) {
		//input.push_back(in);
		//lionel，也可以直接处理
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