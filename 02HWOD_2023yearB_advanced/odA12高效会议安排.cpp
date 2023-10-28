#include "test.h"

void od_a12_impl(int m, int n, vector<pair<int, int>>& input) {
	sort(input.begin(), input.end(), [&](auto& i1, auto& i2) {return i1.first >= i2.first; });

#if 0
	int len = 0;
	int maxnum = 0;
#endif

	int len = input.size();
	vector<int> dp(len);
	dp[0] = input[0].first + input[0].second;
	for (int i = 1; i < len; i++) {
		//这是动规的转移方程，lionel，我抄的，我没想到
		dp[i] = max(dp[i - 1], dp[i - 1] - input[i - 1].second + input[i].first + input[i].second);
	}
	cout << dp[n - 1] << endl;
}

void od_a12() {
	//vector<std::pair<int,int>,std::allocator<std::pair<int,int> > > 不是变量模板
	//https://www.acwing.com/community/content/621232/  【人家也有这个错】
	int m1 = 1, n1 = 1;
	vector<pair<int, int>>inputs1 = { {2,2} };// { make_pair(2, 2) };     //lionel，这个地方是由于我把这行，写到上一行去了，认为它是一个int类型导致的报错
	od_a12_impl(m1, n1, inputs1);  //4，输出4

	//lionel，代表了，我的输入输出设计得有问题
#if 0
	int m2 = 2, n2 = 2;  //m2表示2组任务，n2=2，表示其中的一组任务，需要2个机器，  
	vector<pair<int, int>>inputs2 = { {2,2} };// { make_pair(2, 2) };   
	od_a12_impl(m2, n2, inputs1);
#endif
}

//参考，https://www.nowcoder.com/discuss/470704369432797184  