#include "test.h"

int g_height = 0;
bool cmp32(pair<int, int> m1, pair<int, int> m2) {
	int diff1 = m1.second - g_height;
	int diff2 = m2.second - g_height;
	if (abs(diff1) < abs(diff2)) {
		return 1;
	} else if (abs(diff1) == abs(diff2)) {
		if (m1.first < m2.first)
			return 1;
	}
	return 0;
}

void od32_impl(int height, int count, vector<int> inputs) {
	g_height = height;
	vector<pair<int, int>> res;
	for (int i = 0; i < count; i++) {
		res.emplace_back(make_pair(i, inputs[i]));
	}

	sort(res.begin(), res.end(), cmp32);

	for (auto c : res) {
		cout << c.second << endl;
	}
}

void od32() {
	int heigth1 = 100;
	int count1 = 10;
	vector<int> inputs1{ 95,96,97,98,99,101,102,103,104,105 };
	od32_impl(heigth1, count1, inputs1);
}