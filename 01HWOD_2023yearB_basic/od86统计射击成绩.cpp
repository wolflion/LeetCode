#include "test.h"

bool cmp86(pair<int, int> m1, pair<int, int> m2) {
	if (m1.second > m2.second)
		return 1;
	else if (m1.second == m2.second && m1.first>m2.first) {
		return 1;
	}
	return 0;
}

void od86_impl(int count, vector<int> player, vector<int> score) {
	vector<pair<int, int>>res_helper;
	for (int i = 0; i < count; i++) {
		res_helper.emplace_back(make_pair(player[i], score[i]));
	}

	//先统计次数
	map<int, int> res_map;
	for (auto c : player) {
		res_map[c]++;
	}

	vector<pair<int, int>> res;
	vector<pair<int, int>> res_vector(res_map.begin(), res_map.end());
	for (auto c : res_vector) {
		if (c.second < 3) {
			//res_vector.erase(c.first);
			cout << c.first << endl;  //lionel，如何取消，这个地方应该遗留了一点
		}

		int sum = 0;
		int val = c.first;
		vector<int> top3;
		for (int i = 0; i < res_helper.size(); i++) {
			if (val == res_helper[i].first) {
				//sum += res_helper[i].second;
				top3.emplace_back(res_helper[i].second);
			}
		}
		sort(top3.begin(), top3.end());
		int len = top3.size();
		sum += top3[len - 1];
		sum += top3[len - 2];
		sum += top3[len - 3];  //lionel，第一次忘记算3的成绩了
		res.emplace_back(make_pair(val, sum));
	}

	sort(res.begin(), res.end(),cmp86);

	for (auto c : res) {
		cout << c.first << endl;
	}
}

void od86() {
	int count1 = 13;
	vector<int> players1{ 3,3,7,4,4,4,4,7,7,3,5,5,5 };
	vector<int> scores1{ 53,80,68,24,39,76,66,16,100,55,53,80,55 };
	od86_impl(count1, players1, scores1);
}