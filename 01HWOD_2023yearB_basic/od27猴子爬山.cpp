#include "test.h"
//https://blog.csdn.net/goldarmour/article/details/130790194

//参考过程，https://blog.csdn.net/m0_46672781/article/details/117441931  f(30)=f(29)+f(27）,上跳1级+f(29)+上调3级+(f27)
//lionel，我是不是思考得还是不对啊，20230904

void od27_impl(int input) {
	const int n = 100;//lionel，先定义为100吧
	int dp[n] = {0};
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	//dp[3]=2,dp[2]+dp[1] = 2;
	// dp[4] =dp[3]+dp[2]
	for (int i = 4; i <= input; i++) {  //lionel，这个点要从4开始，我写成了3了
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	cout << dp[input] << endl;
	//动态规划的公式不会算，dp[i]=dp[i-3]
#if 0
	while (input) {
		if (input == 3 || input == 1)
		{
			dp++;
		}
		od27_impl(input--);
	}
	cout << dp << endl;
#endif
}

void od27() {
	//一共50步台阶，大概有多少种解决方案，（一次是1部或者3部）
	int input1 = 50;
	od27_impl(input1);

	int input2 = 3;
	od27_impl(input2);//2

	int input3 = 10;
	od27_impl(input3);//28
}