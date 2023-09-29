#include"test.h"

int od02_impl(vector<int> input, int N) {
	constexpr int len = 100;
	int res = 0;
	int first = 0, last = 1;
	while (first < last) {
		while (last >= input.size())
			//break;
			return res;  //lionel�����Ǹ���ʱ������Ϊ��break; ������ط���������

		int distance = input[first] + input[last];
		if (distance == len) {
			res += 0;
		} else {
			if (distance > len)
				res += 0;//lionel������100��ʱ�򣬲��ùܣ���ʵ �����������С��ֻ�ж�һ�֣�����һЩ���õ��ж����
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