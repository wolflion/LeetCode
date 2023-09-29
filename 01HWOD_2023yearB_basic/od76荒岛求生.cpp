#include "test.h"

void od76_impl(vector<int> input) {
	stack<int> s;
	int res = 0;
	for (auto c : input) {
		if (c > 0) {
			s.push(c);
		} else if (c < 0) {  //lionel，现在是正数多一个，如果是负数多一个怎么办？s.top()取不到值，但c还有，也是要++的，这个地方不够健壮，要判断一下 s.top()
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