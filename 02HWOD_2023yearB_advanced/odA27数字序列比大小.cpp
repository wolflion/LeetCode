#include "test.h"

/*
* ����
3  //�������еĳ���
4,8,10  //A�ĸ�������
3,6,4   //B�ĸ�������
���
3   //AӮB�ķ���
*/

bool cmp27(vector<int> &m1, vector<int> &m2) {  //lionel��Ҫ��� ���� ��ʽ����Ȼ�ֲ���������Ӱ��input�ı仯

	sort(m1.begin(), m1.end());  //lionel����ΪĬ���Ǵ�С�������У����Ƚϵ�ʱ��Ҳ������Ƚ�
	sort(m2.begin(), m2.end());
#if 0
	for (int i = 0; i < 3; i++) {
		if (m2[i] > m1[i]) {
			return 1;
		} else {
			return 0;
		}
	}
#endif
	return 0;
}

void od_a27_impl(int size, vector<vector<int>> input) {
	sort(input.begin(), input.end(), cmp27);
	int res=0;
	for (size_t i = 0; i < input.size()-1; i++) {
		for (int j = 0; j < size; j++) {
			if (input[i][j] > input[i + 1][j])
				res++;
		}
	}

	cout << res << endl;
}

void od_a27() {
	int size1 = 3;
	vector<vector<int>> input1{ {4,8,10},{3,6,4} };
	od_a27_impl(size1, input1);
}