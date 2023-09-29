/*
* 给定一个数组X和正整数K，请找出使表达式X[i] - x[i +1] ... - X[i + K  1]，结果最接近于数组中位数的下标i，如果有多个i满足条件，请返回最大的i。

其中，数组中位数:长度为N的数组，按照元素的值大小升序排列后，下标为N/2元素的值

补充说明:

1.数组X的元素均为正整数;

2.X的长度n取值范围: 2<= n <= 1000;

3.K大于0且小于数组的大小;

4.i的取值范围: 0 <=i < 1000;

5.题目的排序数组X[N]的中位数是X[N/2].

示例1

输入:

[50,50,2,3],2

输出:

1

说明:

1、中位数为50: [50,50,2,3]升序排序后变成[2,3,50,50]，中位数为下标4/2=2的元素50;

2、计算结果为1: X[50,50,2,3]根据题目计算X[i] - ...- X[i + K- 1]得出三个数

0 (X[0]-X[1]= 50 -50) 、

48 (X[1]-X[2] = 50 -2)

-1 (X[2]-X[3]= 2-3) ，

其中48最接近50，因此返回下标1 
*/

#include "test.h"

bool cmp56(pair<int, int> m1, pair<int, int> m2) {
	if (m1.first < m2.first)
		return 1;
	else if (m1.first == m2.first && m1.second < m2.second) {
		return 1; //如果有多个i满足条件，请返回最大的i
	}

	return 0;
}

//题目看懂了，就是用 x[i] 一直到到x[i+(k-1)]，相当于是固定滑动窗口的起始位置
void od56_impl(vector<int> input, int k) {
	vector<int> tmp{ input };
	sort(tmp.begin(), tmp.end());
	int middle = tmp[tmp.size() / 2];
	//cout << middle << endl;

	int diff = 0;
	int left = 0, right = left + k - 1;
	int gap = 0;
	vector<pair<int, int>> res;
	while (left < right) {
		if (right > input.size() - 1)
			break;
		
		int num = right - left;
		while (num) {
			diff = input[left] - input[left + num];
			//cout << diff << endl;
			num--;
		}
		//sum = accumulate(input.begin() + left, input.begin() + right, sum);

		gap = abs(diff - middle);

		res.emplace_back(make_pair(gap, left));

		left++;
		right++;
	}

	sort(res.begin(), res.end(), cmp56);

#if 0
	for (auto c : res) {
		cout << c.second << endl;
	}
#endif
	cout << res[0].second << endl;

}

void od56() {
	int k1 = 2;
	vector<int> inputs1{ 50,50,2,3 };
	od56_impl(inputs1, k1);
}