#include "test.h"

void od10_impl(vector<int> input, int target) {
	//09-12重新想了一下，类似于three sum的写法
	vector<int>res;
	sort(input.begin(), input.end());
	for (int i = 0; i < input.size(); i++) {
		int first = i + 1;
		int last = input.size() - 1;

		target -= input[i];

		while (first < last) {
			if (input[first] + input[last] < target) {
				res.emplace_back(input[first] + input[last] + input[i]);
				first++;//lionel，这个顺序写错了，应该先emplace_back，然后再first++;
			} else {
				last--; 
			}
		}
	}

	sort(res.begin(), res.end());
	for (auto c : res) {
		cout << c << " ";
	}
	cout << res[res.size()-1] << endl;
}

#if 0
//lionel，我这个其实有序的，其实不应该这样，自己没完全想好
void od10_impl(vector<int> input, int target) {
	int sum = 0;
	vector<int>res;
	int first = 0, last = first+3;//lionel,窗口大小为3
	while (first < last) {
		if (last > input.size())
			break;

		sum = input[first] + input[first + 1] + input[first + 2];
		if (sum < target) {
			cout << sum << endl;
			res.emplace_back(sum);
		}
		first++;
		last++;
	}
	sort(res.begin(), res.end());
	cout << res[res.size()] << endl;
}
#endif

void od10() {
	vector<int> input1{ 23,26,36,27 };
	int target1 = 78;
	od10_impl(input1, target1);
}