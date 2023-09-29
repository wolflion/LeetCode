#include "test.h"

bool cmp39(pair<int, int> m1, pair<int, int> m2) {
	if (m1.second < m2.second)  //lionel，因为存在重复的元素，我就聪明的写个=号，会发生断言错误if (m1.second <= m2.second)，这种不支持
		return 1;
	return 0;
}

void od39_impl(vector<int> inputs) {
	map<int, int> countMap;
	for (int i = 0; i < inputs.size(); i++) {
		//lionel，不知道怎么用map去存重复的值了？
		countMap[inputs[i]]++; //lionel,0922突然想起来的
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