#include "test.h"

void od04_impl(vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		int first = accumulate(nums.begin(), nums.begin() + i,0);
		int last = accumulate(nums.begin()+i+1, nums.end(), 0);
		//cout << first << "," << last << endl;
		if (first == last) {
			cout << i << endl;
		}
	}
	//²»È»£¬·µ»Ø-1
}

void od04() {
	vector<int>nums{ 2,5,-1,8,6 };
	od04_impl(nums);
}