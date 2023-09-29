#include"test.h"

int od02_impl(vector<int> input, int N) {
	constexpr int len = 100;
	int res = 0;
	int first = 0, last = 1;
	while (first < last) {
		while (last >= input.size())
			//break;
			return res;  //lionel，这是个临时方案，为何break; 在这个地方不行了呢

		int distance = input[first] + input[last];
		if (distance == len) {
			res += 0;
		} else {
			if (distance > len)
				res += 0;//lionel，大于100的时候，不用管，其实 这里面可以缩小到只判断一种，多了一些无用的判断语句
			else
				res += abs(len - distance);
		}
		first++;
		last++;
	}
	return res;
}

void od02() {
	int N1 = 2;
	vector<int>input1{ 50,50 };
	cout<<od02_impl(input1, N1)<<endl;

	int N2 = 4;
	vector<int>input2{ 50,70,20,70 };
	cout << od02_impl(input2, N2) << endl;
}