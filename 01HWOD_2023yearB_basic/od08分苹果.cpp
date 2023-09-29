#include "test.h"

void od08_impl(int num, vector<int> input) {   //lionel，可能最开始题目都理解错了
	//lionel，问题是，1个数的二进制怎么算？ 跟谁去异或？

	// 先排个序？lionel，其实无所谓
	sort(input.begin(), input.end());

	int res = 0;

	for (int i = 1; i < input.size()-1; i++) { //lionel，这个地方为何是从1开始？还有只到input.size()-1 ？
		int binA = 0, binB = 0;
		int sumA = 0, sumB = 0;  //lionel，这2处赋初值，是不是只能在for里面赋值，啥意思？
		//left
		for (int left = 0; left < i; left++) {
			binA ^= input[left];
			sumA += input[left];
		}

		//right
		for (int right = i; right < input.size(); right++) {
			binB ^= input[right];
			sumB += input[right];
		}

		if (binA == binB) {
			res = max(sumA, sumB);
		}
	}
	cout << res << endl;
	
}

void od08() {
	int num1 = 3;
	vector<int> inputs1{ 3,5,6 };
	od08_impl(3, inputs1);
}