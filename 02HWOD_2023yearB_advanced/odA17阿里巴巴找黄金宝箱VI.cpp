#include "test.h"

//lionel����ȷ��������ط���input�ǲ���ҲҪ��Ϊ����
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
	vector<int> input{ 2,5,2 };  //lionel�������ô���룬�Լ�д��
	stack<pair<int, int>> stk;
	vector<int>res(input.size(), -1);
	findNextBig(input, stk, res);
	if (stk.size() != 1)
		findNextBig(input, stk, res);  //lionel��Ϊɶ��ôд��

	string str;
	for (auto c : res) {
		str += to_string(c);
		str += ",";
	}
	cout << str << endl;
}

//zhihu���ҵĽ���