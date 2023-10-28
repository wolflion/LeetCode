#include "test.h"

void od_a42() {
	int n = 3, n = 3;
	int start = 1, end = 3;
	const int inf = INT_MAX / 2;
	vector<vector<int>> tmp_edge{ {1,2,21},{2,3,13},{1,3,50} };
	vector<vector<int>> g(n, vector<int>(n, inf));

	//lionel��x��y�൱��u��v���൱��0��ʼ������ÿ�ζ���1
	for (auto& t : tmp_edge) {
		int x = t[0] - 1;
		int y = t[1] - 1;
		g[x][y] = t[2];
	}

	//lionel����Ŀ��д�ģ���ȷ���ĵ㣬�Ͳ�ȷ���ĵ�

	vector<int> dist(n, inf);
	dist[start - 1] = 0;
	vector<int> used(n);//��n��Ԫ�ظ�ֵΪ0,  [used(n,3)����n��Ԫ�ظ�ֵΪ3]
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

	cout << dist[end - 1] << endl; //lionel����Ϊ����ط����յ㣬������յ�ȡ������С

#if 0
	int ans = *max_element(dist.begin(), dist.end());
	return ans == inf ? -1 : ans;
#endif
}

//�ο�LC743
//grandyang.com

//https://blog.csdn.net/wj_phm/article/details/132748028