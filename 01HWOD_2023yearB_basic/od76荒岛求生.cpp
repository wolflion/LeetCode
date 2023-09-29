#include "test.h"

void od76_impl(vector<int> input) {
	stack<int> s;
	int res = 0;
	for (auto c : input) {
		if (c > 0) {
			s.push(c);
		} else if (c < 0) {  //lionel��������������һ��������Ǹ�����һ����ô�죿s.top()ȡ����ֵ����c���У�Ҳ��Ҫ++�ģ�����ط�������׳��Ҫ�ж�һ�� s.top()
			if (s.top() + c != 0) {
				res++;
			}
			s.pop();
		}
	}
	if (s.size() > 0)
		res += s.size();
	cout << res << endl;
}

void od76() {
	vector<int> input1{ 5,10,8,-8,-5 };
	od76_impl(input1);
}