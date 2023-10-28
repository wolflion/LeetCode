/*
* 小华和小为是很要好的朋友，他们约定周末一起吃饭。

通过手机交流，他们在地图上选择了多个聚餐地点（由于自然地形等原因，部分聚餐地点不可达），求小华和小为都能到达的聚餐地点有多少个？

输入描述

第一行输入m和n，m代表地图的长度，n代表地图的宽度。

第二行开始具体输入地图信息，地图信息包含：

0 为通畅的道路

1 为障碍物（且仅1为障碍物）

2 为小华或者小为，地图中必定有且仅有2个 （非障碍物）

3 为被选中的聚餐地点（非障碍物）

输出描述

可以被两方都到达的聚餐地点数量，行末无空格。
*/

#include "test.h"

//首先想的是dfs的模板是啥？  【dfs主要是递归，如果不递归，就用栈】

int m = 4, n = 4;  //长，宽

void dfs(vector<vector<int>> input, int x, int y, vector<vector<int>>& point, vector<vector<int>> &person) {
	if (x < 0 || y < 0 || x >= m || y >= n || input[x][y] == 1 || person[x][y] == 1) {
		return;
	}

	if (input[x][y] == 3 && person[x][y] == 0) {
		point[x][y]++;//访问次数+1
	}

	person[x][y] = 1;  //已经访问过

	//lionel，用for和dirs[4][2]是一样的
	dfs(input, x + 1,y, point, person);
	dfs(input, x, y+1, point, person);
	dfs(input, x - 1, y, point, person);
	dfs(input, x, y-1, point, person);
}

void od_a15_impl(int m, int n, vector<vector<int>> input){
	//vector<vector<int>> v(m, vector<int>(n, 0)); //感觉就是input啊
	int sum = 0;
	vector<vector<int>> inn(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {  //lionel，这个地方j<n，写成了i<n，导致越界访问
			if (input[i][j] == 2)
				inn.push_back({ i, j });  //lionel，我没看懂，这个意义在哪里
		}
	}

	vector<vector<int>> point(m, vector<int>(n, 0));
	vector<vector<int>> hua(m, vector<int>(n, 0));
	vector<vector<int>> wei(m, vector<int>(n, 0));

	dfs(input, inn[0][0], inn[0][1], point, hua);
	dfs(input, inn[1][0], inn[1][1], point, wei);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (point[i][j] >= 2)
				sum++;
		}
	}

	cout << sum << endl;
}

void od_a15() {
	int m1 = 4, n1 = 4;  //长，宽
	vector<vector<int>> input1{ {2,1,0,3},{0,1,2,1},{0,3,0,0},{0,0,0,0} };  //3表明聚餐的地方，2表示（小华，小为的位置），0可通行，1不能通行
	od_a15_impl(m1, n1, input1);  //输出2
}

// https://zhuanlan.zhihu.com/p/645083603，这个是python的并查集

// c++的并查集 http://www.sylblog.xin/52/

//https://www.nowcoder.com/discuss/525451151773270016，这是C++的dfs