#include "test.h"

void od12_impl(vector<int> input) {
	int res = 0;
	int len = input.size();
	int prev = -1;
	for (int i = 0; i < len; i++) {
		if (input[i] == 1) {
			if (prev < 0) {
				res += i / 2;
			} else {
				res += (i - prev - 2) / 2;//lionel��û��ɶ��˼
			}
			prev = i; //lionel��Ϊɶ�Ƿ������棿
		}
	}

	if (prev < 0) {
		res += (len + 1) / 2;
	} else {
		res += (len - prev + 1) / 2;
	}

	cout << res << endl;
}

void od12() {
	vector<int> inputs1{ 1,0,0,01 };
	od12_impl(inputs1);
	vector<int> inputs2{ 0,0,0 };
	od12_impl(inputs2);
}