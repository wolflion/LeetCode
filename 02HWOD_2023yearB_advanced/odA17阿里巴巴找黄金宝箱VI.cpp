#include "test.h"

//lionel，不确定，这个地方，input是不是也要改为引用
void findNextBig(vector<int> inputs, stack<pair<int, int>>& stk, vector<int>& res) {
	for (int i = 0; i < inputs.size(); i++) {
		int ele = inputs[i];
		while (1) {
			if (stk.size() == 0) {
				stk.push(make_pair(ele, i));
				break;
			} else {
				pair<int, int> val = stk.top();
				int peekEle = val.first;
				int peekIdx = val.second;
				if (ele > peekEle) {
					res[peekIdx] = ele;
					stk.pop();
				} else {
					stk.push(make_pair(ele, i));
					break;
				}
			}
		}
	}
}

void od_a17() {
	vector<int> input{ 2,5,2 };  //lionel，这个怎么输入，自己写个
	stack<pair<int, int>> stk;
	vector<int>res(input.size(), -1);
	findNextBig(input, stk, res);
	if (stk.size() != 1)
		findNextBig(input, stk, res);  //lionel，为啥这么写？

	string str;
	for (auto c : res) {
		str += to_string(c);
		str += ",";
	}
	cout << str << endl;
}

//zhihu上找的解题