#include "test.h"

//把十进制转二进制相加  
//lionel，我理解错了，我理解成了 二进制加加了
#if 0
int add(int value) {
	value = 258;
	vector<int> res;
	for (int i = 31; i >= 0; i--) {
		res.push_back((value >> i) & 1);
	}
	int sum = 0;
	sum = accumulate(res.begin(), res.end(), sum);
	return sum;
}
#endif
//拆分成4个8位的再相加，二进制，还是不熟悉啊

int add(int value){  //lionel，是我这个理解错了，https://blog.csdn.net/yuhaomogui/article/details/125341750
	int sum = 0;
	while (value > 0) {
		sum += value & 0xff;
		value >>= 8;
	}
	return sum;
}

void od72_impl(vector<int> input) {
	int modNum = input[1];
	int val = input[0];
	vector<int>nums(input.begin() + 2, input.end());
	vector<int> res;
	for (auto c : nums) {
		int v = add(c);
		//cout << v << endl;
		res.push_back(v % modNum);
	}

	map<int, int>m;
	for (auto c : res) {  //lionel，应该是1 2 3 0 1 2 3 0 12，我输出是 0 1 2 3 0 1 2 3 0 1
		m[c]++;
	}

	int min = 0;
	for (auto c : m) {
		//cout << c.first << endl;
		if (c.first < val) {
			min = c.second > min ? c.second : min;
		}
	}
	cout << min << endl;
}

void od72() {
	vector<int> inputs1{ 3,4,256,257,258,259,260,261,262,263,264,265 };
	od72_impl(inputs1);
	vector<int> inputs2{ 1,4,256,257,258,259,260,261,262,263,264,265 };
	od72_impl(inputs2);
}

//https://www.yii666.com/blog/371859.html