#include "test.h"

bool cmp39(pair<int, int> m1, pair<int, int> m2) {
	if (m1.second < m2.second)  //lionel����Ϊ�����ظ���Ԫ�أ��Ҿʹ�����д��=�ţ��ᷢ�����Դ���if (m1.second <= m2.second)�����ֲ�֧��
		return 1;
	return 0;
}

void od39_impl(vector<int> inputs) {
	map<int, int> countMap;
	for (int i = 0; i < inputs.size(); i++) {
		//lionel����֪����ô��mapȥ���ظ���ֵ�ˣ�
		countMap[inputs[i]]++; //lionel,0922ͻȻ��������
	}

	vector<pair<int, int>> res{ countMap.begin(),countMap.end() };
	sort(res.begin(), res.end(), cmp39);

	vector<int> result;
	int len = res.size();
	int max = res[len - 1].second;
	for (int i = len; i > 0; i--) {
		if (res[i - 1].second == max)
			result.push_back(res[i - 1].first);
		else
			break;
	}

	int middle = 0;
	sort(result.begin(), result.end());
	len = result.size();
	if (len % 2 != 0) {
		middle = result[len / 2];
	} else {
		middle = (result[len / 2] + result[len / 2 - 1]) / 2;
	}
	cout << middle << endl;
}

void od39() {
	vector<int> inputs1{ 10,11,21,19,21,17,21,16,21,18,15 };
	od39_impl(inputs1);
	vector<int> inputs2{ 2,1,5,4,3,3,9,2,7,4,6,2,15,4,2,4 };
	od39_impl(inputs2);
}