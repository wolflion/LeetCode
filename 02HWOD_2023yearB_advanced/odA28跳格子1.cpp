#include "test.h"

//n�����ӣ������������������������ܻ�ͷ�������ܹ��õ�����߷���
//lionel���ݹ���ʽ��f(i) = ������max{f(i-2)+cur��f(i-1)}����0����0����1���ǵ�ǰ��f(2)Ҳ���Լ���f(3)����

void od_a28_impl(vector<int> input) {
	//����д����res��vector<int> res;

	vector<int> dp(input.size()); //lionel������ط���д��dp(input.size())����crash����Ҫע����
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

	//�����˼�д�ģ����Բο���
#if 0
	if (input.size() >= 1) {
		dp[0] = input[0];
	}
	
	if (input.size() >=2) {
		dp[1] = max(input[0], input[1]);
	}
#endif	

	//lionel����̬�滮����ô����i�仯�ģ�
	for (int i = 2; i < input.size(); i++) {
		dp[i] = max(dp[i - 2] + input[i], input[i - 1]);
	}

	sort(dp.begin(), dp.end());  //lionel������ط��ǲ���Ҫ�Ÿ���  [�˼��õ�map���ͣ�˵���Ѿ��Ź�����]

	cout << dp[input.size() - 1] << endl;  //lionel�������ɶ�������һ�������ֵ�����������������
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