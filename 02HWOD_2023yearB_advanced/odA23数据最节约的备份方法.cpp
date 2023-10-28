#include "test.h"

void od_a23_impl(vector<int> input) {
	sort(input.begin(), input.end());

	int left = 0, right = input.size() - 1;
	int target = 500;
	int res = 0;

	while (left < right) {
		if (input[right] > target) {
			right--;
		} else if (input[right] == target) {
			right--;
			res++;
		} else if (input[right] + input[left] <= target) {
			res++;
			right--;
			left++;
		}
	}

	cout << res << endl;
}

void od_a23() {
	vector<int> input1{ 100,500,300,200,400 }; //3
	od_a23_impl(input1);
	vector<int> input2{ 1,100,200,300 };  //2
	od_a23_impl(input2);
	vector<int> input3{ 1,100,200,200,200,300 };//3
	od_a23_impl(input3);
}