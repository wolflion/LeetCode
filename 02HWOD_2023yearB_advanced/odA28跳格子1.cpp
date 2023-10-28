#include "test.h"

//n个隔子，任意起跳，不能连续，不能回头，计算能够得到的最高分数
//lionel，递归表达式，f(i) = 至少是max{f(i-2)+cur，f(i-1)}，第0个是0，第1个是当前，f(2)也是自己，f(3)就是

void od_a28_impl(vector<int> input) {
	//本来写的是res，vector<int> res;

	vector<int> dp(input.size()); //lionel，这个地方不写个dp(input.size())还会crash掉，要注意下
#if 0
	if (input.size() == 1 || input.size() == 2) {
		cout << input[input.size()] << endl;
		res[input.size()] = input[input.size() - 1];
	}
#endif
	//sort(input.begin(), input.end());

	dp[0] = input[0];
	if (input.size() > 1) {
		dp[1] = max(input[0], input[1]);
	}

	//这是人家写的，可以参考下
#if 0
	if (input.size() >= 1) {
		dp[0] = input[0];
	}
	
	if (input.size() >=2) {
		dp[1] = max(input[0], input[1]);
	}
#endif	

	//lionel，动态规划，怎么调整i变化的？
	for (int i = 2; i < input.size(); i++) {
		dp[i] = max(dp[i - 2] + input[i], input[i - 1]);
	}

	sort(dp.begin(), dp.end());  //lionel，这个地方是不是要排个序  [人家用的map类型，说明已经排过序了]

	cout << dp[input.size() - 1] << endl;  //lionel，否则会啥非是最后一个是最大值，尤其在这个条件下
}

void od_a28() {
	vector<int> inputs1{ 1,2,3,1 }; //4
	od_a28_impl(inputs1);
	vector<int> inputs2{ 2,7,9,3,1 }; //12
	od_a28_impl(inputs2);
	vector<int> inputs3{ 9,1,2,9 };//18
	od_a28_impl(inputs3);
}


//https://zhuanlan.zhihu.com/p/647057044