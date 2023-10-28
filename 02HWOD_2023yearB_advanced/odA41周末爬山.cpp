/*
* 题目描述

周末小明准备去爬山锻炼，0代表平地，山的高度使用1到9来表示，小明每次爬山或下山高度只能相差k及k以内，每次只能上下左右一个方向上移动一格，小明从左上角(0,0)位置出发

输入描述

第一行输入m n k(空格分隔)

·代表m*n的二维山地图，k为小明每次爬山或下山高度差的最大值，然后接下来输入山地图，一共m行n列，均以空格分隔。取值范围：

·0<m≤500

·O<n≤500

·0<k<5

输出描述

请问小明能爬到的最高峰多高，到该最高峰的最短步数，输出以空格分隔。同高度的山峰输出较短步数。

如果没有可以爬的山峰，则高度和步数都返回0。
*/


#include "test.h"
int m1 = 5, n1 = 4, k1 = 1;
vector<vector<int>> input1{ {0,1,2,0},{1,0,0,0},{1,0,1,2},{1,3,1,0},{0,0,0,9} };  
vector<vector<bool>> visited(m1, vector<bool>(n1, false));
vector<vector<int>> direction{ {1,0},{-1,0},{0,1},{0,-1} };

map<int, int> minSteps;

extern void dfs(int i, int j, int steps);

//2 2，最高峰在(0,2)的位置，高度为2，  最短路径（0,0)-(0,1)-(0,2)，最短步数为2
void od_a41() {
	int max = input1[0][0];

	int steps = 0;
	minSteps[max] = 0;

	dfs(0, 0, 0);  //从开始的(i,j)也就是(0,0)已经走了steps步，第一次steps是0

	for (auto c : minSteps) {
		if (c.first > max) {
			max = c.first;
			steps = c.second;
		}
	}

	cout << max << "," << steps << endl; //输出是2,2  lionel，关注一下
}

void dfs(int i, int j, int steps) {
	//当前山峰高度
	int curHeight = input1[i][j];
	//4个方向
	for (auto d : direction) {
		int mx = i + d[0];
		int my = j + d[1];

		//cout << mx << "," << my << "," << visited[i][j] << endl;
		//lionel，关注一下，应该是mx>=input1.size()，我写成mx>input1.size()，两个式子，都小写了一个=号，导致core掉了
		if (mx<0 || mx>=input1.size() || my<0 || my>=input1[0].size() || visited[i][j]) {
			continue;
		}

		//下一步山峰
		int nextHeight = input1[mx][my];
		if (abs(curHeight - nextHeight) <= k1) {
			steps++;
			if (!minSteps[nextHeight] || minSteps[nextHeight] > steps) {
				minSteps[nextHeight] = steps;
			}

			//标记为已访问
			visited[i][j] = true;
			//下一个
			dfs(mx, my, steps);
			//回退
			visited[i][j] = false;  //lionel，这就很回溯的思想了
			steps--;
		}
	}
}

//https://blog.csdn.net/wj_phm/article/details/132748092