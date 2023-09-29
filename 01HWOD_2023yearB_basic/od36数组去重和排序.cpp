#include "test.h"

bool cmp361(pair<int, int> m1, pair<int, int> m2) {
	if (m1.second > m2.second)
		return 1;
	else if (m1.second == m2.second) {
		if (m1.first > m2.first)  //lionel，这个地方应该比较位置？ 逻辑上有问题
			return 1;
		else
			return 0;
	}
	return 1;
}


bool cmp36(pair<int, pair<int, int>> m1, pair<int, pair<int, int>> m2) {
	if (m1.second.second > m2.second.second)
		return 1;
	else if (m1.second.second == m2.second.second) {
		if (m2.first > m1.first)
			return 1;
	}
	return 0;
}


void od36_impl(vector<int> inputs) {
	unordered_map<int, int> val;  //因为存的时候，数据顺序变掉了，把map改成了unordered_map，lionel
	for (int i = 0; i < inputs.size(); i++)
		val[inputs[i]]++;


	vector<pair<int, pair<int, int>>> res1;  //lionel，用双层给解决了一下
	
	vector<pair<int, int>> res{ val.begin(),val.end() };  //lionel，当时不知道不知道map里面是不能自定义排序的，要用vector去保存一下
	for (int i = 0; i < val.size(); i++) {
		//int i = val[i].second();
		pair<int, int> tmp = res[i];
		pair<int, pair<int, int>> tmp2 = make_pair(i, tmp);
		//res1[i] = tmp;
		//res1.insert(i, tmp);
		res1.emplace_back(tmp2);
	}
	//sort(res1.begin(), res1.end(), cmp36);

	sort(res1.begin(), res1.end(),cmp36);
#if 0
	priority_queue < pair<int, int >> res{ val.begin(),val.end() };

	
	priority_queue(pair<int, int >,vector< pair<int, int >> ,cmp)
#endif
	for (auto c : res1) {
		cout << c.second.first << endl;
	}
}

void od36() {
	vector<int> inputs1{ 1,3,3,3,2,4,4,4,5 };  //3,4,1,2,5
	od36_impl(inputs1);
	vector<int> inputs2{ 1,2,4,4,4,5,3,3,3};  
	od36_impl(inputs2);
	vector<int> inputs3{ 1,2,4,4,4,5,3,3,3,2 };
	od36_impl(inputs3);
}