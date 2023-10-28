/*
* 题目描述

存在一个m*n的二维数组，其成员取值范围为0，1，2。

其中值为1的元素具备同化特性，每经过1S，将上下左右值为0的元素同化为1。

而值为2的元素，免疫同化。

将数组所有成员随机初始化为0或2，再将矩阵的[0, 0]元素修改成1，在经过足够长的时间后求矩阵中有多少个元素是0或2（即0和2数量之和）。
输入描述

输入的前两个数字是矩阵大小。后面是数字矩阵内容。
输出描述

返回矩阵中非1的元素个数。
*/

#include "test.h"

using vvi = vector < vector<int >>; //lionel，自己还不太会用这种，把顺序搞混了， 倒过来的写法 是typedef的用法
using pii = pair<int, int>;
int dirs32[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
void od_a32_impl(int m, int n, vvi &input) {
	//将数组所有成员随机初始化为0或2,再将矩阵的[0,0]元素修改成1  --lionel，要看题干
	input[0][0] = 1;
	queue<pii> q;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (input[i][j] == 1) {
				q.push(make_pair(i, j));//lionel，这个make_pair，不是必须吧
			}
		}
	}
	int count = 1;

	while (q.size()) {  //lionel，这个地方是while()
		int x = q.front().first;  //lionel，队列没有top，只有front
		int y = q.front().second;
		q.pop();
		for (auto dir : dirs32) {
			int mx = x + dir[0];
			int my = y + dir[1];

			if (mx >= 0 && mx < m && my >= 0 && my < n && input[mx][my] == 0) {
				input[mx][my] = 1;
				count++;
				q.push(make_pair(mx, my));
			}
		}
	}
	cout << m * n - count << endl;
}

void od_a32() {
	int m1 = 4, n1 = 4;
	vvi inputs1{ {0,0,0,0},{0,2,2,2},{0,2,0,0},{0,2,0,0} };
	od_a32_impl(m1, n1, inputs1);  //预期9，输出9
}

//https://zhuanlan.zhihu.com/p/644880876