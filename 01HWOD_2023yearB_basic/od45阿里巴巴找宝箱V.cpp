#include "test.h"

void od45_impl(vector<int> inputs, int k) {
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

void od45() {
	vector<int> inputs1{ 2,10,-3,-8,40,5 };
	int k1 = 4;
	od45_impl(inputs1, k1);
}