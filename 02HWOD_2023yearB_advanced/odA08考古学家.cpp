#include "test.h"

//这种做法是组合，不是排列
#if 0
void helper(vector<char> input, int index, string &cur, vector<string> &result) {
	//if (cur.size() == 3) {  //lionel，这个条件是不是写错了？ 【还是写成index==3?】
	if(index == 3){
		result.push_back(cur);
	} else if (index < 3) {
		helper(input, index + 1, cur, result); //不加入

		cur.push_back(input[index]);
		helper(input, index + 1, cur, result);
		cur.pop_back();
	}
}

void od_a08_impl(int n, vector<char> input) {
	vector<string> result;
	if (input.size() == 0) {
		//for_each(input.begin(), input.end(), []() {cout<<})  //lionel，foreach的写法，不太会
		for (auto s : result) {
			cout << s << endl;
		}
		return;
	}
	string cur;

	helper(input, 0, cur, result);  //lionel，下次这种写法就记住了

	for (auto s : result) {
		cout << s << endl;
	}
}
#endif

void swap08(vector<char> &input, int index, int i) {  //lionel，问题出在这个地方没写成引用，导致交换后没有变化
	if (index != i) {
		char tmp = input[index];
		input[index] = input[i];
		input[i] = tmp;
	}
}

void helper(vector<char> input, int index, vector<string>& result) {
	if (index == 3) {  //lionel，index==input.size()，其实就是3
		string cur;
		for (auto c : input) {
			cur.push_back(c);
		}
		result.emplace_back(cur);
	} else {
		for (int i = index; i < 3; ++i) {  //lionel，排列是交换顺序
			//cout << index << "," << i << endl;
			swap08(input, index, i);
			helper(input, index + 1, result);
			swap08(input, index, i);
		}
	}
}

void od_a08_impl(int n, vector<char> input) {
	//n个全排列，就需要n步，但第一个数字时，就有n个选择，生成第2个数字，就有n-1个选择.....
	vector<string> result;
	helper(input, 0, result);
	for (auto s : result) {
		cout << s << endl;
	}
}

void od_a08() {
	int n1 = 3;  //碎石个数
	vector<char> input1{ 'a','b','c'};
	od_a08_impl(n1, input1);
}