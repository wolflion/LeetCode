/*
* 用数组代表每个人的能力。一个比赛活动要求参赛团队的最低能力值为N，每个团队可以由一人或者两人组成，且一个人只能参加一个团队，计算出最多可以派出多少只符合要求的队伍。

输入描述

第一行代表总人数，范围1-500000

第二行数组代表每个人的能力数组大小，范围1-500000。元素取值，范围1-500000

第三行数值为团队要求的最低能力值，范围1-500000

输出描述

最多可以派出的团队数量

用例
*/


#include "test.h"
void od35_impl(int sum, vector<int> input, int ability) {
	sort(input.begin(), input.end());
	int left = 0, right = input.size() - 1;
	int res = 0;
	while (left < right) {
		if (input[right] >= ability) {
			res++;
			right--;
		} else {
			if (input[right] + input[left] >= ability) {
				res++;
				right--;
				left++;
			} else
			{
				left++;
			}
		}
	}
	cout << res << endl;
}

void od35(){
	int sum1 = 5;
	vector<int>inputs1{ 3,1,5,7,9 };
	int ability1 = 8;
	od35_impl(sum1, inputs1, ability1);
}