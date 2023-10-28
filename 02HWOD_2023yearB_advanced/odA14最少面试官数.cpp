#include "test.h"

//思路是，1、按结束时间排序，逐个遍历，如果下一个的开始时间，大于等于 上一个的结束时间，就count++

bool cmp(pair<int, int>m1, pair<int, int> m2) {
	if (m2.second > m1.second) {
		return 1;
	}  //没说结束时间相等的场景，就先这样
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

	cout << (interviewCount / m_count) + 1 <<endl;  //lionel，如果不是正好，加1是可以的，如果正好，加1就不对
}

void od_a14() {
	int m_count1 = 2;//面试官最多面试人次
	int n_total1 = 5;//总的面试场次

	vector<pair<int, int>> input1 = { {1,2},{2,3},{3,4},{4,5},{5,6} };//每场的开始和结束时间
	od_a14_impl(m_count1, n_total1, input1);
}