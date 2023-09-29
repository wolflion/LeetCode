#include "test.h"

void od52_impl(int num, vector<int> input) {
	int total = 0;
	total = accumulate(input.begin(), input.end(), total);

	int res = 0;
	int sum = 0;

	for (int i = 0; i < input.size(); i++) {
		sum += input[i];
		int left = sum, right = total - sum;
		res = max(res, abs(right - left));
	}
	cout << res << endl;
}

void od52() {
	int num1 = 6;
	vector<int> inputs1{ 1,-2,3,4,-9,7 };
	od52_impl(num1, inputs1);
}