#include "test.h"

//因为题没读懂，找了个链接，看到了人家思路**统计每个个数，然后按最多的删除**，https://zhuanlan.zhihu.com/p/642686464?utm_id=0

bool cmp(pair<int, int> m1, pair<int, int> m2) {
	if (m1.second > m2.second)
		return 1;
	return 0;
}

void od29_impl(vector<int> inputs) {
	map<int, int> val;
	for (int i = 0; i < inputs.size(); i++) {
		val[inputs[i]]++;
	}

	int len = inputs.size();
	vector<pair<int, int>> res{ val.begin(),val.end() };

	sort(res.begin(), res.end(), cmp);

	//cout << res[0].first << res[0].second << endl;
	int remain = len / 2 - 0;

	while (remain > 0) { //lionel，这个是临时想到的
		remain -= res[0].second;
		res.erase(res.begin());  //lionel，这个是不会，搜的
	}
	cout << res.size() << endl;
}

void od29() {
	vector<int> inputs1{ 1,1,1,1,3,3,3,6,6,8 };
	od29_impl(inputs1);
	vector<int> inputs2{ 2,2,2,2 };
	od29_impl(inputs2);
}