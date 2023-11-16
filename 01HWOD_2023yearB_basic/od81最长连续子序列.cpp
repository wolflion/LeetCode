#include "test.h"

/*
* 有N个正整数组成的一个序列。给定整数sum，求长度最长的连续子序列，使他们的和等于sum，返回此子序列的长度如果没有满足要求的序列，返回-1。

输入描述

第一行输入是: N个正整数组成的一个序列

第二行输入是: 给定整数sum

输出描述

最长的连续子序列的长度

备注

输入序列仅由数字和英文逗号构成，数字之间采用英文逗号分隔
​序列长度: 1 <= N <= 200
输入序列不考虑异常情况


示例1：

输入

1,2,3,4,2

6

输出

3

说明

1,2,3和4,2两个序列均能满足要求，所以最长的连续序列为1,2,3，因此结果为3.
*/

void od81() {
	vector<int> inputs{ 1,2,3,4,2 };
	int target = 6;

	//这个输入，输出也是对的
#if 0
	vector<int> tmp_inputs;
	string str;
	cin >> str;
	replace(str.begin(), str.end(), ',', ' ');
	istringstream iss(str);
	int num;
	while (iss >> num) {
		tmp_inputs.push_back(num);
	}

	for (auto c : tmp_inputs) {
		cout << c << ",";
	}
#endif 
	int first = 0, last = 1;
	int res = 0, sum = 0;
	while (first < last) {
		if (last > inputs.size())
			break;

		for (int i = first; i < last; i++)
			sum += inputs[i];

		if (target == sum) {
			if (last - first > res) {
				res = last - first;
			}
			first = last;
			last++;
		} else if (target > sum) {
			last++;
		} else {
			first++;
		}
		sum = 0;
	}

	cout << res << endl;
}

//https://zhuanlan.zhihu.com/p/646675185