#include "test.h"

/*
* 题目描述

入职后，导师会请你吃饭，你选择了火锅。 火锅里会在不同时间下很多菜. 不同食材要煮不同的时间，才能变得刚好合适。 你希望吃到最多的刚好合适的菜，但你的
手速不够快，用 m 代表手速，每次下手捞菜后至少要过 m 秒才能再捞(每次只能捞一个)。 那么用最合理的策略，最多能吃到多少刚好合适的菜?

输入描述

第一行两个整数 n，m，其中 n 代表往锅里下的菜的个数，m 代表手速。 (1<n，m< 1000)

接下来有 n 行，每行有两个数 x，y 代表第 x 秒下的菜过 y 秒才能变得刚好合适。

(1<x,y< 1000)

输出描述

输出一个整数代表用最合理的策略，最多能吃到刚好合适的菜的数量.

用例
输入：
2 1   //2个菜，手速m  【下手抄菜后，需要m=1秒才能再捞】

1 2  //第x=1秒下过的菜，过y=2秒变得刚好
2 1

输出：
1     //表示吃到菜的数量？
*/

//问题1：采用什么样的贪心策略？【x+y是总时间】
void od_a07_impl(int n, int m, vector<pair<int, int>> input) {
	vector<int> val(n, 0);
	for (auto c : input) {
		val.push_back(c.first + c.second);
	}

	sort(val.begin(), val.end());  //贪心就是排序

	int res = 1;//lionel，第1个菜必吃
	int pre = 0;
	for (int i = 1; i < n; i++) {
		if (val[i] > val[pre] + m) {
			res++;
			pre = i;//lionel，这个pre，不就相当于n-1嘛
		}
	}
	cout << res << endl;
}

void od_a07(){
	int n1 = 2;//2个菜；，也就是inputs1的大小
	int m1 = 1;//手速，1秒后才能再捞
	vector<pair<int, int>> inputs1{ {1,2},{2,1} };
	od_a07_impl(n1, m1, inputs1);
}



//https://zhuanlan.zhihu.com/p/640498352