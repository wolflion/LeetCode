#include "test.h"

void od24_impl(vector<string> input) {
	vector<int> nums;
	string tmp;
	for (auto s : input) {
		int len = s.size();
		char last = s[len - 1];
		tmp = s.substr(0, len - 1);
		if (last == 'Y') {
			nums.emplace_back(stoi(tmp));
		}
		if (last == 'S') {
			nums.emplace_back(stoi(tmp) * 7);
		}
	}

	int sum = 0;
	int maxValue = 0;
	int first = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] - first > maxValue) {
			sum -= maxValue;
			maxValue = nums[i] - first;  //lionel����ʱ����һ��������������i=len-1ʱ��sum+=maxValue��������һ��maxValue���ܼӵ�����
			sum += maxValue;
		} else {
			maxValue = 0;
			first = nums[i];//lionel����һ��ʱ��д�����sum += maxValue;
		}
	}
	cout << sum << endl;
}

void od24() {
	vector<string> inputs1{ "2Y","3S","4S","6Y","8S" };
	od24_impl(inputs1);
}