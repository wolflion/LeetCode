#include"test.h"

bool cmp47(pair<char, int> m1, pair<char, int> m2) {
	if (m1.second > m2.second)
		return 1;
	return 0;
}

void od47_impl(string input) {
	unordered_map<char, int> res_helper;
	for (int i = 0; i < input.size(); i++) {
		//lionel，这个要连续的，所以需要滑动窗口，这个没写，包括大小写算连续，非字符要break掉
		res_helper[input[i]]++;
	}

#if 0
	vector<pair<char, int>> res;
	for (int i = 0; i < res_helper.size(); i++) {
		//pair<char, int> tmp = res;
		cout << res_helper[i] << endl;
		//res_helper.emplace_back();
	}
#endif

	vector<pair<char, int>> res{ res_helper.begin(),res_helper.end() };
	sort(res.begin(), res.end(),cmp47);

	string result;
	for (auto c : res) {
		//result.push_back(c.first);
		result += c.first;
		//cout << c.second << endl;
		//result.push_back((c.second)+'\0');
		result += to_string(c.second);
	}
	cout << result<<endl;
}

void od47() {
	string inputs1{ "aabbcc" };
	od47_impl(inputs1);
	string inputs2{ "aadddbbbccccaaa" };//c4a3b
	od47_impl(inputs2);
}