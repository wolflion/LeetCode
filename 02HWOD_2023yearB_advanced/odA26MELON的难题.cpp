/*
* MELON��һ�Ѿ������껨ʯ(����Ϊn����������)��׼���͸�S��W��MELONϣ���͸����˵��껨ʯ����һ�£��������һ�������MELONȷ���Ƿ��ܽ��껨ʯƽ�����䡣

��������

��1������Ϊ�껨ʯ����: n��0 < n < 31.

��2������Ϊ�ո�ָ�ĸ��껨ʯ����: m[0] m[1] ..... m[n - 1]�� 0 < m[k] < 1001

����Ҫ�����쳣����������

�������

������Ծ��֣��ӵ�ǰ�껨ʯ�������ó����飬����ʹ���ѵ��������:������ܾ��֣������-1��
*/

#include "test.h"

void od_a26_impl(int m, vector<int> input) {
	int sum = 0;
	sum = accumulate(input.begin(), input.end(), sum);

	sort(input.begin(), input.end(),greater<int>()); //�ӵ���С��

	vector<int> val;
	int target = sum / 2;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] <= target) {
			target -= input[i];
			val.push_back(input[i]);  //lionel���ҵ������⣬��ֻ���һ�֣���Ŀ��˼Ӧ�������г������ҳ�����Ȼ������С�����
		}
	}

	int res = min(input.size() - val.size(), val.size());
	cout << res << endl;
}
void od_a26() {
	int m1 = 4;
	vector<int> inputs1{ 1,1,2,2 };
	//od_a26_impl(m1, inputs1);  //2

	int m2 = 10;
	vector<int> inputs2{ 1,1,1,1,1,9,8,3,7,10 };
	od_a26_impl(m2, inputs2);  //3������3���������4
}


//��Ŀ���ӣ�https://zhuanlan.zhihu.com/p/643853401