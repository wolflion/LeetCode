#include "test.h"

int lowbit(int num) {
	num = abs(num);  //lionel，最开始用了abs(num)，没用num去接
	string tmp = to_string(num);
	int len = tmp.size();
	while (num > 10) {
		int val = pow(10, len - 1);
		len--;
		num -= (num / val) * val;
	}
		
	//cout << num << endl;
	return num;
}

bool cmp79(pair<int, int> m1, pair<int, int> m2) {
	//取最低位
	int num1 = lowbit(m1.second);
	int num2 = lowbit(m2.second);
	//cout << num1 << "," << num2 << endl;
	if (num1 < num2) {
		return 1;
	} else if (num1 == num2) {
		if (m1.first > m2.first) {
			return 0;
		} else
			return 1;
	}
	return 0;
}

void od79_impl(vector<int> input) {
#if 0
	unordered_map<int, int> res_helper;
	for (auto c : input) {
		res_helper[c]++;  //lionel，开始想得有点复杂了，还用map，后来直接用pair()去存就行
	}

	//vector<pair<int,int>> res{ res_helper.begin(),res_helper.end() };

	//sort(res.begin(), res.end(), cmp79);
#endif
	vector<pair<int, int>> res;
	for (int i = 0; i < input.size(); i++) {
		res.emplace_back(make_pair(i, input[i]));
	}

	sort(res.begin(), res.end(), cmp79);

	for (auto c : res) {
		cout << c.second << endl;
	}
}

void od79() {
	vector<int> inputs1{ 1,2,5,-21,22,11,55,-101,42,8,7,32 };
	//cout << lowbit(55);
	od79_impl(inputs1);
}