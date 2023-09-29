#include "test.h"

void od40_impl(vector<int> inputs, int k) {
	int res = 0;
	int first = 0, last = first + k;
	while (first < last) {
		if (last > inputs.size()) {
			break;
		}

		int sum = 0;
		sum = accumulate(inputs.begin() + first, inputs.begin() + last, sum);
		res = max(res, sum);
		first++; //lionel，会忘记这个++
		last++;
	}
	cout << res << endl;
}

void od40() {
	vector<int> inputs1{ 10,20,30,15,23,12 };
	int k1 = 3;
	od40_impl(inputs1, k1);
}