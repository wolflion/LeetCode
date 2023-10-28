#include "test.h"

void od_a42() {
	int n = 3, n = 3;
	int start = 1, end = 3;
	const int inf = INT_MAX / 2;
	vector<vector<int>> tmp_edge{ {1,2,21},{2,3,13},{1,3,50} };
	vector<vector<int>> g(n, vector<int>(n, inf));

	//lionel，x和y相当于u和v，相当从0开始，所以每次都减1
	for (auto& t : tmp_edge) {
		int x = t[0] - 1;
		int y = t[1] - 1;
		g[x][y] = t[2];
	}

	//lionel，题目上写的，已确定的点，和不确定的点

	vector<int> dist(n, inf);
	dist[start - 1] = 0;
	vector<int> used(n);//把n个元素赋值为0,  [used(n,3)，把n个元素赋值为3]
	for (int i = 0; i < n; i++) {
		int x = -1;
		for (int y = 0; y < n; y++) {
			if (!used[y] && (x == -1 || dist[y] < dist[x])) {
				x = y;
			}
		}
		used[x] = true;
		for (int y = 0; y < n; y++) {
			dist[y] = min(dist[y], dist[x] + g[x][y]);
		}
	}

	cout << dist[end - 1] << endl; //lionel，因为这个地方有终点，如果无终点取所有最小

#if 0
	int ans = *max_element(dist.begin(), dist.end());
	return ans == inf ? -1 : ans;
#endif
}

//参考LC743
//grandyang.com

//https://blog.csdn.net/wj_phm/article/details/132748028