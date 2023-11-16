#include "test.h"

/*
* 所谓水仙花数，是指一个n位的正整数，其各位数字的n次方和等于该数本身例如153是水仙花数，153是一个3位数，并且153=1^3+5^3+3^3

输入描述

第一行输入一个整数n，表示一个n位的正整数。n在3到7之间，包含3和7.

第二行输入一个正整数m，表示需要返回第m个水仙花数。

输出描述

返回长度是n的第m个水仙花数。个数从0开始编号若m大于水仙花数的个数，返回最后一个水仙花数和m的乘积。若输入不合法，返回-1。
*/


bool isCheck(int x, int n) {
	vector<int> a;
	int value = x;
	while (x) {
		int t = x % 10;
		x = x / 10;
		a.push_back(t);
	}

	int sum = 0;
	for (auto num : a) {
		sum += pow(num, n);
	}
	a.clear();  //lionel，vec的清空办法，clear()、erarse()、swap()3种方法

	if (sum == value) {
		return true;
	}
	return false;
}

void od23() {
	int n = 3;
	//cin >> n;
	int m = 0;
	//cin >> m;

	int value = 1;
	int tmp = n;
	while (tmp--) {
		value *= 10;
	}

	vector<int> res;
	for (int i = 0; i < value; i++) {
		if (isCheck(i, n) && i>1) { //lionel，这个地方加了一个i>1，不然的话，0也是符合的，1也是符合的
			res.push_back(i);
		}
	}
	cout << res[m] << endl;
}

//https://zhuanlan.zhihu.com/p/644158241