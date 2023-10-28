/*
* 小明玩一个游戏。系统发1+n张牌，每张牌上有一个整数。第一张给小明，后n张按照发牌顺序排成连续的一行。需要小明判断，后n张牌中，是否存在连续的若干张牌，其和可以整除小明手中牌上的数字.



输入描述:

输入数据有多组，每组输入数据有两行，输入到文件结尾结束

第一行有两个整数n和m，空格隔开。m代表发给小明牌上的数字

第二行有n个数，代表后续发的n张牌上的数字，以空格隔开。

输出描述:

对每组输入，如果存在满足条件的连续若干张牌，则输出1:否则，输出0
*/

#include "test.h"

void od_a24_impl(int n, int m, vector<int> input) {
	vector<int> val(n, 0);  //lionel，遇到个问题，没有初始化会core掉，初始化方法不对，我用的是{n,0}表示初始化2个元素，只有使用()才行，表示把n个元素初始化为0
	for (int i = 0; i < input.size(); i++) {
		if (i == 0) {
			val[i] = input[i];
		} else {
			val[i] = val[i - 1] + input[i];
		}
	}

	for (auto num : val) {
		if (num % m == 0) {
			cout << "1" << endl;
			return;
		}
	}
	cout << "0" << endl;
}

void od_a24() {
	int n1 = 6, m1 = 7;
	vector<int> inputs1{ 2,12,6,3,5,5 };
	od_a24_impl(n1, m1, inputs1);

	int n2 = 10, m2 = 11;
	vector<int> inputs2{ 1,1,1,1,1,1,1,1,1,1 };
	od_a24_impl(n2, m2, inputs2);
}

//可以参考，LC1480，https://blog.csdn.net/xt199711/article/details/114678001
