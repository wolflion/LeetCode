#include "test.h"

/*
* 输入
3  //数字序列的长度
4,8,10  //A的各个序列
3,6,4   //B的各个序列
输出
3   //A赢B的分数
*/

bool cmp27(vector<int> &m1, vector<int> &m2) {  //lionel，要变成 引用 格式，不然局部变量不会影响input的变化

	sort(m1.begin(), m1.end());  //lionel，因为默认是从小到大排列，最后比较的时候，也是逐个比较
	sort(m2.begin(), m2.end());
#if 0
	for (int i = 0; i < 3; i++) {
		if (m2[i] > m1[i]) {
			return 1;
		} else {
			return 0;
		}
	}
#endif
	return 0;
}

void od_a27_impl(int size, vector<vector<int>> input) {
	sort(input.begin(), input.end(), cmp27);
	int res=0;
	for (size_t i = 0; i < input.size()-1; i++) {
		for (int j = 0; j < size; j++) {
			if (input[i][j] > input[i + 1][j])
				res++;
		}
	}

	cout << res << endl;
}

void od_a27() {
	int size1 = 3;
	vector<vector<int>> input1{ {4,8,10},{3,6,4} };
	od_a27_impl(size1, input1);
}