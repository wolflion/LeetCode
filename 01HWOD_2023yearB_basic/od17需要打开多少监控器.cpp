#include "test.h"

void od17_impl(vector<vector<int>> input, int m, int n) {
	vector<vector<int>> park(m + 2, vector<int>(n + 2, 0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			park[i][j] = input[i - 1][j - 1];
		}
	}

	int dx[5] = { -1,0,1,0,0 };
	int dy[5] = { 0,-1,0,1,0 };//lionel，为啥是5呢？

	for (int i = 1; i <m; i++) {
		for (int j = 1; j <n; j++) {
			if (park[i][j] == 1) {
				for (int k = 0; k < 5; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
						park[nx][ny] = 1;
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <=m; i++) { //lionl，啥时候要等于，啥时候要不等于，这是个问题，要看下
		for (int j = 1; j <= n; j++) {
			if (park[i][j] == 1)
				res++;
		}
	}

	cout << res << endl;
}

void od17() {
	vector<vector<int>> inputs1{ {0,0,0},{0,1,0},{0,0,0} };
	int m1 = 3;
	int n1 = 3;
	od17_impl(inputs1,m1,n1);
}