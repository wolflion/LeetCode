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
		//���Ƕ����ת�Ʒ��̣�lionel���ҳ��ģ���û�뵽
		dp[i] = max(dp[i - 1], dp[i - 1] - input[i - 1].second + input[i].first + input[i].second);
	}
	cout << dp[n - 1] << endl;
}

void od_a12() {
	//vector<std::pair<int,int>,std::allocator<std::pair<int,int> > > ���Ǳ���ģ��
	//https://www.acwing.com/community/content/621232/  ���˼�Ҳ�������
	int m1 = 1, n1 = 1;
	vector<pair<int, int>>inputs1 = { {2,2} };// { make_pair(2, 2) };     //lionel������ط��������Ұ����У�д����һ��ȥ�ˣ���Ϊ����һ��int���͵��µı���
	od_a12_impl(m1, n1, inputs1);  //4�����4

	//lionel�������ˣ��ҵ����������Ƶ�������
#if 0
	int m2 = 2, n2 = 2;  //m2��ʾ2������n2=2����ʾ���е�һ��������Ҫ2��������  
	vector<pair<int, int>>inputs2 = { {2,2} };// { make_pair(2, 2) };   
	od_a12_impl(m2, n2, inputs1);
#endif
}

//�ο���https://www.nowcoder.com/discuss/470704369432797184  