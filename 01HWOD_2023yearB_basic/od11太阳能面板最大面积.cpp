//https://zhuanlan.zhihu.com/p/645324221

#include "test.h"

void od11_impl(vector<int> input) {
	int res = 0;
	int first = 0, last = input.size() - 1;
	while (first < last) {
		//lionel，怎么移呢，【琢磨出来了，哪个短，哪个移
		int tmp = min(input[first], input[last]);
		//cout << tmp << endl;
		if (tmp == input[first]) {
			first++;
		}
		if (tmp == input[last]) {
			last--;
		}
		int area = (last - first + 1) * tmp; //lionel，这个地方是不是得能+1才行
		res = max(res, area);
	}
	cout << res << endl;
}


void od11() {
	vector<int> inputs{ 10,9,8,7,6,5,4,3,2,1 };
	od11_impl(inputs);
}