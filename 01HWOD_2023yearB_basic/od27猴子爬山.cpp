#include "test.h"
//https://blog.csdn.net/goldarmour/article/details/130790194

//�ο����̣�https://blog.csdn.net/m0_46672781/article/details/117441931  f(30)=f(29)+f(27��,����1��+f(29)+�ϵ�3��+(f27)
//lionel�����ǲ���˼���û��ǲ��԰���20230904

void od27_impl(int input) {
	const int n = 100;//lionel���ȶ���Ϊ100��
	int dp[n] = {0};
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	//dp[3]=2,dp[2]+dp[1] = 2;
	// dp[4] =dp[3]+dp[2]
	for (int i = 4; i <= input; i++) {  //lionel�������Ҫ��4��ʼ����д����3��
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	cout << dp[input] << endl;
	//��̬�滮�Ĺ�ʽ�����㣬dp[i]=dp[i-3]
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
	//һ��50��̨�ף�����ж����ֽ����������һ����1������3����
	int input1 = 50;
	od27_impl(input1);

	int input2 = 3;
	od27_impl(input2);//2

	int input3 = 10;
	od27_impl(input3);//28
}