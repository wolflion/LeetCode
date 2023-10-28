#include "test.h"

/*
* 2XXX 年，人类通过对火星的大气进行宜居改造分析，使得火星已在理论上具备人类宜居的条件；

由于技术原因，无法一次性将火星大气全部改造，只能通过局部处理形式；

假设将火星待改造的区域为 row * columnrow∗column 的网格，每个网格有 3 个值，宜居区、可改造区、死亡区，使用 YES、NO、NA 代替：

YES 表示该网格已经完成大气改造；
NO 表示该网格未进行改造，后期可进行改造；
NA 表示死亡区，不作为判断是否改造完成的宜居，无法穿过；
初始化下，该区域可能存在多个宜居区，并且每个宜居区能同时在每个太阳日单位向上下左右四个方向的相邻格子进行扩散，自动将 4 个方向相邻的真空区改造成宜居区；

请计算这个待改造区域的网格中，可改造区是否能全部变成宜居区，如果可以，则返回改造的太阳日天数，不可以则返回-1。

输入
输入 row * columnrow∗column 个网格数据，每个网格值枚举值如下：YES，NO，NA；

样例：

YES YES NO
NO NO NO
NA NO YES
输出
可改造区是否能全部变成宜居区，如果可以，则返回改造的太阳日天数，不可以则返回-1。
*/

//原题是LC的994

int dirs01[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
using pii = pair<int, int>;

void bfs(queue<pii> &q, vector<vector<string>> &input,int row, int col, int &no_count) {
	int result = 0;
	while (q.size() && no_count) {
		queue<pii> newq;

		//lionel，知道错在哪了，是每个宜居区，这个地方就必须是for()了  【这个地方太扯了，没想清楚】
		for (int i = 0; i < q.size(); i++) {
			int x = q.front().first;  //lionel，队列没有top，只有front
			int y = q.front().second;

			q.pop();
			for (auto dir : dirs01) {
				int mx = x + dir[0];
				int my = y + dir[1];

				cout << mx << "," << my << "before" << endl;
				if (mx >= 0 && mx < row && my >= 0 && my < col && input[mx][my] == "NO") {
					input[mx][my] = "YES";
					cout << mx << "," << my << endl;
					newq.push(make_pair(mx, my));
					no_count--;
				}
			}
			
		}
		cout << "result" << result << endl;
		result++;
		while (!q.empty()) q.pop();
		q = newq;
	}

	if (no_count == 0)
		cout << result << endl;
}


void od_a01_impl(vector<vector<string>>& input) {
	int row = input.size();
	int col = input[0].size();
	queue<pii> q;
	int no_count = 0;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (input[i][j] == "YES") {
				q.push(make_pair(i, j));
			} else if (input[i][j] == "NO") {
				no_count++;
			}
		}
	}
	bfs(q, input, row, col, no_count);
}

void od_a01() {
	vector<vector<string>>inputs1{ {"YES","YES","NO"},{"NO","NO","NO"} ,{"NO","NO","YES"} };
	od_a01_impl(inputs1);
}

//https://zhuanlan.zhihu.com/p/647052060
//https://jsrun.net/XZJKp