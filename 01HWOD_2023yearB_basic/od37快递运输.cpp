#include "test.h"

void od37_impl(vector<int> input, int target) {
	sort(input.begin(), input.end());
	int first = 0, last = first + 1;
	int sum = 0;
	sum += input[first];
	int res = 0;
	while (first < last) {
		if (sum >= target) {
			res = (last - first)-1;
			break;
		}

		sum += input[last];
		last++;
	}
	cout << res << endl;
}

void od37() {
	vector<int> inputs1{ 5,10,2,11 };
	int target1 = 20;
	od37_impl(inputs1, target1);
}