#include "test.h"

//˼·�ǣ�1��������ʱ��������������������һ���Ŀ�ʼʱ�䣬���ڵ��� ��һ���Ľ���ʱ�䣬��count++

bool cmp(pair<int, int>m1, pair<int, int> m2) {
	if (m2.second > m1.second) {
		return 1;
	}  //û˵����ʱ����ȵĳ�������������
	return 0;
}

void od_a14_impl(int m_count, int n_total, vector<pair<int, int>> input) {
	sort(input.begin(), input.end(), cmp);

	int lastTime = 0;
	int interviewCount = 0;
	for (int i = 0; i < n_total; i++) {
		if (input[i].first >= lastTime) {
			interviewCount++;
			lastTime = input[i].second;
		}
	}

	cout << (interviewCount / m_count) + 1 <<endl;  //lionel������������ã���1�ǿ��Եģ�������ã���1�Ͳ���
}

void od_a14() {
	int m_count1 = 2;//���Թ���������˴�
	int n_total1 = 5;//�ܵ����Գ���

	vector<pair<int, int>> input1 = { {1,2},{2,3},{3,4},{4,5},{5,6} };//ÿ���Ŀ�ʼ�ͽ���ʱ��
	od_a14_impl(m_count1, n_total1, input1);
}