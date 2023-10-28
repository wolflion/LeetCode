/*
* MELON有一堆精美的雨花石(数量为n，重量各异)，准备送给S和W。MELON希望送给俩人的雨花石重量一致，请你设计一个程序帮MELON确认是否能将雨花石平均分配。

输入描述

第1行输入为雨花石个数: n，0 < n < 31.

第2行输入为空格分割的各雨花石重量: m[0] m[1] ..... m[n - 1]， 0 < m[k] < 1001

不需要考虑异常输入的情况。

输出描述

如果可以均分，从当前雨花石中最少拿出几块，可以使两堆的重量相等:如果不能均分，则输出-1。
*/

#include "test.h"

void od_a26_impl(int m, vector<int> input) {
	int sum = 0;
	sum = accumulate(input.begin(), input.end(), sum);

	sort(input.begin(), input.end(),greater<int>()); //从到到小排

	vector<int> val;
	int target = sum / 2;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] <= target) {
			target -= input[i];
			val.push_back(input[i]);  //lionel，我的有问题，我只算出一种，题目意思应该是所有场景都找出来，然后找最小的情况
		}
	}

	int res = min(input.size() - val.size(), val.size());
	cout << res << endl;
}
void od_a26() {
	int m1 = 4;
	vector<int> inputs1{ 1,1,2,2 };
	//od_a26_impl(m1, inputs1);  //2

	int m2 = 10;
	vector<int> inputs2{ 1,1,1,1,1,9,8,3,7,10 };
	od_a26_impl(m2, inputs2);  //3，答案是3，我输出的4
}


//题目链接：https://zhuanlan.zhihu.com/p/643853401