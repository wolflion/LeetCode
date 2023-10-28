#include "test.h"

/*
* 某组织举行会议，来了多个代表团同时到达，接待处只有一辆汽车，可以同时接待多个代表团，为了提高车辆利用率，请帮接待员计算可以坐满车的接待方案，输出方案数量。

约束:

1.一个团只能上一辆车，并且代表团人数(代表团数量小于30，每人代表团人数小于30)小于汽车容量(汽车容量小于100)

2.需要将车辆坐满

输入描述

第一行 代表团人数，英文逗号隔开，代表团数量小于30，每个代表团人数小于30

第二行 汽车载客量，汽车容量小于100

坐满汽车的方案数量

如果无解输出0
*/

//如果求所有值，那么就用回溯（组合），求最多数量，可以用动规

void od_a19_impl(vector<int> input) {
	//想法是用二维数组，空间大小正好是数量，不过又回到 回溯上，当前的数组正好为10，加入到result里去


	//lionel，核心问题是没有想到如何构建 表达式
	sort(input.begin(), input.end());
	vector<vector<int>> dp(input.size(), vector<int>(10+1, 0));

	//第一列初始化为1【原因，空间为0时，不论可选元素范围是多少，只有一种方案-不选取任何元素】
	for (int i = 0; i < input.size(); i++) {
		dp[i][0] = 1;
	}

	dp[0][input[0]] = 1; //多了一列的原因？

	for (int i = 1; i < input.size(); i++) {
		for (int j = 0; j < 10 + 1; j++) {
			if (j - input[i] >= 0) {//10与input[i]逐个比较的过程？
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - input[i]];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[input.size() - 1][10] << endl;
}

//作者dp[i][j]的思路：i表示input中的0到i的元素，j表示客车容纳的人数  dp[i][j]表示限定的几种方法

void od_a19() {
	vector<int> input1{ 5,4,2,3,2,4,9 };
	int target = 10;
	//输出4，坐满汽车的解决方案数量，【lionel,相当于最多值】，想了一下，只等是等于10，它应该是组合，2+3+5；4+4+2；2+3+5,2+4+4
	od_a19_impl(input1);
}

//https://www.nowcoder.com/discuss/526649664700018688

//https://zhuanlan.zhihu.com/p/644931774，这个是python，没懂