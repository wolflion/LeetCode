#include "test.h"

/*
* 题目描述
给你一个由 '0'（空地）、 '1'（银矿）、'2'（金矿）组成的的地图，矿堆只能由上下左右相邻的金矿或银矿连接形成。

超出地图范围可以认为是空地。

假设银矿价值 1 ，金矿价值 2 ，请你找出地图中最大价值的矿堆并输出该矿堆的价值。

输入
地图元素信息如： 22220 00000 00000 11111

地图范围最大 300*300

0<= 地图元素 <=2

输出
矿堆的最大价值。 
*/



#if 0
bool visited[100][100] = { false };
vector<vector<int>>inputs1{ {2,2,2,2,0},{0,0,0,0,0},{0,0,0,0,0},{0,1,1,1,1} };

bool check(int x, int y, int m, int n) {
	if (x > m || y > n || x < 0 || y < 0)
		return false;
	return true;
}

void dfs(int x, int y,int &sum,int m, int n) {
	//lionel，退出条件是啥
	if (x > m || y > n) {
		cout << sum << endl;
		return;
	}

	if (inputs1[x][y] && !visited[x][y]) {
		sum += inputs1[x][y];
		visited[x][y] = true;
	}

	//4个方向上递归
	int dirs[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
	for (int k = 0; k < 4; k++) {
		int mx = x + dirs[k][0];
		int my = y + dirs[k][1];

		if (check(mx, my, m, n) && (!visited[mx][my]) && (inputs1[mx][my] != 0)) {
			sum += inputs1[mx][my];
			visited[mx][my] = true;
			dfs(mx, my, sum, m, n);
		}
			
	}
}


#endif
vector<vector<int>>inputs;
int dirs21[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

#if 0
void dfs(vector<vector<int>> &visited, vector<vector<int>>&input, int row, int col, int x, int y, int &sum) {
	visited[x][y] = 1;//把当前标识为走过
	for (int k = 0; k < 4; k++) {
		int mx = x + dirs21[k][0];
		int my = y + dirs21[k][1];

		//我本来想把这个check，弄成一个函数，感觉也没必要，lionel
		if (mx < 0 || mx >= row || my < 0 || my >= col || input[mx][my] == 0)
			//continue;
			return;

		if ((input[mx][my] == 1 || input[mx][my] == 2) && visited[mx][my] == 0) {
			//cout << input[mx][my] << endl;
			//sum += input[mx][my];
			dfs(visited, input, row, col, mx, my,sum);
		}
			
	}
}
#endif

void dfs(vector<vector<int>>& input, int x, int y, int& island) {
	int row = input.size();
	int col = input[0].size();

#if 0
	if (x < 0 || x >= row || y < 0 || y >= col || input[x][y] == 0)
		return;
#endif
	
	//sum = max(sum, ++cnt);
	island += input[x][y];

	input[x][y] = 0; //修改一下，相当于visited[][]
	

	for (auto dir : dirs21) {
		int mx = x + dir[0];
		int my = y + dir[1];
		if (mx >= 0 && mx < row && my >= 0 && my < col && input[mx][my]) {
			dfs(input, mx, my, island);
		}
	}
}

void od_a21_impl(vector<vector<int>> &input) {
	int row = input.size();
	int col = input[0].size();

	int res = 0, island = 0;
	//vector<vector<int>> visited(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//lionel，在于这个逻辑不太熟悉
			if (input[i][j]) {
				dfs(input, i, j, island);
				res = max(res, island);
				island = 0;
			}
			
#if 0
			if (visited[i][j] == 0 && input[i][j] != 0) {
				cout << input[i][j] << endl;
				//sum += input[i][j];
				dfs(visited, input, row, col, i, j, sum);
				sum += input[i][j];
		}
			//visited[i][j] = true;
			dfs(i, j, sum, m, n);
#endif
		}
	}
	cout << res << endl;
}
void od_a21() {
	vector<vector<int>>inputs1{ {2,2,2,2,0},{0,0,0,0,0},{0,0,0,0,0},{0,1,1,1,1} };
	inputs = inputs1;
	od_a21_impl(inputs1);
}


//参考的https://blog.csdn.net/fuxuemingzhu/article/details/79182435，这个解法